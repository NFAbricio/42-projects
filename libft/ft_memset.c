/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 02:12:51 by marvin            #+#    #+#             */
/*   Updated: 2026/06/02 02:12:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memset(void *b, int c, size_t len)
{
    size_t  i;
    if (!b)
        return (NULL);
    i = 0;
    while (i < len)
    {
        *(unsigned char*)(b + i) = (unsigned char)c;
        i++;
    }
    return(b);
}