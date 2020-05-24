/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:16:32 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:21:10 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_dim(unsigned long n, int base)
{
	int				iter;

	iter = 0;
	while ((n /= base) != 0)
		iter++;
	return (iter + 1);
}

char		*ft_itoa_ubase(unsigned long n, int base)
{
	char			*p;
	int				iter;
	const char		*s = "0123456789abcdef";

	iter = ft_dim(n, base) + 1;
	p = ft_calloc(sizeof(char), iter);
	if (!p)
		return (NULL);
	iter -= 2;
	*(p + iter) = s[n % base];
	while (iter-- && (n /= base) != 0)
		*(p + iter) = s[n % base];
	return (p);
}
