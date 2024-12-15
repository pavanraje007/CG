#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <iostream>
using namespace std;
class WalkingMan {
 int rhx, rhy;
public:
 void drawRain(int i); // Function to draw rain
 void drawMan(int i); // Function to draw walking man
};
// Function to draw rain (simple lines falling)
void WalkingMan::drawRain(int i) {
 for (int j = 0; j < 5; j++) {
 line(30 + 20 * j, i, 30 + 20 * j, i + 10);
 }
}
// Function to draw walking man
void WalkingMan::drawMan(int i) {
 // Platform
 line(20, 380, 580, 380); // Platform
 // Walking man
 if (i % 2 == 0) {
 // Left leg and right leg while walking
 line(25 + i, 380, 35 + i, 340); // Left leg
 line(45 + i, 380, 35 + i, 340); // Right leg
 // Left hand and right hand while walking
 line(35 + i, 310, 25 + i, 330); // Left hand
 } else {
 line(35 + i, 380, 35 + i, 340); // Left leg (standing)
 line(35 + i, 310, 40 + i, 330); // Right hand (raising umbrella)
 }
 // Body
 line(35 + i, 340, 35 + i, 310); // Body
 // Head
 circle(35 + i, 300, 10); // Head (circle)
 // Right hand holding the umbrella
 line(35 + i, 310, 50 + i, 330); // Right hand
 // Umbrella stick
 line(50 + i, 330, 50 + i, 280); // Umbrella stick
 // Umbrella body (umbrella shape)
 line(15 + i, 280, 85 + i, 280); // Umbrella body (horizontal line)
 // Umbrella arc (arc of the umbrella)
 arc(50 + i, 280, 0, 180, 35); // Umbrella body (half-circle)
 // Umbrella handle (arc)
 arc(55 + i, 330, 180, 360, 5); // Umbrella handle (small arc)
}
// Main program
int main() {
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "");
 WalkingMan man;
 int i = 0;
 // Animate the walking man with umbrella in the rain
 while (!kbhit()) {
 for (i = 0; i < 100; i++) {
 cleardevice(); // Clear the screen
 // Draw the rain
 man.drawRain(i);
 // Draw the walking man
 man.drawMan(i);
 delay(50); // Delay for a while to simulate animation
 }
 }
 getch();
 closegraph(); // Close graphics window
 return 0;
}
