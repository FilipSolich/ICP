#ifndef SEQUENCEDIAGRAM_HH
#define SEQUENCEDIAGRAM_HH

#include <QWidget>
#include <QGraphicsScene>

#include "diagram.hh"

class SequenceDiagram : public QWidget
{
    Q_OBJECT
    QGraphicsScene *sequence_scene = nullptr;
    Diagram *diagram = nullptr;
public:
    explicit SequenceDiagram(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    void makeSequence(QVector<QString> names);
    void addConnection();
    void Activate();
    void Deactivate();
    void Timestamp();
signals:

};

#endif // SEQUENCEDIAGRAM_HH
