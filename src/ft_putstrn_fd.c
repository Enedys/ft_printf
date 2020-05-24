/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 20:08:49 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:21:18 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putstrn_fd(const char *s, size_t n, int fd)
{
	size_t	max;

	if (!s)
		return ;
	max = -1;
	if (n == max)
		ft_putstr_fd((char *)s, fd);
	else
		write(fd, s, n);
}
