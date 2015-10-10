#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define outcode int 
#define BLACK 0
#define maxx 25
#define maxy 25
#define dx 15
#define dy 10
#define true 1
#define false 0

int f=0,f2=0;
double xz,yz,xo,yo;

//Functions for input through mouse
void OnClick1(int button, int state, int x, int y)
{
     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
     {
                  xo=(double)((x*5510)/10000);
                  yo=(double)(600-y);
     } 
}
int d[1000],c[1000];
void OnClick2(int button, int state, int x, int y)
{
     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
     {
                 d[f]=(double)((x*5510)/10000);
                 c[f]=(double)(600-y);
                 f++;
     }
}
int d1[1000],c1[1000];
void OnClick3(int button, int state, int x, int y)
{
     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
     {
                 d1[f2]=(double)((x*5510)/10000);
                 c1[f2]=(double)(600-y);
                 f2++;
     }
}
void Write(char *string)
{
    while(*string)
    {
                   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    }
}
//Exit screen
void display11(void)
{     
      glClear(GL_COLOR_BUFFER_BIT);
    char *p2="  THANK YOU  ";
    int k;
    glColor3f(1,0,0);
    glRasterPos2f(-0.2,0.1);     
    for(k=0;k<=strlen(p2);k++)
    {
         glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,p2[k]);    
      } 
      glFlush();
      int i=0;
      while(i<199999999)
      i++;  
      exit(0);
}
////////////////////////////////////////////////1.Tetrahedron///////////////////////////////////////////////////////
GLfloat v[4][3]={{0.0,0.0,1.0},{0.0,0.9,-0.3},{-0.8,-0.4,-0.3},{0.8,-0.4,-0.3}};
GLfloat colors1[4][3]={{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.0,0.0,0.0}};
int n,i,l,f1=0,j=0;
void triangle(GLfloat *va,GLfloat *vb,GLfloat *vc)
{
    glBegin(GL_TRIANGLES);
    glNormal3fv(va);
  glVertex3fv(va);
  glVertex3fv(vb);
  glVertex3fv(vc);
    glEnd();
    glutPostRedisplay();
//  glFlush();
}
void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{
  glColor3fv(colors1[0]);
  triangle(a,b,c);
  glColor3fv(colors1[1]);
  triangle(a,c,d);
  glColor3fv(colors1[2]);
  triangle(a,d,b);
  glColor3fv(colors1[3]);
  triangle(b,d,c);
//  glutPostRedisplay();
  glFlush();  //For Animation (keeps refreshing and drawing) else everything is working well
}
void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m)
{
  GLfloat mid[6][3];
  int j;
  if(m>0)
  {
    for(j=0;j<3;j++) mid[0][j]=(a[j]+b[j])/2;
    for(j=0;j<3;j++) mid[1][j]=(a[j]+c[j])/2;
    for(j=0;j<3;j++) mid[2][j]=(a[j]+d[j])/2;
    for(j=0;j<3;j++) mid[3][j]=(b[j]+d[j])/2;
    for(j=0;j<3;j++) mid[4][j]=(d[j]+c[j])/2;
    for(j=0;j<3;j++) mid[5][j]=(b[j]+c[j])/2;

    divide_tetra(a,mid[0],mid[1],mid[2],m-1);
    divide_tetra(mid[0],b,mid[3],mid[5],m-1);
    divide_tetra(mid[1],mid[4],c,mid[5],m-1);
    divide_tetra(mid[2],mid[3],mid[4],d,m-1);
  }
  else
    tetra(a,b,c,d);
}
void Refresh()
{
     glutPostRedisplay();
     glFlush();
}
void display2()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
    glRasterPos2f(-1.73,1.57);
  Write("Choose no. of divisions : -");
  glRasterPos2f(-1.73,1.37);
  Write("1) One division");
  glRasterPos2f(-1.73,1.17);
  Write("2) Two divisions");
  glRasterPos2f(-1.73,0.97);
  Write("3) Three divisions");
  glRasterPos2f(-1.73,0.77);
  Write("4) Four divisions");
  glRasterPos2f(-1.73,0.57);
  Write("5) Five divisions");
  glRasterPos2f(-1.73,0.37);
  Write("6) Six divisions");
  glColor3f(0.0,0.0,1.0);
  glRasterPos2f(-1.53,-1.37);
  Write("Refresh");
  glColor3f(0.0,0.0,1.0);
  glRasterPos2f(-0.73,-1.37);
  Write("Close");
  glutMouseFunc(OnClick1);
    n=3;
    if(xo>25&&xo<107&&yo>507&&yo<523)
         n=1;
    if(xo>25&&xo<115&&yo>477&&yo<491)
         n=2;
    if(xo>25&&xo<122&&yo>447&&yo<461)
         n=3;
    if(xo>25&&xo<116&&yo>416&&yo<433)
         n=4;
    if(xo>25&&xo<113&&yo>385&&yo<403)
         n=5;
    if(xo>25&&xo<107&&yo>355&&yo<374)
         n=6;
    if(xo>45&&xo<86&&yo>95&&yo<113)
         glutPostRedisplay();
    if(xo>121&&xo<152&&yo>95&&yo<113)
         glutHideWindow();
    glLoadIdentity();
  divide_tetra(v[0],v[1],v[2],v[3],n);
  glFlush();
}
void init()
{    
     glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-2,2,-2,2,-2,2);
   glMatrixMode(GL_MODELVIEW);  
   glutPostRedisplay();
}
//////////////////////////////////////////////////tetrahedron-end/////////////////////////////////////////////////

/////////////////////////////////////////////////2. teapot////////////////////////////////////////////////////////
void wall(double thickness)
{
     glPushMatrix();
     glTranslated(0.5,0.5*thickness,0.5);
     glScaled(1.0,thickness,1.0);
     glutSolidCube(1.0);
     glPopMatrix();
}
void tl(double thick,double len)
{
     glPushMatrix();
     glTranslated(0,len/2,0);
     glScaled(thick,len,thick);
     glutSolidCube(1.0);
     glPopMatrix();
}
void table(double tw,double tt,double lt,double ll)
{
     glPushMatrix();
     glTranslated(0,ll,0);
     glScaled(tw,tt,tw);
     glutSolidCube(1.0);
     glPopMatrix();
     double dist=0.95*tw/2.0-lt/2.0;
     glPushMatrix();
     glTranslated(dist,0,dist);
     tl(lt,ll);
     glTranslated(0.0,0.0,-2*dist);
     tl(lt,ll);
     glTranslated(-2*dist,0,2*dist);
     tl(lt,ll);
     glTranslated(0,0,-2*dist);
     tl(lt,ll);
     glPopMatrix();
}
void display3(void)
{
     GLfloat ma[]={1.0f,0.0f,0.0f,0.0f};
     GLfloat md[]={0.5f,0.5f,0.5f,1.0f};
     GLfloat ms[]={1.0f,1.0f,1.0f,1.0f};
     GLfloat msh[]={50.0f};
     glMaterialfv(GL_FRONT,GL_AMBIENT,ma);
     glMaterialfv(GL_FRONT,GL_DIFFUSE,md);
     glMaterialfv(GL_FRONT,GL_SPECULAR,ms);
     glMaterialfv(GL_FRONT,GL_SHININESS,msh);
     GLfloat li[]={0.9f,0.9f,0.9f,1.0f};
     GLfloat lp[]={2.0f,6.0f,3.0f,0.0f};
     glLightfv(GL_LIGHT0,GL_POSITION,lp);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,li);
     
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     double w=1.0;
     glOrtho(-w*64/48.0,w*64/48.0,-w,w,0.1,100.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
     
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
      glColor3f(1.0,1.0,1.0);
     glRasterPos2f(2.03,-2.57);
   Write("Close");
   glutMouseFunc(OnClick1);
          
     if(xo>172&&xo<202&&yo>266&&yo<304)
          glutHideWindow();
    glPushMatrix ();
    glTranslated(0.4,0.4,0.6);
    glRotated(45,0,0,1);
    glScaled(0.08,0.08,0.08);
    glPopMatrix();
     
     glPushMatrix ();
     glTranslated(0.4,0.38,0.4); 
     glRotated(30,0,1,0);
     glutSolidTeapot(0.08);
     glPopMatrix();
     
     glPushMatrix ();
     glTranslated(0.4,0,0.4);
     table(0.6,0.02,0.02,0.3);
     glPopMatrix();
     wall(0.02);
     
     glPushMatrix();
     glRotated(90.0,0.0,0.0,1.0);
     wall(0.02);
     glPopMatrix();
     
     glPushMatrix();
     glRotated(-90.0,1.0,0.0,0.0);
     wall(0.02);
     glPopMatrix();     
     
     glFlush();
     
}

////////////////////////////////////////////////teapot-end/////////////////////////////////////////////////////////


////////////////////////////////////////////////3. ColorCube//////////////////////////////////////////////////////

/*cube is centered at origin */
GLfloat vertices[][3] = {{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0} ,
{-1.0,-1.0,-1.0},{-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0}};
GLfloat normals[][3] = {{-1.0,-1.0,1.0},{-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0} ,
{-1.0,-1.0,-1.0},{-1.0,1.0,-1.0},{1.0,1.0,-1.0}, {1.0,-1.0,-1.0}};
/*colors are assigned to the vertices */
GLfloat colors[][3] = {{0.0,0.0,0.0},{1.0,0.0,0.0}, 
            {0.0,1.0,0.0}, {0.0,0.0,1.0}, {1.0,1.0,0.0},{1.0,0.0,1.0}, 
            {0.0,1.0,-1.0},{1.0,1.0,-1.0} };
GLubyte CubeIndices[]={0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4};
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;

void polygon(int a, int b, int c, int d)
{ /* draw a polygon via list of vertices */
  glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glNormal3fv(normals[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(colors[b]);
    glNormal3fv(normals[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(colors[c]);
    glNormal3fv(normals[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(colors[d]);
    glNormal3fv(normals[d]);
    glVertex3fv(vertices[d]);
  glEnd();
}
//void colorcube()
//{ /* map vertices to faces */
/*  polygon(0,3,2,1);
  polygon(2,3,7,6);
  polygon(0,4,7,3);
  polygon(1,2,6,5);
  polygon(4,5,6,7);
  polygon(0,1,5,4);
}*/
void display4()
{ /* display callback, clear frame buffer and z buffer,
   rotate cube and draw, swap buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
     glColor3f(1.0,1.0,1.0);
   glRasterPos2f(-2.03,-1.57);
   Write("Close");
   glutMouseFunc(OnClick1);
          
     if(xo>24&&xo<54&&yo>64&&yo<85)
          glutHideWindow();
  glRotatef(theta[0], 1.0, 0.0, 0.0);
  glRotatef(theta[1], 0.0, 1.0, 0.0);
  glRotatef(theta[2], 0.0, 0.0, 1.0);
  
  glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,CubeIndices);
  glBegin(GL_LINES);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(1.0,1.0,1.0);
    glEnd();
//  colorcube();
  glFlush();
  glutSwapBuffers();
}

void spinCube()
{ /* idle callback, spin cube 2 degrees about selected axis */
  theta[axis] += 0.1;
  if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
  glutPostRedisplay();  
}
void mouse(int btn, int state, int x, int y)
{ /* mouse callback, selects an axis about which to rotate */
  if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
  if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
  if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
}
void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,
            2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,
            2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

////////////////////////////////////////////////colorcube-end//////////////////////////////////////////////////////


////////////////////////////////////////////////4. house///////////////////////////////////////////////////////////
GLfloat house[3][9] = {{150.0,150.0,225.0,300.0,300.0,200.0,200.0,250.0,250.0},{150.0,250.0,300.0,250.0,150.0,150.0,200.0,200.0,150.0},{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0},{0},{0}};
GLfloat h=150.0;
GLfloat k=150.0;
GLfloat theta1=30.0;
void multiply()
{
     int i,j,l;
     for(i=0;i<3;i++)
     for(j=0;j<9;j++)
     {
                     result[i][j]=0;
                     for(l=0;l<3;l++)
                     result[i][j]=result[i][j]+rot_mat[i][l]*house[l][j];
     }
}
int rotate()
{
  GLfloat m,n;
  m=-h*(cos(theta1)-1)+k*(sin(theta1));
  n=-k*(cos(theta1)-1)-h*(sin(theta1));
    rot_mat[0][0]=cos(theta1);
    rot_mat[0][1]=-sin(theta1);
    rot_mat[0][2]=m;
    rot_mat[1][0]=sin(theta1);
    rot_mat[1][1]=cos(theta1);
    rot_mat[1][2]=n;
    rot_mat[2][0]=0;
    rot_mat[2][1]=0;
    rot_mat[2][2]=1;
    multiply();
    return 0;
}

void rhouse()
{
    glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(result[0][0],result[1][0]);
  glVertex2i(result[0][1],result[1][1]);
  glVertex2i(result[0][3],result[1][3]);
  glVertex2i(result[0][4],result[1][4]);
  glEnd();
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(result[0][5],result[1][5]);
  glVertex2i(result[0][6],result[1][6]);
  glVertex2i(result[0][7],result[1][7]);
  glVertex2i(result[0][8],result[1][8]);
  glEnd();
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(result[0][1],result[1][1]);
  glVertex2i(result[0][2],result[1][2]);
  glVertex2i(result[0][3],result[1][3]);
  glEnd();
}
void dhouse()
{
     glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(house[0][0],house[1][0]);
  glVertex2i(house[0][1],house[1][1]);
  glVertex2i(house[0][3],house[1][3]);
  glVertex2i(house[0][4],house[1][4]);
  glEnd();
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(house[0][5],house[1][5]);
  glVertex2i(house[0][6],house[1][6]);
  glVertex2i(house[0][7],house[1][7]);
  glVertex2i(house[0][8],house[1][8]);
  glEnd();
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(house[0][1],house[1][1]);
  glVertex2i(house[0][2],house[1][2]);
  glVertex2i(house[0][3],house[1][3]);
  glEnd();
}
void display1()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,1.0);
  glRasterPos2f(30.03,50.77);
  Write("Close");
  glutMouseFunc(OnClick1);

    if(xo>22&&xo<53&&yo>61&&yo<82)
         glutHideWindow();
  dhouse();
  rotate();
  rhouse();
  glFlush();
}
void myinit()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(1.0,0.0,0.0);
  glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,499.0,0.0,499.0);
  
}
//////////////////////////////////////////////////house -end/////////////////////////////////////////////

//////////////////////////////////////////////////5.cohen Sutherland////////////////////////////////////


double xmax,ymax,xmin,ymin;
double xvmin,yvmin,xvmax,yvmax;
const int TOP=1;
const int BOTTOM=2;
const int RIGHT=4;
const int LEFT=8;

outcode computecode(double x,double y)
{
  outcode code=0;
  if(y>ymax)
  code |=TOP;
  if(y<ymin)
  code |=BOTTOM;
  if(x>xmax)
  code |=RIGHT;
  if(x<xmin)
  code |=LEFT;
  return code;
}
void cohenclipanddraw(double xz,double yz,double xo,double yo)
{
  outcode outcode0,outcode1,outcodeout;
  double sx,sy,vx0,vy0,vx1,vy1;
  int accept=0,done=0;
  outcode0=computecode(xz,yz);
  outcode1=computecode(xo,yo);

  do
  {
    if(!(outcode0|outcode1))
    {
      accept=1;
      done=1;
    }
    else if(outcode0&outcode1)
      done=1;
    else
    {
      double x,y;
      outcodeout=outcode0?outcode0:outcode1;
      if(outcodeout&TOP)
      {
        x=xz+(xo-xz)*(ymax-yz)/(yo-yz);
        y=ymax;
      }
      else if(outcodeout&BOTTOM)
      {
        x=xz+(xo-xz)*(ymin-yz)/(yo-yz);
        y=ymin;
      }
      else if(outcodeout&RIGHT)
      { 
        y=yz+(yo-yz)*(xmax-xz)/(xo-xz);
        x=xmax;
      }
      else
      { 
        y=yz+(yo-yz)*(xmin-xz)/(xo-xz);
        x=xmin;
      }
      if(outcodeout==outcode0)
      {
        xz=x;yz=y;
        outcode0=computecode(xz,yz);
      }
      else
      {
        xo=x;yo=y;
        outcode1=computecode(xo,yo);
      }
    }
  }
  while(!done);

  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINE_LOOP);
    glVertex2f(xvmin,yvmin);
    glVertex2f(xvmax,yvmin);
    glVertex2f(xvmax,yvmax);
    glVertex2f(xvmin,yvmax);
  glEnd();

  if(accept)
  {
    sx=(xvmax-xvmin)/(xmax-xmin);
      sy=(yvmax-yvmin)/(ymax-ymin);

      vx0=xvmin+(xz-xmin)*sx;
      vy0=yvmin+(yz-ymin)*sy;
      vx1=xvmin+(xo-xmin)*sx;
      vy1=yvmin+(yo-ymin)*sy;
  
      glColor3f(1.0,0.0,0.0);
      glBegin(GL_LINES);
           glVertex2f(vx0,vy0);
           glVertex2f(vx1,vy1);
      glEnd();
  }
}
void myinit1()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(1.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,500.0,0.0,500.0);
  glMatrixMode(GL_MODELVIEW);
}
void display5()
{
  glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(0.0,0.0,1.0);
   glRasterPos2f(10.03,10.57);
   Write("Close");

  glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
  glEnd();
 
      glutMouseFunc(OnClick2);
      if(d[f-2]>7&&d[f-2]<38&&c[f-2]>13&&c[f-2]<33)
          glutHideWindow();
    glBegin(GL_LINES);
    glVertex2f(d[f-2],c[f-2]);
    glVertex2f(d[f-1],c[f-1]);
  glEnd();
    cohenclipanddraw(d[f-2],c[f-2],d[f-1],c[f-1]);
  glFlush();
  glutPostRedisplay();
}



//////////////////////////////////////////////////cohen-sutherlnd end///////////////////////////////////


/////////////////////////////////////////////////6. Area filling algo///////////////////////////////////

float xo1,x2,x3,x4,yo1,y2,y3,y4;

void edgedetect(GLfloat xo1, GLfloat yo1, GLfloat x2, GLfloat y2,GLint *le,int *re)
{
  float mx,x,temp;
  int i;
  if((y2-yo1)<0)  
  {
    temp=yo1;yo1=y2;y2=temp;
    temp=xo1;xo1=x2;x2=temp;
  }
  if((y2-yo1)!=0) 
    mx=(x2-xo1)/(y2-yo1);
  else
    mx=x2-xo1;
  x=xo1;
  for(i=yo1;i<=y2;i++)
  {
    if(x<(float)le[i])
      le[i]=(int)x;
    if(x>(float)re[i])
      re[i]=(int)x;
    x+=mx;
  }
}
void draw_ppixel(GLint x, GLint y, GLfloat v)
{
  glColor3f(0.0,0.0,0.0);
  glBegin(GL_POINTS);
    glVertex2i(x,y);
  glEnd();
}
void scanfill(float xo1,float yo1, float x2, float y2,float x3, float y3,float x4, float y4)
{
  int le[500],re[500];
  int i,scanline;
  for(i=0;i<500;i++)
  {
    le[i]=500;
    re[i]=0;
  }
    edgedetect(xo1,yo1,x2,y2,le,re);  
    edgedetect(x2,y2,x3,y3,le,re);  
    edgedetect(x3,y3,x4,y4,le,re);  
    edgedetect(x4,y4,xo1,yo1,le,re);  
  for(scanline=0; scanline<500; scanline++)
  {
    if(le[scanline]<=re[scanline])
        for(i=(int)le[scanline];i<(int)re[scanline];i++)
      draw_ppixel(i,scanline,BLACK);    
  }

}
void display6()
{
    xo1=200.0;yo1=200.0;x2=100.0;y2=300.0;x3=200.0;y3=400.0;x4=300.0;y4=300.0;
  glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
   glRasterPos2f(50.03,60.57);
   Write("Close");
   glutMouseFunc(OnClick1);

     if(xo>38&&xo<69&&yo>72&&yo<91)
          glutHideWindow(); 
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(xo1,yo1);
  glVertex2f(x2,y2);
  glVertex2f(x3,y3);
  glVertex2f(x4,y4);
  glEnd();
  scanfill(xo1,yo1,x2,y2,x3,y3,x4,y4);
  glFlush();
}
void myinit2()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(1.0,0.0,0.0);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,500.0,0.0,500.0);
}
/////////////////////////////////////////////////line scanning algo end////////////////////////////////

////////////////////////////////////////////////7.rectangular mesh//////////////////////////////////////

GLfloat xx[maxx]={0.0},yy[maxy]={0.0};
GLfloat xz1=50,yz1=50;
GLint i,j;

void init2()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(1.0,0.0,0.0);
  glPointSize(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,499.0,0.0,499.0);
}

void display7(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,1.0);
   glRasterPos2f(10.03,10.57);
   Write("Close");
   glutMouseFunc(OnClick1);
          
     if(xo>6&&xo<38&&yo>14&&yo<32)
            glutHideWindow();
  glColor3f(1.0,0.0,0.0);
  for(i=0;i<maxx;i++)
  xx[i]=xz1+i*dx;
  for(j=0;j<maxy;j++)
  yy[j]=yz1+j*dy;

  glColor3f(1.0,0.0,0.0);
  for(i=0;i<maxx-1;i++)
  for(j=0;j<maxy-1;j++)
  {
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xx[i],yy[j]);
    glVertex2f(xx[i],yy[j+1]);
    glVertex2f(xx[i+1],yy[j+1]);
    glVertex2f(xx[i+1],yy[j]);
    glEnd();
    glFlush();
  }
}



///////////////////////////////////////////////////rectngular mesh end//////////////////////////////////////

///////////////////////////////////////////////////8.CAMERA//////////////////////////////////////////////////
GLdouble viewer[]={0.0,0.0,5.0};
void colorcube()
{ /* map vertices to faces */
  polygon(0,3,2,1);
  polygon(2,3,7,6);
  polygon(0,4,7,3);
  polygon(1,2,6,5);
  polygon(4,5,6,7);
  polygon(0,1,5,4);
}
void display12()
{ /* display callback, clear frame buffer and z buffer,
   rotate cube and draw, swap buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(1.0,1.0,1.0);
   glRasterPos2f(-2.03,-1.57);
   Write("Close");
   glutMouseFunc(OnClick1);
          
     if(xo>24&&xo<54&&yo>64&&yo<85)
          glutHideWindow();
    gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);
  glRotatef(theta[0], 1.0, 0.0, 0.0);
  glRotatef(theta[1], 0.0, 1.0, 0.0);
  glRotatef(theta[2], 0.0, 0.0, 1.0);
  colorcube();
  
  glFlush();
  glutSwapBuffers();
}
void mymouse(int btn,int state,int x,int y)
{ 
  if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN) axis=0;
  if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN) axis=1;
  if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN) axis=2;
  theta[axis]+=0.1;
  if(theta[axis]>360.0) theta[axis]-=360.0;
  display12();
}
void keys(unsigned char key,int x,int y)
{
    if(key=='X') viewer[0]-=1.0;
    if(key=='x') viewer[0]+=1.0;
    if(key=='Y') viewer[1]-=1.0;
    if(key=='y') viewer[1]+=1.0;
    if(key=='Z') viewer[2]-=1.0;
    if(key=='z') viewer[2]+=1.0;
    display12();
}

///////////////////////////////////////////////////CAMERA END////////////////////////////////////////////////


//////////////////////////////////////////////////9. Cylinder and parallopiped///////////////////////////////

void draw_pixel(GLint cx, GLint cy)
{
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POINTS);
    glVertex2i(cx, cy);
  glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
  draw_pixel(x+h, y+k);
  draw_pixel(-x+h, y+k);
  draw_pixel(x+h, -y+k);
  draw_pixel(-x+h, -y+k);
  draw_pixel(y+h, x+k);
  draw_pixel(-y+h, x+k);
  draw_pixel(y+h, -x+k);
  draw_pixel(-y+h, -x+k);
}

void circle_draw(GLint h, GLint k, GLint r)
{
  GLint d=1-r, x=0,y=r;
  while(y>x)
  {
    plotpixels(h, k, x, y);
    if(d<0) d+=2*x+3;
    else
    {
      d+=2*(x-y)+5;
      --y;
    }
    ++x;
  }
  plotpixels(h, k, x, y);
}

void cylinderdraw()
{
  GLint xc=75,yc=75,r=50; 
GLint i, n=50;
  for(i=0;i<n;i+=3)
  {
    circle_draw(xc, yc+i, r);
  }
}

void parallelpiped(int x1, int x2, int y1, int y2)
{
  glColor3f(0.0,0.0,1.0);
  glPointSize(2.0);
  glBegin(GL_LINE_LOOP);
    glVertex2i(x1,y1);
    glVertex2i(x2,y1);
    glVertex2i(x2,y2);
    glVertex2i(x1,y2);
  glEnd();
}

void parallelpiped_draw()
{
  int x1=200,x2=300,y1=100,y2=175;
  GLint i, n=40;
  for(i=0;i<n;i+=2)
  {
    parallelpiped(x1+i,x2+i,y1+i,y2+i);
  }
}

void init3(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,400.0,0.0,300.0);
}

void display9(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,0.0,1.0);
   glRasterPos2f(10.03,10.57);
   Write("Close");
   glutMouseFunc(OnClick1);
          
     if(xo>8&&xo<40&&yo>21&&yo<41)
          glutHideWindow();
  glColor3f(1.0,0.0,0.0);
  cylinderdraw();
  parallelpiped_draw();
  glFlush();
}
/////////////////////////////////cylinder and parallelopiped-end///////////////////////////////////////

/////////////////////////////////Liang-Barskey///////////////////////////////////////////////////////
double xmin=50,ymin=50,xmax=100,ymax=100,xd,yd,xe,ye;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;
float X0,Y0,X1,Y1;

int cliptest(double p,double q,double *t1,double *t2)
{
    double t=q/p;
    if(p<0.0)
    {
             if(t>*t1) *t1=t;
             if(t>*t2) return(false);
    }
    else
        if(p>0.0)
        {
                 if(t<*t2) *t2=t;
                 if(t<*t1) return(false);
        }
        else
            if(p==0.0)
            {
                          if(q<0.0) return(false);
            }
            return(true);
}
void Liang(double x0,double y0, double x1, double y1)
{
     double dz=x1-x0,da=y1-y0,te=0.0,t1=1.0;
     glColor3f(1.0,0.0,0.0);
             
                            glBegin(GL_LINE_LOOP);
                            glVertex2f(xvmin,yvmin);
                            glVertex2f(xvmax,yvmin);
                            glVertex2f(xvmax,yvmax);
                            glVertex2f(xvmin,yvmax);
                            glEnd();
     if(cliptest(-dz,x0-xmin,&te,&t1))
      if(cliptest(dz,xmax-x0,&te,&t1)) 
       if(cliptest(-da,y0-ymin,&te,&t1))
        if(cliptest(da,ymax-y0,&te,&t1))
        {
                                      if(t1<1.0)
                                      {
                                                    x1=x0+t1*dz;
                                                    y1=y0+t1*da;
                                      }
                                      if(te>0.0)
                                      {
                                                    x0=x0+te*dz;
                                                    y0=y0+te*da;
                                      }
                                      double sx=(xvmax-xvmin)/(xmax-xmin);
                                      double sy=(yvmax-yvmin)/(ymax-ymin);
                                      double vx0=xvmin+(x0-xmin)*sx;
                                      double vy0=yvmin+(y0-ymin)*sy;
                                      double vx1=xvmin+(x1-xmin)*sx;
                                      double vy1=yvmin+(y1-ymin)*sy;
                                      glColor3f(0.0,0.0,1.0);
                                      glBegin(GL_LINES);
                                      glVertex2d(vx0,vy0);
                                      glVertex2d(vx1,vy1);
                                      glEnd();
      }
}
void display10()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.0,0.0,1.0);
   glRasterPos2f(10.03,10.57);
   Write("Close");
   
     glColor3f(1.0,0.0,0.0);
     glutMouseFunc(OnClick3); 
     
     if(d1[f2-2]>7&&d1[f2-2]<38&&c1[f2-2]>13&&c1[f2-2]<33)
          glutHideWindow();
     glBegin(GL_LINES);
     glVertex2f(d1[f2-2],c1[f2-2]);
     glVertex2f(d1[f2-1],c1[f2-1]);
     glEnd();
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_LINE_LOOP);
     glVertex2f(xmin,ymin);
     glVertex2f(xmax,ymin);
     glVertex2f(xmax,ymax);
     glVertex2f(xmin,ymax);
     glEnd();
     Liang(d1[f2-2],c1[f2-2],d1[f2-1],c1[f2-1]);
     glFlush();
     glutPostRedisplay();
}
void myinit10()
{
     glClearColor(1.0,1.0,1.0,1.0);
     glColor3f(1.0,0.0,0.0);
     glPointSize(8.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,499.0,0.0,499.0);
}
///////////////////////////////Liang-barskey-end//////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OnMouseClick(int button, int state, int x, int y)
{     
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  { 
     
     if(x>25&&x<275&&y>15&&y<45)
     {      
            glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
          glutInitWindowSize(700,600);
          glutInitWindowPosition(400,100);
          glutCreateWindow("3DGasKet");
            glutDisplayFunc(display2);
          init();
          glEnable(GL_DEPTH_TEST);
          glClearColor(1.0,1.0,1.0,1.0);
          glutMainLoop();            
     }
     if(x>25&&x<275&&y>69&&y<99)
     {                      
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
      glutInitWindowSize(700,600);
      glutInitWindowPosition(400,100);
      glutCreateWindow("TEAPOT");
      glutDisplayFunc(display3);
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glShadeModel(GL_SMOOTH);
      glEnable(GL_DEPTH_TEST);
      glEnable(GL_NORMALIZE);
      glClearColor(0.1,0.1,0.1,0.0);
    glViewport(0,0,700,600);
     glutMainLoop();
     }
     if(x>25&&x<275&&y>123&&y<153)
     {                      
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(700, 600);
        glutInitWindowPosition(400,100);
        glutCreateWindow("colorcube");
        glutReshapeFunc(myReshape);
        glutDisplayFunc(display4);
        glutIdleFunc(spinCube);
        glutMouseFunc(mouse);
        glEnable(GL_DEPTH_TEST); 
               glEnableClientState(GL_COLOR_ARRAY);
               glEnableClientState(GL_NORMAL_ARRAY);
               glEnableClientState(GL_VERTEX_ARRAY);
               glVertexPointer(3,GL_FLOAT,0,vertices);
               glColorPointer(3,GL_FLOAT,0,colors);
               glNormalPointer(GL_FLOAT,0,normals);
               glClearColor(0.0,0.0,0.0,0.0);
               glColor3f(1.0,1.0,1.0);
        glutMainLoop();
           
     }
     if(x>25&&x<275&&y>177&&y<207)
     {                      
        theta1=theta1*(3.14/180);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
      glutInitWindowSize(700,600);
      glutInitWindowPosition(400,100);
      glutCreateWindow("House");
      glutDisplayFunc(display1);
      myinit();
      glutMainLoop();
     }
     if(x>25&&x<275&&y>231&&y<261)
     {               
      xmin=50;ymin=50;
      xmax=100;ymax=100;
      xvmin=200,yvmin=200;
      xvmax=300;yvmax=300;
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
      glutInitWindowSize(700,600);
      glutInitWindowPosition(400,100);
      glutCreateWindow("COHEN SutherLand");
      glutDisplayFunc(display5);
      myinit1();
      glutMainLoop();
     }      
     if(x>25&&x<275&&y>285&&y<315)
     { 
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
      glutInitWindowSize(700,600);
      glutInitWindowPosition(400,100);
      glutCreateWindow("Filling a Polygon using Scan-line Algorithm");
      glutDisplayFunc(display6);
      myinit2();
      glutMainLoop();
      
     }
     if(x>25&&x<275&&y>339&&y<369)
     {                      
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
      glutInitWindowSize(700,600);
      glutInitWindowPosition(400,100);
      glutCreateWindow("Rectangular mesh");
      glutDisplayFunc(display7);
      init2();
      glutMainLoop();
     }
     if(x>25&&x<275&&y>393&&y<423)
     {                      
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(700, 600);
        glutInitWindowPosition(400,100);
        glutCreateWindow("CAMERA");
        glutReshapeFunc(myReshape);
        glutDisplayFunc(display12);
      //  glutIdleFunc(spinCube);
        glutMouseFunc(mymouse);
        glutKeyboardFunc(keys);
        glEnable(GL_DEPTH_TEST); 
        glutMainLoop();  
     }
     if(x>25&&x<275&&y>447&&y<477)
     {                     
         glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
       glutInitWindowPosition(400,100);
       glutInitWindowSize(700,600);
       glutCreateWindow("Cylinder & ParralelPiped");
       init3();
       glutDisplayFunc(display9);
     }
    if(x>25&&x<275&&y>501&&y<531)
    {   
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(700,600);
        glutInitWindowPosition(400,100);
        glutCreateWindow("liang barsky line clipping algorithm");
        myinit10();
      glutDisplayFunc(display10);
        glutMainLoop();
     }
                                                           
     if(x>25&&x<275&&y>555&&y<585)
     {                             
         glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
         glutInitWindowSize(700,600);
         glutInitWindowPosition(400,100);
         glutCreateWindow("EXIT");
         glutDisplayFunc(display11);
     }
  } 
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0,0.0,0.7);
    glBegin(GL_POLYGON);
  glVertex2f(-0.4,-1.0);
  glVertex2f(-1.0,-1.0);
  glVertex2f(-1.0,1.0);
  glVertex2f(-0.4,1.0);
  glEnd();  
    glColor3f (0.0,0.2,0.0);
    glBegin(GL_POLYGON);
  glVertex2f(-0.4,1.0);
  glVertex2f(1.0,1.0);
  glVertex2f(1.0,-1.0);
  glVertex2f(-0.4,-1.0);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.23,0.67);
    Write("COMPUTER GRAPHICS PROJECT WITH OPENGL");
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.23,0.47);
    Write("                     A MENU BASED  PACKAGE");
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.23,0.27);
    Write(" UNDER THE GUIDANCE OF Mrs. HS VIMALA MA'AM");
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.23,-0.07);
    Write("                       BY ABHISHEK DUTTA");
    glRasterPos2f(-0.23,-0.67);
    Write("    CLICK ON ANY OF THE BUTTONS ON THE LEFT");
    
  glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,0.85);
  glVertex2f(-0.95,0.85);
  glVertex2f(-0.95,0.95);
  glVertex2f(-0.45,0.95);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,0.87);
    Write("TETRAHEDRON");

  glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,0.67);
  glVertex2f(-0.95,0.67);
  glVertex2f(-0.95,0.77);
  glVertex2f(-0.45,0.77);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,0.69);
    Write("TEAPOT");

    glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,0.49);
  glVertex2f(-0.95,0.49);
  glVertex2f(-0.95,0.59);
  glVertex2f(-0.45,0.59);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,0.51);
    Write("COLORCUBE");
    
    glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,0.31);
  glVertex2f(-0.95,0.31);
  glVertex2f(-0.95,0.41);
  glVertex2f(-0.45,0.41);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,0.33);
    Write("HOUSE");

    glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,0.13);
  glVertex2f(-0.95,0.13);
  glVertex2f(-0.95,0.23);
  glVertex2f(-0.45,0.23);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,0.15);
    Write("COHEN SUTHER");

    glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,-0.85);
  glVertex2f(-0.95,-0.85);
  glVertex2f(-0.95,-0.95);
  glVertex2f(-0.45,-0.95);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,-0.93);
    Write("EXIT");

    glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,-0.49);
  glVertex2f(-0.95,-0.49);
  glVertex2f(-0.95,-0.59);
  glVertex2f(-0.45,-0.59);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,-0.57);
    Write("CYLINDER AND PP");

    glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,-0.41);
  glVertex2f(-0.95,-0.41);
  glVertex2f(-0.95,-0.31);
  glVertex2f(-0.45,-0.31);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,-0.39);
    Write("CAMERA");

    glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,-0.13);
  glVertex2f(-0.95,-0.13);
  glVertex2f(-0.95,-0.23);
  glVertex2f(-0.45,-0.23);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,-0.21);
    Write("MESH");

    glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,-0.05);
  glVertex2f(-0.95,-0.05);
  glVertex2f(-0.95,0.05);
  glVertex2f(-0.45,0.05);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,-0.03);
    Write("SCANLINE AREA");
    
  glBegin(GL_POLYGON);
  glColor3f (0.6,0.3, 0.8);
  glVertex2f(-0.45,-0.67);
  glVertex2f(-0.95,-0.67);
  glVertex2f(-0.95,-0.77);
  glVertex2f(-0.45,-0.77);
  glEnd();
  glColor3f(1.0,1.0,1.0);
    glRasterPos2f(-0.93,-0.75);
    Write("LIANG BARSKY");
    glFlush();
}
int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(1000,600);
  glutInitWindowPosition(100,100);
  glutCreateWindow("PROJECT MENU LIST");
  glutMouseFunc(OnMouseClick);
    glutDisplayFunc(display);
  glutMainLoop();
}

