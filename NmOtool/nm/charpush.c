/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:37:12 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 17:37:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

char		*charpush(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	if (str == NULL)
	{
		str = (char*)malloc(sizeof(char) * 2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	else
	{
		new = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
		new[i] = c;
		new[++i] = '\0';
	}
	free(str);
	return (new);
}
