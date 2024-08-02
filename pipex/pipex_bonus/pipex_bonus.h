/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:41:07 by aaskal            #+#    #+#             */
/*   Updated: 2024/03/30 16:38:55 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "getnextline/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define MAXLEN 100
# define MAXARGS 100

typedef struct s_pipex
{
	int		i;
	int		in_file;
	int		out_file;
	int		new_pipe[2];
	int		old_pipe[2];
	pid_t	cpid;
	int		here_doc;
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
int			handle_here_doc(char *limiter);
#endif
