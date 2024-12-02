/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenigno <ybenigno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:11:48 by ybenigno          #+#    #+#             */
/*   Updated: 2024/12/02 15:08:49 by ybenigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putnbr_base(long int nbr, char *base);
int	ft_printf(const char *, ...);
int	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int ft_putnbr_base_for_p(unsigned long int nbr, char *base);

#endif
