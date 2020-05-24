/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_aster_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 19:42:44 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:21:49 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

const char	*process_aster(const char *s, int *n, int pos, va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	if (pos == 4)
	{
		n[2] = 1;
		if (num < 0)
		{
			n[pos] = -num;
			n[1] = 1;
		}
		else
			n[pos] = num;
		return (++s);
	}
	n[3] = 1;
	if (num < 0)
	{
		n[pos] = -2;
		n[3] = 0;
	}
	else
		n[pos] = num;
	s++;
	return (s);
}

const char	*process_number(const char *str, int *n)
{
	long	resu;

	resu = 0;
	while (*str >= '0' && *str <= '9')
		resu = resu * 10 + ((*str++) - '0');
	*n = (int)resu;
	return (str);
}
