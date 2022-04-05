#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "sequenceeditor.hh"
#include "diagram.hh"
#include "cdclass.hh"
#include "sdclass.h"
#include "sequencemsg.h"
#include "sdeditorscene.h"

#include <QLabel>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QGraphicsLayout>
#include <QGraphicsEllipseItem>

SequenceEditor::SequenceEditor(QWidget *parent, Diagram *diagram)
    : QWidget{parent}
{
    this->diagram = diagram;

    QVBoxLayout *seq_layout = new QVBoxLayout;
    QWidget *seqBtns = new QWidget(this);

    QGridLayout *seq_layout_btns = new QGridLayout(seqBtns);

    QPushButton *remove_btn = new QPushButton("-",seqBtns);



    seq_layout_btns->addWidget(remove_btn,0,1);

    seq_layout_btns->setColumnStretch(0,1);
    seq_layout_btns->setColumnStretch(1,1);
    seq_layout_btns->setColumnStretch(2,30);

    seqBtns->setLayout(seq_layout_btns);
    this->setLayout(seq_layout);

    sequence_scene = new SDEditorScene(this);
    QGraphicsView *sequence_view = new QGraphicsView(this);
    sequence_view->setScene(sequence_scene);

    seq_layout->addWidget(seqBtns);
    seq_layout->addWidget(sequence_view);

     QVector<QString> v_names(1);
     makeSequence(v_names);


     connect(remove_btn,&QPushButton::clicked,this,&SequenceEditor::addSeqSlot);


}

void SequenceEditor::makeSequence(QVector<QString> names)
{

    if (names.size() != 0 ) //empty
    {
        for(int i=0; i<names.size();i++){
            SDClass *new_seq = new SDClass("trida",this,-1200);

            v_diagrams.push_back(new_seq);
            v_rect_diagrams.push_back(new_seq->item);
        }
    }
}

void SequenceEditor::add()
{
    QVector<QString> v_names(1);
    makeSequence(v_names);
}
void SequenceEditor::remove()
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



void SequenceEditor::addSeqSlot(void)
{
    add();
}
void SequenceEditor::removeSeqSlot(void)
{
    remove();
}

/*
 * TODO
Function for making circles
*/
