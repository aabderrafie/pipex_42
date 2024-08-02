/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:31:13 by aaskal            #+#    #+#             */
/*   Updated: 2024/03/30 16:51:21 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_first_command(t_pipex *p, char *command1, char **envp)
{
	if (command1 == NULL || ft_strlen(command1) == 0)
	{
		ft_error("command1 is empty", 1);
		return ;
	}
	close(p->pipefd[0]);
	dup2(p->in_file, STDIN_FILENO);
	dup2(p->pipefd[1], STDOUT_FILENO);
	close(p->pipefd[1]);
	execute_command(command1, envp);
}

void	execute_second_command(t_pipex *p, char *command2, char **envp)
{
	if (command2 == NULL || ft_strlen(command2) == 0)
	{
		ft_error("command2 is empty", 1);
		return ;
	}
	p->cpid2 = fork();
	if (p->cpid2 == 0)
	{
		close(p->pipefd[1]);
		dup2(p->pipefd[0], STDIN_FILENO);
		dup2(p->out_file, STDOUT_FILENO);
		close(p->pipefd[0]);
		execute_command(command2, envp);
	}
	else
	{
		close(p->pipefd[0]);
		close(p->pipefd[1]);
		wait(NULL);
		wait(NULL);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	p;

	if (argc != 5)
		ft_error(" Error: bad argument  \n", 1);
	p.in_file = open(argv[1], O_RDONLY);
	p.out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p.in_file == -1 || p.out_file == -1)
		ft_error("open", 1);
	if (pipe(p.pipefd) == -1)
		ft_error("pipe", 1);
	p.cpid1 = fork();
	if (p.cpid1 == -1)
		ft_error("fork", 1);
	if (p.cpid1 == 0)
		execute_first_command(&p, argv[2], envp);
	else
		execute_second_command(&p, argv[3], envp);
	return (0);
}
