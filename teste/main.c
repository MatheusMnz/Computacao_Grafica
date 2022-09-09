// C program to demonstrate
// drawing a circle using
// OpenGL
#include <stdio.h>
#include <GL/glut.h>
#include "math.h"
#define SQR_2 1.41421356237

typedef struct grade
{
    float x;
    float y;
    float z;
    int h_cubes;
    int v_cubes;
} grade_t;

typedef struct Matrix
{
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Creates a table
grade_t tabl = {
    .x = 0,
    .y = 0,
    .z = .0,
    .h_cubes = 3,
    .v_cubes = 3};

// function to initialize
void myInit(void)
{
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(0.0, 1.0, 0.0);

    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    // glOrtho(-100, 100, -100, 100, -1, 1);
}

void drawSquare(float x, float y, float l_size, int state)
{
    // Draws the square
    // 0 means a clear path
    // 1 means a closed path
    // 2 means its a searching path

    if (!state)
    {
        // Paints the lines of a clear path with WHITE
        glColor3f(1.0, 1.0, 1.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else
    {
        // Fills the squares
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        if (state == 1)
            glColor3f(0.0, 0.0, 1.0); // Sets the color to BLUE
        else
            glColor3f(1.0, 0.0, 0.0); // Sets the color to RED
    }

    /*
            - - - - <- x = x + l_size/2  ,  y = y + l_size/2
            - - - -
            - - - -
            - - - -
    */
    l_size = l_size / 2;

    glBegin(GL_POLYGON);

    glVertex3f(x - (l_size), y + l_size, 0.0);
    glVertex3f(x + l_size, y + l_size, 0.0);
    glVertex3f(x + (l_size), y - l_size, 0.0);
    glVertex3f(x - (l_size), y - l_size, 0.0);

    glEnd();
}

// Callback for drawing
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    printf("Drawing \n");

    // Desenha os cubin
    // float x = tabl.x - ((tabl.h_cubes - 1) * 10), y = tabl.y + ((tabl.v_cubes - 1) * 10), s_y = y;
    // for (int i = 0; i < tabl.h_cubes; i++, x += 20)
    // {
    //     for (int j = 0; j < tabl.v_cubes; j++, y -= 20)
    //     {
    //         drawSquare(x, y, 20.0, 0);
    //     }
    //     y = s_y;
    // }

    glColor3ub(0, 147, 55);
    glBegin(GL_POLYGON);
    glVertex3i(-100, 100, 0);
    glVertex3i(100, 100, 0);
    glVertex3i(100, -100, 0);
    glVertex3i(-100, -100, 0);
    glEnd();

    glColor3ub(241, 212, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 50, 0);
    glVertex3f(0, -50, 0);
    glVertex3f(-70, 0, 0);

    glVertex3f(0, 50, 0);
    glVertex3f(0, -50, 0);
    glVertex3f(70, 0, 0);
    glEnd();

    glColor3ub(0, 29, 109);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3i(0, 0, 0);
    float x = 0, y = 0;
    for (int i = 0; i <= 2000; ++i)
    {
        float t = 2 * M_PI * i / 2000;
        glVertex2f(x + cos(t) * 30, y + sin(t) * 30);
    }
    glEnd();

    glFlush();
}

void configuraProjecao()
{
    float razaoAspecto = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * razaoAspecto, 100 * razaoAspecto, -100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void redimensiona(int width, int height)
{	
    printf("ahsahsga");
    glViewport(0, 0, width, height);
    configuraProjecao();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("Imbrochavel");

    glutDisplayFunc(display);
    glutReshapeFunc(redimensiona);
   

    myInit();
    glutMainLoop();
}
