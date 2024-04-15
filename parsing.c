/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufreder <lufreder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:55:51 by lufreder          #+#    #+#             */
/*   Updated: 2024/04/15 16:55:53 by lufreder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_valid;
return map_invalid;