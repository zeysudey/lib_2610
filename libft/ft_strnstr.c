/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:33:54 by zyilmaz           #+#    #+#             */
/*   Updated: 2024/10/15 17:08:03 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	len_n;

	len_n = ft_strlen(needle);
	if (len_n == 0)
		return ((char *)haystack);
	if (len == 0)
		return ((char *) NULL);
	i = 0;
	while (i <= (len - len_n) && haystack[i] != '\0')
	{
		if (ft_strncmp(&haystack[i], needle, len_n) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return ((char *) NULL);
}
