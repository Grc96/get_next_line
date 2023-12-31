/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:59:59 by gdel-cas          #+#    #+#             */
/*   Updated: 2023/12/18 19:06:16 by gdel-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE.H
# define GET_NEXT_LINE.H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#include<unistd.h>
#include <stdlib.h>

// get_next_line
char	*get_next_line(fd)


//UTILS

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

