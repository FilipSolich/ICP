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
        new SDClass("jmeno",sq_i,pos,this);
    }
}

Class::~Class()
{
    delete cdClass;
    // TODO add delete sdClass
    diagram->classes.remove(diagram->classes.indexOf(this));
}

void Class::setName(QString newName)
{
    name = newName;
}

QString Class::getName()
{
    return name;
}
