#include<iostream>
#include<graphics.h>
using namespace std;

void drawLineDDA(int x1, int y1, int x2, int y2);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates of the line
    int x1 = 100, y1 = 100, x2 = 400, y2 = 300;

    // Draw the line using DDA algorithm
    drawLineDDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;

    // Determine the number of steps to put pixel
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    // Calculate increment in x and y for each step
    float increment_x = dx / (float)steps;
    float increment_y = dy / (float)steps;

    // Start drawing the line
    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE); // Put pixel at (x, y)
        x += increment_x; // Increment in x at each step
        y += increment_y; // Increment in y at each step
        delay(100); // Introduce a delay to visualize the line drawing process
    }
}

