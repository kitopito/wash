
#include "parse.h"
#include "../minishell.h"
//#include <libft.h>
#include <stdlib.h>

char *ft_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;
	char	*s_start;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
		s_start = (char *)s + start;
	else
		s_start = (char *)s + s_len;
	if (ft_strlen(s_start) < len)
		len = ft_strlen(s_start);
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s_start[i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

t_token	*new_token()
{
    t_token	*token;

    token = malloc(sizeof(t_token));
    if (token == NULL)
        return (NULL);
    token->lexeme = NULL;
    token->type = TOKEN_PLAIN;
    token->next = NULL;
    return (token);
}

void	free_token(t_token *token)
{
    if (token == NULL)
        return;
    free(token->lexeme);
    free(token);
}

void	free_tokens(t_token *head)
{
    t_token	*tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free_token(tmp);
    }
}

char *token_space(char *line, t_token *token) {
    token->lexeme = NULL;
    token->type = TOKEN_SPACE;
    //while (*line != NULL && ft_isspace(*line))
    while (*line != NULL && isspace(*line))
        line++;
    return (line);
}

char *token_pipe(char *line, t_token *token) {
    token->lexeme = NULL;
    token->type = TOKEN_PIPE;
    line++;
    return (line);
}

char *token_semicolon(char *line, t_token *token) {
    token->lexeme = NULL;
    token->type = TOKEN_SEMICOLON;
    line++;
    return (line);
}

// char *token_and(char *line, t_token *token) {
//     token->lexeme = NULL;
//     token->type = TOKEN_AND;
//     line++;
//     return (line);
// }

// char *token_or(char *line, t_token *token) {
//     token->lexeme = NULL;
//     token->type = TOKEN_OR;
//     line++;
//     return (line);
// }

char *token_redirect_in(char *line, t_token *token) {
    token->lexeme = NULL;
    token->type = TOKEN_REDIRECT_IN;
    line++;
    return (line);
}

char *token_redirect_out(char *line, t_token *token) {
    token->lexeme = NULL;
    token->type = TOKEN_REDIRECT_OUT;
    line++;
    return (line);
}

char *token_append(char *line, t_token *token) {
    token->lexeme = NULL;
    token->type = TOKEN_APPEND;
    line += 2;
    return (line);
}

char *token_heredoc(char *line, t_token *token) {
    token->lexeme = NULL;
    token->type = TOKEN_HEREDOC;
    line += 2;
    return (line);
}

char *token_double_q(char *line, t_token *token) {
    line++;

    char *line_copy = line;
    while(*line_copy != '\0' && *line_copy != '\"')
        line_copy++;
    
    if(*line_copy == '\0')
        return (NULL);

    token->type = TOKEN_DOUBLE_QUOTE;
    token->lexeme = ft_substr(line, 0, line_copy - line);
    if(token->lexeme == NULL)
        return (NULL);
    
    return (line_copy + 1);
    
}

char *token_single_q(char *line, t_token *token) {
    line++;

    char *line_copy = line;
    while(*line_copy != '\0' && *line_copy != '\'')
        line_copy++;
    
    if(*line_copy == '\0')
        return (NULL);

    token->type = TOKEN_SINGLE_QUOTE;
    token->lexeme = ft_substr(line, 0, line_copy - line);
    if(token->lexeme == NULL)
        return (NULL);
    
    return (line_copy + 1);
}

char *token_plain(char *line, t_token *token) {
    char *line_copy = line;
    while(*line_copy != '\0' && isspace(*line_copy) == 0 && *line_copy != '|' && 
            *line_copy != ';' && *line_copy != '<' && *line_copy != '>' && 
            *line_copy != '\"' && *line_copy != '\'')
        line_copy++;
    
    token->type = TOKEN_PLAIN;
    token->lexeme = ft_substr(line, 0, line_copy - line);
    if(token->lexeme == NULL)
        return (NULL);
    
    return (line_copy);
}

t_token    *lex(t_var *var, char *line)
{
    t_token	*head = NULL;
    t_token	*current = NULL;
    char	*start = line;
    char	*end;

    while (*line != '\0')
    {
        if(head == NULL)
        {
            head = new_token();
            if (head == NULL)
                return (NULL);
            current = head;
        }
        else
        {
            current->next = new_token();
            if (current->next == NULL)
            {
                free_tokens(head);
                return (NULL);
            }
            current = current->next;
        }

        //if(ft_isspace(*line))
        if(isspace(*line))
            line = token_space(line, current);
        else if (*line == '|')
            line = token_pipe(line, current);
        else if (*line == ';')
            line = token_semicolon(line, current);
        // else if (*line == '&')
        //     line = token_and(line, current);
        // else if (*line == '|')
        //     line = token_or(line, current);
        else if (*line == '<' && *(line + 1) == '<')
            line = token_heredoc(line, current);
        else if (*line == '<')
            line = token_redirect_in(line, current);
        else if (*line == '>' && *(line + 1) == '>')
            line = token_append(line, current);
        else if (*line == '>')
            line = token_redirect_out(line, current);
        else if (*line == '\"')
            line = token_double_q(line, current);
        else if (*line == '\'')
            line = token_single_q(line, current);
        else
            line = token_plain(line, current);
        
        if(line == NULL)
        {
            free_tokens(head);
            return (NULL);
        }
    }
    return (head);
}

// #include <stdio.h>
// #include <unistd.h>
// int main(void)
// {
//     t_var *var = NULL;

//     char buf[100];
//     int bytes_read = read(STDIN_FILENO, buf, sizeof(buf) - 1);
//     buf[bytes_read] = '\0';
//     t_token *tokens = lex(var, buf);
//     t_token *current = tokens;

//     while (current != NULL)
//     {
//         if(current->type == TOKEN_PLAIN)
//             printf("TOKEN_PLAIN: %s\n", current->lexeme);
//         else if(current->type == TOKEN_PIPE)
//             printf("TOKEN_PIPE\n");
//         else if(current->type == TOKEN_SEMICOLON)
//             printf("TOKEN_SEMICOLON\n");
//         else if(current->type == TOKEN_SPACE)
//             printf("TOKEN_SPACE\n");
//         else if(current->type == TOKEN_REDIRECT_IN)
//             printf("TOKEN_REDIRECT_IN\n");
//         else if(current->type == TOKEN_REDIRECT_OUT)
//             printf("TOKEN_REDIRECT_OUT\n");
//         else if(current->type == TOKEN_APPEND)
//             printf("TOKEN_APPEND\n");
//         else if(current->type == TOKEN_HEREDOC)
//             printf("TOKEN_HEREDOC\n");
//         else if(current->type == TOKEN_DOUBLE_QUOTE)
//             printf("TOKEN_DOUBLE_QUOTE: %s\n", current->lexeme);
//         else if(current->type == TOKEN_SINGLE_QUOTE)
//             printf("TOKEN_SINGLE_QUOTE: %s\n", current->lexeme);
//         current = current->next;
//     }

//     free_tokens(tokens);
//     return 0;
// }

/*
./a.out
 cat <'hoge.txt'    |  grep "neko $USER" | wc -l 2>"mosa".txt 1>>bosu  <<poko
*/