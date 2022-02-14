/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarray_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:23:06 by ablaamim          #+#    #+#             */
/*   Updated: 2022/02/07 15:26:25 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intarray.h"

int	ft_intarray_get(t_intarray tab, int index)
{
	return (tab.data[index]);
}