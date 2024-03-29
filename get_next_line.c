/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:17 by gdel-cas          #+#    #+#             */
/*   Updated: 2024/02/15 12:21:22 by gdel-cas         ###   ########.fr       */
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
	int		len_str;
	int		i;

	if (str[0] == '\0')
		return (NULL);
	len_str = 0;
	while (str[len_str] != '\n' && str[len_str])
		len_str++;
	if (str[len_str] != '\0')
		len_str++;
	line = malloc(sizeof(char) * (len_str + 1));
	if (!line)
		return (NULL);
	i = 0;
	ft_strlcpy(line, str, (len_str + 1));


	/*while (str[i] != '\0' && i < (len_str - 1))
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';*/
	return (line);
}
//funcion para extraer la nueva linea despues del salto de linea

char	*ft_new_line(char *str)
{
	char	*fin;
	int		index;

	if(!ft_strchr(str, '\n') || str[0] == '\0')
		return(free(str), str = NULL, NULL);
	index = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n'));
	fin  = ft_strdup(&str[index + 1]);
	free(str);
	
	return(fin);	
		
		
		
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
	*new = '\0';
	r = 1;
	while (r > 0 && !ft_strchr(str, '\n'))
	{
		r = read(fd, new, BUFFER_SIZE);
		if (r == -1)
			return (free(str), str = NULL, NULL);
		new[r] = '\0';
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
	//printf("total_str=%s\n", str);
	line = ft_get_line(str);
	//printf("line=%s\n", line);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = ft_new_line(str);
	//printf("str=%s\n", str);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("text.txt",  O_RDONLY);
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
}
