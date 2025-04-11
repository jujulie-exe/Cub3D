#include "../../include/render3d.h"

void	calc_dda(t_ray *ray, t_player *player, char **map)
{
	while (!collision(ray, player, map))
	{
		ray->delta_x += cos(player->angle);
		ray->delta_y += sin(player->angle);
	}
}

float	calc_dist(float X, float y)
{
	float	dst;

	dst = sqrt(x * x + y * y);
	return (dst);
}

float	dist_to_wall()
{
	float	dtw;


}

// float fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
// {
//     float delta_x = x2 - x1;
//     float delta_y = y2 - y1;
//     float angle = atan2(delta_y, delta_x) - game->player.angle;
//     float fix_dist = distance(delta_x, delta_y) * cos(angle);
//     return fix_dist;
// }

// if(!DEBUG)
// {
// 	float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
// 	float height = (BLOCK / dist) * (WIDTH / 2);
// 	int start_y = (HEIGHT - height) / 2;
// 	int end = start_y + height;
// 	while(start_y < end)
// 	{
// 		put_pixel(i, start_y, 255, game);
// 		start_y++;
// 	}

// int draw_loop(t_game *game)
// {
//     t_player *player = &game->player;
//     move_player(player);
//     clear_image(game);
//     if(DEBUG)
//     {
//         draw_square(player->x, player->y, 10, 0x00FF00, game);
//         draw_map(game);
//     }
//     float fraction = PI / 3 / WIDTH;
//     float start_x = player->angle - PI / 6;
//     int i = 0;
//     while(i < WIDTH)
//     {
//         draw_line(player, game, start_x, i);
//         start_x += fraction;
//         i++;
//     }
//     mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
//     return 0;
// }