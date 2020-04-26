/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:51:25 by cramdani          #+#    #+#             */
/*   Updated: 2020/04/25 21:56:59 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_uint(t_flags *flags, char *print)
{
	int len;

	len = ft_strlen(print);
	if (flags->precision > len)
	{
		print = realloc(print, flags->precision + 1);
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
	}
	end_disp(print, flags);
}

static char *add_pre_ptr(char *print,t_flags *flags, int i)
{
    int len;

    len = ft_strlen(print);
    if (i == 1)
    {
        add_zero(print, flags);
        add_back(print, ' ', flags->precision + 2, *flags);
        ft_memcpy(print,"Ox", 2);
    }
    else if (flags->zero == 1 && flags->precision == -1)
        return (print);
    else
    {
        print = ft_memmove(print + 2, print, len + 1);
        print -= 2;
        ft_memcpy(print,"Ox", 2);
    }
        return (print);
}

void    display_ptr(t_flags *flags, char *print)
{
    int len;

	len = ft_strlen(print) + 2;
	print = realloc(print, len + 1);
    add_back(print, '0', len, *flags);
	print[1] = 'x';
	if (flags->width > len)
	{
		print = ft_realloc(print, flags->width + 1);
		if (flags->dash == 1)
			add_front(print, ' ', flags->width);
		else
			add_back(print, ' ', flags->width, *flags);
	}
	end_disp(print, flags);
}

/*
void    display_ptr(t_flags *flags, char *print)
{
    int len;

	len = ft_strlen(print);
	if (flags->precision > len)
	{
		print = realloc(print, flags->precision + 3);
		print = add_pre_ptr(print, flags, 1);
	}
	len = ft_strlen(print);
	if (flags->width > len + 2)
	{
		print = ft_realloc(print, flags->width + 1);
        print = add_pre_ptr(print, flags, 2);
		if (flags->dash == 1)
			add_front(print, ' ', flags->width - 2);
		else if (flags->zero == 1 && flags->precision == -1)
        {
        	add_back(print, '0', flags->width, *flags);
            ft_memcpy(print, "0x", 2);
        }
		else
			add_back(print, ' ', flags->width, *flags);
	}
	end_disp(print, flags);
}*/