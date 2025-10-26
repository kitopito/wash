
#ifndef PARSE_H
# define PARSE_H
# include "../minishell.h"

typedef enum token_type
{
    TOKEN_UNKNOWN,
    TOKEN_PLAIN,
    TOKEN_PIPE,
    TOKEN_SEMICOLON,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_SPACE,
    TOKEN_REDIRECT_IN,
    TOKEN_REDIRECT_OUT,
    TOKEN_APPEND,
    TOKEN_HEREDOC,
    TOKEN_DOUBLE_QUOTE,
    TOKEN_SINGLE_QUOTE,
}	t_token_type;

typedef struct s_token
{
    char *lexeme;
    t_token_type type;
    struct s_token *next;
}	t_token;

t_token	*lex(t_var *var, char *line);

t_cmd	*parse(t_var *var, char *line);

#endif