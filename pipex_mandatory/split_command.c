/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:09:07 by aaskal            #+#    #+#             */
/*   Updated: 2024/03/27 00:10:59 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

char	*trim_spaces(char *str, t_command *cmd)
{
	char	*end;

	cmd->i = 0;
	cmd->j = 0;
	cmd->k = 0;
	cmd->in_single_quotes = 0;
	if (str == NULL)
		return (NULL);
	while (ft_is_space(*str))
		str++;
	end = str + ft_strlen(str) - 1;
	while (end > str && ft_is_space(*end))
		end--;
	*(end + 1) = 0;
	return (str);
}

char	**split_command(char *command)
{
	t_command	cmd;

	command = trim_spaces(command, &cmd);
	cmd.args = (char **)malloc(sizeof(char *) * (MAXARGS + 1));
	cmd.args[cmd.j] = (char *)malloc(sizeof(char) * (MAXLEN + 1));
	while (command[cmd.i] != '\0')
	{
		if (command[cmd.i] == ' ' && cmd.in_single_quotes == 0)
		{
			if (command[cmd.i - 1] != ' ' || cmd.i == 0)
			{
				cmd.args[cmd.j][cmd.k] = '\0';
				cmd.j++;
				cmd.k = 0;
				cmd.args[cmd.j] = (char *)malloc(sizeof(char) * (MAXLEN + 1));
			}
		}
		else if (command[cmd.i] == '\'')
			cmd.in_single_quotes = !cmd.in_single_quotes;
		else
			cmd.args[cmd.j][cmd.k++] = command[cmd.i];
		cmd.i++;
	}
	return (cmd.args[cmd.j][cmd.k] = '\0', cmd.args[cmd.j + 1] = NULL,
		cmd.args);
}
