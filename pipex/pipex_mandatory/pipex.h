/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:41:07 by aaskal            #+#    #+#             */
/*   Updated: 2024/03/28 15:03:18 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h> 
# include <sys/wait.h>
# include <unistd.h> 

# define MAXLEN 100
# define MAXARGS 100

typedef struct s_pipex
{
	int		in_file;
	int		out_file;
	int		pipefd[2];
	pid_t	cpid1;
	pid_t	cpid2;
}			t_pipex;
typedef struct s_command
{
	char	**args;
	int		i;
	int		j;
	int		k;
	int		in_single_quotes;
}			t_command;

void		ft_error(char *str, int exit_code);
char		*get_full_path(char *cmd, char **envp);
void		execute_command(char *command, char **envp);
char		**split_command(char *command);

#endif
