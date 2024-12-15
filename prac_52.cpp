#include<iostream>
#include<stdlib.h>
#include<graphics.h>
using namespace std;
void move(int j, int h, int &x, int &y)
{
 if (j == 1) // Up
 y -= h;
 else if (j == 2) // Right
 x += h;
 else if (j == 3) // Down
 y += h;
 else if (j == 4) // Left
 x -= h;
 lineto(x, y); // Drawing line to new point (x, y)
}
void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y)
{
 if (i > 0)
 {
 i--;
 hilbert(d, r, u, l, i, h, x, y); // Recursive call for first part
 move(r, h, x, y); // Move to next position
 hilbert(r, d, l, u, i, h, x, y); // Recursive call for second part
 move(d, h, x, y); // Move to next position
 hilbert(r, d, l, u, i, h, x, y); // Recursive call for third part
 move(l, h, x, y); // Move to next position
 hilbert(u, l, d, r, i, h, x, y); // Recursive call for fourth part
 }
}
int main()
{
 int n;
 int x0 = 50, y0 = 150, x, y;
 int h = 10, r = 2, d = 3, l = 4, u = 1;
 cout << "Enter value of n (order of Hilbert curve): ";
 cin >> n;
 x = x0;
 y = y0;
 int gd = DETECT, gm;
 initgraph(&gd, &gm, NULL); // Initialize graphics mode
 moveto(x, y); // Move to initial position
 hilbert(r, d, l, u, n, h, x, y); // Generate Hilbert curve
 delay(10000); // Wait for 10 seconds
 closegraph(); // Close graphics window
 return 0;
}
