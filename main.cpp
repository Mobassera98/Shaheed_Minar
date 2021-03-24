#include<windows.h>
#include<GL/glut.h>
#include <stdio.h>
#include <time.h>
#include<bits/stdc++.h>
#include <stdlib.h>

double view[3]={2,2,12.9};  //eye x,y,z
double look[3]={2,2,10};    //center x,t,z
int mgo=0;
int lt=0;
GLUquadricObj *Cylinder;



void drawBall(void) {

    //Add ambient light
	//sh that shines everywhere in our scene by the same amount
	//every face gets the same amount
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	// 0 because direced light source
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);


        glColor3f(3.0,1.5,1.0); //set ball colour
        glTranslated(2,7.6,5);//move:x,y,z
        //moving it toward the screen a bit on creation
        glutSolidSphere (0.25, 35, 35); //create ball.

}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	//you can have upto 8 lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}

void myinit(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0,1.0,-1*1366/768,1*1366/768,1,200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    Cylinder = gluNewQuadric();
}


void wall(double thickness)
{
	glPushMatrix();
	glTranslated(2,.5*thickness,2);
	glScaled(4.0,thickness,4.0);
	glutSolidCube(1.0);
	glPopMatrix();
}


void floor(void){
    glColor3d(0.8,0.1,0);
	glPushMatrix();
	glTranslated(-1*3,-0.05,-.01*4);
	glScaled(2.6+.01,2,1);
	wall(0.08);
	glPopMatrix();

	}

void piller(void){

    //left 1 -r
    glColor3d(1,1,1);
    glPushMatrix();
	glTranslated(0.5,0,1);//move:x,y,z
	glScaled(0.02+.02,0.7,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

    //pipe_1
	glColor3d(0,0,0);
    glPushMatrix();
	glTranslated(0.23,0,1);//move:x,y,z
	glScaled(0.006,0.65,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();
    //pipe_2
	glPushMatrix();
	glTranslated(0.383,0,1);//move:x,y,z
	glScaled(0.006,0.65,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();


	glPushMatrix();
    glColor3d(1,1,1);
	glTranslated(0.0,0,1);//move:x,y,z
	glScaled(0.02+.02,0.7,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

    glPushMatrix();
	glTranslated(0,2.6,1);//move:x,y,z
	glScaled(.16,.05,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

 //left 2
    glPushMatrix();
	glTranslated(0.9,0,1);//move:x,y,z
	glScaled(0.02+.02,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	  //pipe_1

    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(1.20,0,1);//move:x,y,z
	glScaled(0.006,0.93,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();
	  //pipe_2

    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(1.37,0,1);//move:x,y,z
	glScaled(0.006,0.93,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

    //r
    glPushMatrix();
    glColor3d(1,1,1);
	glTranslated(1.5,0,1);//move:x,y,z
	glScaled(0.02+.02,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

    //t
	glPushMatrix();
	glTranslated(0.9,3.78,1);//move:x,y,z
	glScaled(.16,.05,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

//right big
    glPushMatrix();
	glTranslated(3.5,0,1);//move:x,y,z
	glScaled(0.02+.02,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe_1
    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(3.750,0,1);//move:x,y,z
	glScaled(0.006,0.93,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe_1
    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(3.950,0,1);//move:x,y,z
	glScaled(0.006,0.93,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

    glPushMatrix();
    glColor3d(1,1,1);
	glTranslated(4.1,0,1);//move:x,y,z
	glScaled(0.02+.02,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.5,3.78,1);//move:x,y,z
	glScaled(.16,.05,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

//right small

//left
    glPushMatrix();
	glTranslated(4.5,0,1);//move:x,y,z
	glScaled(0.02+.02,0.7,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe_1
	glColor3d(0,0,0);
    glPushMatrix();
	glTranslated(4.76,0,1);//move:x,y,z
	glScaled(0.006,0.65,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe_2
	glColor3d(0,0,0);
    glPushMatrix();
	glTranslated(4.94,0,1);//move:x,y,z
	glScaled(0.006,0.65,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();


	glPushMatrix();
	glColor3d(1,1,1);
	glTranslated(5.1,0,1);//move:x,y,z
	glScaled(0.02+.02,0.7,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	glPushMatrix();
	glTranslated(4.5,2.6,1);//move:x,y,z
	glScaled(.16,.05,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();



//main bllock wall
    //uppersite
    glPushMatrix();
	glTranslated(1.9,5.6,1.4);//move:x,y,z
	glScaled(0.34,0.02+.02,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();
//uppersite
	glPushMatrix();
	glTranslated(1.9,5.6,1.4101);//move:x,y,z
	glScaled(0.34,0.02+.02,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();



//main left
    //l
	glPushMatrix();
	glTranslated(1.9,0,1);//move:x,y,z
	glScaled(0.02+.02,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe_1
    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(2.190,0,1);//move:x,y,z
	glScaled(0.006,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe_2
    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(2.360,0,1);//move:x,y,z
	glScaled(0.006,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

// pipe up 1
	glPushMatrix();
	glColor3d(0,0,0);
	glTranslated(2.360,4,1);//move:x,y,z
	glScaled(0.006,0.4,2);//size:x,y,z
	glRotated(-87,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

// pipe up 2
	glPushMatrix();
	glColor3d(0,0,0);
	glTranslated(2.190,4,1);//move:x,y,z
	glScaled(0.006,0.4,2);//size:x,y,z
	glRotated(-87,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	glPushMatrix();
	glColor3d(1,1,1);
	glTranslated(1.9,4,1);//move:x,y,z
	glScaled(0.02+.02,0.4,2);//size:x,y,z
	glRotated(-87,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

    //main mid
	glPushMatrix();
	glTranslated(2.5,0,1);//move:x,y,z
	glScaled(0.02+.02,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe horogonter
    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(2.07,3.28,1);//move:x,y,z
	glScaled(0.11,.009,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(2.67,3.28,1);//move:x,y,z
	glScaled(0.11,.009,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe_3
    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(2.76,0,1);//move:x,y,z
	glScaled(0.006,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();
	//pipe_4
    glPushMatrix();
    glColor3d(0,0,0);
	glTranslated(3,0,1);//move:x,y,z
	glScaled(0.006,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//pipe up 3
	glPushMatrix();
	glColor3d(0,0,0);
	glTranslated(2.76,4,1);//move:x,y,z
	glScaled(0.006,0.4,2);//size:x,y,z
	glRotated(-87,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

//pipe up 4
	glPushMatrix();
	glColor3d(0,0,0);
	glTranslated(3,4,1);//move:x,y,z
	glScaled(0.006,0.4,2);//size:x,y,z
	glRotated(-87,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	glPushMatrix();
	glColor3d(1,1,1);
	glTranslated(2.5,4,1);//move:x,y,z
	glScaled(0.02+.02,0.4,2);//size:x,y,z
	glRotated(-87,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	//right
	glPushMatrix();
	glTranslated(3.1,0,1);//move:x,y,z
	glScaled(0.02+.02,1,2);//size:x,y,z
	glRotated(-90,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.1,4,1);//move:x,y,z
	glScaled(0.02+.02,0.4,2);//size:x,y,z
	glRotated(-87,60,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

}

void gate(void){
    int i;
	glPushMatrix();
	// main gate
	if(mgo==1){

    glTranslated(1.5,0,0);
    	}

	glTranslated(-1.3,0,6);

	//top frame gate
	glColor3d(1,1,0);
	glPushMatrix();
	glTranslated(4,1.5,0);
	glScaled(1.7,.04,.04);
	glutSolidCube(1);
	glPopMatrix();
	//bottom fram gate
	glPushMatrix();
	glTranslated(4,.05,0);
	glScaled(1.7,.04,.04);
	glutSolidCube(1);
	glPopMatrix();
	//left frame gate
	glPushMatrix();
	glTranslated(3.16,.75,0);
	glScaled(.04,1.5,.04);
	glutSolidCube(1);
	glPopMatrix();
	//right frame gate
	glPushMatrix();
	glTranslated(4.8,.75,0);
	glScaled(.04,1.5,.04);
	glutSolidCube(1);
	glPopMatrix();
	//horizantal pipes gate
	for(i=1;i<=3;i++)
	{
    glColor3d(1,1,0);
	glPushMatrix();
	glTranslated(3.16,.4*i,0);
	glRotated(90,0,1,0);
	gluCylinder(Cylinder,.02,.02,1.7,32,32);
	glPopMatrix();
	}
	//vertical strips gate
	for(i=1;i<=5;i++)
	{
    glColor3d(1,0,0);
	glPushMatrix();
	glTranslated(3.1+.3*i,.75,0);
	glScaled(.2,1.5,.02);
	glutSolidCube(1);
	glPopMatrix();
	}


	glPopMatrix();

}

void wall(void) {
//left wall

    glColor3d(1,1,1);
    glPushMatrix();
	glTranslated(-3,0,0);//move:x,y,z
	glScaled(11+.02,.3,1.5);//size:x,y,z
	glRotated(90.0,0,0,1);
	wall(.02);//wall thikness
	glPopMatrix();

    glColor3d(1,1,1);
//right wall
	glPushMatrix();
	glTranslated(7.4,0,0);//move:x,y,z
	glScaled(11+.02,.3,1.5);//size:x,y,z
	glRotated(90.0,0,0,1);
	wall(.02);//wall thikness
	glPopMatrix();


    glColor3d(0.4,0.2,1);
//back wall
    glPushMatrix();
	glTranslated(-3,0,0);//move:x,y,z
	glScaled(2.6,0.3,1.9);
	glRotated(-90,1,0,0);
	wall(.02);//wall thikness
	glPopMatrix();


//font left wall of compound
glColor3d(1,1,1);
    glPushMatrix();
	glTranslated(-3,0,6);//move:x,y,z
	glScaled(1.22,0.1,1.8);
	glRotated(-90,1,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

	glColor3d(1,1,1);
//font Right wall of compound
    glPushMatrix();
	glTranslated(3.5,0,6);//move:x,y,z
	glScaled(1.0,0.1,1.8);
	glRotated(-90,1,0,0);
	wall(.02);//wall thikness
	glPopMatrix();

}

void circle(void)
{

    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(2.7,2.1,0.1);
    glScaled(1.5,1.5,0.01);
    glutSolidSphere(1,50,50);//redius,slice,stack
    glPopMatrix();
}


void Keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{

	//to open and close main gate
	case 'g':
	case 'G':
				if(mgo==0)
				  mgo=1;
				else
					mgo=0;
	break;

	//Light on off

	case 'e':
	case 'E':
            glEnable(GL_LIGHT0);
            glEnable(GL_LIGHT1);
            break;
    case 'd':
    case 'D':
            glDisable(GL_LIGHT0);
            glDisable(GL_LIGHT1);
            break;

    // Close View
	case 'c':
	case 'C':
				view[0]=2.8;
				view[1]=2;
				view[2]=4.8;
				look[0]=2.8;
				look[1]=2;
				look[2]=1;
	break;

//front view
	case 'f':
	case 'F':
				view[0]=2;
				view[1]=2;
				view[2]=12.9;
				look[0]=2;  //move x +-
				look[1]=2;   //move Y +-
				look[2]=3;
	break;
	//back view
	case 'b':
	case 'B':
				view[0]=1;
				view[1]=6;
				view[2]=-7;
				look[0]=2;
				look[1]=4;
				look[2]=2;
	break;

	case 27: //Escape key
            exit(0);
        default:
            break;
	}

}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:


				view[2]-=.1;
				glutPostRedisplay();
				break;


         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
                view[2]+=.1;
				glutPostRedisplay();
				break;

      default:
         break;
   }
}


void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	gluLookAt(view[0],view[1],view[2],look[0],look[1],look[2],0,1.0,0.0);
    floor();
//drawing the SUN
    glPushMatrix();
        drawBall();
    glPopMatrix();

	wall();
	piller();
	circle();
	gate();
	glFlush();
	glutSwapBuffers();// swap double buffer
	glutPostRedisplay();//Mark the normal plane of current window as needing to be redisplayed.
}
int main(int argc,char**argv)
{
    printf("**<<Press G for Gate on & off>>**\n");
    printf("**<<Press C for Close view >>**\n");
    printf("**<<Press B for back view  >> **\n");
    printf("**<<Press F for Front view >>**\n");
    printf("**<<Press E for Light On >>**\n");
    printf("**<<Press D for Light Off >>**\n");
    printf("**<<Click Mouse Left and Middle for Zoom Extend >>**\n");
    printf("**<<Click Mouse Right for Zoom Decrease >>**\n");

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1366,768);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Shaheed Minar");
	myinit();
	glutDisplayFunc(display);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(my_mouse);
	glShadeModel(GL_SMOOTH);//smooth shaded
	glClearColor(0,.4,.88,0);  //display background colour
    glEnable(GL_CULL_FACE); //view from 3 side.
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);  //deft view for show object
    glDepthFunc(GL_LESS);   //compare each incoming pixel depth value with the depth value presen
    initRendering();
    glEnable(GL_COLOR_MATERIAL);
    glutMainLoop();
	return 0;
}
