#include <iostream>
#include <graphics.h>
#include <cmath>

void translate3D(int& x, int& y, int& z, int tx, int ty, int tz) {
    x += tx;
    y += ty;
    z += tz;
}

void scale3D(int& x, int& y, int& z, float sx, float sy, float sz) {
    x *= sx;
    y *= sy;
    z *= sz;
}

void rotate3D(int& x, int& y, int& z, float angleX, float angleY, float angleZ) {
    float radX = angleX * (M_PI / 180.0);
    float radY = angleY * (M_PI / 180.0);
    float radZ = angleZ * (M_PI / 180.0);

    float cosX = cos(radX);
    float sinX = sin(radX);
    float cosY = cos(radY);
    float sinY = sin(radY);
    float cosZ = cos(radZ);
    float sinZ = sin(radZ);

    int tempX = x;
    int tempY = y;
    int tempZ = z;

    // Rotation around X-axis
    y = tempY * cosX - tempZ * sinX;
    z = tempY * sinX + tempZ * cosX;

    // Rotation around Y-axis
    x = tempX * cosY + z * sinY;
    z = -tempX * sinY + z * cosY;

    // Rotation around Z-axis
    tempX = x;
    tempY = y;
    x = tempX * cosZ - tempY * sinZ;
    y = tempX * sinZ + tempY * cosZ;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Initial coordinates of the point
    int x = 100;
    int y = 100;
    int z = 100;

    // Draw initial point
    putpixel(x, y, YELLOW);

    // Translation
    translate3D(x, y, z, 50, 50, 50);
    putpixel(x, y, YELLOW);

    // Scaling
    scale3D(x, y, z, 2.0, 2.0, 2.0);
    putpixel(x, y, YELLOW);

    // Rotation
    rotate3D(x, y, z, 45.0, 45.0, 45.0);
    putpixel(x, y, YELLOW);

    getch();
    closegraph();
    return 0;
}

