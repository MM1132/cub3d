/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:32:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/06 17:22:41 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <math.h>

// Window
# define WIDTH 2000
# define HEIGHT 1200

// Minimap
// The width and height in pixels of a single tile shown in the Minimap
// # define MINIMAP_SCALE 5 // This can now be calculated: size / range
# define MINIMAP_MARGIN 15
// # define MINIMAP_RANGE 40
# define MAX_MINIMAP_SIZE 500 // The width and height in pixels
# define MINIMAP_CAMERA_FOLLOW_SPEED 5

// Player
// This does not define the speed itself directly
// But it defines the increase amount of the palyer's speed
# define PLAYER_ACCELERATION 1
// Defines the speed at which the speed will be decreasing over time
# define PLAYER_SPEED_DECREASE_MULTIPLIER 0.82
# define PLAYER_ROTATION_SPEED 0.005
# define PLAYER_SIZE 0.5
# define MINIMAP_PLAYER_SIZE 10

// Defines the viewing angle and the number of rays
# define PLAYER_VIEW_ANGLE M_PI_2

#endif
