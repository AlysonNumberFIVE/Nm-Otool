/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:28:22 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 11:28:43 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int			read_file(void **content,
		size_t *size, char *filename)
{
	int			fd;
	struct stat	info;

	fd = open(filename, O_RDONLY);
	fstat(fd, &info);
	*size = info.st_size;
	*content = mmap(0, *size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*content == MAP_FAILED)
	{
		ft_putstr(": No such file or directory\n");
		return (-1);
	}
	return (1);
}
