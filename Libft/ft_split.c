/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:25:43 by sdaher            #+#    #+#             */
/*   Updated: 2025/11/12 13:14:12 by sdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// char	*ft_substr(char const *s, unsigned int start, size_t len);

static int	count_words(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static void	free_splits(char **arr, int filled)
{
	while (--filled >= 0)
		free(arr[filled]);
}

static int	fill(char **array, char const *s, char c, int count)
{
	int		start;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] && j < count)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		array[j] = ft_substr(s, start, i - start);
		if (!array[j])
		{
			free_splits(array, j);
			return (0);
		}
		j++;
	}
	array[count] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	array = malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!fill(array, s, c, count))
	{
		free(array);
		return (NULL);
	}
	return (array);
}

// int main()
// {
// 	char	s[] = "Welcome to 42 Beirut";
// 	char	c = ' ';
// 	char	**arr = ft_split(s,c);
// 	int	i = count_words(s,c);
// 	int	j = 0;
// 	while (j < i)
// 	{
// 		printf("arr[%d] =%s\n",j,arr[j]);
// 		j++;
// 	}
// }