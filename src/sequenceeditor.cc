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


    this->setLayout(seq_layout);

    sequence_scene = new SDEditorScene(this);
    QGraphicsView *sequence_view = new QGraphicsView(this);
    sequence_view->setScene(sequence_scene);

    seq_layout->addWidget(seqBtns);
    seq_layout->addWidget(sequence_view);

}
/*
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
*/

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



