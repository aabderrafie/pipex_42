/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:55:50 by aaskal            #+#    #+#             */
/*   Updated: 2024/01/23 18:00:10 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	count_char(t_list *list)
{
	int		len;
	char	*str;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		str = list->str;
		while (*str)
		{
			if (*str == '\n')
			{
				len++;
				return (len);
			}
			str++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	get_new_line(t_list *list)
{
	char	*str;

	if (!list || !list->str)
		return (0);
	while (list)
	{
		str = list->str;
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	int		i;
	char	*str;
	t_list	*new;

	while (!get_new_line(*list))
	{
		str = malloc(sizeof(char) * BUFFER_SIZE + 1);
		i = read(fd, str, BUFFER_SIZE);
		str[i] = '\0';
		if (i == 0)
		{
			free(str);
			str = NULL;
			return ;
		}
		new = (t_list *)malloc(sizeof(t_list));
		if (!new || !str)
			return ;
		if (ft_lstlast(*list))
			ft_lstlast(*list)->next = new;
		else
			*list = new;
		new->str = str;
		new->next = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free_everything(&list[fd], NULL, NULL);
		return (NULL);
	}
	create_list(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	line = get_next_line_utils(list[fd]);
	rest_of_str(&list[fd]);
	return (line);
}
