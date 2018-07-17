/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lettering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:32:06 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/17 14:20:06 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "nm.h"

int			s_check(unsigned int val)
{
	if (val == 49 || val == 41 || val == 50 ||
			val == 39 || val == 34 || val == 36)
		return (1);
	return (-1);
}

void		special_letters(unsigned n_sect, unsigned int n_type)
{
	unsigned int		val;
	int					flag;

	flag = n_sect % 2;
	val = 14 + n_sect + n_type;
	if (val == 29)
		ft_putstr(" t ");
	else if (val == 30)
		ft_putstr(" T ");
	else if ((val == 38 || val == 40) && flag == 0)
		ft_putstr(" b ");
	else if ((val == 38 || val == 40) && flag != 0)
		ft_putstr(" D ");
	else if (val == 51 && flag == 0)
		ft_putstr(" D ");
	else if (val == 51)
		ft_putstr(" b ");
	else if ((val == 39 || val == 37) && flag != 0)
		ft_putstr(" d ");
	else if (val == 32 || val == 33)
		ft_putstr(" s ");
	else if (s_check(val) == 1)
		ft_putstr(" S ");
	else
		ft_putstr(" T ");
}
