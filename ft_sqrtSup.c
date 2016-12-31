/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:28:25 by malbanes          #+#    #+#             */
/*   Updated: 2016/12/08 13:36:08 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrtSup(int nb)
{
	int	x;

	x = 0;
	if (x < 0)
		return (0);
	while (x < nb / 4 + 2)
	{
		if ((x * x) >= nb)
			return (x);
		x++;
	}
	return (0);
}
