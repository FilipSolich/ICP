/**
 * \file movecommand.cc
 *
 * \brief Source code for MoveCommand.
 *
 * \date 8. 5. 2022
 * \author Filip Solich
 */

#include <QGraphicsScene>

#include "movecommand.hh"

MoveCommand::MoveCommand(QGraphicsItem *item, const QPointF &oldPosition, QUndoCommand *parent)
    : QUndoCommand(parent), myDiagramItem(item)
    , myOldPos(oldPosition), newPos(item->pos())
{
}

void MoveCommand::undo()
{
    myDiagramItem->setPos(myOldPos);
    myDiagramItem->scene()->update();
}
