/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:32:39 by rreimann          #+#    #+#             */
/*   Updated: 2025/04/28 19:12:42 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

// Window
# define WIDTH 1800
# define HEIGHT 1000

// Minimap
// The width and height in pixels of a single tile shown in the Minimap
# define MINIMAP_SCALE 40
# define MINIMAP_MARGIN 15

// Player
// This does not define the speed itself directly
// But it defines the increase amount of the palyer's speed
# define PLAYER_ACCELERATION 0.7
// Defines the speed at which the speed will be decreasing over time
# define PLAYER_SPEED_DECREASE_MULTIPLIER 0.74
# define PLAYER_ROTATION_SPEED 3
# define PLAYER_SIZE 0.4

# define PI 3.141592653589793

#endif
