#ifndef CLASS_HH
#define CLASS_HH

#include <QString>

#include "cdclass.hh"
#include "sdclass.h"
class Diagram;
class CDEditor;
class SequenceEditor;
class Class
{
public:
    QString name;
    Diagram *diagram = nullptr;
    CDClass *cdClass = nullptr;
    SDClass *sdClass = nullptr;
    SequenceEditor *sequence = nullptr;

    Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceEditor *> *sqEditors, QPointF pos = {0, 0});

    ~Class();

    void setName(QString newName);
    QString getName();
};

#endif // CLASS_HH
