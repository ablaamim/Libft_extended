/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarray_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:43:31 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/03 13:05:23 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modules.h"

void	ft_intarray_destroy(t_intarray tab)
{
	free(tab->data);
	free(tab);
}