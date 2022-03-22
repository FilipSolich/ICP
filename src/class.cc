#include "class.hh"

Class::Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors)
{
    // TODO: Create CDClass and SDClass
    cdClass = new CDClass(diagram, cdEditor);
}

void Class::setName(QString name)
{

}

QString Class::getName()
{

}
