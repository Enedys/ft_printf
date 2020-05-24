/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:00:38 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 14:56:42 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define FD 1

# include <stdarg.h>
# include "libft_src/libft.h"

void		ft_putstrn_fd(const char *s, size_t n, int fd);

const char	*process_aster(const char *s, int *n, int pos, va_list ap);
const char	*process_number(const char *str, int *n);

int			ft_max(int a, int b);
int			print_infill(int c, int size);
int			print_formated_d(int *mask, char *s);
int			print_formated_p(int *m, char *s);
int			print_formated_s(int *mask, char *s);

int			p_d(int *mask, va_list ap);
int			p_u(int *mask, va_list ap);
int			p_x(int *mask, va_list ap);
int			p_ux(int *mask, va_list ap);
int			p_ch(int *mask, va_list ap);
int			p_s(int *mask, va_list ap);
int			p_p(int *mask, va_list ap);
void		infill_oper(int (**oper)(int *, va_list));

int			null_proc_p(int *mask);
int			nil_proc_p(int *mask);

char		*ft_itoa_ubase(unsigned long n, int base);
int			ft_printf(const char *s, ...);

#endif
