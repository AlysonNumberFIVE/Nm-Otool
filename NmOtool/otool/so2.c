/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:19:23 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/18 17:26:09 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

unsigned char	*print_obj_name(unsigned char *content, size_t size)
{
	size_t			i;
	extern size_t	g_int;

	ft_putchar('(');
	i = 0;
	while (content[i] != 0x20)
	{
		if (g_int >= size)
			return (content);
		ft_putchar(content[i]);
		i++;
		g_int++;
	}
	ft_putstr("):\n");
	return (&content[i]);
}

unsigned char	*find_first_label_seg(unsigned char *content, size_t size)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (i < size)
	{
		if (g_int >= size)
			exit(1);
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00)
			break ;
		i++;
		g_int++;
	}
	i += 2;
	g_int += 2;
	return (&content[i]);
}

unsigned char	*exit_header(unsigned char *content, size_t size)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (42)
	{
		if (g_int >= size)
			break ;
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00 &&
				content[i + 2] == 0x5f)
			break ;
		i++;
		g_int++;
	}
	i += 2;
	g_int += 2;
	return (find_first_label_seg(&content[i], size));
}

unsigned char	*leave_header(unsigned char *content, size_t size)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (42)
	{
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00 &&
				content[i + 2] == 0x00 &&
				content[i + 3] == 0x00)
			break ;
		i++;
		g_int++;
	}
	i += 4;
	content = exit_header(&content[i], size);
	return (content);
}

int				start_frame(unsigned char *content, size_t size)
{
	extern size_t	g_int;

	if (g_int + 8 >= size)
		return (-1);
	if (content[0] == 0xcf &&
			content[1] == 0xfa &&
			content[2] == 0xed &&
			content[3] == 0xfe &&
			content[4] == 0x07 &&
			content[5] == 0x00 &&
			content[6] == 0x00 &&
			content[7] == 0x01)
		return (1);
	return (-1);
}
