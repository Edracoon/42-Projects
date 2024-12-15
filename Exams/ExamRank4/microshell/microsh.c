#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STDIN	0
#define STDOUT	1
#define STDERR	2

#define END		3
#define PIPE	4
#define SEMI	5

typedef struct	s_data
{
	struct s_data	*prev;
	char			**cmd;
	int				type;
	int				size;
	int				fd[2];
	struct s_data	*next;
}	t_data;

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i] != 0)
		i++;
	return (i);
}

void	fatal_error()
{
	write(STDERR, "error: fatal\n", 13);
	exit(EXIT_FAILURE);
}

int	error_cd()
{
	write(STDERR, "error: cd: bad arguments\n", 25);
	return (EXIT_FAILURE);
}

int	error_cd2(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", 39);
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	return (EXIT_FAILURE);
}

void	error_execve(char *str)
{
	write(STDERR, "error: cannot execute ", 22);
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

char	*ft_strdup(char *str)
{
	int		i = ft_strlen(str);
	char	*dest;

	if (!str)
		return (NULL);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

int	size_cmd(char **av)
{
	int	i = 0;
	while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
		i++;

	return (i);
}

int	check_type(char *av)
{
	if (!av)
		return (END);
	if (strcmp(av, "|") == 0)
		return (PIPE);
	if (strcmp(av, ";") == 0)
		return (SEMI);
	return (0);
}

void	ft_lstadd_back(t_data **data, t_data *new)
{
	t_data	*temp;

	if (!(*data))
		*data = new;
	else
	{
		temp = *data;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

int		parser_argv(t_data **data, char **av)
{
	t_data	*new;
	int		size = size_cmd(av);

	new = malloc(sizeof(t_data));
	if (!new)
		fatal_error();
	new->cmd = malloc(sizeof(char *) * (size + 1));
	if (!(new->cmd))
		fatal_error();
	new->next = NULL;
	new->prev = NULL;
	new->size = size;
	new->cmd[size] = NULL;
	while (--size >= 0)
		new->cmd[size] = ft_strdup(av[size]);
	new->type = check_type(av[new->size]);
	ft_lstadd_back(data, new);
	return (new->size);
}

void	ft_execve(t_data *temp, char **env)
{
	pid_t	pid;
	int		pidstatus;
	int		pipe_open;

	if (temp->type == PIPE || (temp->prev && temp->prev->type == PIPE))
	{
		pipe_open = 1;
		if (pipe(temp->fd))
			fatal_error();
	}
	pid = fork();
	if (pid < 0)
		fatal_error();
	else if (pid == 0) // enfant
	{
		if (temp->type == PIPE && dup2(temp->fd[1], STDOUT) < 0)
			fatal_error();
		if (temp->prev && temp->prev->type == PIPE && dup2(temp->prev->fd[STDIN], STDIN) < 0)
			fatal_error();
		if (execve(temp->cmd[0], temp->cmd, env) < 0)
			error_execve(temp->cmd[0]);
		exit(EXIT_SUCCESS);
	}
	else // parent
	{
		waitpid(pid, &pidstatus, 0);
		if (pipe_open)
		{
			close(temp->fd[STDOUT]);
			if (!temp->next || temp->type == SEMI)
				close(temp->fd[STDIN]);
		}
		if (temp->prev && temp->prev->type == PIPE)
			close(temp->prev->fd[STDIN]);
	}
}

void	cmds_execute(t_data *data, char **env)
{
	t_data	*temp;
	(void)env;
	temp = data;
	while (temp)
	{
		if (strcmp(temp->cmd[0], "cd") == 0)
		{
			if (temp->size < 2)
				error_cd();
			else if (chdir(temp->cmd[1]) == -1)
				error_cd2(temp->cmd[1]);
		}
		else
			ft_execve(temp, env);
		temp = temp->next;
	}
}

int		main(int ac, char **av, char **env)
{
	t_data	*data = NULL;
	int	i = 1;

	if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], ";") == 0)
			{
				i++;
				continue ;
			}
			i += parser_argv(&data, &av[i]);
			if (!av[i])
				break ;
			else
				i++;
		}
		// while (data)
		// {
		// 	printf("=================\n");
		// 	for (i = 0; i < data->size; i++)
		// 		printf("%s\n", data->cmd[i]);
		// 	printf("TYPE: %d\n", data->type);
		// 	printf("SIZE: %d\n", data->size);
		// 	printf("=================\n");
		// 	data = data->next;
		// }
		// printf("END\n");
		if (data)
			cmds_execute(data, env);
	}
	return (0);
}
