/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:11:25 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:19:32 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	void	*start;

	start = s;
	while (n--)
		*((t_uchar *)s++) = (t_uchar)0;
	return (start);
}
