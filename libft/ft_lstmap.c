/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:42:59 by marvin            #+#    #+#             */
/*   Updated: 2026/06/22 10:42:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new;

    if (!lst || !f || !del)
        return (NULL);
    new = ft_lstnew(f(lst->content));
    if (!new)
    {
        return (NULL);
    }
    new->next = ft_lstmap(lst->next, f, del);
    if (lst->next && !new->next)
    {
        ft_lstclear(&new, del);
        return (NULL);
    }
    return (new);
}