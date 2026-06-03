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

int ft_memcmp (const void *s1, const void *s2, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        if (*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i))
            return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i))
        i++;
    }
    return (0);
}