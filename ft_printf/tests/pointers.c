/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:17:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 18:01:36 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	/*
	printf("ptf:%.0p, %.p\n", 0, 0);
	ft_printf("ftp:%.0p, %.p", 0, 0);
	*/
	printf("ptf:{%5p}", 0);
	ft_printf("\nftp:{%5p}", 0);
	
	return (0);
}