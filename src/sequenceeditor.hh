#ifndef SEQUENCEEDITOR_H
#define SEQUENCEEDITOR_H

#include <QWidget>
#include <QGraphicsScene>
#include <QVector>
#include "diagram.hh"
#include "sdclass.h"
#include "sdedge.h"
#include <QPainter>
class SequenceEditor : public QWidget
{
    Q_OBJECT

    Diagram *diagram = nullptr;
    QVector<SDClass *> v_diagrams;
    QVector<QGraphicsRectItem *> v_rect_diagrams;

public:
    SDEdge *currentEdge = nullptr;

    QGraphicsScene *sequence_scene = nullptr;

    explicit SequenceEditor(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    void makeSequence(QVector<QString> names);


    void remove();



};
#endif // SEQUENCEEDITOR_H
