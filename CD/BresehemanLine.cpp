#include <iostream>
#include <graphics.h>
using namespace std;

void drawLineBresenham(int x1, int y1, int x2, int y2);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates of the line
    int x1 = 100, y1 = 100, x2 = 400, y2 = 300;

    // Draw the line using Bresenham's algorithm
    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int p;

    int incx = 1, incy = 1;
    if (x2 < x1) incx = -1;
    if (y2 < y1) incy = -1;

    x = x1;
    y = y1;

    if (dx > dy) {
        putpixel(x, y, WHITE);
        p = 2 * dy - dx;

        for (int i = 0; i < dx; i++) {
            if (p >= 0) {
                y += incy;
                p += 2 * (dy - dx);
            } else {
                p += 2 * dy;
            }
            x += incx;
            putpixel(x, y, WHITE);
            delay(100); // Introduce a delay to visualize the line drawing process
        }
    } else {
        putpixel(x, y, WHITE);
        p = 2 * dx - dy;

        for (int i = 0; i < dy; i++) {
            if (p >= 0) {
                x += incx;
                p += 2 * (dx - dy);
            } else {
                p += 2 * dx;
            }
            y += incy;
            putpixel(x, y, WHITE);
            delay(100); // Introduce a delay to visualize the line drawing process
        }
    }
}

