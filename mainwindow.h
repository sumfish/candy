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
    bool judge(int r1, int c1);
    bool judgestar(int row,int col);
    void renewpic();
    int bomb(int r, int c);
    int record(int r, int c);
    int drop();//往下移動
    bool trychange(int r, int c);//試能不能移動
    int producenewpic();//
    ~MainWindow();
public slots:
    void button_clicked(int row,int column);
    void zerovanish();
private:
    Ui::MainWindow *ui;
    bool isclicked;
    int indexv;//橫斜炸彈
    int indexh;
    int record_r;
    int record_c;
    int lbomb;//九宮格炸彈
    int temnum;
    int over;
    int step;
    int score;
    bool lasttest();
    blank *b[10][10];
    int re[10][10];
};

#endif // MAINWINDOW_H
