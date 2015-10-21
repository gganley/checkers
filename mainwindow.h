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
  std::vector<Piece*> Red;
  std::vector<Piece*> Black;
  int mouseX, mouseY;
  bool turn = true; // true == red, false == black
  Piece* selected;
  
public:
  MainWindow(QWidget *parent = 0);
  void paintEvent(QPaintEvent *);
  void mousePressEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent *);
  
  void drawPieces(QPainter *);
  int owner(int x, int y);
  void anyNewKings();
  ~MainWindow();
};

#endif // MAINWINDOW_H
