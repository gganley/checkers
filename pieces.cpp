#include "pieces.h"

void Piece::draw(QPainter *e)
{
  e->setBrush(c);
  e->drawEllipse(QPoint(posX,posY), 40, 40);
}

std::pair<int,int> Piece::getPos()
{
    return std::make_pair(posX, posY);
}

void Piece::setPos(std::pair<int,int> n)
{
  posX = n.first;
  posY = n.second;
}

void Piece::setCords(std::pair<int,int> n)
{
  posX = n.first * 80 + 40;
  posY = n.second * 80 + 40;
}

bool Piece::compareCords(std::pair<int,int> n)
{
  if (posX / 80 == n.first / 80 && posY / 80 == n.second / 80)
    return true;

  return false;
}

std::pair<int,int> getCords()
{
  return std::make_pair(posX / 80, posY / 80);
}
