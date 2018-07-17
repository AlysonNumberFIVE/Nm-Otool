/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endswith.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 14:19:46 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 14:20:15 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int			endswith(char *str, char *end)
{
	int		i;
	int		j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(end) - 1;
	while (j > -1)
	{
		if (str[i] != end[j])
			return (-1);
		j--;
		i--;
	}
	return (1);
}
