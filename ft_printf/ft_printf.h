/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:20:35 by lufreder          #+#    #+#             */
/*   Updated: 2023/12/13 10:20:38 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, int *count);
void	ft_putnbr_hex_ptr(unsigned long nbr, int *count);
void	ft_putnbr_hex_xlo(unsigned int nb, int *count);
void	ft_putnbr_hex_xup(unsigned int nb, int *count);
void	ft_putnbr_u(unsigned int nb, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putptr(void *ptr, int *count);
void	ft_putstr(char *str, int *count);

#endif