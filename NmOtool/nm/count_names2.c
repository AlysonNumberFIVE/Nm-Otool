/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_names2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:06:46 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 17:07:43 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int			end_of_function(unsigned char *content)
{
	if (content[0] == 0x23 &&
		content[1] == 0x31 &&
		content[2] == 0x2f)
		return (1);
	return (-1);
}

int			get_labels(unsigned char *content)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (42)
	{
		if (end_of_function(&content[i]) == 1)
			break ;
		if (content[i] == 0x00)
			count++;
		i++;
	}
	return (count);
}

size_t		get_entrance(unsigned char *content)
{
	size_t		i;

	i = 0;
	while (42)
	{
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00 &&
				content[i + 2] == 0x5f)
			break ;
		i++;
	}
	i += 3;
	return (get_labels(&content[i]));
}

size_t		find_start_position(unsigned char *content,
		size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if (content[i] == 0x00 &&
				content[i + 1] == 0x00 &&
				content[i + 2] == 0x00 &&
				content[i + 3] == 0x00 &&
				content[i + 4] == 0x00)
			break ;
		i++;
	}
	i += 3;
	return (get_entrance(&content[i]));
}
