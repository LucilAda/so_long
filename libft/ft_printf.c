/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:20:03 by lufreder          #+#    #+#             */
/*   Updated: 2024/07/18 15:01:20 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_define_type(char s, va_list ap, int *count)
{
	if (!ap)
		*count = -1;
	else if (s == 'c')
		ft_putchar (va_arg(ap, int), count);
	else if (s == 'i' || s == 'd')
		ft_putnbr(va_arg(ap, int), count);
	else if (s == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (s == 'p')
		ft_putptr(va_arg(ap, void *), count);
	else if (s == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int), count);
	else if (s == 'x')
		ft_putnbr_hex_xlo(va_arg(ap, unsigned int), count);
	else if (s == 'X')
		ft_putnbr_hex_xup(va_arg(ap, unsigned int), count);
	else if (s == '%')
		ft_putchar('%', count);
	else
	{
		ft_putchar('%', count);
		ft_putchar(s, count);
	}
}

int	ft_printf(const char *s, ...)
{
	int			i;
	va_list		ap;
	int			count;

	count = 0;
	if (!s)
		return (-1);
	va_start (ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_define_type(s[i], ap, &count);
		}
		else
			ft_putchar((s[i]), &count);
		if (count == -1)
			return (-1);
		i++;
	}
	va_end(ap);
	return (count);
}

/*int	main(void)
{
	int				nombre;
	char			c;
	int				d;
	char			*s;
	unsigned int	u;
	unsigned int	x;

	nombre = 4;
	c = 'c';
	d = 4;
	s = "La vita e bella";
	u = -21474836;
	x = 12;
	printf("The original = La réponse à la question est: %c %d %s dont 
	l'adresse est %p et i vaut: %i et u vaut : %u, en hexadecimal dans 
	le texte : %x ou %X\n", c, d, s, s, d, u, x, x);
	ft_printf("The notre = La réponse à la question est: %c %d %s dont 
	l'adresse est %p et i vaut: %i et u vaut : %u, en hexadecimal dans 
	le texte : %x ou %X\n", c, d, s, s, d, u, x, x);
	return (0);
}*/