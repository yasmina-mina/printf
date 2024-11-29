/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenigno <ybenigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:07:03 by ybenigno          #+#    #+#             */
/*   Updated: 2024/11/29 20:15:34 by ybenigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_element(const char c, va_list args)
{
	int	count;
	
	count = 0;
	if (c == 'c')
		count += write(1, &(char){(char)va_arg(args, int)}, 1);
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		count += write(1, "%", 1);
	if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base(va_arg(args, long int), "0123456789abcdef");
		
	}
	if (c == 'u')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	
	va_list	args;
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if(!format[i])
				return (0);
			len += ft_element(format[i], args);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	return (len);
}

/* int	main(void)
{
	int *p;
	int i;
	i = 10;
	p = &i;

	 ft_printf(" NULL %s NULL \n", NULL);
	printf(" NULL %s NULL ", NULL);
 	ft_printf("lettre %c\n", 'a');
	ft_printf("string %s\n%", "bonjour");
	ft_printf("%d\n",ft_printf("pointeur : %p\n", &p));
	printf("%d\n",printf("pointeur : %p\n", &p));
	ft_printf("entier %d\n", INT32_MIN);
	ft_printf("pourcentage %%\n");
	ft_printf("hexa min %x\n", -695450);
	ft_printf("hexa maj  %X\n", -695450);
	ft_printf("pointeur %p\n", &p);
	ft_printf("unsigned %u\n", 8555); 
} */