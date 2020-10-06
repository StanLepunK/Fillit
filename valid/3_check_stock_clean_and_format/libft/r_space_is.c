/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_space_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:24:38 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/14 10:24:41 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	r_space_is(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (TRUE);
	else
		return (FALSE);
}
