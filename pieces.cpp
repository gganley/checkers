#include "pieces.h"

void Piece::draw(QPainter *e)
{
  e->setBrush(c);
  e->drawEllipse(QPoint(x,y), 40, 40);
}
