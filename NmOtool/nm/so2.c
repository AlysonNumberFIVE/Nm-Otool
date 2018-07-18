/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:10:44 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/18 17:21:07 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

unsigned char	*reverse_to_next_frame(unsigned char *content)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (content[i] != 0x00)
	{
		i--;
		g_int--;
	}
	return (&content[i]);
}

unsigned char	*next_frame(unsigned char *content, size_t size)
{
	size_t			i;
	extern size_t	g_int;

	i = 0;
	while (g_int < size)
	{
		if (content[i] == 0x20 &&
			content[i + 1] == 0x20 &&
			content[i + 2] == 0x20)
			break ;
		i++;
		g_int++;
	}
	return (reverse_to_next_frame(&content[i]));
}

unsigned char	*name_space(unsigned char *content, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00 &&
				content[i + 2] == 0x5f)
			break ;
		i++;
	}
	i += 2;
	return (&content[i]);
}

unsigned char	*print_labels(unsigned char *content, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x00 &&
			content[i + 1] == 0x00 &&
			content[i + 2] == 0x00 &&
			content[i + 3] == 0x00)
			break ;
		i++;
	}
	return (name_space(&content[i], size));
}

unsigned char	*print_names(unsigned char *content, char *filepath)
{
	size_t			i;

	ft_putstr(filepath);
	ft_putstr("(");
	i = 1;
	while (content[i])
	{
		ft_putchar(content[i]);
		i++;
	}
	ft_putstr(".o):\n");
	i++;
	return (&content[i]);
}
