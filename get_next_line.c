/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:17 by gdel-cas          #+#    #+#             */
/*   Updated: 2024/02/01 17:43:10 by gdel-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

//funcion para sacar la primera linea hasta el salto de linea
char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
//funcion para extraer la nueva linea despues del salto de linea

char	*ft_new_line(char *str)
{
	char	*fin;

	
	fin  = ft_strdup(ft_strchr(str, '\n'));
	
		
		
		
		
		
	rest = malloc (sizeof(char) *  (i + 1));
	if (!rest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	aux2 = malloc(sizeof(char) * ());
	if (!aux2)
		return (NULL);
	y = 0;
	while (str[i])
	{
		aux2[y++] = str[i++];
	}
	aux2[i] = '\0';
	free(str);
	return (aux2);
}
//leer los datos del fd y concatenarlos con str

char	*ft_read_str(int fd, char *str)
{
	char	new[BUFFER_SIZE + 1];
	int		r;
	char	*aux;

	if (!str)
	{
		str = malloc (sizeof(char) * 1);
		if(!str)
			return (NULL);
		*str = '\0';
	}
	r = 1;
	while (r > 0 && !ft_strchr(str, '\n'))
	{
		r = read(fd, new, BUFFER_SIZE);
		if (r == -1)
			return (NULL);
		aux = str;
		str = ft_strjoin(str, new);
		free(aux);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
		return (NULL);
	str = ft_new_line(str);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("text.txt", O_RDONLY);
	next_line = "";
	while(next_line)
	{
		next_line = get_next_line(fd);
		printf("%s\n", next_line);
		free(next_line);
	}
	close(fd);
	//system("leaks -q a.out");
	return(0);
}*/ft_new_line(str)
