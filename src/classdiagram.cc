#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "classdiagram.hh"

ClassDiagram::ClassDiagram(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    this->setLayout(layout);

    QGraphicsScene *gs = new QGraphicsScene;

    QGraphicsView *view = new QGraphicsView(this);
    view->setScene(gs);
    layout->addWidget(view);

    // Green rectangle
    QBrush *greenBrush = new QBrush(Qt::green);
    QPen *outlinePen = new QPen(Qt::black);
    outlinePen->setWidth(2);

    QGraphicsRectItem *rect = gs->addRect(-100.0, -100.0, 80.0, 100.0, *outlinePen, *greenBrush);
    rect->setFlag(QGraphicsItem::ItemIsMovable);
}
