#ifndef CLASS_HH
#define CLASS_HH

#include <QString>

#include "cdclass.hh"

class SequenceDiagram;

class Class
{
public:
    CDClass *cdClass = nullptr;
    // TODO Add SDClass

    Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors);

    void setName(QString name);
    QString getName();
};

#endif // CLASS_HH
