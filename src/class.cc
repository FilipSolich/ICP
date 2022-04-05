#include "class.hh"
#include "diagram.hh"
#include "sequenceeditor.hh"
#include "sdclass.h"

Class::Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceEditor *> *sqEditors, QPointF pos)
    : diagram{diagram}
{
    cdClass = new CDClass(this, cdEditor, pos);
    for(SequenceEditor *sq_i : *sqEditors){
        new SDClass("jmeno",sq_i);
    }
}

Class::~Class()
{
    delete cdClass;
    // TODO add delete sdClass
    int idx = diagram->classes.indexOf(this);
    diagram->classes.remove(idx);
}

void Class::setName(QString newName)
{
    name = newName;
}

QString Class::getName()
{
    return name;
}
