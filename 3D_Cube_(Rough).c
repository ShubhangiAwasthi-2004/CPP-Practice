#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>

#define WIDTH 120
#define HEIGHT 30

// Function declaration
void projectAndDraw(float angle);

// 3D Cube vertices
float cube[8][3] = {
    {-1, -1, -1},
    { 1, -1, -1},
    { 1,  1, -1},
    {-1,  1, -1},
    {-1, -1,  1},
    { 1, -1,  1},
    { 1,  1,  1},
    {-1,  1,  1}
};

// Cube edges
int edges[12][2] = {
    {0,1},{1,2},{2,3},{3,0},
    {4,5},{5,6},{6,7},{7,4},
    {0,4},{1,5},{2,6},{3,7}
};

void projectAndDraw(float angle) {
    char screen[HEIGHT][WIDTH];
    memset(screen, ' ', sizeof(screen));

    float cosA = cos(angle), sinA = sin(angle);
    float rotated[8][2];

    for (int i = 0; i < 8; ++i) {
        float x = cube[i][0];
        float y = cube[i][1];
        float z = cube[i][2];

        // Rotate cube around Y and X axis
        float x1 = x * cosA - z * sinA;
        float z1 = x * sinA + z * cosA;
        float y1 = y * cosA - z1 * sinA;
        z1 = y * sinA + z1 * cosA;

        // Perspective projection
        float scale = 40 / (z1 + 5);
        int sx = (int)(x1 * scale + WIDTH / 2);
        int sy = (int)(y1 * scale + HEIGHT / 2);

        rotated[i][0] = sx;
        rotated[i][1] = sy;
    }

    // Draw edges
    for (int e = 0; e < 12; ++e) {
        int a = edges[e][0];
        int b = edges[e][1];

        int x1 = rotated[a][0];
        int y1 = rotated[a][1];
        int x2 = rotated[b][0];
        int y2 = rotated[b][1];

        int dx = abs(x2 - x1), dy = abs(y2 - y1);
        int sx = x1 < x2 ? 1 : -1;
        int sy = y1 < y2 ? 1 : -1;
        int err = dx - dy;

        while (1) {
            if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT)
                screen[y1][x1] = '#';

            if (x1 == x2 && y1 == y2) break;
            int e2 = 2 * err;
            if (e2 > -dy) { err -= dy; x1 += sx; }
            if (e2 < dx) { err += dx; y1 += sy; }
        }
    }

    system("cls"); // clear screen
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
            putchar(screen[i][j]);
        putchar('\n');
    }
}

int main() {
    float angle = 0;
    for (int frame = 0; frame < 100; frame++) { // 100 frames
        projectAndDraw(angle);
        angle += 0.05;
        Sleep(40);
    }
    return 0;
}
