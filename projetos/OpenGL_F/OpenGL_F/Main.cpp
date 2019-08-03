#include <windows.h>		// for MS Windows
#include <GL\freeglut.h>	// GLUT, include glu.h and gl.h
#include <fstream>		    // File library
#include <iostream>
#include <list> 
#include <iterator> 
using namespace std;

GLfloat angleV, fAspect;
GLfloat angle = 0.0f, angle1 = 0.0f;
int numObjects;
int ObjectList[10];         // Lista de Objetos, 10 é o número máximo
list <int> Objects;
int x[10], y[10], z[10], dimensao[10], solid[10];
GLfloat r[10], g[10], b[10];
int indexObj = 0, indexSoma = 1;
GLfloat somaR = 0.1, somaG = 0.1, somaB = 0.1;
char title[] = "OpenGL-PUC PR: Guilherme Solski Alves";
#define Pi_ 3.14
void Cone(GLfloat Raio, GLfloat H) {
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, 0.0);// BASE
	for (GLfloat angle = 0.0; angle < (2.0*Pi_); angle += (2.0*Pi_ / 8.0)) {
		GLfloat x = Raio * sin(angle);
		GLfloat y = Raio * cos(angle);
		glNormal3f(x, y, 0);
		glVertex3f(x, y, 0.0);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, H);//Parte de cima
	for (GLfloat angle = 0.0; angle < (2.0*Pi_); angle += (2.0*Pi_ / 36.0)) {
		GLfloat x = Raio * sin(angle);
		GLfloat y = Raio * cos(angle);
		glNormal3f(x, y, 0);
		glVertex3f(x, y, 0.0);
	}
	glEnd();
}

// Função para leitura do arquivo de cena
void DisplayFileRead(const char* fileName)
{
	fstream inStream;
	inStream.open(fileName, ios::in); // abre o arquivo
	if (inStream.fail())  return;      //falha na abertura do arquivo
	cout << "Abertura do arquivo com sucesso ..." << endl;
	inStream >> numObjects;			  // lê primeira linha do arquivo, número de objetos 
	cout << numObjects << " Objetos na cena ..." << endl;
	for (int i = 0; i < numObjects; i++) { // leitura das demais linhas, ID dos objetos, posição e cor (101, nao tem float)
		inStream >> ObjectList[i] >> x[i] >> y[i] >> z[i] >> r[i] >> g[i] >> b[i] >> dimensao[i] >> solid[i];

	}
	inStream.close();				// fecha o arquivo
}



// Função callback chamada para fazer o desenho
void render(void)
{

	//	DisplayFileRead("df.txt");  // se estiver aqui, lê a cada redesenho da tela (dá para alterar o arquivo em tempo de execução)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // limpa a tela e o buffer de profundidade
	glPushMatrix();
	glRotatef(angle, 1.0f, 0.0f, 0.0f);// roda em y
	glRotatef(angle1, 0.0f, 1.0f, 0.0f); // roda em x
	glColor3f(255, 255, 255);
	glutWireCube(300);  // simula os limites da cena
	for (int i = 0; i < numObjects; i++) {
		glColor3f(r[i], g[i], b[i]);
		glTranslatef(x[i], y[i], z[i]);



		if (solid[i] == 1) {
			if (ObjectList[i] == 0) glutSolidCube(20 + dimensao[i]);
			else if (ObjectList[i] == 1) glutSolidSphere(20 + dimensao[i], 24, 24);
			else if (ObjectList[i] == 2) Cone(20 + dimensao[i], 20 + dimensao[i]);//glutSolidCone(20 + dimensao[i], 20 + dimensao[i], 24, 24);
			else if (ObjectList[i] == 3) glutSolidCylinder(20 + dimensao[i], 20 + dimensao[i], 24, 24);
			else if (ObjectList[i] == 4) glutSolidTorus(1 + dimensao[i], 10 + dimensao[i], 24, 24);
			else if (ObjectList[i] == 5) glutSolidTeapot(20 + dimensao[i]);
		}
		else if (solid[i] == 0) {
			if (ObjectList[i] == 0) glutWireCube(20 + dimensao[i]);
			else if (ObjectList[i] == 1) glutWireSphere(20 + dimensao[i], 24, 24);
			else if (ObjectList[i] == 2) glutWireCone(20 + dimensao[i], 20 + dimensao[i], 24, 24);
			else if (ObjectList[i] == 3) glutWireCylinder(20 + dimensao[i], 20 + dimensao[i], 24, 24);
			else if (ObjectList[i] == 4) glutWireTorus(1 + dimensao[i], 10 + dimensao[i], 24, 24);
			else if (ObjectList[i] == 5) glutWireTeapot(20 + dimensao[i]);
		}



		glTranslatef(x[i] * -1, y[i] * -1, z[i] * -1);// volta para a origem		
	}

	//Objeto selecionado
	glColor3f(0.2, 0.2, 0.2);//cor preto
	glTranslatef(x[indexObj], y[indexObj], z[indexObj]);

	if (ObjectList[indexObj] == 0) glutWireCube(20 + dimensao[indexObj]);
	else if (ObjectList[indexObj] == 1) glutWireSphere(20 + dimensao[indexObj], 24, 24);
	else if (ObjectList[indexObj] == 2) glutWireCone(20 + dimensao[indexObj], 20 + dimensao[indexObj], 24, 24);
	else if (ObjectList[indexObj] == 3) glutWireCylinder(20 + dimensao[indexObj], 20 + dimensao[indexObj], 24, 24);
	else if (ObjectList[indexObj] == 4) glutWireTorus(1 + dimensao[indexObj], 10 + dimensao[indexObj], 24, 24);
	else if (ObjectList[indexObj] == 5) glutWireTeapot(20 + dimensao[indexObj]);

	glTranslatef(x[indexObj] * -1, y[indexObj] * -1, z[indexObj] * -1);// volta para a origem



	glPopMatrix();
	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void initGL(void)
{
	angleV = 45;

	//aqui seu código de inicialização
}

// Função usada para especificar o volume de visualização
void setVisParam(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();
	// Especifica a projeção perspectiva
	gluPerspective(angleV, fAspect, 0.1, 500);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
}

// Função callback chamada quando o tamanho da janela é alterado 
void reshape(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if (h == 0) h = 1;
	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);
	// Calcula a correção de aspecto
	fAspect = (GLfloat)w / (GLfloat)h;
	setVisParam();
}

// Função callback chamada para gerenciar eventos do mouse
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angleV >= 10) angleV -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angleV <= 130) angleV += 5;
		}
	setVisParam();
	glutPostRedisplay();  // redraw
}
// Keyboard ...
void processKeys(unsigned char key, int xx, int yy) {
	if (r[indexObj] > 1 || r[indexObj] < 0.0)		somaR *= -1;
	if (g[indexObj] > 1 || g[indexObj] < 0.0)		somaG *= -1;
	if (b[indexObj] > 1 || b[indexObj] < 0.0)		somaB *= -1;
	switch (toupper(key)) {
	case 'D':
		x[indexObj]++;
		break;
	case 'A':
		x[indexObj]--;
		break;
	case 'W':
		y[indexObj]++;
		break;
	case 'S':
		y[indexObj]--;
		break;
	case 'Q':
		z[indexObj]++;
		break;
	case 'E':
		z[indexObj]--;
		break;
	case 'X':
		dimensao[indexObj] ++;
		break;
	case 'C':
		dimensao[indexObj] --;
		break;
	case 'J':
		solid[indexObj] = 0;
		break;
	case 'K':
		solid[indexObj] = 1;
		break;
	case 'R':
		r[indexObj] += somaR;
		cout << "R: " << r[indexObj] << " G: " << g[indexObj] << " B: " << b[indexObj] << endl;
		break;
	case 'G':
		g[indexObj] += somaG;
		cout << "R: " << r[indexObj] << " G: " << g[indexObj] << " B: " << b[indexObj] << endl;
		break;
	case 'B':
		b[indexObj] += somaB;
		cout << "R: " << r[indexObj] << " G: " << g[indexObj] << " B: " << b[indexObj] << endl;
		break;
	}

	setVisParam();
	glutPostRedisplay();
}

void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT:
		angle1--;
		break;
	case GLUT_KEY_RIGHT:
		angle1++;
		break;
	case GLUT_KEY_UP:
		angle--;
		break;
	case GLUT_KEY_DOWN:
		angle++;
		break;
	case GLUT_KEY_F1:
		indexObj += indexSoma;
		cout << "Index do objeto selecionado: " << indexObj << endl;
		break;
	}

	if (indexObj >= (numObjects - 1) || indexObj <= 0)
		indexSoma *= -1;

	setVisParam();
	glutPostRedisplay();   // redraw
}

// Programa Principal
int main(int argc, char** argv) {

	DisplayFileRead("df.txt");              // se estiver aqui, lê somente uma vez
	cout << "Setas - rotaciona a cena" << endl;
	cout << "Mouse Click - zoom" << endl;
	cout << "F1 para selecionar o objeto, por parametro começa no zero" << endl;
	cout << "W S para movimentar o objeto em y, A D para movimentar o objeto em x, Q E  para movimentar o objeto em z" << endl;
	cout << "J K para alternar entre solido e não solido" << endl;
	cout << "X C para aumentar e diminuir o objeto" << endl;
	cout << "R G B para alterar os parametros de cor" << endl;
	glutInit(&argc, argv);					// Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE);		// Enable double buffered mode
	glutInitWindowSize(640, 480);			// Set the window's initial width & height
	glutInitWindowPosition(50, 50);			// Position the window's initial top-left corner
	glutCreateWindow(title);				// Create window with the given title
	glutDisplayFunc(render);				// Regster callback for render function
	glutSpecialFunc(processSpecialKeys);	// Register callback handler for arrow keys (keyborad)
	glutKeyboardFunc(processKeys);			// Registre teclas nao especiais
	glutReshapeFunc(reshape);				// Register callback for window resize event
	glutMouseFunc(mouse);					// Register callback for mouse event
											//	glutIdleFunc(render);					// no animation
	initGL();								// Initialization function
	glutMainLoop();							// event loop
	return 0;
}