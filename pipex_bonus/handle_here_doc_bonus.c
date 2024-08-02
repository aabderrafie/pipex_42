/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:04:25 by aaskal            #+#    #+#             */
/*   Updated: 2024/03/28 14:56:09 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	write_to_file(char *limiter_newline, int fd)
{
	char	*line;

	while (1)
	{
		write(1, "pipe heredoc --> ", 17);
		line = get_next_line(0);
		if (!line)
		{
			free(limiter_newline);
			break ;
		}
		if (ft_strncmp(line, limiter_newline, ft_strlen(limiter_newline)) == 0)
		{
			free(line);
			free(limiter_newline);
			break ;
		}
		if (write(fd, line, ft_strlen(line)) == -1)
			ft_error("write", 1);
		free(line);
	}
	return (fd);
}

int	handle_here_doc(char *limiter)
{
	char	*limiter_newline;
	int		fd;

	fd = open("heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_error("open", 1);
	limiter_newline = ft_strjoin(limiter, "\n");
	if (!limiter_newline)
		ft_error("ft_strjoin", 1);
	fd = write_to_file(limiter_newline, fd);
	close(fd);
	open("heredoc", O_RDONLY);
	return (fd);
}
