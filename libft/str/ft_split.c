/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouannh <ehosta@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:04:45 by elouannh          #+#    #+#             */
/*   Updated: 2024/11/06 21:04:45 by elouannh         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

static size_t	count_words(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			word_count++;
		while (*s && *s != c)
			s++;
	}
	return (word_count);
}

static int	bufcpy(char **result, size_t w, const char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (*s == c && *s)
		s++;
	while (s[len] != c && s[len])
		len++;
	result[w] = (char *)malloc((len + 1) * sizeof(char));
	if (!result[w])
	{
		while (w)
			free(result[--w]);
		free(result);
		return (-1);
	}
	i = 0;
	while (i < len && s[i])
	{
		result[w][i] = s[i];
		i++;
	}
	result[w][i] = '\0';
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	w;
	char	**tabstr;
	int		bufcpyres;

	word_count = count_words(s, c);
	tabstr = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!tabstr)
		return (NULL);
	w = 0;
	while (w < word_count)
	{
		while (*s && *s == c)
			s++;
		bufcpyres = bufcpy(tabstr, w, s, c);
		if (bufcpyres == -1)
			return (NULL);
		s += bufcpyres;
		w++;
	}
	tabstr[word_count] = NULL;
	return (tabstr);
}
