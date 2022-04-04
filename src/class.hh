#ifndef CLASS_HH
#define CLASS_HH

#include <QString>

#include "cdclass.hh"

class Diagram;
class CDEditor;
class SequenceDiagram;

class Class
{
public:
    QString name;
    Diagram *diagram = nullptr;
    CDClass *cdClass = nullptr;
    // TODO Add SDClass

    Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceDiagram *> *sqEditors, QString name = "", QPointF pos = {0, 0});
    ~Class();

    void setName(QString newName);
    QString getName();
};

#endif // CLASS_HH
