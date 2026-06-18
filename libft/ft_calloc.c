/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnunes-d <fnunes-dn@student.42.fr>         +#+  +:+     +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:54:20 by fnunes-d          #+#    #+#             */
/*   Updated: 2026/06/15 14:54:20 by fnunes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void    *ptr;

    ptr = (void*)malloc(count * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, count);
    return (ptr);
}