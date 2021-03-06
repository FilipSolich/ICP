/**
 * \file cdedge.cc
 *
 * \brief Source code file for `CDEdge` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include <QDebug>
#include <QGraphicsScene>
#include <QMessageBox>

#include "cdedge.hh"
#include "cdedgeitem.hh"
#include "cdeditor.hh"

QMap<CDEdge::Type, QString> CDEdge::typeMap = {
    {CDEdge::Type::Association, "Association"},
    {CDEdge::Type::Aggregation, "Aggregation"},
    {CDEdge::Type::Composition, "Composition"},
    {CDEdge::Type::Generalization, "Generalization"},
};

CDEdge::CDEdge(QString type, CDSocket *s1, CDSocket *s2, bool import)
{
    this->type = CDEdge::typeMap.key(type);

    item = new CDEdgeItem(this);
    s1->item->scene()->addItem(item);

    setSocket(s1, EdgeEndType::Start, import);
    setSocket(s2, EdgeEndType::End, import);

    if (!s2) {
        this->startSocket->cdClass->editor->currentEdge = this;
    }

    if (this->type == Type::Aggregation || this->type == Type::Generalization) {
        QPointF socketCenter;
        if (s2) {
             socketCenter = s2->getSocketCenter();
        } else {
            socketCenter = s1->getSocketCenter();
        }
        arrow1 = new QGraphicsLineItem(socketCenter.x(), socketCenter.y(), arrowPoint1.x(), arrowPoint1.y(), item);
        arrow2 = new QGraphicsLineItem(socketCenter.x(), socketCenter.y(), arrowPoint2.x(), arrowPoint2.y(), item);
        QPen pen = item->pen();
        arrow1->setPen(pen);
        arrow2->setPen(pen);
    }
}

CDEdge::~CDEdge()
{
    item->scene()->removeItem(item);
    delete item;
    if (startSocket) {
        if (type == Type::Generalization && !startSocket->cdClass->editor->currentEdge) {
            startSocket->cdClass->removeHeredity(endSocket->cdClass, true);
        }
        startSocket->removeEdge(this);
    }

    if (endSocket) {
        if (type == Type::Generalization && !startSocket->cdClass->editor->currentEdge) {
            endSocket->cdClass->removeHeredity(startSocket->cdClass, false);
        }
        endSocket->removeEdge(this);
    }
}

void CDEdge::setSocket(CDSocket *socket, EdgeEndType type, bool import)
{
    if (type == EdgeEndType::Start) {
        startSocket = socket;
    } else {
        endSocket = socket;
    }

    if (socket) {
        setPoints(type, socket->getSocketCenter(), socket->position);
    } else if (type == EdgeEndType::End) {
        setPoints(type, startSocket->getSocketCenter(), startSocket->position);
    }

    if (type == EdgeEndType::End && socket != nullptr) {
        startSocket->cdClass->editor->currentEdge = nullptr;
        this->item->setFlag(QGraphicsItem::ItemIsSelectable);
        if (!import) {
            CreateTaskWindow();
        }
        createLabels();
    }
}

void CDEdge::createLabels()
{

    QPointF p = this->startSocket->getSocketCenter();
    QPointF p2 = this->endSocket->getSocketCenter();

    if(this->startSocket->position == CDSocket::Position::Top)
        p.ry()-= 40;
    else if(this->startSocket->position == CDSocket::Position::Bottom)
        p.ry()+= 40;

    else if(this->startSocket->position == CDSocket::Position::Left)
        p.rx() -= 20;

    else if(this->startSocket->position == CDSocket::Position::Right)
        p.rx() += 20;

    if(this->endSocket->position == CDSocket::Position::Top)
       p2.ry()-=40;
    else if(this->endSocket->position == CDSocket::Position::Bottom)
        p2.ry()+=40;

    else if(this->endSocket->position == CDSocket::Position::Left)
        p2.rx() -= 20;

    else if(this->endSocket->position == CDSocket::Position::Right)
        p2.rx() += 20;

    kard_start = new QGraphicsTextItem(kardinalita_from.text(), item);
    kard_start->setPos(p);

    kard_end = new QGraphicsTextItem(kardinalita_to.text(), item);
    kard_end->setPos(p2);


    edgeText = new QGraphicsTextItem(name.text(), item);
    float px = p.x() + p2.x() ;
    float py = p.y() + p2.y() ;
    edgeText->setPos(px/2.0,py/2.0);


    kard_start->setFlag(QGraphicsItem::ItemIsMovable);
    kard_start->setFlag(QGraphicsItem::ItemIsSelectable);
    kard_end->setFlag(QGraphicsItem::ItemIsMovable);
    kard_end->setFlag(QGraphicsItem::ItemIsSelectable);
    edgeText->setFlag(QGraphicsItem::ItemIsMovable);
    edgeText->setFlag(QGraphicsItem::ItemIsSelectable);
}

QPointF CDEdge::calculateC(QPointF point, CDSocket::Position socPos)
{
    QPointF c{point};
    switch (socPos) {
        case CDSocket::Position::Top:
            c.setY(c.y() - C_DISTANCE);
            break;
        case CDSocket::Position::Right:
            c.setX(c.x() + C_DISTANCE);
            break;
        case CDSocket::Position::Bottom:
            c.setY(c.y() + C_DISTANCE);
            break;
        case CDSocket::Position::Left:
            c.setX(c.x() - C_DISTANCE);
            break;
    }

    return c;
}

void CDEdge::setPoints(EdgeEndType type, QPointF point, CDSocket::Position socPos)
{
    if (type == EdgeEndType::Start) {
        startPoint = point;
        c1 = calculateC(point, socPos);
    } else {
        endPoint = point;
        c2 = calculateC(point, socPos);
        if (socPos == CDSocket::Position::Top) {
            arrowPoint1.setX(endPoint.x() - 10);
            arrowPoint1.setY(endPoint.y() - 10);
            arrowPoint2.setX(endPoint.x() + 10);
            arrowPoint2.setY(endPoint.y() - 10);
        } else if (socPos == CDSocket::Position::Right) {
            arrowPoint1.setX(endPoint.x() + 10);
            arrowPoint1.setY(endPoint.y() - 10);
            arrowPoint2.setX(endPoint.x() + 10);
            arrowPoint2.setY(endPoint.y() + 10);
        } else if (socPos == CDSocket::Position::Bottom) {
            arrowPoint1.setX(endPoint.x() - 10);
            arrowPoint1.setY(endPoint.y() + 10);
            arrowPoint2.setX(endPoint.x() + 10);
            arrowPoint2.setY(endPoint.y() + 10);
        } else if (socPos == CDSocket::Position::Left) {
            arrowPoint1.setX(endPoint.x() - 10);
            arrowPoint1.setY(endPoint.y() - 10);
            arrowPoint2.setX(endPoint.x() - 10);
            arrowPoint2.setY(endPoint.y() + 10);
        }
    }

    setPath();

}

void CDEdge::setPath()
{
    QPainterPath path{startPoint};
    path.cubicTo(c1, c2, endPoint);
    item->setPath(path);

    if (arrow1) {
        arrow1->setLine(endPoint.x(), endPoint.y(), arrowPoint1.x(), arrowPoint1.y());
    }
    if (arrow2) {
        arrow2->setLine(endPoint.x(), endPoint.y(), arrowPoint2.x(), arrowPoint2.y());
    }
}

void CDEdge::setMousePos(QPointF pos)
{
    setPoints(EdgeEndType::End, pos);
}

void CDEdge::socketMoved(CDSocket *s)
{
    if (s == startSocket) {
        setPoints(EdgeEndType::Start, s->getSocketCenter(), s->position);
    } else {
        setPoints(EdgeEndType::End, s->getSocketCenter(), s->position);
    }
}

void CDEdge::CreateTaskWindow(){

    QMessageBox *mg = new QMessageBox;
    QLabel namelabel;
    namelabel.setText("Name of relation: ");

    QLabel kard_from_label;
    kard_from_label.setText("Cardinality(from):");

    QLabel kard_to_label;
    kard_to_label.setText("Cardinality(to):");

    mg->setWindowTitle("SET PATH");
    if(this->type == Type::Association){
         mg->setText("Association");

    }
    else if(this->type == Type::Composition){
          mg->setText("Composition");
    }

    if( this->type == Type::Composition or this->type == Type::Association)
    {
        mg->layout()->addWidget(&namelabel);
        mg->layout()->addWidget(&name);

        mg->layout()->addWidget(&kard_from_label);
        mg->layout()->addWidget(&kardinalita_from);

        mg->layout()->addWidget(&kard_to_label);
        mg->layout()->addWidget(&kardinalita_to);

        mg->addButton(QMessageBox::Ok);
        mg->exec();
    }
}
