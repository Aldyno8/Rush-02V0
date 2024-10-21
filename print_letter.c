/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:32:31 by bvelonja          #+#    #+#             */
/*   Updated: 2024/10/21 07:52:19 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_find_number(char *number, char *dict, char *tab, int index);

// Retourne la taille d'un tableau a 2 dimensions
int	ft_strlentab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

// fonction qui alloue de la memoire pour le tableau des int
void	*alloc_memory(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tab[i] = malloc(sizeof(char) * 42);
		i ++;
	}
	tab[i] = NULL;
	if (tab == NULL)
		return (NULL);
	return (tab);
}

// Fonction qui divise le nombre 3 par 3 dans un tableau a 2 dimensions
char	**divide_nbr(char **tab, char *str)
{
	int	i;
	int	j;
	int	len;
	int	c;

	len = ft_strlen(str); //longueur de la chaine donner en parametre
	if (tab == NULL)
		return (NULL);
	i = 0;
	c = 0;
	j = 0;
	while (str[c])
	{
		tab[j][i] = str[(len - 1)];
		i ++;
		if ((c + 1) % 3 == 0) //verifie si on est au 3 eme chiffre
		{
			i = 0; //Si oui, remettre l'index a 0
			j += 1; //et passe a un second tableau
		}
		c++;
		len --;
	}
	tab[j] = NULL;
	return (tab); // return le tableau a 2 dim a la fin
}

// fonction qui parcours le tableau et affiche la valeur en lettre a l'aide de find number
void	print_letter(char *str, char *dict)
{
	char	**tab_number;
	char	**t;
	int		i;
	int		len;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * 42);
	t = malloc(sizeof(char) * 42);
	alloc_memory(t, 42);
	tab_number = divide_nbr(t, str); // appel de la fonction pour diviser le nombre donner en parametre.
	len = ft_strlentab(tab_number); //recupere la taille de ce nouveau tableau
	if (tab_number == NULL)
		return ;
	while (i < len)
	{
		ft_find_number(tab_number[i], dict, tab, i); //boucle sur ce tableau pour printer leur valeur en lettre
		i ++;
	}
	free(tab);
	free(tab_number);
}

// fonction de preparation de find number, il est utiliser dans le fichier find_number_in_dict(ligne 52)
char	*prepa_number3(int index, char *number3, int i)
{
	if (index == 0)
	{
		number3[0] = '1';
		number3[1] = '0';
		number3[2] = '0';
	}
	if (index > 0)
	{
		while (i <= index)
		{
			number3[i] = '0';
			i ++;
		}
	}
	return (number3);
}
