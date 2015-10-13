#include "mainwindow.h"


void drawBoard(QPainter *);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  // init Player1 and Player2;
  // buffer so that ellipse is in the middle
  int bufferL = 40;
  int bufferU = 40;
  
  for (int i = 0; i < 8; ++i) {
    // Player1 or top rows
    if (i % 2 == 0) {
      Player1.push_back(Piece(bufferL + (i * 80), 0 + bufferU, QColor(0,0,0)));
    } else {
      Player1.push_back(Piece(bufferL + (i * 80), 1 * 80 + bufferU, QColor(0,0,0)));
    }
  }

  for (int i = 0; i < 8; ++i) {
    if (i % 2 == 0) {
      Player2.push_back(Piece(bufferL + (i * 80), 6 * 80 + bufferU, QColor(255,0,0)));      
    } else {
      Player2.push_back(Piece(bufferL + (i * 80), 7 * 80 + bufferU, QColor(255,0,0)));
    }
  }
}

MainWindow::~MainWindow()
{
  
}

void MainWindow::paintEvent(QPaintEvent *)
{
  qDebug() << "painted at " << time(0) << endl;
  QPainter p(this);
  bool b = true;
  int bufferL, bufferU = 0;
  for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
          if (b) {
              p.fillRect(bufferL, bufferU, 80, 80, QColor(125,125,125));
          } else {
              p.fillRect(bufferL, bufferU, 80, 80, QColor(255,255,255));
          }
          b = !b;
          bufferL += 80;
      }
      b = !b;
      bufferL = 0;
      bufferU += 80;
  }
  
  for (Piece x: Player1) {
    x.draw(&p);
  }
  for (Piece x: Player2) {
    x.draw(&p);
  }
  
}

//void MainWindow::mousePressEvent(QMouseEvent *e)
void MainWindow::mousePressEvent(QMouseEvent *)
{
  
}

//void MainWindow::mouseReleaseEvent(QMouseEvent *e)
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
  
}

void MainWindow::drawPieces(QPainter *)
{  

}

void drawBoard(QPainter *)
{

}

