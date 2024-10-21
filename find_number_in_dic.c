/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number_in_dic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:29:49 by andriamr          #+#    #+#             */
/*   Updated: 2024/10/21 07:52:45 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <unistd.h>
#include <stdlib.h>

char	*prepa_number3(int index, char *number3, int i);

void	ft_find_number(char *number, char *dict, char *tab, int index)
{
	int	len;

	len = ft_strlen(number);
	if (len == 3)
	{
		find_number3(number, dict, tab, index);
		return ;
	}
	else if (len == 2)
	{
		find_number2(number, dict, tab);
		return ;
	}
	else if (len == 1)
	{
		find_number1(number[0], dict);
		return ;
	}
}

void	find_number3(char *number, char *dict, char *tab, int index)
{
	char	*number3;
	int		i;

	i = 0;
	number3 = tab;
	if (number[0] == '0')
		find_number2(&number[1], dict, tab);
	else
	{
		number3 = prepa_number3(index, number3, i);
		find_number1(number[0], dict);
		while (dict[i] != '\0')
		{
			if (ft_strncmp(&dict[i], number3, 3) == 0)
			{
				ft_putstr_letter(&dict[i + 2 + 2]);
				break ;
			}
			i++;
		}
		write(1, " ", 1);
		find_number2(&number[1], dict, tab);
	}
}

void	ft_number10(char *number, char *dict)
{
	int	i;

	i = 0;
	while (dict[i] != '\0')
	{
		if (ft_strncmp(&dict[i], number, 2) == 0)
		{
			ft_putstr_letter(&dict[i + 2 + 2]);
			break ;
		}
		i++;
	}
}

void	find_number2(char *number, char *dict, char *tab)
{
	int		i;
	char	number1;
	char	*tmp;

	i = 0;
	if (number[0] == '1')
		ft_number10(number, dict);
	else if (number[0] == '0')
		find_number1(number[1], dict);
	else
	{
		tmp = tab;
		if (!tmp)
			return ;
		tmp[0] = number[0];
		tmp[1] = '0';
		number1 = number[1];
		ft_number10(tmp, dict);
		write(1, " ", 1);
		find_number1(number1, dict);
	}
}

void	find_number1(char number, char *dict)
{
	int	i;

	i = 0;
	while (dict[i] != number)
		i++;
	ft_putstr_letter(&dict[i + 2 + 1]);
}
