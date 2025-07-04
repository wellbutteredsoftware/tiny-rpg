#include "microui.h"
#include <raylib.h>
#include <string.h>

/**
 * muirl -- a custom wrapper and set of util functions for microui
 *          with a Raylib backend. rather than polluting main.c w/
 *          all this code, i figured it'd be easier to ship it in
 *          a helpful single file util
 * 
 *          all funcs of course are prefixed by: 'mu_raylib'
 */

#define MU_ROW(ctx, h) mu_layout_row(ctx, h, (int[]){ -1 }, 1)
#define FONT_SIZE 16

int mu_raylib_text_width(mu_Font font, const char *text, int len) {
    (void)font;
    /* If len == -1, measure whole string */
    if (len < 0) {
        return MeasureText(text, FONT_SIZE); 
    } else {
        char buf[256];
        if (len >= (int)sizeof(buf)) len = (int)sizeof(buf)-1;
        memcpy(buf, text, len);
        buf[len] = '\0';
        return MeasureText(buf, FONT_SIZE);
    }
}

int mu_raylib_text_height(mu_Font font) {
    (void)font;
    return  FONT_SIZE;
}