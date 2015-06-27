#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "blank.h"
#include "destroy.h"
#include "star.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setclickpic(blank*b);
    void gamestart();//初始化遊戲
    bool judge(int r1,int c1,int r2,int c2);
    bool judgestar(int row,int col);
    void renewpic();
    ~MainWindow();
public slots:
    void button_clicked(int row,int column);
    void zerovanish();
private:
    Ui::MainWindow *ui;
    bool isclicked;
    int record_r;
    int record_c;
    blank *b[10][10];
};

#endif // MAINWINDOW_H
