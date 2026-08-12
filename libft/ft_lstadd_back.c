/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:48:02 by marvin            #+#    #+#             */
/*   Updated: 2026/06/19 11:48:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *aux;

    if (!new || !lst)
        return ;
    if (!*lst)
    {
        *lst = new;
    }
    else
    {
        aux = ft_lstlast(*lst);
        aux->next = new; 
    }
}