/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:03:23 by gevorg            #+#    #+#             */
/*   Updated: 2023/09/05 14:04:03 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_key_config(t_key_conf *key_conf)
{
	key_conf->w = RELEASE;
	key_conf->a = RELEASE;
	key_conf->s = RELEASE;
	key_conf->d = RELEASE;
	key_conf->up = RELEASE;
	key_conf->down = RELEASE;
	key_conf->left = RELEASE;
	key_conf->right = RELEASE;
}
