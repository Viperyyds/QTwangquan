#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include<QtOpenGL/QGL>
#include<QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class myglWidget; }
QT_END_NAMESPACE

class myglWidget : public QGLWidget
{
    Q_OBJECT

public:
    myglWidget(QWidget *parent = nullptr);
    ~myglWidget();

private:
    Ui::myglWidget *ui;
protected:
    //对3个纯虚函数的重定义
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void keyPressEvent(QKeyEvent *event);           //处理键盘按下事件

private:
    bool fullscreen;                                //是否全屏显示
    bool m_Light;
    bool m_Blend;
private:
        GLfloat m_xRot;                                 //绕x轴旋转的角度
        GLfloat m_yRot;                                 //绕y轴旋转的角度
        GLfloat m_xSpeed;                               //绕x轴旋转的速度
        GLfloat m_ySpeed;                               //绕y轴旋转的速度
        GLfloat m_Deep;                                 //深入屏幕的距离

        QString m_FileName;                             //图片的路径及文件名
        GLuint m_Texture;                               //储存一个纹理

};
#endif // MYGLWIDGET_H
