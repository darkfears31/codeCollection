#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main() {
    float A = 0, B = 0;
    // z array is used to store the depth of each point on the screen, while b array is used to store the corresponding ASCII character for shading.
    char b[1760];
    float z[1760];
    // uses an ANSI escape sequence to clear the terminal screen.
    printf("\x1b[2J");
    for(;;) {
        // memset is used to initialize the b array with spaces (ASCII code 32) and the z array with zeros.
        //1760 is the total number of characters that can be displayed on an 80x22 terminal screen (80 columns * 22 rows).
        //7040 is the total number of bytes in the z array (1760 elements * 4 bytes per float).
        // The z array is initialized to 0, which means that initially, all points are considered to be infinitely far away (or not visible).
        memset(b,32,1760);
        memset(z,0,7040);
        // 2 is the size of the plane, and 0.1 is the step size for iterating through the points on the plane.
        for(float j=-2.5; j < 2.5; j += 0.1) { 
            for(float i=-2.5; i < 2.5; i += 0.1) {
                // Define the 3D coordinates of the point on the plane. The plane is defined in the xz-plane, so py is set to 0.
                // The point (px, py, pz) represents a point on the plane that we want to project onto the 2D screen. The x-coordinate is given by i, the y-coordinate is fixed at 0 (since it's a flat plane), and the z-coordinate is given by j.
                float px = i;
                float py = 0; // Set the y-coordinate to 0 to make the plane visible above the origin. You can adjust this value to change the height of the plane.
                float pz = j;
                // Calculate the sine and cosine of the rotation angles A and B. These values will be used to rotate the points on the plane around the y-axis (for A) and x-axis (for B).
                float cosA = cos(A);
                float sinA = sin(A);
                float cosB = cos(B);
                float sinB = sin(B);
                // The rotation around the y-axis is performed first, followed by the rotation around the x-axis. The rotated coordinates (rx, ry, rz) are calculated using the standard rotation formulas for 3D transformations.
                // Rotate around y-axis
                float rx = px * cosA - pz * sinA;
                float ry = py;
                float rz = px * sinA + pz * cosA;
                // Rotate around x-axis
                float rx2 = rx;
                float ry2 = ry * cosB - rz * sinB;
                float rz2 = ry * sinB + rz * cosB;
                // The depth (D) of the point is calculated as the inverse of the z-coordinate (rz2) plus a constant (7 in this case) to ensure that points closer to the viewer have a larger D value. This depth value is used for shading and determining which points are visible on the screen.
                float D = 1 / (rz2 + 7);
                // The 2D screen coordinates (x, y) are calculated by projecting the 3D coordinates onto the 2D plane. The x-coordinate is calculated by scaling the rotated x-coordinate (rx2) by the depth (D) and adding an offset to center it on the screen. The y-coordinate is calculated similarly using the rotated y-coordinate (ry2).
                int x = 40 + 30 * D * rx2;
                int y = 12 + 15 * D * ry2;
                // The index (o) in the b and z arrays is calculated based on the x and y screen coordinates. The shading character (N) is set to a constant value (8 in this case) for simplicity, but it can be modified to create different shading effects based on the depth or angle of the point.
                int o = x + 80 * y;
                int N = 8; // Simple shading for the plane
                // The if statement checks if the calculated screen coordinates (x, y) are within the bounds of the terminal screen (0 to 79 for x and 0 to 21 for y) and if the depth (D) of the point is greater than the current depth stored in the z array at index o. If these conditions are met, it means that this point is visible and closer to the viewer than any previously stored point at that location.
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        //ANSI escape sequence that moves the cursor to the home position (top-left corner of the terminal) without clearing the screen.
        printf("\x1b[H");
        // The loop iterates through each character position on the screen (from 0 to 1760) and uses the putchar function to print the corresponding character from the b array. If the index k is a multiple of 80, it prints a newline character (ASCII code 10) to move to the next line.
        for(int k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            // Rotation of plane around first-> y-axis and second-> x-axis.
            A += 0.00004; 
            B += 0.00004;
        }
        usleep(30000);
    }
    return 0;
}