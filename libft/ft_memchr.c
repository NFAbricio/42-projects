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

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;

    if (!s)
        return (NULL);
    i = 0;
    while (i < n)
    {
        if (*(unsigned char*)(s + i) == (unsigned char)c)
            return ((void*)(s + i));
        i++;
    }
    return (NULL);
}
