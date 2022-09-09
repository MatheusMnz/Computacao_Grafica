#include <GL/freeglut.h>
#include <math.h>

GLfloat tom = 0.5f;
GLfloat incremento = 0.01;

void mudaCor(GLint valor) {
  tom += incremento;
  if (tom > 1 || tom < 0) {
    // inverte o sinal
    incremento *= -1;
  }
  glutPostRedisplay();

  glutTimerFunc(33, mudaCor, 0);
}

void desenhaMinhaCena() {
    //seto o background
    glClearColor(0.0, 0.0, 0.0, 1.0);

    //Limpando o buffer de cores
    glClear(GL_COLOR_BUFFER_BIT);

    //Seto a cor utilizada
    glColor3ub(0, 147, 55);

    //Desenho o retangulo verde
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(-100, 100, 0.0);
        glVertex3f(100, 100, 0.0);
        glVertex3f(100, -100, 0.0);
        glVertex3f(-100, -100, 0.0);
    glEnd();

    //Seto a cor amarela
    glColor3f(1.0, 1.0, 0.0);

   // <LOSANGO> O posiconamento dos Vértices variam de 0 à 100
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(100, 0.0, 0.0);
        glVertex3f(0.0, 50, 0.0);
        glVertex3f(-100, 0.0, 0.0);
        glVertex3f(0.0, -50, 0.0);
    glEnd();

    //Set blue
    glColor3f(tom, tom+0.45, tom+0.6);

    Silhueta:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    

    //Draw the Blue Circle
    glBegin(GL_TRIANGLE_FAN);
        glVertex3i(0, 0, 0);
        GLfloat x = 0, y = 0;

        for (GLint i = 0; i <= 3000; ++i){
            GLfloat t = 2 * M_PI * i / 3000;
            glVertex2f(x + cos(t) * 35, y + sin(t) * 35);
        }
    glEnd();

    //Jogo pra tela
    glFlush();
}

void teclaPressionada(GLubyte key, GLint x, GLint y) {
    // vê qual tecla foi pressionada
    switch(key) {
    case 27:      // Tecla "ESC"
        exit(0);  // Sai da aplicação
        break;
    default:
        break;
    }
}

void configuraProjecao(){
    //Configuro meu aspecto, para ter proporção
    float razaoAspecto = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);

    //Inicializo a matriz de projeção, quando redimensionar a tela
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Configuro a perspectiva
    glOrtho(-100 * razaoAspecto, 100 * razaoAspecto, -100, 100, -100, 100);
    
    //Volto para a Model_View
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void redimensiona(GLint width, GLint height){	
    glViewport(0, 0, width, height);
    configuraProjecao();
}

void initConf(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}




int main(int argc, char** argv){
    //Passo os argumentos
    glutInit(&argc, argv);

    //Configuro inicial da janela do GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);

    // Abre janela com o nome
    glutCreateWindow("Entendo a freeglut");

    // Registro de callbacks de eventos
    glutDisplayFunc(desenhaMinhaCena);
    glutTimerFunc(0, mudaCor, 33);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclaPressionada);

    initConf();
    glutMainLoop();

 
    return 0;
}



