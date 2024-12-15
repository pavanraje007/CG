#include <GL/glut.h>
// Initial cube position
float angle = 0.0; // Rotation angle
float scale = 1.0; // Scaling factor
float translateX = 0.0, translateY = 0.0, translateZ = -5.0; // Translation values
// Function to draw the cube
void drawCube() {
 glBegin(GL_QUADS);
 // Front face
 glColor3f(1.0, 0.0, 0.0);
 glVertex3f(-1.0, -1.0, 1.0);
 glVertex3f( 1.0, -1.0, 1.0);
 glVertex3f( 1.0, 1.0, 1.0);
 glVertex3f(-1.0, 1.0, 1.0);
 // Back face
 glColor3f(0.0, 1.0, 0.0);
 glVertex3f(-1.0, -1.0, -1.0);
 glVertex3f(-1.0, 1.0, -1.0);
 glVertex3f( 1.0, 1.0, -1.0);
 glVertex3f( 1.0, -1.0, -1.0);
 // Top face
 glColor3f(0.0, 0.0, 1.0);
 glVertex3f(-1.0, 1.0, -1.0);
 glVertex3f(-1.0, 1.0, 1.0);
 glVertex3f( 1.0, 1.0, 1.0);
 glVertex3f( 1.0, 1.0, -1.0);
 // Bottom face
 glColor3f(1.0, 1.0, 0.0);
 glVertex3f(-1.0, -1.0, -1.0);
 glVertex3f( 1.0, -1.0, -1.0);
 glVertex3f( 1.0, -1.0, 1.0);
 glVertex3f(-1.0, -1.0, 1.0);
 // Right face
 glColor3f(1.0, 0.0, 1.0);
 glVertex3f( 1.0, -1.0, -1.0);
 glVertex3f( 1.0, 1.0, -1.0);
 glVertex3f( 1.0, 1.0, 1.0);
 glVertex3f( 1.0, -1.0, 1.0);
 // Left face
 glColor3f(0.0, 1.0, 1.0);
 glVertex3f(-1.0, -1.0, -1.0);
 glVertex3f(-1.0, -1.0, 1.0);
 glVertex3f(-1.0, 1.0, 1.0);
 glVertex3f(-1.0, 1.0, -1.0);
 glEnd();
}
// Function to apply transformations and draw the cube
void display() {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and 
depth buffers
 glLoadIdentity(); // Reset transformations
 // Apply translation
 glTranslatef(translateX, translateY, translateZ);
 // Apply scaling
 glScalef(scale, scale, scale);
 // Apply rotation
 glRotatef(angle, 1.0, 1.0, 0.0); // Rotate the cube around the X and Y axes
 drawCube(); // Draw the cube
 glutSwapBuffers(); // Swap the front and back buffers
}
// Function to handle key presses for transformation control
void keyboard(unsigned char key, int x, int y) {
 if (key == 'w') translateY += 0.1; // Move up
 if (key == 's') translateY -= 0.1; // Move down
 if (key == 'a') translateX -= 0.1; // Move left
 if (key == 'd') translateX += 0.1; // Move right
 if (key == 'q') translateZ += 0.1; // Move forward
 if (key == 'e') translateZ -= 0.1; // Move backward
 if (key == '+') scale += 0.1; // Scale up
 if (key == '-') scale -= 0.1; // Scale down
 if (key == 'r') angle += 5.0; // Rotate clockwise
 if (key == 'l') angle -= 5.0; // Rotate counterclockwise
 glutPostRedisplay(); // Redraw the scene
}
// Function to initialize OpenGL settings
void initOpenGL() {
 glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
 glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D
 glMatrixMode(GL_PROJECTION); // Set the projection matrix mode
 gluPerspective(45.0, 1.0, 0.1, 50.0); // Set perspective view
 glMatrixMode(GL_MODELVIEW); // Set the modelview matrix mode
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display 
mode
 glutInitWindowSize(500, 500); // Set window size
 glutCreateWindow("3D Cube Transformation"); // Create window
 initOpenGL(); // Initialize OpenGL settings
 glutDisplayFunc(display); // Register display function
 glutKeyboardFunc(keyboard); // Register keyboard input function
 glutMainLoop(); // Enter the GLUT main loop
 return 0;
}
