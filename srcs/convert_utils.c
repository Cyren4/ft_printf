/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 12:04:33 by cramdani          #+#    #+#             */
/*   Updated: 2020/04/25 19:15:19 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void conversion(va_list args, t_flags *flags)
{
	if (flags->conversion == '0')
		return;
	if (flags->conversion == '%' || flags->conversion == 'c')
		flags->conversion == '%' ? display_char('%', flags) : display_char(va_arg(args, int), flags);
	else if (flags->conversion == 's')
		display_string(va_arg(args, char *), flags);
	else if (flags->conversion == 'd' || flags->conversion == 'i')
		display_nb(va_arg(args, int), flags);
	else if (flags->conversion == 'u' || flags->conversion == 'x' || flags->conversion == 'X')
		convert_disp_uint(va_arg(args, unsigned long int), flags);
	else if (flags->conversion == 'p')
		convert_disp_uint((unsigned long int)va_arg(args, void *), flags);
}