#ifndef BLANK_H
#define BLANK_H

#include<QPushButton>
#include<QObject>
#include<Qtimer>

class blank:public QObject{
    Q_OBJECT
public:
    blank(int R,int C,QWidget *parent);
    const int row;
    const int column;
    int number;
    QPushButton *button;
    QTimer *time;
    int shift;
    void setnumber();
    void setbuttonpic();
    void operator-(blank*b);
    void operator|(blank*b);
public slots:
    void click();
    void moveleft();
    void moveright();
    void movedown();
    void moveup();

signals:
    void Click(int row,int column);
    void movedone();
};

#endif // BLANK_H
