#ifndef PIECES
#define PIECES

#include <QPaintDevice>
#include <QPainter>

class Piece
{
  int x, y;
  QColor c;
public:
  Piece(int arg1, int arg2, QColor arg3)
    : x(arg1), y(arg2), c(arg3) {}
  void draw(QPainter *);
};

#endif // PIECES

