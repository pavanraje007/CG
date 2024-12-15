#include <iostream>
#include <cmath>
using namespace std;
// Define a class for a 2D point
class Point {
public:
 float x, y;
 // Constructor to initialize a point
 Point(float x_val = 0, float y_val = 0) : x(x_val), y(y_val) {}
 // Operator overloading for Scaling
 Point operator*(float scale) {
 return Point(x * scale, y * scale);
 }
 // Operator overloading for Translation
 Point operator+(const Point& p) {
 return Point(x + p.x, y + p.y);
 }
 // Operator overloading for Rotation (counterclockwise)
 Point operator()(float angle) {
 float rad = angle * M_PI / 180; // Convert angle to radians
 float new_x = x * cos(rad) - y * sin(rad);
 float new_y = x * sin(rad) + y * cos(rad);
 return Point(new_x, new_y);
 }
 // Method to display the point
 void display() {
 cout << "(" << x << ", " << y << ")\n";
 }};
int main() {
 Point p1(2, 3); // Initial point (2, 3)
 cout << "Original point: ";
 p1.display();
 // Scaling the point by a factor of 2
 Point p2 = p1 * 2;
 cout << "After scaling by 2: ";
 p2.display();
 // Translating the point by (3, 4)
 Point p3 = p1 + Point(3, 4);
 cout << "After translation by (3, 4): ";
 p3.display();
 // Rotating the point by 90 degrees
 Point p4 = p1(90);
 cout << "After rotating by 90 degrees: ";
 p4.display();
 return 0;
}
