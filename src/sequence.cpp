#include "sequence.h"

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>

Sequence::Sequence(QWidget *parent, QString name)
    : QWidget{parent}
{
    seq_layout = new QGridLayout(this);
    seq_name = new QLabel(name,this);
    seq_name->setFixedWidth(200);
    seq_name->setFixedHeight(50);
    //seq_body = new QLabel(this);

    //seq_name->setFrameStyle(QFrame::Box | QFrame::Plain);
    //seq_body->setFrameStyle(QFrame::VLine | QFrame::Plain);

    //seq_name_edit = new QLineEdit(this);
    //seq_name->setBuddy(seq_name_edit);

    seq_layout->addWidget(seq_name);
   // seq_layout->addWidget(seq_body);
}
