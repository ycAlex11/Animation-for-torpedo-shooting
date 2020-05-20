#include <GL/glut.h>
#include "assignment.h"
#include <stdio.h>
#include <math.h>


void createObject(void)
{
	//create two simple objects one for mountain(solidCone) and another one are stones
	glPushMatrix();
	glColor4f(0.545, 0.271, 0.075,0.5f);
	glTranslatef(-15.0,-25.0,2.0);
	glScalef(0.8,0.7,0.5);
	glutSolidSphere(5.0f, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(15.0,-25.0,2.0);
	glScalef(0.8,0.7,0.5);
	glutSolidSphere(5.0f, 10, 10);
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4.0,-25.0,-2.0);
	glRotatef(270.0, 1.0, 0.0, 0.0);
	glutSolidCone(5.0,10,70,12);
	glPopMatrix();

}

void drawSubmarine(void)
{
	
	
	glPushMatrix();
	glTranslatef(0,0,0);
	//draw the body
	glPushMatrix();
	
	glColor3f(0.184, 0.310, 0.310);
	glScalef(0.25,0.25,0.75);
	glutSolidSphere(height/4,12,12);
	glPopMatrix();
	
	//commanding tower
	glPushMatrix();
	glTranslatef(0,2,0.95);
	glScalef(0.25,0.75,0.5);
	glutSolidSphere(height/15,10,10);
	glPopMatrix();
	
	//propeller
	glPushMatrix();
	glTranslatef(0,0,-6);
	glScalef(0.5,0.5,0.5);
	glRotatef(90,0,1,0);

	glutSolidCone(height/30, height/5,10,10);
	glRotatef(90,1,0,0);
	
	glutSolidCone(height/30,height/5,10,10);
	glRotatef(90,1,0,0);
	
	glutSolidCone(height/30,height/5,10,10);
	glRotatef(90,1,0,0);
	
	glutSolidCone(height/30,height/5,10,10);
	
	glPopMatrix();
	//periscope
	glPushMatrix();
	glTranslatef(0,3,-1.85);
	glRotatef(90,5,0,0);
	glutSolidSphere(height/42,4,5);
	gluCylinder(gluNewQuadric(), height/120, height/120, height/15, 5, 5);
	glPopMatrix();

	glPopMatrix();
	

}
void drawFish(void)
{
	 
	
	

    glPushMatrix();
	
    glTranslatef(0,0,0);
	

    glPushMatrix();
    glPushMatrix();
    //head
    glTranslatef(1.8, 0, 0.1);
    glRotatef(-270, 0, 1, 0);
    glColor3f(0.980, 0.502, 0.447);	
    glutSolidCone(radius/2, 2*height2/5, 5, 1);
    glPopMatrix();

    // body
    glRotatef(180 -270, 0, 1, 0);
    glutSolidCone(radius/4, height2/2, 5, 1);
    glPushMatrix();
    glTranslatef(0, 0, 0.1);
    glRotatef(135, 0, 2, 0);
    glutSolidCone(radius/6, 2*height2/7, 5, 1);
    glPopMatrix();

    //tail
    glTranslatef(0, 0, height2/2);
    glRotatef(180 + 30, 0, 1, 0);
    glTranslatef(-0.5, 0, -height2/5);
    glScalef(0.5, 1, 1);
    glutSolidCone(radius/2, height2/5, 5, 1);
    glPopMatrix();
	
    //eyes
    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(3.5, 0, -1.5);	
    glutSolidSphere(1.0f, 10, 10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5, 0, 1.5);	
    glutSolidSphere(1.0f, 10, 10);
    glPopMatrix();

    glPopMatrix();
	
}
//This is for the torpedo head
void drawHemisphere(float radius, int longSlices, int latSlices)
{
   int  i, j;
   for(j = 0; j < latSlices; j++)
   {
      // one latitudinal triangle strip.
      glBegin(GL_TRIANGLE_STRIP);
      for(i = 0; i <= longSlices; i++)
      {
         glVertex3f( radius * cos( (float)(j+1)/latSlices * PI/2.0 ) * cos( 2.0 * (float)i/longSlices * PI ),
                     radius * sin( (float)(j+1)/latSlices * PI/2.0 ),
					 radius * cos( (float)(j+1)/latSlices * PI/2.0 ) * sin( 2.0 * (float)i/longSlices * PI ) );
         glVertex3f( radius * cos( (float)j/latSlices * PI/2.0 ) * cos( 2.0 * (float)i/longSlices * PI ),
                     radius * sin( (float)j/latSlices * PI/2.0 ),
					 radius * cos( (float)j/latSlices * PI/2.0 ) * sin( 2.0 * (float)i/longSlices * PI ) );         
	  }
      glEnd();
   }
}
void drawTorpedo(void)
{
     
   glPushMatrix(); 
   

   glColor3f(0.753, 0.753, 0.753);
   

   glRotatef(270, 0.0, 1.0, 0.0);
 
  

   // initialize quadric.
   gluQuadricDrawStyle(gluNewQuadric(), GLU_FILL);  

   // the body quadric.
   
   gluCylinder(gluNewQuadric(), 0.5, 0.5, 4.0, 15, 15);

   glPushMatrix(); 

   glTranslatef(0.0, 0.0, 4.0);
   glRotatef(90.0, 1.0, 0.0, 0.0);
   glScaled(1.1, 1.1, 1.1);
   drawHemisphere(0.5, 10, 10);
   glPopMatrix();

   // Propeller stem.
   glPushMatrix();
   glScaled(1.65, 1.65, 1.65);
   glTranslatef(0.0, 0.0, -0.5);
   gluCylinder(gluNewQuadric(), 0.2, 0.2, 0.5, 5, 5); 
   glPopMatrix();
   glPopMatrix();
}

void display(void)
{
	glClearColor(0.1f,0.1f,0.55f,0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 1.0f, -50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glScalef(zoom,zoom,zoom);

	
	//glTranslatef(0.0f,0.0f,-2.0f);
	rotation();
	if(xRotation == true)
	{
		xrot -= .1;
		
	}
	if(yRotation == true)
	{
		yrot += .1;
	}
	if(animationEnabled == true)
	{
		//fish Animation
		if(direction == 0)
		{
		  fishMove = fishMove - (.01 * animationSpeed);
		}
		if(direction == 1)
		{
			fishMove = fishMove + (.01 * animationSpeed);
		}
		if(fishMove < -15)
		{
			direction = 1;
		}
		if(fishMove > 15)
		{
			direction = 0;
		}


		//torpedo Animation
		if(direction == 0)
		{
			troMove = troMove - (.2 * animationSpeed);
		}
		

		
		//Submarine Animation
		if(subDire == 0)
		{
			subMove = subMove - (.03 * animationSpeed);
		}
		if(subDire == 1)
		{
			subMove = subMove + (.03 * animationSpeed);
		}
		if(subMove < -4)
		{
			subDire = 1;
		}
		if(subMove > 4)
		{
			subDire = 0;
		}
		//Aim Animation
		if(aimDire ==0)
		{
			aimMove = aimMove -(0.008*animationSpeed);		
		}
		if(aimDire ==1)
		{
			aimMove = aimMove +(0.008*animationSpeed);		
		}
		if(aimMove < -2)
		{
			aimDire = 1;
		}
		if(aimMove > 2)
		{
			aimDire = 0;
		}





	}
	//show submarine on window
	glPushMatrix();
	glTranslatef(40.0,3.0,5.0);
	glRotatef(270,0,1,0);
	glRotatef(subMove,1,1,-5);
	glTranslatef(subMove,subMove,5.0);
	drawSubmarine();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35.0,-8.0,5.0);
	glRotatef(270,0,1,0);
	glRotatef(-subMove,1,1,5);
	glTranslatef(-subMove,-subMove,5.0);
	drawSubmarine();
	glPopMatrix();
	//show torpedo on window
	glPushMatrix();
	glTranslatef(32.0,-9.0,3.0);
	glRotatef(0,1,3,0);
	glTranslatef(troMove,0,0);
	glScalef(1.4,1.4,1.4);
	drawTorpedo();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(36.0,2.0,3.0);
	glTranslatef(troMove,0,0);
	glScalef(1.4,1.4,1.4);
	drawTorpedo();
	glPopMatrix();
	
	//show all fishs
	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glRotatef(180,0,1,0);
	glRotatef(8*fishMove,1,3,0);
	glTranslatef(-fishMove,-fishMove,0);
	glScalef(0.4,0.4,0.4);
	drawFish();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(4.0,2.0,0.0);
	glRotatef(0,0,1,0);
	glRotatef(-10*fishMove,1,3,0);
	glTranslatef(-fishMove,-fishMove,0);
	glScalef(0.4,0.4,0.4);
	drawFish();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.0,-2.0,2);
	glRotatef(0,0,1,0);
	glRotatef(7*fishMove,1,3,0);
	glTranslatef(-fishMove,fishMove,0);
	glScalef(0.4,0.4,0.4);
	drawFish();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-3.0,-3.0,0.0);
	glRotatef(180,0,1,0);
	glRotatef(10*fishMove,1,3,0);
	glTranslatef(-fishMove,fishMove,0);
	glScalef(0.4,0.4,0.4);
	drawFish();
	glPopMatrix();
	
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glTranslatef(-25.0f,0.0f,0.0f);
	glTranslatef(0,aimMove,0);
	glScalef(2.5,2.5,2.5);
	glutSolidIcosahedron();
	glPopMatrix();
	
	init();
	createObject();

	glutSwapBuffers();
	
	

}


void rotation (void) 
{
    //rotate on x axis
    glRotatef(xrot,1.0,0.0,0.0); 
    //rotate on y axis 
    glRotatef(yrot,0.0,1.0,0.0);  
}
// resizing of the window.
void reshape(int width,int height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(GLfloat)width/(GLfloat)height,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
	
}

// user input received from the keyboard.
void keyPressed (unsigned char key, int x, int y) 
{  

	switch(key)
	{
	//rotate clockwise around x if 'x' or 'X' are pressed
	case 'x':
	case 'X':
		if(xRotation == false)
		{
			xRotation = true;
		}
		else
		{
			xRotation = false;
		}
		break;
	//rotate clockwise around y if 'y' or 'Y' are pressed
	case 'y':
	case 'Y':
		if(yRotation == false)
		{
			yRotation = true;
		}
		else
		{
			yRotation = false;
		}
		break;
	case 'Z':
		if(zoom < 1.5f)
		{		
			zoom += 0.1f;
		}
		break;
	//zoom out, done by scaling scene down 
	case 'z':
		if(zoom >= 0.4f)
		{
			zoom -= 0.1f;
		}
		break;

        case 'A': // start the animation
        case 'a':
            animationEnabled = true;
            break;

        case 'F': // speed up animation
        case 'f':
            animationSpeed *= 1.5;
            break;
            
        case 'S': // slow down animation
        case 's':
            animationSpeed *= 0.9;
            break;
        
        case 'T': // pause the animation
        case 't':
            animationEnabled = false;
            break;

        case 'C': // resume the animation
        case 'c':
            animationEnabled = true;
            break;
        
        case 'p': // render with flat shading
            glShadeModel(GL_FLAT);
            break;
            
        case 'P': // render with smooth shading
            glShadeModel(GL_SMOOTH);
            break;


	}
}  


void init(void)
{
    //  light properties
    GLfloat light_position0[] = {1.0, 5.0, 1.0, 0.0};
    GLfloat light_position1[] = {0.0, -10.0, 0, 0.0};
    GLfloat white[] = {1.0, 1.0, 1.0};
    GLfloat black[] = {0.0, 0.0, 0.0};
    GLfloat golden[]={0.855, 0.647, 0.125};
    GLfloat ivory[]={1.000, 1.000, 0.941};
    // set the position of the lights
    glLightfv(GL_LIGHT0, GL_POSITION,light_position0);
      // Enable depth testing 
    glEnable(GL_DEPTH_TEST);
    

    // enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
   
    glEnable(GL_COLOR_MATERIAL);

    // Set the properties of light 0
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);

    // Set the properties of light 1
    glLightfv(GL_LIGHT1, GL_POSITION,light_position1);
     glEnable(GL_LIGHT1);
      glLightfv(GL_LIGHT1, GL_SPECULAR, golden);
      glLightfv(GL_LIGHT1, GL_AMBIENT, black);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, ivory);

}
//shows all the keys on Terminal 
void outputKey(void)
{
	printf("click Z to zoom in and z to zoom out\n");
	printf("click X or x rotate(stop) about x axis\n");
	printf("click Y or y rotate(stop) about y axis\n");
	printf("click A or a starts animation\n");
	printf("click F or f increases the speed of animation\n");
	printf("click S or s decreases the speed of animation\n");
	printf("click T or t pauses the animation\n");
	printf("click C or c continues the animation\n");
	printf("click p-Flat shading and P-Smooth shading\n" );

}

int main(int argc,char** argv)
{
	// initialise GLUT
	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_SINGLE);
	
	//set up the windows size and position
	glutInitWindowSize(800,400);
	glutInitWindowPosition(100,100);

	glutCreateWindow("Assignment");
	 // set up the functions
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	outputKey();
	glutMainLoop();
	

}
