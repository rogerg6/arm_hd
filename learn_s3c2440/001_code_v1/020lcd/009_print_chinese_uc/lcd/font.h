

#ifndef _FONT_H
#define _FONT_H

# include "lcd.h"
# include "framebuffer.h"
void put_font(int x, int y, char * ps, unsigned int color);
void font_init(void);
int put_chinese(int x, int y, char * str, unsigned int color);

#endif   /* _FONT_H */




