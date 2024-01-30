r* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:17 by gdel-cas          #+#    #+#             */
/*   Updated: 2024/01/30 15:23:58 by gdel-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include  "get_next_line.h"
#include<fcntl.h>

/* funcion que coja la linea leida y a guarde enun buffer y se guarda en la variable estatica*/
char	*ft_save_str(int fd, char *save_str)
{
	char	*str;
	char	*aux;
	int	i;

	str = ft_calloc((BUFFER_SIZE + 1), sizeof (char *));
	str = aux;
	i = 0;
	while (aux != '\0' && !ft_strchr(str, '\n'))
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			return (NULL);
		}
	
		aux[i] = '\0';
		save_str = ft_strjoin(save_str, str);
	}
	free (str);
	return (save_str);
}

char	*get_next_line(int fd)
{
	int	bytes_read;
	static char	*buf;

	/*buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));*/
	buf = ft_save_str(fd, buf);
	if(!buf)
		return(NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	return(buf);
}	

int	main(void)
{
	int	fd;
	int	count;
	char	*next_line;
	
	count = 0;
	fd = open("text.txt",O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("%d: %s\n", count, next_line);
	close(fd);
	return(0);


}
