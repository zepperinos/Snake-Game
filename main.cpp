#include <GL/gl.h>
#include <GL/glut.h>

void display_callback();
void reshape_callback(int,int);

void init()
{
	glClearColor(1.0,1.0,0.5,1.0);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800,750);
	glutCreateWindow("SNAKE");
	glutDisplayFunc(display_callback);
	glutReshapeFunc(reshape_callback);
	init();
	glutMainLoop();
	return 0;
}

void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
} 

voidreshape_callback(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
