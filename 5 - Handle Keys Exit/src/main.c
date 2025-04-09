#include "../include/utils.h"

typedef struct
{
    void *mlx;
    void *win;
}var_t;

int handle_key(int key, var_t *data)
{
    printf("keycode premuto: %d\n", key);

    if(key == 53)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return 0;
}


int main(void)
{

    var_t data;
    int width = 600;
    int height = 500;
    char *title = "so_long";

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, width,height, title);
    mlx_key_hook(data.win, handle_key, &data);
    mlx_loop(data.mlx);

}



