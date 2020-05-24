/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 20:46:15 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:21:14 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int			valid_modifier(int c)
{
	const char	*arr = "cspdiuxX%";
	int			iter;

	iter = 0;
	while (arr[iter])
		if ((char)c == arr[iter++])
			return (iter);
	return (0);
}

static const char	*scip_and_print(const char *s, int *res)
{
	const char	*start = s;

	if (*res == -1)
		return (s);
	while (*s && *s != '%')
		s++;
	*res = *res + s - start;
	ft_putstrn_fd(start, s - start, FD);
	return (s);
}

static int			put_result(int *mask, int c, va_list ap, int *ret)
{
	int	(*oper[9]) (int *, va_list);
	int	res;

	if (c == 0)
		return (0);
	infill_oper(oper);
	res = oper[c - 1](mask, ap);
	if (res == -1)
		*ret = -1;
	else
		*ret = *ret + res;
	return (1);
}

static const char	*get_format(const char *s, va_list ap, int *ret)
{
	int	mask[7];

	ft_memset(mask, -2, sizeof(int) * 7);
	while (*s == '-' || *s == '0')
		mask[*s++ == '0' ? 0 : 1] = 1;
	if (*s == '*')
		s = process_aster(s, mask, 4, ap);
	else
		s = process_number(s, &mask[4]);
	if (*s == '.')
	{
		if (*(++s) == '*')
			s = process_aster(s, mask, 5, ap);
		else
			s = process_number(s, &mask[5]);
	}
	put_result(mask, valid_modifier(*s++), ap, ret);
	return (s);
}

int					ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, s);
	res = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (res == -1)
			return (-1);
		if (*s == '%')
			s = get_format(++s, ap, &res);
		s = scip_and_print(s, &res);
	}
	va_end(ap);
	return (res);
}
