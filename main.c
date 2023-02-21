#include "touch.h"
#include "showpic.h"


int main(int argc, char **argv)
{
    int x, y;
    
    LcdDevice *lcd = create_lcd("/dev/fb0");
    show_bmp(lcd, "pic/keyboard.bmp",400,200);
    show_font(lcd, 0, 0, key_input());
    
    //printf("%d:%d\n", x, y);
    

    destroy_lcd(lcd);
    return 0;
}