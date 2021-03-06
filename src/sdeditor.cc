/**
 * \file sequenceeditor.h
 *
 * \brief `SequenceEditor` source code of that class.
 *
 * \date 6. 5. 2022
 * \author Marek Sechra
 */

#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "sdeditor.hh"
#include "diagram.hh"
#include "cdclass.hh"
#include "sdclass.hh"
#include "sdeditorscene.hh"

#include <QLabel>
#include <QGraphicsItem>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QGraphicsLayout>
#include <QGraphicsEllipseItem>

SDEditor::SDEditor(QWidget *parent, Diagram *diagram)
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

void SDEditor::remove()
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
