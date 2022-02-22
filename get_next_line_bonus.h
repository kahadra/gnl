/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:58:35 by chpark            #+#    #+#             */
/*   Updated: 2022/01/21 14:05:17 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	int				fd;
	char			*line;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strnjoin(char *s1, char const *s2, ssize_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *s);
t_gnl	*make_lst(t_gnl *head, int fd);
char	*read_gnl(int fd, char *line);
char	*updat_gnl(t_gnl *node, char *line);

#endif
