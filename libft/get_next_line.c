/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:56:07 by ssitruk           #+#    #+#             */
/*   Updated: 2019/05/07 15:12:17 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*start_line(char *rest)
{
	if (!rest)
		rest = ft_strdup("");
	return (rest);
}

int		len_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*new_line(char *rest)
{
	if (rest[len_line(rest)] == '\n')
		rest = ft_strdup(&rest[len_line(rest) + 1]);
	else
		rest = ft_strnew(0);
	return (rest);
}

char	*free_line(char *rest)
{
	char	*tmp;

	tmp = rest;
	rest = new_line(rest);
	free(tmp);
	return (rest);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*rest[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	ret = 0;
	rest[fd] = start_line(rest[fd]);
	while (!(ft_strchr(rest[fd], '\n'))
			&& ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		rest[fd] = ft_strjoin_free(rest[fd], buf, 1);
	}
	if (ret == -1)
	{
		ft_strclr(rest[fd]);
		return (-1);
	}
	(*line) = ft_strsub(rest[fd], 0, len_line(rest[fd]));
	ret = ft_strlen(rest[fd]);
	rest[fd] = free_line(rest[fd]);
	if (len_line(*line))
		return (1);
	return (ret > 0 ? 1 : 0);
}
