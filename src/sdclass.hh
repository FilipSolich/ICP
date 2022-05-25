/**
 * \file sdclass.h
 *
 * \brief `SDClass` class representing SequenceDiagram class.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */

#ifndef SDCLASS_H
#define SDCLASS_H

#include <QWidget>

#include "sdsocket.hh"
#include "sdclassitem.hh"
#include "sdclasswidget.hh"

class SDEditor;
class Class;

/**
* This class encapsulates Sequenceitem and SeqeunceWidget(pointers).
*  Contains only public objects.
*/
class SDClass
{
public:

    QGraphicsProxyWidget *seq_proxy = nullptr;
    SDEditor *diagram;

    Class *cls = nullptr;

    SDClassItem *item = nullptr;
    SequenceWidget *widget = nullptr;
    SDSocket *sockets[18];
    QPointF position;

    /**
     * SDClass constructor
     * \param diagram is pointer on  `SequenceEditor`
     * \param cls is pointer on  `Class`
     */
    SDClass(SDEditor *diagram = nullptr , Class *cls = nullptr, QPointF position = {0,0});

    /**
     * Destructor of SDClass
     */
    ~SDClass();

    /**
     * Redraw new position on sockets
     */
    void redrawSockets(void);
};

#endif // SDCLASS_H
