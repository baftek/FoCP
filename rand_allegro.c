// Copyright 2014 by Siarkowy.
// Released under the terms of GNU GPL v3 license.

#define USE_CONSOLE

#include <cstdlib>
#include <ctime>
#include "allegro.h"

#define MAX     100     // max result from rand
#define MAX_COLS  6     // number of colors
#define WIN_X   640     // width
#define WIN_Y   512     // height
#define WIN_D    24     // depth
#define WIN_P    50     // padding

#define BAR_W     (WIN_X-2*WIN_P)/MAX   // bar width
#define BAR_MAX_H (WIN_Y-2*WIN_P)       // max height of bars

using namespace std;

int COLS[MAX_COLS][3] = {
    {255, 0, 0},
    {255, 255, 0},
    {0, 255, 0},
    {0, 255, 255},
    {0, 0, 255},
    {255, 0, 255},
};

int main()
{
    int nums[MAX];
    int i;

    // Erase data
    for (i = 0; i < MAX; ++i)
        nums[i] = 0;

    // Calculate data
    for (i = 0; i < 3000; ++i)
        ++nums[(rand() % MAX + rand() % MAX + rand() % MAX + rand() % MAX)/4];

    // Allegro stuff
    allegro_init();
    install_keyboard();
    set_color_depth(WIN_D);
    set_gfx_mode(GFX_GDI,WIN_X,WIN_Y,0,0);

    // Draw chart
    int col = 0;
    line(screen, WIN_P, WIN_Y - WIN_P, WIN_P, WIN_P, makecol(127, 127, 127));
    for (i = 0; i < MAX; ++i)
    {
        int vertices[8];

        // bot left
        vertices[0] = WIN_P + i * BAR_W;
        vertices[1] = WIN_Y - WIN_P;

        // bot right
        vertices[2] = WIN_P + (i+1) * BAR_W;
        vertices[3] = WIN_Y - WIN_P;

        // top right
        vertices[4] = WIN_P + (i+1) * BAR_W;
        vertices[5] = WIN_Y - WIN_P - BAR_MAX_H * nums[i]/MAX;

        // top left
        vertices[6] = WIN_P + i * BAR_W;
        vertices[7] = WIN_Y - WIN_P - BAR_MAX_H * nums[i]/MAX;

        ++col;
        col %= MAX_COLS;

        polygon(screen,4,vertices,makecol(COLS[col][0], COLS[col][1], COLS[col][2]));
    }

    readkey();
    return 0;
}
