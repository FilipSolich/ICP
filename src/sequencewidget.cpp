#include "sequencewidget.h"
#include <QBoxLayout>
#include <QLabel>
#include <QFrame>
#include "sdclass.h"
#include "class.hh"

SequenceWidget::SequenceWidget(SDClass *sequence_parent ,QString name ,QWidget *parent )
    :QWidget{parent}
{
    this->sequence_parent = sequence_parent;

    seq_layout = new QGridLayout(this);
    seq_name = new QLabel(this);
    seq_name->setText(name);
    seq_name->setAlignment(Qt::AlignCenter);
    seq_line = new QLabel(this);
    seq_line->setAlignment(Qt::AlignCenter);
    seq_name->setMinimumWidth(100);

    seq_line->setFrameShape(QFrame::VLine);
    seq_line->setLineWidth(10);
    seq_line->setMinimumHeight(300);

    seq_layout->setGeometry(geometry());

    seq_layout->addWidget(seq_name,0,0);
    seq_layout->addWidget(seq_line,1,0);
    connect(sequence_parent->cls, &Class::setNameSignal, this, &SequenceWidget::newNameSlot);

}

void SequenceWidget::newNameSlot(const QString &name)
{
    if (this->seq_name->text() != name) {
        this->seq_name->setText(name);
    }
}
