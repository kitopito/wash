
#ifndef VARIABLE_H
# define VARIABLE_H

typedef struct s_var
{
	char			*name;
	char			*value;
	int				is_env;
	struct s_var	*next;
}					t_var;

t_var				*new_var(void);

void				free_var_list(t_var *head);

t_var				*get_var_last(t_var *head);

t_var				*init_var(void);
char				*ft_getvar(t_var *var, const char *name);
t_var				*ft_getvar_ptr(t_var *var, const char *name);
int					ft_setvar(t_var *var, const char *name, const char *val);
// void				ft_export(t_var *var, char *name, char *val);
char				**get_env_arr(t_var *var);

int					delete_var(t_var **var, const char *var_str);

void				free_var(t_var *var);

#endif