/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:09:36 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 17:42:44 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

unsigned char		*obj_name(unsigned char *content)
{
	size_t			i;

	i = 1;
	while (content[i] != 0x00)
	{
		ft_putchar(content[i]);
		i++;
	}
	ft_putstr("):\n");
	return (&content[i]);
}

unsigned char		*function_name(unsigned char *content, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x60)
		{
			content = obj_name(&content[i]);
			break ;
		}
		i++;
	}
	return (content);
}

void				arc_nm(void *content, size_t size, char *filename)
{
	unsigned char	*file;
	size_t			i;

	file = (unsigned char *)content;
	content = first_obj_name((unsigned char *)content, &size);
	i = find_start_position(file, size);
	recursive_nm(content, size, i, filename);
	last_word(file, size);
}
