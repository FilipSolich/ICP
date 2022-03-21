#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "sequencediagram.hh"
#include "diagram.hh"
#include "class.hh"
#include "sequence.h"
#include "sequencemsg.h"

#include <QLabel>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QGraphicsLayout>
#include <QGraphicsEllipseItem>

SequenceDiagram::SequenceDiagram(QWidget *parent, Diagram *diagram)
    : QWidget{parent}
{
    this->diagram = diagram;

    QVBoxLayout *seq_layout = new QVBoxLayout;

    QWidget *seqBtns = new QWidget(this);

    QGridLayout *seq_layout_btns = new QGridLayout(seqBtns);
    QPushButton *add_btn = new QPushButton("+",seqBtns);
    QPushButton *remove_btn = new QPushButton("-",seqBtns);

    QPushButton *sync_btn = new QPushButton("Sync",seqBtns);
    QPushButton *async_btn = new QPushButton("Async",seqBtns);
    QPushButton *create_btn = new QPushButton("Create",seqBtns);
    QPushButton *destroy_btn = new QPushButton("Destroy",seqBtns);

    seq_layout_btns->addWidget(add_btn,0,0);
    seq_layout_btns->addWidget(remove_btn,0,1);
    seq_layout_btns->addWidget(sync_btn,0,3);
    seq_layout_btns->addWidget(async_btn,0,4);
    seq_layout_btns->addWidget(create_btn,0,5);
    seq_layout_btns->addWidget(destroy_btn,0,6);


    seq_layout_btns->setColumnStretch(0,1);
    seq_layout_btns->setColumnStretch(1,1);
    seq_layout_btns->setColumnStretch(2,30);

    seqBtns->setLayout(seq_layout_btns);
    this->setLayout(seq_layout);

    sequence_scene = new QGraphicsScene;

    QGraphicsView *sequence_view = new QGraphicsView(this);
    sequence_view->setScene(sequence_scene);

    seq_layout->addWidget(seqBtns);
    seq_layout->addWidget(sequence_view);

     QVector<QString> v_names(1);
     makeSequence(v_names);


     connect(add_btn,&QPushButton::clicked,this,&SequenceDiagram::addSeqSlot);
     connect(remove_btn,&QPushButton::clicked,this,&SequenceDiagram::removeSeqSlot);
     connect(async_btn,&QPushButton::clicked,new SequenceMsg(this),&SequenceMsg::draw_async_slot);
     connect(sync_btn,&QPushButton::clicked,new SequenceMsg(this),&SequenceMsg::draw_sync_slot);
     connect(create_btn,&QPushButton::clicked,new SequenceMsg(this),&SequenceMsg::draw_create_slot);
     connect(destroy_btn,&QPushButton::clicked,new SequenceMsg(this),&SequenceMsg::draw_destroy_slot);

}

void SequenceDiagram::makeSequence(QVector<QString> names)
{

    if (names.size() != 0 ) //empty
    {
        for(int i=0; i<names.size();i++){
            Sequence *new_seq = new Sequence();
            auto circle = new QGraphicsEllipseItem(245,50,10,10);
            circle->setFlag(QGraphicsItem::ItemIsMovable);
            circle->setFlag(QGraphicsItem::ItemIsSelectable);




            //QGraphicsRectItem *seq_rect = sequence_scene->addRect(0,0,200,300);
            auto seq_rect = new QGraphicsRectItem(0,0,200,300);
            seq_rect->setFlag(QGraphicsItem::ItemIsMovable);
            seq_rect->setFlag(QGraphicsItem::ItemIsSelectable,true);
            seq_rect->setFlag(QGraphicsItem::ItemIsFocusable);
           // seq_rect->setParentItem(circle);
            circle->setParentItem(seq_rect);

             sequence_scene->addItem(seq_rect);

            QGraphicsProxyWidget *seq_proxy = sequence_scene->addWidget(new_seq);

            new_seq->seq_proxy = seq_proxy;
            seq_proxy->setPos(0, 0);
            seq_proxy->setParentItem(seq_rect);

            v_diagrams.push_back(new_seq);
            v_rect_diagrams.push_back(seq_rect);
        }
    }
}

void SequenceDiagram::add()
{
    QVector<QString> v_names(1);
    makeSequence(v_names);
}
void SequenceDiagram::remove()
{
    for(int i = 0; i<v_rect_diagrams.size();++i)
    {
        if(v_rect_diagrams[i]->isSelected())
        {
           delete v_diagrams[i]->seq_proxy;
           delete v_rect_diagrams[i];
           v_rect_diagrams[i] = nullptr;
           v_diagrams[i] = nullptr;
           break;
        }

    }
    v_diagrams.erase(std::remove(v_diagrams.begin(), v_diagrams.end(), nullptr), v_diagrams.end());
    v_rect_diagrams.erase(std::remove(v_rect_diagrams.begin(), v_rect_diagrams.end(), nullptr), v_rect_diagrams.end());

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

void SequenceDiagram::addSeqSlot(void)
{
    add();
}
void SequenceDiagram::removeSeqSlot(void)
{
    remove();
}

/*
 * TODO
Function for making circles
*/
