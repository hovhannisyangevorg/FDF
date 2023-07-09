/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:06:27 by gehovhan          #+#    #+#             */
/*   Updated: 2023/07/01 15:06:40 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
* RETURN void
*
* Structure NameThe code provided defines
* A function called "panic".
* That takes a string (char*) argument named "str".
* The function writes the contents of the 
* String to standard error (file descriptor 2) 
*/
void	ft_panic(char *str)
{
	write (2, str, ft_strlen(str));
	write (2, "\n", 1);
	exit (EXIT_FAILURE);
}