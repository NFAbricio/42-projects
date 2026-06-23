/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:01:07 by marvin            #+#    #+#             */
/*   Updated: 2026/06/02 18:01:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    const unsigned char *bytes;

    if (!s)
        return (NULL);
    bytes = (const unsigned char *)s;
    i = 0;
    while (i < n)
    {
        if (bytes[i] == (unsigned char)c)
            return ((void *)(bytes + i));
        i++;
    }
    return (NULL);
}
