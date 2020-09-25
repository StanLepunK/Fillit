/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:23:01 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/28 16:54:12 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t len)
{
	void	*result;

	if (!(result = malloc(len)))
		return (NULL);
	ft_bzero(result, len);
	return (result);
}
