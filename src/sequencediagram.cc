#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "sequencediagram.hh"
#include "diagram.hh"
#include "class.hh"
#include "sequence.h"

#include <QLabel>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>


SequenceDiagram::SequenceDiagram(QWidget *parent, Diagram *diagram)
    : QWidget{parent}
{
    this->diagram = diagram;

    QVBoxLayout *seq_layout = new QVBoxLayout;
    this->setLayout(seq_layout);

    sequence_scene = new QGraphicsScene;

    QGraphicsView *sequence_view = new QGraphicsView(this);
    sequence_view->setScene(sequence_scene);
    seq_layout->addWidget(sequence_view);


    // the bug, of crash new tab is there
    /*if(diagram->classes.size() == 0)
    {
        QVector<QString> v_names(1);
    }
    else
    {
        QVector<QString> v_names(diagram->classes.size());
    }

    if (diagram->classes.size() != 0){
       for(int i=0; i< diagram->classes.size(); ++i)
       {
            v_names += diagram->classes.at(i)->widget->name->text();
       }
     }*/
     QVector<QString> v_names(1);
     makeSequence(v_names);
}

void SequenceDiagram::makeSequence(QVector<QString> names)
{

    if (names.size() != 0 ) //empty
    {
        for(int i=0; i<names.size();i++){
            Sequence *new_seq = new Sequence();

            QGraphicsRectItem *seq_rect = sequence_scene->addRect(0,0,200,50);
            seq_rect->setFlag(QGraphicsItem::ItemIsMovable);
            seq_rect->setFlag(QGraphicsItem::ItemIsSelectable);

            QGraphicsProxyWidget *seq_proxy = sequence_scene->addWidget(new_seq);
            new_seq->seq_proxy = seq_proxy;
            seq_proxy->setPos(0, 0);
            seq_proxy->setParentItem(seq_rect);
        }
    }


}

void SequenceDiagram::addConnection()
{
    // TODO
}

void SequenceDiagram::Activate()
{
    // TODO
}

void SequenceDiagram::Deactivate()
{
    // TODO
}

void SequenceDiagram::Timestamp()
{
    //TODO
}
