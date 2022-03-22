#include "class.hh"
#include "diagram.hh"

Class::Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors, QPointF pos)
    : diagram{diagram}
{
    // TODO: Create CDClass and SDClass
    cdClass = new CDClass(cdEditor, this, pos);
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
