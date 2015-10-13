#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintDevice>
#include <QDebug>

#include "pieces.h"
#include <vector>
#include <ctime>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::vector<Piece> Player1;
    std::vector<Piece> Player2;
public:
    MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void drawPieces(QPainter *);
    ~MainWindow();
};

#endif // MAINWINDOW_H
