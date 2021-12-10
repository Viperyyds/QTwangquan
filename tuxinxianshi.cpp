#include "tuxinxianshi.h"
#include <QMatrix4x4>
#include <QTime>
#include <QtMath>
#include <QOpenGLFunctions>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
    ,VBO(QOpenGLBuffer::VertexBuffer)
{
    connect(&timer,SIGNAL(timeout()),this,SLOT(on_timeout()));
    timer.start(500);
    rline = 0.0 ;
}

Widget::~Widget()
{
    makeCurrent();
}
void Widget::initializeGL()
{
   initializeOpenGLFunctions();
   glShadeModel(GL_SMOOTH);
   glClearColor(1.0f,1.0f,1.0f,0.0f);
   glClearDepth(1.0);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   VAO.create();
   VAO.bind();
   VBO.create();
   VBO.bind();
   float vertices[]=
     {
       g,h,j,
       k,p,o,
     };
   VBO.allocate(vertices,sizeof (vertices));
   shaderprogram.create();
   shaderprogram.addCacheableShaderFromSourceFile(QOpenGLShader::Vertex,":/gl.vert");
   shaderprogram.addCacheableShaderFromSourceFile(QOpenGLShader::Fragment,":/gl.frag");
   shaderprogram.link();
   shaderprogram.enableAttributeArray(0);
   shaderprogram.setAttributeBuffer(0,GL_FLOAT,0,3);
   VAO.release();
   VBO.release();


}
void Widget::paintGL()
{
    QMatrix4x4 matrix;
    //unsigned int time = QTime::currentTime().msec();
    matrix.rotate(rline,0.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    shaderprogram.bind();
    QOpenGLVertexArrayObject::Binder bind(&VAO);
    shaderprogram.setUniformValue("matrix",matrix);
    glDrawArrays(GL_LINES,0,2);
    rline = rline - 10;

}
void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}
void Widget::on_timeout()
{
    update();
}

