/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:10:54 by chpark            #+#    #+#             */
/*   Updated: 2022/02/22 12:56:40 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*make_lst(t_gnl *head, int fd)
{
	t_gnl	*node;

	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_gnl *)malloc(sizeof(t_gnl));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->line = ft_strndup("", 0);
	node->next = head->next;
	if (head->next)
		(head->next)->prev = node;
	node->prev = head;
	head->next = node;
	return (node);
}

char	*updat_gnl(t_gnl *node, char *line)
{
	char	*find;
	char	*temp;

	if (!line || !*line)
	{
		free(line);
		(node->prev)->next = node->next;
		if (node->next)
			(node->next)->prev = node->prev;
		free(node);
		return (NULL);
	}
	find = ft_strchr(line, '\n');
	if (find)
	{
		node->line = ft_strndup(find + 1, ft_strlen(find + 1));
		temp = ft_strndup(line, find - line + 1);
		free(line);
		return (temp);
	}
	return (line);
}

char	*read_gnl(int fd, char *line)
{
	char	*buf;
	ssize_t	n;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		line = ft_strnjoin(line, buf, n);
		if (n < BUFFER_SIZE)
			break ;
	}
	free(buf);
	if (n < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl	head;
	t_gnl			*now;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	now = make_lst(&head, fd);
	if (!now)
		return (NULL);
	line = now->line;
	now->line = NULL;
	line = read_gnl(fd, line);
	line = updat_gnl(now, line);
	return (line);
}
