/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 20:37:50 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:21:31 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_max(int a, int b)
{
	if (a < 0 && b < 0)
		return (0);
	return (a > b ? a : b);
}

int	null_proc_p(int *mask)
{
	int		len;
	char	*s;

	s = "(null)";
	mask[6] = ft_strlen(s);
	if (mask[1] > 0 || mask[4] == 0)
	{
		if (mask[5] < 0 || mask[5] >= mask[6])
			ft_putstr_fd(s, FD);
		else
			mask[6] = 0;
		len = mask[6] + print_infill(' ', mask[4] - ft_max(0, mask[6]));
		return (len);
	}
	if (mask[5] < mask[6] && mask[5] >= 0)
		len = print_infill(' ', mask[4]);
	else
	{
		len = mask[6] + print_infill(' ', mask[4] - mask[6]);
		ft_putstr_fd(s, FD);
	}
	return (len);
}

int	nil_proc_p(int *mask)
{
	int		len;
	char	*s;

	s = "(nil)";
	len = ft_strlen(s);
	mask[6] = len;
	if (mask[1] > 0)
	{
		ft_putstr_fd(s, FD);
		len += print_infill(' ', mask[4] - mask[6]);
		return (len);
	}
	len += print_infill(' ', mask[4] - mask[6]);
	ft_putstr_fd(s, FD);
	return (len);
}
