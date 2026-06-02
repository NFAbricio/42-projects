/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:03:40 by marvin            #+#    #+#             */
/*   Updated: 2026/06/02 16:03:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strchr (const char *s, int c)
{
    int i;

    if (!s)
        return (NULL);
    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char*)(s + i));
        i++;
    }
    if (s[i] == (char)c)
        return ((char*)(s + i));
    return (NULL);
}