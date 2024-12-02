/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_supp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenigno <ybenigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:43:29 by ybenigno          #+#    #+#             */
/*   Updated: 2024/12/02 15:10:08 by ybenigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if(!s)
		return(write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	int	type_base;
	int	len;

	len = 0;
	type_base = (int)ft_strlen(base);
	if (nbr < 0)
	{
		len += (int)write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= type_base)
	{
		len += (int)ft_putnbr_base(nbr / type_base, base);
		len += (int)write(1, &base[(nbr % type_base)], 1);
	}
	if (nbr < type_base)
		len += (int)write(1, &base[(nbr % type_base)], 1);
	return (len);
}

int	ft_putnbr_base_for_p(unsigned long int nbr, char *base)
{
	unsigned long int	type_base;
	unsigned long int	len;

	len = 0;
	type_base = (int)ft_strlen(base);
	if (nbr < 0)
	{
		len += (int)write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= type_base)
	{
		len += (int)ft_putnbr_base(nbr / type_base, base);
		len += (int)write(1, &base[(nbr % type_base)], 1);
	}
	if (nbr < type_base)
		len += (int)write(1, &base[(nbr % type_base)], 1);
	return (len);
}