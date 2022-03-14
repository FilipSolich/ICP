#ifndef SEQUENCEDIAGRAM_HH
#define SEQUENCEDIAGRAM_HH

#include <QWidget>
#include <QGraphicsScene>
#include <QVector>
#include "diagram.hh"
#include "sequence.h"

class SequenceDiagram : public QWidget
{
    Q_OBJECT
    QGraphicsScene *sequence_scene = nullptr;
    Diagram *diagram = nullptr;
    QVector<Sequence *> v_diagrams;

public:
    explicit SequenceDiagram(QWidget *parent = nullptr, Diagram *diagram = nullptr);

    void makeSequence(QVector<QString> names);
    void addConnection();
    void Activate();
    void Deactivate();
    void Timestamp();

    void remove();
    void add();

public slots:
    void addSeqSlot(void);
    void removeSeqSlot(void);


};
#endif // SEQUENCEDIAGRAM_HH
