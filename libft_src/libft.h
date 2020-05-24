/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 02:00:27 by Kwillum           #+#    #+#             */
/*   Updated: 2020/05/21 12:40:16 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef unsigned char	t_uchar;

void					*ft_memset(void *s, int c, size_t n);
void					*ft_bzero(void *s, size_t n);
size_t					ft_strlen(const char *s);
int						ft_toupper(int c);
char					*ft_strdup(const char *s);
void					*ft_calloc(size_t memb, size_t size);
char					*ft_substr(char const *s, unsigned int st, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_itoa(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);

#endif
