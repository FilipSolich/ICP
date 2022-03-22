/**
 * \file classdiagrameditor.hh
 *
 * \brief ClassDiagramEditor class representing editor for class diagrams.
 *
 * \date 8. 4. 2022
 * \author Filip Solich
 */

#ifndef CDEDITOR_H
#define CDEDITOR_H

#include <QWidget>
#include <QGraphicsView>

#include "cdeditorscene.hh"
#include "diagram.hh"

class CDEditor : public QWidget
{
    Q_OBJECT

    Diagram *diagram = nullptr;

public:
    QGraphicsView *view = nullptr;
    CDEditorScene *scene = nullptr;

    CDEditor(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    CDClass *addClass(int x = 0, int y = 0);
    void removeClass(void);
};

#endif // CDEDITOR_H
