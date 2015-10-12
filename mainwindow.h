#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pieces.h"
#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::vector<Piece> Player1;
    std::vector<Piece> player2;
public:
    MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void drawPieces(QPaintEvent *);
    ~MainWindow();
};

#endif // MAINWINDOW_H
