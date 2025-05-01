/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:32:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/05/01 21:14:39 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

// Window
# define WIDTH 1800
# define HEIGHT 1045

// Minimap
// The width and height in pixels of a single tile shown in the Minimap
# define MINIMAP_SCALE 30
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
# define PLAYER_SIZE 1.2

# define PI 3.141592653589793

// Defines the viewing angle and the number of rays
# define PLAYER_VIEW_ANGLE PI/2

#endif
