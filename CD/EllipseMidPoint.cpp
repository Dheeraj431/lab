#include <iostream>
#include <graphics.h>
using namespace std;

void drawEllipseMidPoint(int xc, int yc, int rx, int ry);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Ellipse center and radii
    int xc = 300, yc = 300, rx = 150, ry = 100;

    // Draw the ellipse using Mid-Point algorithm
    drawEllipseMidPoint(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}

void drawEllipseMidPoint(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int rx2 = rx * rx, ry2 = ry * ry;
    int rx2y2 = rx2 * y * y, ry2x2 = ry2 * x * x;
    int p, px = 0, py = 2 * rx2 * y;

    // Region 1
    p = ry2 - (rx2 * ry) + (0.25 * rx2);
    while (px < py) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;
        px += 2 * ry2;
        if (p < 0)
            p += ry2 + px;
        else {
            y--;
            py -= 2 * rx2;
            p += ry2 + px - py;
        }
        delay(100); // Introduce a delay to visualize the ellipse drawing process
    }

    // Region 2
    p = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
    while (y > 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;
        py -= 2 * rx2;
        if (p > 0)
            p += rx2 - py;
        else {
            x++;
            px += 2 * ry2;
            p += rx2 - py + px;
        }
        delay(100); // Introduce a delay to visualize the ellipse drawing process
    }
}

