/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:31:39 by cramdani          #+#    #+#             */
/*   Updated: 2020/04/25 19:02:47 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char	*check_nb(int nb, t_flags *flags)
{
	if (nb < 0)
        flags->sign = 1;
    if (flags->precision == 0 && nb == 0)
        return (ft_strdup(""));
    else
        return (ft_itoa(nb));
}

void	display_nb(int nb, t_flags *flags)
{
	char *print;
	int len;

	print = check_nb(nb, flags);
	len = ft_strlen(print);
	if (flags->precision > len - flags->sign)
	{
		print = realloc(print, flags->precision + flags->sign + 1);
		print = add_zero(print, flags);
	}
	len = ft_strlen(print);
	if (flags->width > len)
	{
		print = ft_realloc(print, flags->width + 1);
        if (flags->dash == 1)
			add_front(print, ' ', flags->width);
		else if (flags->zero == 1 && flags->precision == -1)
			add_back(print, '0', flags->width, *flags);
		else
			add_back(print, ' ', flags->width, *flags);
        if (flags->sign == 1 && (flags->zero == 1 && flags->precision == -1 ))
            print[0] = '-';
	}
	end_disp(print, flags);
}
