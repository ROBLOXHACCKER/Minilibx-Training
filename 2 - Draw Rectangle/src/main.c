#include "../include/utils.h"


int main(void)
{
    void *mlx;
    void *win;
    void *img;
    int *data;
    int width = 800;
    int height = 600;
    int tot_pixel = width * height;
    int temp_1, temp_2, temp_3;
    int i = 0;
    int x = 0;
    char *title = "so_long"; 

    mlx = mlx_init();
    win = mlx_new_window(mlx, width, height, title);
    img = mlx_new_image(mlx, width, height);
    data = (int*)mlx_get_data_addr(img, &temp_1, &temp_2, &temp_3);
    while(x < tot_pixel)
    {
        while(i<400)
        {
            data[x] = 0x00FF0000;
            i++;
            x++;
        }
        while (i >= 400 && i <= 799)
        {
            data[x] = 0x00FF00FF;
            i++;
            x++;
        }
        i = 0;
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);

    mlx_loop(mlx);
}