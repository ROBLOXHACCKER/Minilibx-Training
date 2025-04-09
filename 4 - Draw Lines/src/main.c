#include "../include/utils.h"

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    int *data;
    int width = 800;
    int height = 600;
    int grid_tomargin = 50;
    int widthlinee = 6;
    int tot_pixel = width * height;
    int temp_1, temp_2, temp_3;
    int i = 0;
    int x = 0;
    int n = 0;
    //int y = 0;
    char *title = "so_long"; 

    mlx = mlx_init();
    win = mlx_new_window(mlx, width, height, title);
    img = mlx_new_image(mlx, width, height);
    data = (int*)mlx_get_data_addr(img, &temp_1, &temp_2, &temp_3);

    while (x < tot_pixel)
    {
        if ((i % grid_tomargin >= grid_tomargin - widthlinee / 2) &&
            (i % grid_tomargin <= grid_tomargin + widthlinee / 2))
        {
            data[x] = 0xFFA500;
        }
        else if ((n % grid_tomargin >= grid_tomargin - widthlinee / 2) &&
                 (n % grid_tomargin <= grid_tomargin + widthlinee / 2))
        {
            data[x] = 0xFFA500;
        }
        i++;
        x++;
        if (i % width == 0)
        {
            i = 0;
            n++;
        }
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}