#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdbool.h> 

float angulo = 0.0f;
bool rotacionar = false;

void init(void)
{
    glClearColor(0,0,0,0);
    gluOrtho2D(0, 500, 0, 500);
}

void displayCatavento(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Céu
	glColor3f(0.53f, 0.81f, 0.98f);
	glBegin(GL_POLYGON);
	glVertex2i(0, 500);	  
	glVertex2i(500, 500); 
	glVertex2i(500, 100); 
	glVertex2i(0, 100);	  
	glEnd();

    // chão
	glColor3f(0.0, 1.0, .0);
	glBegin(GL_POLYGON);
	glVertex2i(0, 99);
	glVertex2i(500, 99);
	glVertex2i(500, 0);
	glVertex2i(0, 0);
	glEnd();


    //haste 
	glColor3f(1.0, .0, .0);
	glBegin(GL_POLYGON);
	glVertex2i(248, 250);
	glVertex2i(252, 250);
	glVertex2i(252, 100);
	glVertex2i(248, 100);
	glEnd();


    //hélices do catavento
    glPushMatrix();
    {
        
        glTranslatef(250, 250, 0);
        glRotated(angulo, 0, 0, 1);
        glTranslatef(-250, -250, 0);

        //hélice 1
        glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(230, 200);
        glVertex2i(270, 200);
        glEnd();

        //hélice 3
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(300, 230);
        glVertex2i(300, 270);
        glEnd();

        //hélice 3
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(230, 300);
        glVertex2i(270, 300);
        glEnd();

        //hélice 4
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2i(250, 250);
        glVertex2i(200, 270);
        glVertex2i(200, 230);
        glEnd();
       
    }
    glPopMatrix();

    glFlush();
}

void update(int value) {
    if (rotacionar) {
        angulo += 2.0f; 
        if (angulo >= 360.0f) angulo -= 360.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(16, update, 0); 
}

void keyboard(unsigned char key, int x, int y)
{
    if( key == 'q' ) exit(0);
	
    if(key == 'p') rotacionar = !rotacionar;
}

int main(int arg , char ** argv)
{
    glutInit(&arg, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(600,200);

    glutCreateWindow("Catavento");
    init();

    glutDisplayFunc(displayCatavento);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);


    glutMainLoop();
}