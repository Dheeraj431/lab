#include <iostream>
#include <graphics.h>
using namespace std;

void drawHut();
void drawSmiley();

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawHut();
    drawSmiley();

    getch();
    closegraph();
    return 0;
}

void drawHut() {
    // Draw hut
    setcolor(BROWN);
    rectangle(50, 250, 350, 450);
    rectangle(100, 300, 300, 400);
    rectangle(125, 325, 275, 375);

    // Draw roof
    line(50, 250, 200, 150);
    line(200, 150, 350, 250);

    // Draw door
    setcolor(BLUE);
    rectangle(175, 400, 225, 450);
    floodfill(180, 420, BLUE);

    // Draw windows
    setcolor(LIGHTBLUE);
    rectangle(75, 300, 125, 350);
    floodfill(80, 320, LIGHTBLUE);
    rectangle(275, 300, 325, 350);
    floodfill(280, 320, LIGHTBLUE);
}

void drawSmiley() {
    // Draw face
    setcolor(YELLOW);
    circle(500, 350, 100);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(500, 350, YELLOW);

    // Draw eyes
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(450, 300, 5);
    floodfill(450, 300, BLACK);
    circle(550, 300, 5);
    floodfill(550, 300, BLACK);

    // Draw mouth
    arc(500, 350, 200, 340, 50);
}

