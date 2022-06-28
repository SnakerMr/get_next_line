/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasson <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:12:10 by lomasson          #+#    #+#             */
/*   Updated: 2022/03/18 16:19:31 by lomasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	int		x;

	x = -1;
	tab = (char *)malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		i1;

	i = 0;
	i1 = 0;
	while (s1[i])
		i++;
	while (s2[i1])
		i1++;
	tab = malloc(sizeof(char) * (i + i1 + 1));
	if (!tab)
		return (NULL);
	i = -1;
	i1 = 0;
	while (s1[++i])
		tab[i] = s1[i];
	while (s2[i1])
		tab[i++] = s2[i1++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}
