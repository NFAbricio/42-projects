/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:48:18 by marvin            #+#    #+#             */
/*   Updated: 2026/06/02 10:48:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*s1, const void	*s2, size_t	n)
{
	char		*dst;
	const char	*src;

	if (!s1 && !s2)
		return (NULL);
	dst = (char *)s1;
	src = (const char *)s2;
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		while (n--)
			dst[n] = src[n];
	}
	return (s1);
}