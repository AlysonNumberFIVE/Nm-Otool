/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:10:05 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/20 13:41:01 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

size_t			g_int;

unsigned char	*print_obj_name(unsigned char *content, size_t size)
{
	size_t			i;

	ft_putchar('(');
	i = 0;
	while (i < size)
	{
		if (content[i] == 0x60 && content[i] + 0x0a)
			break ;
		i++;
	}
	i += 2;
	ft_putstr((const char *)&content[i]);
	ft_putstr("):\n");
	return (&content[i]);
	while (content[i] != 0x20)
	{
		if (g_int >= size)
			return (&content[i]);
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
