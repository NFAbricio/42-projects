/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:52:11 by marvin            #+#    #+#             */
/*   Updated: 2026/06/19 12:52:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list  *tmp;
    t_list  *tmp2;

    if (!lst)
        return ;
    tmp = lst;
    while (tmp)
    {
        tmp2 = tmp->next;
        f(tmp->content);
        tmp = tmp2;
    }
}