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

#include "sdsocket.h"
#include "sequenceitem.h"
#include "sequencewidget.h"
class SequenceEditor;
class Class;
/**
* This class encapsulates Sequenceitem and SeqeunceWidget(pointers).
*  Contains only public objects.
*/
class SDClass
{

public:

    QGraphicsProxyWidget *seq_proxy = nullptr;
    SequenceEditor *diagram;

    Class *cls = nullptr;

    Sequenceitem *item = nullptr;
    SequenceWidget *widget = nullptr;
    SDSocket *sockets[18];
    QPointF position;
    /**
     * SDClass constructor
     * \param diagram is pointer on  `SequenceEditor`
     * \param cls is pointer on  `Class`
     * */
    SDClass(SequenceEditor *diagram = nullptr , Class *cls = nullptr, QPointF position = {0,0});
    /**
     * Destructor of SDClass
     *
    */
    ~SDClass();

    /**
     * Redraw new position on sockets§
     */
    void redrawSockets(void);


};

#endif // SDCLASS_H
