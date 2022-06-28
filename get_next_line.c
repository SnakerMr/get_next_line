/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasson <lomasson@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:31:22 by lomasson          #+#    #+#             */
/*   Updated: 2022/03/23 12:33:59 by lomasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;
	int		nbr;

	buffer = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	str = NULL;
	nbr = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	if (nbr > 0)
		str = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	while (nbr > 0 && buffer[0] != '\n')
	{
		str = ft_strjoin(str, buffer);
		nbr = read(fd, buffer, (BUFFER_SIZE / BUFFER_SIZE));
	}
	if (buffer[0] == '\n')
		str = ft_strjoin(str, "\n");
	free (buffer);
	return (str);
}
