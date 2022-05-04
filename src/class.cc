/**
 * \file class.cc
 *
 * \brief Source code for `Class` class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#include "class.hh"
#include "diagram.hh"
#include "sequenceeditor.hh"
#include "sdclass.h"

Class::Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceEditor *> *sqEditors, QString name, QPointF pos)
    : name{name},
      diagram{diagram}
{
    cdClass = new CDClass(this, cdEditor, pos);
    for(SequenceEditor *sq_i : *sqEditors){

        SDClass *p =  new SDClass(sq_i,this);
        sq_i->v_diagrams.push_back(p);
        //sdClass->push_back(p);
    }
}

Class::~Class()
{
    //sdClass->erase(std::remove(sdClass->begin(), sdClass->end(), nullptr), sdClass->end());
    delete sdClass;
    delete cdClass;
    diagram->classes.remove(diagram->classes.indexOf(this));

}

void Class::setName(QString newName)
{
    if (name != newName) {
        name = newName;
        emit setNameSignal(name);
    }
}

QString Class::getName()
{
    return name;
}
