#include <iostream>
#include <graphics.h>
using namespace std;

// Define region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define window boundaries
const int X_MIN = 50;
const int X_MAX = 250;
const int Y_MIN = 50;
const int Y_MAX = 250;

// Define point structure
struct Point {
    int x, y;
};

// Function to compute region code for a point
int computeCode(Point p) {
    int code = INSIDE;

    if (p.x < X_MIN)
        code |= LEFT;
    else if (p.x > X_MAX)
        code |= RIGHT;

    if (p.y < Y_MIN)
        code |= BOTTOM;
    else if (p.y > Y_MAX)
        code |= TOP;

    return code;
}

// Function to clip a line segment
void cohenSutherland(Point p1, Point p2) {
    int code1 = computeCode(p1);
    int code2 = computeCode(p2);

    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints are inside the window, accept the line
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside the same clip boundary, reject the line
            break;
        } else {
            // Compute intersection point from outside to inside
            int code_out;
            Point p;

            // Pick the endpoint which is outside the clip boundary
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point
            if (code_out & TOP) {
                p.x = p1.x + (p2.x - p1.x) * (Y_MAX - p1.y) / (p2.y - p1.y);
                p.y = Y_MAX;
            } else if (code_out & BOTTOM) {
                p.x = p1.x + (p2.x - p1.x) * (Y_MIN - p1.y) / (p2.y - p1.y);
                p.y = Y_MIN;
            } else if (code_out & RIGHT) {
                p.y = p1.y + (p2.y - p1.y) * (X_MAX - p1.x) / (p2.x - p1.x);
                p.x = X_MAX;
            } else if (code_out & LEFT) {
                p.y = p1.y + (p2.y - p1.y) * (X_MIN - p1.x) / (p2.x - p1.x);
                p.x = X_MIN;
            }

            // Replace the outside point with intersection point
            if (code_out == code1) {
                p1.x = p.x;
                p1.y = p.y;
                code1 = computeCode(p1);
            } else {
                p2.x = p.x;
                p2.y = p.y;
                code2 = computeCode(p2);
            }
        }
    }

    if (accept) {
        // Draw the clipped line
        line(p1.x, p1.y, p2.x, p2.y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw the window
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Define line segment
    Point p1 = {30, 40};
    Point p2 = {300, 350};

    // Draw the original line segment
    setcolor(RED);
    line(p1.x, p1.y, p2.x, p2.y);

    // Apply Cohen-Sutherland algorithm to clip the line segment
    setcolor(WHITE);
    cohenSutherland(p1, p2);

    getch();
    closegraph();
    return 0;
}

