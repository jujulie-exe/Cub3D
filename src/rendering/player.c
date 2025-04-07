void    init_player(t_player *player)
{
    player->x = window_W/2;
    player->y = window_H/2;

    player->up = false;
    player->down = false;
    player->left = false;
    player->right = false;
}