/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:32:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/05 17:38:49 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

// Window
# define WIDTH 1800
# define HEIGHT 1045

// Minimap
// The width and height in pixels of a single tile shown in the Minimap
# define MINIMAP_SCALE 10
# define MINIMAP_MARGIN 15
# define MINIMAP_RANGE 12
# define MINIMAP_CAMERA_FOLLOW_SPEED 1

// Player
// This does not define the speed itself directly
// But it defines the increase amount of the palyer's speed
# define PLAYER_ACCELERATION 2
// Defines the speed at which the speed will be decreasing over time
# define PLAYER_SPEED_DECREASE_MULTIPLIER 0.82
# define PLAYER_ROTATION_SPEED 0.005
# define PLAYER_SIZE 0.8

// Defines the viewing angle and the number of rays
# define PLAYER_VIEW_ANGLE M_PI/2
#endif
