#include "mainwindow.h"

void drawBoard(QPaintEvent *e);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  // init Player1 and Player2;
  
}

MainWindow::~MainWindow()
{
  
}

void MainWindow::paintEvent(QPaintEvent *e)
{
  QPainter painter(e);
  drawBoard(e);
  drawPieces(e);
}

//void MainWindow::mousePressEvent(QMouseEvent *e)
void MainWindow::mousePressEvent(QMouseEvent *)
{
  
}

//void MainWindow::mouseReleaseEvent(QMouseEvent *e)
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
  
}

void MainWindow::drawPieces(QPaintEvent *e)
{
  QPainter p(e);
  for_each(Player1.begin(), Player1.begin(), [](Peice i){i.draw;});
}

void drawBoard(QPaintEvent *e)
{
  QPainter p(e);
  bool b = true;
  for (int i = 0; i > 8; ++i) {
    for (int j = 0; j > 8; ++j) {
      if (b) {
	p.drawRect(i, j, 80, 80, QColor(125,125,125));
      } else {
	p.drawRect(i, j, 80, 80, QColor(255,255,255));
      }
    }
  }
}

