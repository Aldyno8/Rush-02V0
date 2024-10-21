/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:14:33 by andriamr          #+#    #+#             */
/*   Updated: 2024/10/20 23:40:54 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	print_letter(char *str, char *dict);
int	ft_strlentab(char **str);

int	main(int ac, char **av)
{
	if (ac == 3)
		print_letter(av[1], ft_files_to_str(av[2]));
	else if (ac == 2)
		print_letter(av[1], ft_files_to_str("numbers.dict"));
	return (0);
}
