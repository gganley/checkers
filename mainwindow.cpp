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
  int endX = e->x();
  int endY = e->y();
  bool tryingToMove = abs((endX / 80) - (mouseX / 80)) == 1 && abs((endY / 80) - (mouseY / 80)) == 1;
  bool tryingToJump = abs((endX / 80) - (mouseX / 80)) == 2 && abs((endY / 80) - (mouseY / 80)) == 2;

  // check if trying to jump or just trying to move
  
  if (tryingToMove) {
    switch(owner(endX, endY)) {
    case 0:
      
      selected->setCords(std::make_pair(endX / 80, endY / 80));
      repaint();
    }
  } else if (tryingToJump) {
    Piece* jumpedPiece;
    switch(owner(mouseX, mouseY)) {
    case 1:
      //black
      // y should be positive and linear with x
      if ((endX / 80) - (mouseX / 80) == 2 && (endY / 80) - (mouseY / 80) == 2) {
	switch (owner(mouseX + 80, mouseY + 80)) {
	  // move and remove red piece
    case 2:
	  for (auto a : Red) {
          qDebug() << a->getCords().second << a->getCords().first;
        if (a->compareCords(std::make_pair((mouseX / 80) + 1, (mouseY / 80) + 1))){
          jumpedPiece = a;
          break;
	    }
	  }
	  Red.erase(std::find(Red.begin(), Red.end(), jumpedPiece));
	  selected->setCords(std::make_pair(endX / 80, endY / 80));
	  repaint();
	  break;
	}
      } else if ((endX / 80) - (mouseX / 80) == -2 && (endY / 80) - (mouseY / 80) == 2) {
	switch (owner(mouseX - 80, mouseY + 80)) {
	case 2:
	  // move and remove red piece
	  for (auto a : Red) {
        if (a->compareCords(std::make_pair((mouseX / 80) - 1, (mouseY / 80) + 1))) {
	      jumpedPiece = a;
	      break;
	    }
	  }
	  Red.erase(std::find(Red.begin(), Red.end(), jumpedPiece));
	  selected->setCords(std::make_pair(endX / 80, endY / 80));
	  repaint();
	}
      }
      break;
    case 2:
      // red
      // y should be negitaive and linear with x
      if ((endX / 80) - (mouseX / 80) == 2 && (endY / 80) - (mouseY / 80) == -2) {
	switch (owner(mouseX + 80, mouseY - 80)) {
	case 1:
	  for (auto a : Black) {
        if (a->compareCords(std::make_pair((mouseX / 80) + 1, (mouseY / 80) - 1))) {
	      jumpedPiece = a;
	      break;
	    }
	  }
	  Black.erase(std::find(Black.begin(), Black.end(), jumpedPiece));
	  selected->setCords(std::make_pair(endX / 80, endY / 80));
	  repaint();
	}
      } else if ((endX / 80) - (mouseX / 80) == -2 && (endY / 80) - (mouseY / 80) == -2){
	switch (owner(mouseX - 80, mouseY - 80)) {
	case 1:
	  for (auto a : Black) {
        if (a->compareCords(std::make_pair((mouseX / 80) - 1, (mouseY / 80) - 1))) {
	      jumpedPiece = a;
	      break;
	    }
	  }
	  Black.erase(std::find(Black.begin(), Black.end(), jumpedPiece));
	  selected->setCords(std::make_pair(endX / 80, endY / 80));
	  repaint();	  
	}
      }
      break;
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
