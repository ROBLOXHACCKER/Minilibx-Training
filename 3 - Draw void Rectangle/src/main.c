#include "../include/utils.h"


int main(void)
{
    void *mlx;
    void *win;
    void *img;
    int *data;
    int width = 600;
    int height = 900;
    int tot_pixel = width * height;
    int maargin_l_r = 150;
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
        if((i > maargin_l_r && i < width - maargin_l_r) && (x > maargin_l_r * width && x < (tot_pixel - maargin_l_r * width)))
        {
            data[x] = 0xFFA500;
        }else
        {
            data[x] = 0x00FFFF;
        }
        if(i%width==0)
        {
            i=0;
        }
        i++;
        x++;
    }


    mlx_put_image_to_window(mlx, win, img, 0, 0);

    mlx_loop(mlx);
}