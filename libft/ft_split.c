/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:16:08 by mmesum            #+#    #+#             */
/*   Updated: 2022/10/19 23:58:58 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	pass_char(int *counter, char *str, char c, int mode)
{
	if (mode == 1)
		while (str[*counter] == c)
			*counter = *counter + 1;
	else
		while (str[*counter] != c && str[*counter] != '\0')
			*counter = *counter + 1;
}

static int	getwordcount(char *str, char c)
{
	int	counter;
	int	wordcount;

	wordcount = 0;
	counter = 0;
	while (str[counter] != '\0')
	{
		pass_char(&counter, str, c, 1);
		if (str[counter] != '\0')
			wordcount++;
		while (str[counter] != c && str[counter] != '\0')
			counter++;
	}
	return (wordcount);
}

static char	*getword(char *str, char c)
{
	int		len;
	char	*word;
	int		i;

	i = 0;
	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	word = malloc((len + 1) * sizeof(char));
	while (str[i] != c && str[i] != '\0')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	int		counter;
	char	**arr;
	char	*word;
	int		index;

	index = 0;
	counter = 0;
	arr = malloc((getwordcount(str, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	while (str[counter] != '\0')
	{
		pass_char(&counter, str, c, 1);
		if (str[counter] == '\0')
			break ;
		word = getword(&str[counter], c);
		pass_char(&counter, str, c, 0);
		arr[index] = word;
		index++;
	}
	arr[index] = 0;
	return (arr);
}
