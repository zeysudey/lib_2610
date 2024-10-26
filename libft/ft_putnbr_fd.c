/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:23:10 by zyilmaz           #+#    #+#             */
/*   Updated: 2024/10/26 17:02:29 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = (tmp * -1);
	}
	if (tmp < 10)
		ft_putchar_fd(tmp + 48, fd);
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putnbr_fd(tmp % 10, fd);
	}
}
