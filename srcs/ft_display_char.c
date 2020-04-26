/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 01:01:14 by cramdani          #+#    #+#             */
/*   Updated: 2020/04/25 23:05:32 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_char(int c, t_flags *flags)
{
	char *print;

//	print = ft_calloc(1, sizeof(char) * 2);
	if (!(print = malloc(sizeof(char) * 2)))
		return ((void)NULL);
	*print = (unsigned char)c;
	*(print + 1) = '\0';
	if (c == '\0' && (flags->width == 0 || flags->width == 1))
	{
		flags->len += 1;
		return;
	}
	if (flags->width > 1)
	{
		print = ft_realloc(print, (flags->width + 1));
		if (flags->dash == 1)
			add_front(print, ' ', flags->width);
		else if (flags->zero == 1)
			add_back(print, '0', flags->width, *flags);
		else
			add_back(print, ' ', flags->width, *flags);
		*(print + flags->width) = '\0';
	}
	end_disp(print, flags);
}

/*void	display_char1(int c, t_flags *flags)
{
	char *print;

	if (!(print = malloc(sizeof(char) * 2)))
		return ((void)NULL);
	*print = (unsigned char)c;
	*(print + 1) = '\0';
	if (flags->width > 1)
	{
		print = ft_realloc(print, (flags->width + 1));
		if (flags->dash == 1)
			ft_memset(print + 1, ' ', flags->width);
		else
		{
				print = ft_memmove(&print[flags->width - 1], print, 2);
				print -= (flags->width - 1);
			if (flags->zero == 1)
					ft_memset(print, '0', flags->width - 1);
				else
					ft_memset(print, ' ', flags->width - 1);
			*(print + flags->width) = '\0';
		}
	}
    write(1, print, ft_strlen(print));
    flags->len += ft_strlen(print);
	free(print);
}*/

void	display_string(char *str, t_flags *flags)
{
	char *print;

	if (!str)
		str = ft_strdup("(null)");
	if (flags->precision < ft_strlen(str))
		print = ft_substr(str, 0, flags->precision);
	else
		print = ft_strdup(str);
	if (flags->width > ft_strlen(print))
	{
		print = ft_realloc(print, (flags->width + 1));
		if (flags->dash == 1)
			add_front(print, ' ', flags->width);
		else if (flags->zero == 1 && flags->precision == -1)
			add_back(print, '0', flags->width, *flags);
		else
			add_back(print, ' ', flags->width, *flags);
	}
	end_disp(print, flags);
}