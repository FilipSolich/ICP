#include "class.hh"
#include "diagram.hh"

Class::Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors, QPointF pos)
    : diagram{diagram}
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
