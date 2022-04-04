/**
 * \file class.cc
 *
 * \brief Source code for Class class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#include "class.hh"
#include "diagram.hh"

Class::Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors, QString name, QPointF pos)
    : name{name},
      diagram{diagram}
{
    // TODO: Create CDClass and SDClass
    cdClass = new CDClass(this, cdEditor, pos);
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
