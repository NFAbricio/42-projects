/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:41:38 by marvin            #+#    #+#             */
/*   Updated: 2026/06/19 12:41:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *tmp;
    t_list  *tmp2;

    if (!*lst)
        return ;
    tmp =  *lst;
    while (tmp)
    {
        tmp2 = tmp->next;
        del(tmp->content);
        free(tmp);
        tmp = tmp2;
    }
    *lst = NULL;
}