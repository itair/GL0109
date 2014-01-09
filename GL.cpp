#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glew32.lib")

#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>

void init()
{
  glewInit();
  glClearColor(1.0,1.0,0.0,0.0);
  glBlendFunc(GL_ONE,GL_ONE);
  glEnable(GL_BLEND);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,1.0);
  glRectf(-0.5,-0.5,0.5,0.5);
  glFlush();
}

void keyboard(unsigned char key,int x,int y)
{
  switch(key)
  {
  case 'a':case 'A':
    glBlendEquation(GL_FUNC_ADD);
    break;
  case 's':case 'S':
    glBlendEquation(GL_FUNC_SUBTRACT);
    break;
  case 'r':case 'R':
    glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
    break;
  case 'm':case 'M':
    glBlendEquation(GL_MIN);
    break;
  case 'x':case 'X':
    glBlendEquation(GL_MAX);
    break;
  case 27:
    exit(0);
    break;
  }
  glutPostRedisplay();
}
void processMenuEvents(int option) {
  switch (option)
  {
  case 1:
    ;
  case 2:
    ;
  case 3:
    ;
  default:
    break;
  }
}

void creatGLUTMenus() {
  int menu;
  menu = glutCreateMenu(processMenuEvents);

  glutAddMenuEntry("Red",1);
  glutAddMenuEntry("BLue",2);
  glutAddMenuEntry("Green",3);

  glutAttachMenu(GLUT_RIGHT_BUTTON);
}



int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  creatGLUTMenus(); // mouse
  glutMainLoop();
  return 0;
}