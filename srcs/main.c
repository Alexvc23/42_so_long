/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:19:07 by jvalenci          #+#    #+#             */
/*   Updated: 2022/02/28 10:26:22 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx.h"

int main()
{
    void    *mlx_ptr;
    void    *win_ptr; 

    //we will create a connexion between the screen and my software
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500,  "test"); 
    mlx_loop(mlx_ptr);
}