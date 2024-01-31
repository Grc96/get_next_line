/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:22:46 by gdel-cas          #+#    #+#             */
/*   Updated: 2024/01/31 12:40:17 by gdel-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include<stddef.h>
#include<stdio.h>
#include<unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t  i;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void    ft_bzero(void *s, size_t n)
{
        unsigned char   *ptr;

        ptr = (unsigned char *) s;
        while (n-- > 0)
                *(ptr++) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
		
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{	
	size_t  i;
	size_t  j;
	char    *new;
		
	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!new)
		return (NULL);
	if (!s1  || !s2)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		new[i++] = s2[j++];
	return (new);
}
char    *ft_strchr(const char *s, int c)
{
	int i;
   	i = 0;
   	while (s[i])
	{
	   	if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (char)c == '\0')
		return ((char *)&s[i]);
			return (NULL);
}
