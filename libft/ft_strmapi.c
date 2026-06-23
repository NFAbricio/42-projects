/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 00:32:37 by marvin            #+#    #+#             */
/*   Updated: 2026/06/14 00:32:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi (char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    size_t  i;

    if (!(str = ft_strdup(s)))
        return (NULL);
    i = 0;
    while (str[i])
    {
        str[i] = (*f)(i, str[i]);
        i++;
    }
    return (str);
}