#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QWidget>
#include <QBoxLayout>
#include <QFrame>
#include <QLabel>


class Sequence : public QWidget
{
    Q_OBJECT

    QGridLayout *seq_layout = nullptr;
    QLabel *seq_name = nullptr;
    QLabel *seq_line = nullptr;
    QLabel *seq_circle = nullptr;



public:
    QGraphicsProxyWidget *seq_proxy = nullptr;
    explicit Sequence(QWidget *parent = nullptr, QString name = "Class diagram not exist yet");

signals:

};

#endif // SEQUENCE_H
