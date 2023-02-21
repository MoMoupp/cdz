#include "yuan.h"

void ck(LcdDevice *lcd)
{
    char ck[20];
    char *ck_name[368];

    for (int i = 0; i < 368; i++)
    {
        sprintf(ck, "ckjpg/%d.jpg", i);
        ck_name[i] = (char *)malloc(sizeof(ck));
        strcpy(ck_name[i], ck);
    }
    printf("create over\n");

    lcd->lcd_vinfo->yoffset = 0;
    lcd->lcd_vinfo->xoffset = 0;
    ioctl(lcd->lcd_fd, FBIOPAN_DISPLAY, lcd->lcd_vinfo);
    
    for (int i = 0; i < 368; i++)
    {
        show_gif_jpeg(lcd, ck_name[i], 0, 0);
        printf(ck_name[i]);
        printf("\n");
    }

    for (int i = 0; i < 368; i++)
    {
        free(ck_name[i]);
    }

    destroy_lcd(lcd);
}