/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:22:02 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/04 20:22:08 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		size;
	int		search;
	char	letter;

	size = 0;
	search = 0;
	while (str[size] != '\0')
		size++;
	size--;
	while (size > search)
	{
		letter = str[search];
		str[search] = str[size];
		str[size] = letter;
		size--;
		search++;
	}
	return (str);
}
