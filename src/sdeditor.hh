/**
 * \file sequenceeditor.h
 *
 * \brief `SequenceEditor` class representing Editor of SDClass.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */


#ifndef SDEDITOR_H
#define SDEDITOR_H

#include <QWidget>
#include <QGraphicsScene>
#include <QVector>
#include "diagram.hh"
#include "sdclass.hh"
#include "sdedge.hh"
#include <QPainter>

/**
 * \brief The SequenceEditor class
 */
class SDEditor : public QWidget
{



public:
    Diagram *diagram = nullptr;

    QVector<QGraphicsRectItem *> v_rect_diagrams;
    QVector<SDClass *> v_diagrams;
    SDEdge *currentEdge = nullptr;

    QGraphicsScene *sequence_scene = nullptr;
    /**
     * \brief SequenceEditor Constructor
     * \param parent pointer on parent qwidget
     * \param diagram pointer on diagram
     */
    explicit SDEditor(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    //TODO delete or not, idk yet
    void makeSequence(QVector<QString> names);
    void remove();



};
#endif // SDEDITOR_H
