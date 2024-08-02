/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:39:55 by aaskal            #+#    #+#             */
/*   Updated: 2024/03/28 14:48:38 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_command(char *command, char **envp)
{
	char	**args;
	char	*full_path;

	args = split_command(command);
	if (args[0][0] == '/' || ft_strncmp(args[0], "./", 2) == 0)
		full_path = ft_strdup(args[0]);
	else
		full_path = get_full_path(args[0], envp);
	if (full_path == NULL)
		ft_error("Command not found", 127);
	if (execve(full_path, args, envp) == -1)
		ft_error("execve ", 126);
	free(full_path);
	free(args);
}
