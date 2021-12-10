#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QTimer>
#include <QWidget>
extern int r ;
extern float g;
extern float h;
extern float j;
extern float k;
extern float p;
extern float o;

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
    QTimer timer;
public slots:
    void on_timeout();
protected:
    float rline;


};
#endif // WIDGET_H
