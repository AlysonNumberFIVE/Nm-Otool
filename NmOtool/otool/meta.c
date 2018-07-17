/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:24:26 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 15:37:38 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void		line_put(char *filename)
{
	ft_putstr(filename);
	ft_putstr(":\n");
}

void		*dynamic_lib_read(void *content, size_t size)
{
	size_t			i;
	unsigned char	*file;

	file = (unsigned char *)content;
	i = 0;
	while (i < size)
	{
		if (find_magic_number(&file[i]) == 1)
			break ;
		i++;
	}
	return ((void*)&file[i]);
}

void		usage(void)
{
	ft_putstr("Usage : ./ft_otool [file to examine]");
	return ;
}
