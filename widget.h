#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class Widget : public QOpenGLWidget , protected QOpenGLExtraFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;
private:
    QOpenGLShaderProgram shaderprogram;
    QOpenGLVertexArrayObject VAO;
    QOpenGLBuffer VBO;
public:
    float b[1]={0.5};

};
#endif // WIDGET_H
