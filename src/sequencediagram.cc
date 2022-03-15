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
#include <QPushButton>
#include <QGraphicsLayout>
#include <QGraphicsSceneMouseEvent>

SequenceDiagram::SequenceDiagram(QWidget *parent, Diagram *diagram)
    : QWidget{parent}
{
    this->diagram = diagram;

    QVBoxLayout *seq_layout = new QVBoxLayout;

    QWidget *seqBtns = new QWidget(this);

    QGridLayout *seq_layout_btns = new QGridLayout(seqBtns);
    QPushButton *add_btn = new QPushButton("+",seqBtns);
    QPushButton *remove_btn = new QPushButton("-",seqBtns);


    seq_layout_btns->addWidget(add_btn,0,0);
    seq_layout_btns->addWidget(remove_btn,0,1);

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

}

void SequenceDiagram::makeSequence(QVector<QString> names)
{

    if (names.size() != 0 ) //empty
    {
        for(int i=0; i<names.size();i++){
            Sequence *new_seq = new Sequence();

            QGraphicsRectItem *seq_rect = sequence_scene->addRect(0,0,200,300);
            seq_rect->setFlag(QGraphicsItem::ItemIsMovable);
            seq_rect->setFlag(QGraphicsItem::ItemIsSelectable,true);
            seq_rect->setFlag(QGraphicsItem::ItemIsFocusable);

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
