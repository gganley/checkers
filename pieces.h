#ifndef PIECES
#define PIECES

#include <QPaintDevice>
#include <QPainter>
#include <QMouseEvent>

#include <utility>

class Piece
{
  int posX, posY;
  QColor c;
public:

  Piece(int arg1, int arg2, QColor arg3)
    : posX(arg1), posY(arg2), c(arg3) {}
  void draw(QPainter *);
  std::pair<int,int> getPos();
  std::pair<int,int> getCords();
  void setPos(std::pair<int,int>);
  void setCords(std::pair<int,int>);
  bool compareCords(std::pair<int,int>)
};

#endif // PIECES

