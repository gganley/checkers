// this is some horrible hacking I'm sorry my functional gods

#include "mainwindow.h"


void drawBoard(QPainter *);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  // init Player1 and Player2;
  // buffer so that ellipse is in the middle
  int bufferL = 40;
  int bufferU = 40;
  resize(640, 640);
  for (int i = 0; i < 8; ++i) {
    // Player1 or top rows
    if (i % 2 == 0) {
      Black.push_back(new Piece(bufferL + (i * 80), 0 + bufferU, QColor(0,0,0)));
      Black.push_back(new Piece(bufferL + (i * 80), 2 * 80 + bufferU, QColor(0,0,0)));
    } else {
      Black.push_back(new Piece(bufferL + (i * 80), 1 * 80 + bufferU, QColor(0,0,0)));
    }
  }

  for (int i = 0; i < 8; ++i) {
    if (i % 2 == 0) {
      Red.push_back(new Piece(bufferL + (i * 80), 6 * 80 + bufferU, QColor(255,0,0)));
    } else {
      Red.push_back(new Piece(bufferL + (i * 80), 7 * 80 + bufferU, QColor(255,0,0)));
      Red.push_back(new Piece(bufferL + (i * 80), 5 * 80 + bufferU, QColor(255,0,0)));
    }
  }
}

MainWindow::~MainWindow()
{
  
}

void MainWindow::paintEvent(QPaintEvent *)
{
  QPainter *p = new QPainter(this);

  // BOARD ISNT DRAWING WTF
  drawBoard(p);
  drawPieces(p);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
  mouseX = e->x();
  mouseY = e->y();
  int ownedBy = owner(mouseX, mouseY);
  switch (ownedBy) {
  case 2:
    for (auto a : Red) {
      if(a->compareCords(std::make_pair(mouseX / 80, mouseY / 80))){
        selected = a;
      }
    }
    break;
  case 1:
    for (auto a : Black) {
      if (a->compareCords(std::make_pair(mouseX / 80, mouseY / 80)))
    selected = a;
    }
    break;
  }
     
  // check if turn owner owns the piece
  // bind checker piece to move with cursor
}


void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
  // check if you pressed a piece
  if (owner(mouseX,mouseY) == 0)
    return;
  // check if vector is well behaved
  if (
      // if not proper either one of these
      !(
	// if move
	(abs(endX / 80 - mouseX / 80) == 1 && abs(endY / 80 - mouseY / 80) == 1)
	// if jump
     || (abs(endX / 80 - mouseX / 80) == 2 && abs(endY / 80 - mouseY / 80) == 2)))
    return;
  
  int endX = e->x();
  int endY = e->y();
  // currently king == T
  bool cK = selected->isKing();
  // currently red == T or black == F
  bool cR;
  // trying to move == T or jump == F
  bool M;
  // is the end space empty?
  bool eE = owner(endX,endY) == 0;
  // move vector, something akin to (+- 2, +- 2) || (+- 1, +- 1)
  std::pair<int,int> mV = std::make_pair(endX / 80 - mouseX / 80, endY / 80 - mouseY / 80);
  // is the jumped piece Red?
  bool nR;
  

  if (owner(mouseX,mouseY) == 2)
    cR = true;
  else if (owner(mouseX, mouseY) == 1)
    cR = false;
  
  if (abs(endX / 80 - mouseX / 80) == 1 && abs(endY / 80 - mouseY / 80) == 1)
    M = true;
  else if (abs(endX / 80 - mouseX / 80) == 2 && abs(endY / 80 - mouseY / 80) == 2)
    M = false;

  if (owner((mouseX / 80 + mV.first) * 80, (mouseY / 80 + mV.second) * 80) == 2)
    nR = true;
  else if (owner((mouseX / 80 + mV.first) * 80, (mouseY / 80 + mV.second) * 80) == 1)
    nR = false;
  
  if (cK) {
    if (M) {
      
    } else {
      if (cR && !nR) {
	
      } else if (!cR && nR) {
	
      }      
    }     
  } else {
    if (M) {
      if (cR) {
	if (mV.first == -1 && mV.second == -1) {
	  
	} else if (mV.first == 1 && mV.second == -1) {
	  
	}
      } else {
	if (mV.first == -1 && mV.second == 1) {
	  
	} else if (mV.first == 1 && mV.second == 1) {
	  
	}
      }
    } else {
      if (cR && !nR) {
        if (mV.first == -2 && mV.second == -2) {
	  
	} else if (mV.first == 2 && mV.second == -2) {
	  
	}
      } else if (!nR && nR) {
	if (mV.first == -2 && mV.second == 2) {
	  
	} else if (mV.first == 2 && mV.second == 2) {
	  
	}	
      }
    }
  }

void MainWindow::drawPieces(QPainter *p)
{  
  for (auto x: Red) {
    x->draw(p);
  }
  for (auto x: Black) {
    x->draw(p);
  }
}

void drawBoard(QPainter *p)
{
  bool b = true;
  int bufferL = 0;
  int bufferU = 0;
  
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      
      if (b) {
	p->fillRect(bufferL, bufferU, 80, 80, QColor(125,125,125));
      } else {
	p->fillRect(bufferL, bufferU, 80, 80, QColor(255,255,255));
      }
      
      b = !b;
      bufferL += 80;
      
    }
    
    b = !b;
    bufferL = 0;
    bufferU += 80;
  }
}

int MainWindow::owner(int x, int y)
{


  for (auto n : Black) {
    auto a = n->getPos();
    int posX = a.first;
    int posY = a.second;
    if (posX / 80 == x / 80 && posY / 80 == y / 80) {
      return 1;
    }
  }
  for (auto n : Red) {
    auto a = n->getPos();
    int posX = a.first;
    int posY = a.second;
    if (posX / 80 == x / 80 && posY / 80 == y / 80) {
      return 2;
    }
  }
  return 0;
}
