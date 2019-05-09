/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:23:12 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/05 12:12:13 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (!needle[i])
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && needle[j] == haystack[i + j])
		{
			j++;
			if (!needle[j])
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
