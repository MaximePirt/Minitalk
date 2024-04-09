/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:47:52 by maxime_pier       #+#    #+#             */
/*   Updated: 2024/03/12 12:15:42 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	word_counter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	return (i);
}

static char	*copword(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (*s && *s == c)
		s++;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		word[len] = s[len];
		len++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_split(char **split_result)
{
	int	i;

	if (!split_result)
		return ;
	i = 0;
	while (split_result[i])
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = word_counter(s, c);
	dst = (char **)malloc (sizeof (char *) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s && i < len)
	{
		while (*s == c)
			s++;
		dst[i] = copword(s, c);
		if (!dst[i++])
		{
			free_split(dst);
			return (NULL);
		}
		s += ft_strlen(dst[i - 1]);
	}
	dst[i] = 0;
	return (dst);
}
