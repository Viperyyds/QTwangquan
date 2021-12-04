#include "widget.h"
#include <QMatrix4x4>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
    ,VBO(QOpenGLBuffer::VertexBuffer)
{
}

Widget::~Widget()
{
    makeCurrent();
}
void Widget::initializeGL()
{
   initializeOpenGLFunctions();
   glClearColor(0.0f,0.0f,0.0f,1.0f);
   glClear(GL_COLOR_BUFFER_BIT);
   VAO.create();
   VAO.bind();
   VBO.create();
   VBO.bind();
   float vertices[]=
     {
       0.0f,0.0f,0.0f,
       0.5f,0.5f,1.5f,

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
    /*int w = width();
    int h = height();
    QMatrix4x4 matrix;
    matrix.perspective(45.0f, (GLfloat)w/(GLfloat)h, 0.001f, 100.0f);
    matrix.translate(0.0, 0.0, -3.0);
    matrix.rotate(90.0f, 0.0f, 0.0f, 1.0f);

    shaderprogram.setUniformValue("RotationMatrix", matrix);*/
    shaderprogram.bind();
    QOpenGLVertexArrayObject::Binder bind(&VAO);
    glDrawArrays(GL_LINES,0,6);
}
void Widget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}
