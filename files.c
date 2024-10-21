/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:54:21 by andriamr          #+#    #+#             */
/*   Updated: 2024/10/20 23:08:23 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_files_size(char *dict)
{
	int		fd;
	int		size;
	int		char_read;
	char	buffer[42];

	fd = open(dict, O_RDONLY);
	size = 0;
	char_read = -1;
	if (fd == -1)
		return (0);
	while (char_read != 0)
	{
		char_read = read(fd, buffer, 41);
		if (char_read == -1)
			return (0);
		size = size + char_read;
	}
	close (fd);
	return (size);
}

char	*ft_files_to_str(char *dict)
{
	int		size;
	int		char_read;
	int		fd;
	char	*str;
	char	buffer[42];

	size = ft_files_size(dict);
	str = malloc (sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	str[0] = '\0';
	fd = open(dict, O_RDONLY);
	if (fd == 0)
		return (0);
	char_read = -1;
	while (char_read != 0)
	{
		char_read = read(fd, buffer, 41);
		if (char_read == -1)
			return (0);
		buffer[char_read] = '\0';
		ft_strcat(str, buffer);
	}
	close (fd);
	return (str);
}

char	*take_number(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[i] <= 13) && (str[i] >= 9 || str[i] == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j++;
		i++;
	}
	if (str[i] != '\0')
		write(2, "Error\n", 6);
	return (&str[i - j]);
}
