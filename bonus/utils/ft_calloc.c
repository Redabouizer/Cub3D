/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:33:40 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/11 18:33:42 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count && size && count > (4294967295 / size))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
