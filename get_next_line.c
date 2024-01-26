/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:31:17 by gdel-cas          #+#    #+#             */
/*   Updated: 2024/01/26 19:40:53 by gdel-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include  "get_next_line.h"
#include<fcntl.h>

/* funcion que coja la linea leida y a guarde enun buffer y se guarda en la variable estatica*/
char	*ft_save_str(int fd, char *save_str)
{

}

char	*get_next_line(int fd)
{
	int	bytes_read;
	char	*buf;

	buf = ft_calloc(20 + 1, sizeof(char));
	if(!buf)
		return(NULL);
	
	bytes_read = read(fd, buf, 20);
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
