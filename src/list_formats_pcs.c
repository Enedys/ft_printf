/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_formats_pcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 20:28:50 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:21:27 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		p_ch(int *mask, va_list ap)
{
	char	c;
	int		res;

	c = (char)va_arg(ap, int);
	res = 1;
	if (mask[1] > 0)
	{
		ft_putchar_fd(c, FD);
		res += print_infill(' ', mask[4] - 1);
		return (res);
	}
	if (mask[0] > 0)
		res += print_infill('0', mask[4] - 1);
	else
		res += print_infill(' ', mask[4] - 1);
	ft_putchar_fd(c, FD);
	return (res);
}

int		p_s(int *mask, va_list ap)
{
	char	*s;
	int		res;
	int		flag;

	flag = 0;
	s = va_arg(ap, char *);
	if (!s)
	{
		s = ft_strdup("(null)");
		flag = 1;
	}
	res = print_formated_s(mask, s);
	if (flag == 1)
		free(s);
	return (res);
}

int		p_p(int *mask, va_list ap)
{
	char			*s;
	unsigned long	res;
	int				len;

	res = va_arg(ap, unsigned long);
	s = ft_itoa_ubase(res, 16);
	if (*s == '0' && mask[5] == 0)
		*s = '\0';
	mask[6] = ft_strlen(s) + 2;
	len = print_formated_p(mask, s);
	free(s);
	return (len);
}

int		p_per(int *mask, va_list ap)
{
	const char	c = '%';
	int			res;
	va_list		a;

	va_copy(a, ap);
	va_end(a);
	res = 1;
	if (mask[1] > 0)
	{
		ft_putchar_fd(c, FD);
		res += print_infill(' ', mask[4] - 1);
		return (res);
	}
	if (mask[0] > 0)
		res += print_infill('0', mask[4] - 1);
	else
		res += print_infill(' ', mask[4] - 1);
	ft_putchar_fd(c, FD);
	return (res);
}

void	infill_oper(int (**oper)(int *, va_list))
{
	oper[0] = p_ch;
	oper[1] = p_s;
	oper[2] = p_p;
	oper[3] = p_d;
	oper[4] = p_d;
	oper[5] = p_u;
	oper[6] = p_x;
	oper[7] = p_ux;
	oper[8] = p_per;
}
