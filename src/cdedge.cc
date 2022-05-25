/**
 * \file cdedge.cc
 *
 * \brief Source code file for `CDEdge` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#include <QGraphicsScene>

#include "cdedge.hh"
#include "cdedgeitem.hh"
#include "cdeditor.hh"
#include <QMessageBox>

QMap<CDEdge::Type, QString> CDEdge::typeMap = {
    {CDEdge::Type::Association, "Association"},
    {CDEdge::Type::Aggregation, "Aggregation"},
    {CDEdge::Type::Composition, "Composition"},
    {CDEdge::Type::Generalization, "Generalization"},
};

CDEdge::CDEdge(QString type, CDSocket *s1, CDSocket *s2)
{
    this->type = CDEdge::typeMap.key(type);

    item = new CDEdgeItem(this);
    s1->item->scene()->addItem(item);

    setSocket(s1, EdgeEndType::Start);
    setSocket(s2, EdgeEndType::End);

    if (!s2) {
        this->startSocket->cdClass->editor->currentEdge = this;
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

void CDEdge::setSocket(CDSocket *socket, EdgeEndType type)
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
        CreateTaskWindow();
    }
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
    }

    setPath();

}

void CDEdge::setPath()
{
    QPainterPath path{startPoint};
    path.cubicTo(c1, c2, endPoint);
    item->setPath(path);

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
    QLineEdit le;

    QLabel kard_label;
    kard_label.setText("Cardinality(from):");

    QLabel kard_label2;
    kard_label2.setText("Cardinality(to):");

    QLineEdit kardinalita_in;
    QLineEdit kardinalita_out;

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
        mg->layout()->addWidget(&le);

        mg->layout()->addWidget(&kard_label);
        mg->layout()->addWidget(&kardinalita_in);

        mg->layout()->addWidget(&kard_label2);
        mg->layout()->addWidget(&kardinalita_out);

        mg->addButton(QMessageBox::Ok);
        mg->exec();
    }
}
