/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:50:04 by marvin            #+#    #+#             */
/*   Updated: 2026/06/18 13:50:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
    }
    else
    {
        if (n < 0)
        {
            ft_putchar_fd('-', fd);
            n = -n;
        }
        if (n < 10)
        {
            ft_putchar_fd(n + '0', fd);
            return ;
        }
        else 
            ft_putnbr_fd(n / 10, fd);
        ft_putchar_fd((n % 10) + '0', fd);
    }
}