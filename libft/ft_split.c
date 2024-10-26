/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:37:29 by zyilmaz           #+#    #+#             */
/*   Updated: 2024/10/26 18:40:17 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_dup(char const *s, int start, int end, char c)
{
	int		i;
	char	*word;

	i = 0;
	if (s[i] == c)
		end = i;
	else
		end = i + 1;
	word = (char *)malloc((end - start + 1) * (sizeof(char)));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || s[i + 1] == '\0') && start >= 0)
		{
			result[j++] = ft_dup(s, start, i, c);
			start = -1;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}

#include <stdio.h>
int main(){
    char **c;
    c=ft_split("zeynep-sude-yilmaz",'-');
    int i;
    i = 0;
    while (c[i])
    {
            printf("%s",c[i]);
             free(c[i]);
            i++;

    }
    free(c);

}
