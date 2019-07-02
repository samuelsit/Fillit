/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:20:31 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/08 16:19:29 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list	*lst_tetris(t_tetris *tetris, size_t content_size)
{
	t_list	*list;

	if (!(list = malloc(sizeof(*list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = tetris;
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
