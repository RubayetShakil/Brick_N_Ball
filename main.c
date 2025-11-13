
#include <stdio.h>
#include <GL/glut.h>
#include <stdbool.h>

double x=100.0;
double y=-790.0;
double ball_speed=0.1;
bool started=false;
double ball_x=0.0;
double ball_y=-790.0;
double dx=1;
double dy=1;
int restart_counter=0;
bool restart=false;
bool brick[16][16];
double brick_x[16][16];
double brick_y[16][16];

void draw_shapes(double x, double y){
  
  glBegin(GL_QUADS);
  
  glColor3f(1,1,1);
  glVertex2d(x,y);
  glColor3f(1,1,1);
  glVertex2d(x-200.0,y);
  glColor3f(1,1,1);
  glVertex2d(x-200.0, y-10);
  glColor3f(1,1,1);
  glVertex2d(x, y-10);

  glEnd();

  glPointSize(10);
  glBegin(GL_POINTS);
  
  glColor3f(0.3,0.4,0.5);
  glVertex2d(ball_x, ball_y);
  
  glEnd();

  int i,j;
  
  for (i=0; i<16; i++){
    for (j=0; j<16; j++){
      
      if (!brick[i][j]) continue;
      
      glBegin(GL_QUADS);
      glColor3f(0.5,0.1,0);
      glVertex2d(brick_x[i][j],brick_y[i][j]);
      glColor3f(0.1,0.9,0.2);
      glVertex2d(brick_x[i][j]+100,brick_y[i][j]);
      glColor3f(0,0.3,1);
      glVertex2d(brick_x[i][j]+100, brick_y[i][j]-40);
      glColor3f(1,1,1);
      glVertex2d(brick_x[i][j], brick_y[i][j]-40);
      glEnd();
    }
  }
  
  
  
}

void special_key_listener(int key, int k, int l){

  if (!started){
    
    switch(key){
      
    case GLUT_KEY_LEFT:
      dx=dx*-1;
      started=true;
      break;

    case GLUT_KEY_RIGHT:
      started=true;
      break;
    }
    glClearColor(0,0,0,1);
      
    
  }else{
    
    switch(key){

    case GLUT_KEY_LEFT:
      if (x-200>-800) x-=40;
      break;

    case GLUT_KEY_RIGHT:
      if (x<800) x+=40;
      break;

    }
  }
  glutPostRedisplay();
}
  

void setup_projection(){
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-800,800,-800,800);
  glMatrixMode(GL_MODELVIEW);
}
  
void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  draw_shapes(x,y);
  
  glutSwapBuffers();
}

void animate(){
  
  if (!started && !restart){
    ball_x=x-100;
    ball_y=y+15;

  }else if (restart){
   
    restart_counter++;
    glClearColor(1,1,1,1);
    
    if (restart_counter >=300){
      printf("GAME OVER MATE!!!!!!!!!!!");
      restart=false;
      started=false;
      restart_counter=0;
      dx=1;
      dy=1;
      ball_speed=0.1;
    }
  }else{

    ball_x+=dx*ball_speed;
    ball_y+=dy*ball_speed;

    if (ball_x>790.0 || ball_x<-790.0){
      dx*=-1;
    }
    if (ball_y<-820.0) restart=true;
    }

  int i,j;
  
  for (i=0; i<16; i++){
    for (j=0; j<16; j++){
      
      if (!brick[i][j]) continue;
      
      if (ball_x>brick_x[i][j] && ball_x<brick_x[i][j]+100 && ball_y<brick_y[i][j] && ball_y>brick_y[i][j]-40){
	
	brick[i][j]=false;
	dy*=-1;
      }
	
    }
  }
  
  if (ball_x>=x-200 && ball_x<=x && ball_y+dy*ball_speed<=y+5 && ball_y+dy*ball_speed>=y-15){
    dy*=-1;
  }
    
  glutPostRedisplay();
}


int main(int argc, char ** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("BrICK_N_BALL>>Let's go!!!!!");
  setup_projection();

  int i,j;
  for (i=0; i<16; i++){
    for (j=0; j<16; j++){
      brick[i][j]=true;
      brick_x[i][j]=-800+i*110;
      brick_y[i][j]=800-j*50;
    }
  }

  glutDisplayFunc(display);
  glutIdleFunc(animate);
  glutSpecialFunc(special_key_listener);
  

  glutMainLoop();
} 



  
