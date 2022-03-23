#ifndef SEQUENCEWIDGET_H
#define SEQUENCEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class Sequence;

class SequenceWidget : public QWidget
{
    Q_OBJECT
    QGridLayout *seq_layout = nullptr;
    QLabel *seq_name = nullptr;
    QLabel *seq_line = nullptr;
    QLabel *seq_circle = nullptr;

public:
    Sequence *sequence_parent = nullptr;

    SequenceWidget(Sequence *sequence_parent, QString name = "class", QWidget *parent = nullptr);
};

#endif // SEQUENCEWIDGET_H
