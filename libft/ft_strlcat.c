/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:18:08 by marvin            #+#    #+#             */
/*   Updated: 2026/06/02 11:18:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  j;
    size_t  dest_lenght;
    size_t  src_lenght;

    src_lenght = ft_strlen(src);
    dest_lenght = ft_strlen(dst);
    j = dest_lenght;
    i = 0;
    if (dest_lenght < size - 1 && size > 0)
    {
        while (src[i] && dest_lenght + i < size - 1)
        {
            dst[j] =  src[i];
            i++;
            j++;
        }
        dst[j] = 0;
    }
    if (dest_lenght >= size)
        dest_lenght = size;
    return (dest_lenght + src_lenght);
}
