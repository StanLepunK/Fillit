/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarcais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:05:27 by smarcais          #+#    #+#             */
/*   Updated: 2019/11/13 17:13:46 by smarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int index_src;

	index = 0;
	index_src = 0;
	while (s1[index] != '\0')
	{
		index++;
	}
	while (s2[index_src] != '\0')
	{
		s1[index + index_src] = s2[index_src];
		index_src++;
	}
	s1[index + index_src] = '\0';
	return (s1);
}
