/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_formats_dxu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 20:33:19 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:21:22 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*up_str(char *s)
{
	char	*start;

	start = s;
	while (*start)
	{
		*start = ft_toupper(*start);
		start++;
	}
	return (s);
}

int			p_d(int *mask, va_list ap)
{
	char	*s;
	int		res;

	s = ft_itoa((int)va_arg(ap, int));
	if (!s)
		return (-1);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s);
	if (*s == '-')
		mask[5]++;
	res = print_formated_d(mask, s);
	free(s);
	return (res);
}

int			p_u(int *mask, va_list ap)
{
	char	*s;
	int		res;

	s = ft_itoa_ubase(va_arg(ap, unsigned int), 10);
	if (!s)
		return (-1);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s);
	res = print_formated_d(mask, s);
	free(s);
	return (res);
}

int			p_x(int *mask, va_list ap)
{
	char	*s;
	int		res;

	s = ft_itoa_ubase(va_arg(ap, unsigned int), 16);
	if (!s)
		return (-1);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s);
	res = print_formated_d(mask, s);
	free(s);
	return (res);
}

int			p_ux(int *mask, va_list ap)
{
	char	*s;
	int		res;

	s = ft_itoa_ubase(va_arg(ap, unsigned int), 16);
	if (!s)
		return (-1);
	s = up_str(s);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s);
	res = print_formated_d(mask, s);
	free(s);
	return (res);
}
