/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:40:31 by aaskal            #+#    #+#             */
/*   Updated: 2024/03/27 00:25:58 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_getenv(char **envp)
{
	const char	*name = "PATH=";
	char		*path;

	while (*envp != 0)
	{
		if (ft_strnstr(*envp, name, 5))
		{
			path = ft_substr(*envp, 5, ft_strlen(*envp));
			if (!path)
				ft_error("ft_substr", 1);
			return (path);
		}
		envp++;
	}
	return (NULL);
}

char	*get_full_path(char *cmd, char **envp)
{
	char	*path;
	char	**dirs;
	char	*full_path;
	int		i;

	path = ft_getenv(envp);
	if (!path)
		ft_error("ft_getenv", 1);
	dirs = ft_split(path, ':');
	if (!dirs)
		ft_error("ft_split", 1);
	full_path = NULL;
	i = 0;
	while (dirs[i] != NULL)
	{
		full_path = ft_strjoin(dirs[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (!full_path)
			ft_error("ft_strjoin", 1);
		if (access(full_path, F_OK) == 0)
			break ;
		free(full_path);
		i++;
	}
	return (free(path), free(dirs), full_path);
}
