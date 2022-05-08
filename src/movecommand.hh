/**
 * \file movecommand.hh
 *
 * \brief Class implementing move command for class diagram class move.
 *
 * \date 8. 5. 2022
 * \author Filip Solich
 */
#ifndef MOVECOMMAND_HH
#define MOVECOMMAND_HH

#include <QGraphicsItem>
#include <QUndoCommand>
#include <QObject>


// This code is taken from https://doc.qt.io/qt-5/qtwidgets-tools-undoframework-example.html
/**
 * Class implement QUndoCommand for class move action
 */
class MoveCommand : public QUndoCommand
{
public:
    /** Cosntructor */
    MoveCommand(QGraphicsItem *item, const QPointF &oldPosition, QUndoCommand *parent = nullptr);

    /**
     * move class on its old postion
     */
    void undo() override;

private:
    QGraphicsItem *myDiagramItem;
    QPointF myOldPos;
    QPointF newPos;
};

#endif // MOVECOMMAND_HH
