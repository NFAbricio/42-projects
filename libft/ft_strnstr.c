/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:16:05 by marvin            #+#    #+#             */
/*   Updated: 2026/06/03 16:16:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;

    if (!haystack || !needle)
        return (NULL);
    if (!needle || !needle[0])
        return ((char*)haystack);
    i = 0;
    while (haystack[i] && i < len)
    {
        j = 0;
        while (haystack[i + j] && needle[j] && i + j < len && haystack[i + j] == needle[j])
            j++;
        if (!needle[j])
            return ((char*)(haystack + i));
        i++;
    }
    return (NULL);
}