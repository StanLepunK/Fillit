/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:35:05 by smarcais          #+#    #+#             */
/*   Updated: 2019/09/11 09:21:45 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t len_1;
	size_t len_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (len_1 <= len_2)
		return (ft_strncmp(s1, s2, len_2));
	else
		return (1);
}
