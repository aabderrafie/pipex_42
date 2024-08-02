/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:31:26 by aaskal            #+#    #+#             */
/*   Updated: 2024/03/28 14:58:22 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_child_process(t_pipex *p, char *command, char **envp, int argc)
{
	if (command == NULL || ft_strlen(command) == 0)
	{
		ft_error("command is empty", 1);
		return ;
	}
	if (p->old_pipe[0] == -1)
		dup2(p->in_file, STDIN_FILENO);
	else
	{
		close(p->old_pipe[1]);
		dup2(p->old_pipe[0], STDIN_FILENO);
		close(p->old_pipe[0]);
	}
	if (p->i != argc - 2)
	{
		dup2(p->new_pipe[1], STDOUT_FILENO);
		close(p->new_pipe[0]);
		close(p->new_pipe[1]);
	}
	else
		dup2(p->out_file, STDOUT_FILENO);
	execute_command(command, envp);
}

void	handle_parent_process(t_pipex *p, int i, int argc)
{
	if (p->old_pipe[0] != -1)
	{
		close(p->old_pipe[0]);
		close(p->old_pipe[1]);
	}
	p->old_pipe[0] = p->new_pipe[0];
	p->old_pipe[1] = p->new_pipe[1];
	if (i == argc - 2)
		close(p->new_pipe[1]);
}

void	create_pipe_and_fork(t_pipex *p)
{
	if (pipe(p->new_pipe) == -1)
		ft_error("pipe", 1);
	p->cpid = fork();
	if (p->cpid == -1)
		ft_error("fork", 1);
}

void	initialize_pipex(t_pipex *p, int argc, char *argv[], int *i)
{
	p->old_pipe[0] = -1;
	p->old_pipe[1] = -1;
	*i = 2;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		p->in_file = handle_here_doc(argv[2]);
		(*i)++;
	}
	else
		p->in_file = open(argv[1], O_RDONLY);
	if (p->in_file == -1)
		ft_error(" Error ", 3);
	p->out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->out_file == -1)
		ft_error(" Error ", 3);
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	p;
	int		i;

	if (argc < 5)
		ft_error(" Error: bad argument  \n", 1);
	initialize_pipex(&p, argc, argv, &i);
	while (i < argc - 1)
	{
		p.i = i;
		create_pipe_and_fork(&p);
		if (p.cpid == 0)
			handle_child_process(&p, argv[i], envp, argc);
		else
			handle_parent_process(&p, i, argc);
		i++;
	}
	close(p.old_pipe[0]);
	while (wait(NULL) > 0)
		;
	close(p.out_file);
	unlink("heredoc");
	return (0);
}
