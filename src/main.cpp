#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0); glVertex2f(-0.6f, -0.4f);
        glColor3f(0, 1, 0); glVertex2f(0.6f, -0.4f);
        glColor3f(0, 0, 1); glVertex2f(0.0f, 0.6f);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("GLEW + OpenGL on Fedora");

    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cerr << "GLEW init failed: " << glewGetErrorString(err) << std::endl;
        return 1;
    }

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
