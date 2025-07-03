#include "microui.h"
#include <raylib.h>
#include <string.h>

/**
 * muirl -- a custom wrapper and set of util libraries for microui
 *          with a Raylib backend. rather than polluting main.c w/
 *          all this code, i figured it'd be easier to ship it in
 *          a helpful single file util
 */

#define MU_ROW(ctx, h) mu_layout_row(ctx, h, (int[]){ -1 }, 1)

int mu_raylib_text_width(mu_Font font, const char *text, int len) {
    (void)font;
    /* If len == -1, measure whole string */
    if (len < 0) {
        return MeasureText(text, 16); 
        /* Font size 16 */
    } else {
        char buf[256];
        if (len >= (int)sizeof(buf)) len = (int)sizeof(buf)-1;
        memcpy(buf, text, len);
        buf[len] = '\0';
        return MeasureText(buf, 16);
    }
}

int mu_raylib_text_height(mu_Font font) {
    (void)font;
    return 16;
}