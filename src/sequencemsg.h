#ifndef SEQUENCEMSG_H
#define SEQUENCEMSG_H

#include <QWidget>
#include <sdeditor.hh>

#include <QPainter>
#include <QPoint>
class SequenceEditor;

class SequenceMsg : public QWidget
{
    Q_OBJECT

public:
    SequenceMsg(SequenceEditor *parentDiagram);

    SequenceEditor *parentDiagram;


    void draw_sync();
    void draw_async();
    void draw_create();
    void draw_destroy();

    //void draw_arrow(QPainter& painter, QPoint start, QPoint end);

 public slots:
        void draw_sync_slot(void);
        void draw_async_slot(void);
        void draw_create_slot(void);
        void draw_destroy_slot(void);
};

#endif // SEQUENCEMSG_H
