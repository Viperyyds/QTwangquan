#include "myglwidget.h"
#include"qmath.h"

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    fullscreen = false;
}

MyGLWidget::~MyGLWidget()
{

}
void MyGLWidget::initializeGL()                         //此处开始对OpenGL进行所以设置
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                   //黑色背景
    glShadeModel(GL_SMOOTH);                            //启用阴影平滑

    glClearDepth(1.0);                                  //设置深度缓存
    glEnable(GL_DEPTH_TEST);                            //启用深度测试
    glDepthFunc(GL_LEQUAL);                             //所作深度测试的类型
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  //告诉系统对透视进行修正
}
void MyGLWidget::paintGL()                              //从这里开始进行所以的绘制
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除屏幕和深度缓存
    glLoadIdentity();                                   //重置当前的模型观察矩阵
    glTranslatef(-1.5f, 0.0f, -6.0f);                   //左移1.5单位，并移入屏幕6.0单位
       glBegin(GL_TRIANGLES);                              //开始绘制三角形
           glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点
           glVertex3f(-1.0f, -1.0f, 0.0f);                 //左下
           glVertex3f(1.0f, -1.0f, 0.0f);                  //右下
       glEnd();                                            //三角形绘制结束

       glTranslatef(3.0f, 0.0f, 0.0f);                     //右移3.0单位
       glBegin(GL_QUADS);                                  //开始绘制四边形
           glVertex3f(-1.0f, 1.0f, 0.0f);                  //左上
           glVertex3f(1.0f, 1.0f, 0.0f);                   //右上
           glVertex3f(1.0f, -1.0f, 0.0f);                  //左下
           glVertex3f(-1.0f, -1.0f, 0.0f);                 //右下
       glEnd();                                            //四边形绘制结束

}

void MyGLWidget::resizeGL(int w, int h)                 //重置OpenGL窗口的大小
{
    glViewport(0, 0, (GLint)w, (GLint)h);               //重置当前的视口
    glMatrixMode(GL_PROJECTION);                        //选择投影矩阵
    glLoadIdentity();                                   //重置投影矩阵
    //设置视口的大小
    //gluPerspective(45.0, (GLfloat)w/(GLfloat)h, 0.1, 100.0);
    GLdouble aspectRatio = (GLfloat)w/(GLfloat)h;
        GLdouble zNear = 0.1;
        GLdouble zFar = 100.0;

        GLdouble rFov = 45.0 * 3.14159265 / 180.0;
         glFrustum( -zNear * tan( rFov / 2.0 ) * aspectRatio,
                   zNear * tan( rFov / 2.0 ) * aspectRatio,
                   -zNear * tan( rFov / 2.0 ),
                   zNear * tan( rFov / 2.0 ),
                   zNear, zFar );

    glMatrixMode(GL_MODELVIEW);                         //选择模型观察矩阵
    glLoadIdentity();                                   //重置模型观察矩阵
}


