/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:17 by gdel-cas          #+#    #+#             */
/*   Updated: 2024/02/01 09:59:00 by gdel-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

//funcion para sacar la primera linea hasta el salto de linea
char    *ft_get_line(char *str)
{
        char    *aux;
        int     i;

        i = 0;
        if (!str)
                return (NULL);
        while (str[i] != '\n' && str[i] )
                i++;
        aux = (char *)ft_calloc(i + 1, sizeof(char));    
        if (!aux)
                return (NULL);
        i = 0;
        while (str[i] != '\0' && str[i] != '\n')
	{
		aux[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

//funcion para extraer la nueva linea despues del salto de linea

char	*ft_new_line(char *str)
{
	char	*aux2;
	int	i;
	int	y;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	aux2 = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!aux2)
		return (NULL);
	y = 0;
	while (str[i])
	{
		aux2[y] = str[i];
		y++;
		i++;
	}
	aux2[i] = '\0';
	free(str);
	return (aux2);
}
//leer los datos del fd y concatenarlos con str
char	*ft_join_str(int fd, char *str)
{
	char	*aux;
	int	r;

	aux = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	r = 1;
	while (r != 0 && !ft_strchr(str, '\n'))
	{
		r = read(fd, aux, BUFFER_SIZE);
		if (r == -1)
		{
			free (aux);
			return (NULL);
		}
	
		aux[r] = '\0';
		str = ft_strjoin(str, aux);
	}
	free (aux);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*str;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	str = ft_join_str(fd, str);
	if (!str)
		return(NULL);
	line = ft_get_line(str);
	str = ft_new_line(str);
	return (line);
}	

int	main(void)
{
	int	fd;
	int	count;
	char	*next_line;
	
	count = 1;
	fd = open("text.txt",O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("%d: %s\n", count, next_line);
	free(next_line);
	close(fd);
	return(0);


}
