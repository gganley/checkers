#ifndef PIECES
#define PIECES

#include <QPaintDevice>

class Piece
{
  int x, y;
 public:
  void draw(QPaintDevice *);
};

#endif // PIECES

