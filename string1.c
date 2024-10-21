/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:32:21 by andriamr          #+#    #+#             */
/*   Updated: 2024/10/20 23:41:31 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_strncmp(str, to_find, ft_strlen(to_find)) != 0 || str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (&str[i]);
}

void	ft_putstr_letter(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
}


