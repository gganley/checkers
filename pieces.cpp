void Piece::draw(QPaintDevice *e)
{
  QPainter painter(e);
  painter.paintEllipse(QPoint(x,y), 40, 40);
}
