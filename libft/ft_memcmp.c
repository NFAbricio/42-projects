/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:45:29 by marvin            #+#    #+#             */
/*   Updated: 2026/06/03 15:45:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp (const void *s1, const void *s2, size_t n)
{
    size_t  i;
    const unsigned char *left;
    const unsigned char *right;

    i = 0;
    left = (const unsigned char *)s1;
    right = (const unsigned char *)s2;
    while (i < n)
    {
        if (left[i] != right[i])
            return (left[i] - right[i]);
        i++;
    }
    return (0);
}