void    init_player(t_player *player)
{
    player->x = window_W/2; //mettre les vraies variables par rapport à la fenetre
    player->y = window_H/2;

    player->up = false; //voir comment on fait pour les keyhooks
    player->down = false;
    player->left = false;
    player->right = false;
}

int key_press(int keycode, t_player *player)
{
    if (keycode == W)
        player->up = true;
    if (keycode == S)
        player->down = true;
    if (keycode == A)
        player->left = true;
    if (keycode == D)
        player->right = true;
    return (0);
}
