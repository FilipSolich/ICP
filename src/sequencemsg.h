#ifndef SEQUENCEMSG_H
#define SEQUENCEMSG_H

#include <QWidget>
#include <sequencediagram.hh>

class SequenceDiagram;

class SequenceMsg : public QWidget
{
    Q_OBJECT

public:
    SequenceMsg(SequenceDiagram *parentDiagram);

    SequenceDiagram *parentDiagram;

    void draw_sync();
    void draw_async();
    void draw_create();
    void draw_destroy();

 public slots:
        void draw_sync_slot(void);
        void draw_async_slot(void);
        void draw_create_slot(void);
        void draw_destroy_slot(void);
};

#endif // SEQUENCEMSG_H