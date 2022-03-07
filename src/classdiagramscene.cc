#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "diagram.hh"
#include "class.hh"
#include "classdiagramscene.hh"

#include <QLabel>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>

ClassDiagramScene::ClassDiagramScene(QWidget *parent, Diagram *diagram)
    : QWidget(parent)
{
    this->diagram = diagram;

    QVBoxLayout *layout = new QVBoxLayout;
    this->setLayout(layout);

    scene = new QGraphicsScene;

    QGraphicsView *view = new QGraphicsView(this);
    view->setScene(scene);
    layout->addWidget(view);

    // Green rectangle
    //QBrush *greenBrush = new QBrush(Qt::green);
    //QPen *outlinePen = new QPen(Qt::black);
    //outlinePen->setWidth(2);

    //QGraphicsRectItem *rect = scene->addRect(-100.0, -100.0, 80.0, 100.0, *outlinePen, *greenBrush);
    //rect->setFlag(QGraphicsItem::ItemIsMovable);

    //QLabel *label = new QLabel;
    //label->setText("TEXT");

    //QGraphicsRectItem *rect1 = scene->addRect(10, 10, 50, 50, *outlinePen, *greenBrush);
    //rect1->setFlag(QGraphicsItem::ItemIsMovable);

    //QGraphicsProxyWidget *proxy = scene->addWidget(label);
    //proxy->setPos(0, rect1->rect().height());
    //proxy->setParentItem(rect1);

    addClass();
}

void ClassDiagramScene::addClass()
{
    int x = 0, y = 0;
    Class *new_class = new Class();
    this->diagram->classes.push_back(new_class);

    QGraphicsRectItem *rect = scene->addRect(x, y, new_class->width(), new_class->height());
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    rect->setFlag(QGraphicsItem::ItemIsSelectable);

    QGraphicsProxyWidget *proxy = scene->addWidget(new_class);
    new_class->proxy = proxy;
    proxy->setPos(x, y);
    proxy->setParentItem(rect);
}
