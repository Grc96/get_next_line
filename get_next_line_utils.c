/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:22:46 by gdel-cas          #+#    #+#             */
/*   Updated: 2024/01/11 18:22:54 by gdel-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
void	ft_bzero(void *s, size_t n)
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
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t  i;
	
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}





