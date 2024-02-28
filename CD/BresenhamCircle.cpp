#include <iostream>
#include <graphics.h>
using namespace std;

void drawCircleBresenham(int xc, int yc, int radius);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Circle center and radius
    int xc = 300, yc = 300, radius = 100;

    // Draw the circle using Bresenham's algorithm
    drawCircleBresenham(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}

void drawCircleBresenham(int xc, int yc, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (x <= y) {
        // Plot the octants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d <= 0)
            d = d + 4 * x + 6;
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
        delay(100); // Introduce a delay to visualize the circle drawing process
    }
}

