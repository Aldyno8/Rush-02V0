/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelonja <bvelonja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:55:32 by andriamr          #+#    #+#             */
/*   Updated: 2024/10/20 23:04:23 by bvelonja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

void	ft_find_number(char *number, char *dict, char *tab, int index);
void	find_number1(char number, char *dict);
void	find_number2(char *number, char *dict, char *tab);
void	find_number3(char *number, char *dict, char *tab, int index);
void	ft_putstr_letter(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_files_to_str(char *dict);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strstr(char *str, char *to_find);
char	*take_number(char *str);
int		ft_strlen(char *str);
int		ft_files_sizes(char dict);
int		ft_strncmp(char *s1, char *s2, unsigned int n);

#endif
