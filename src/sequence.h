#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>

class Sequence : public QWidget
{
    Q_OBJECT
    QGridLayout *seq_layout = nullptr;
    QLabel *seq_name = nullptr;
    //QLabel *seq_body = nullptr;
    //QLineEdit *seq_name_edit = nullptr;

public:
    QGraphicsProxyWidget *seq_proxy = nullptr;
    explicit Sequence(QWidget *parent = nullptr, QString name = "Class diagram not exist yet");

signals:

};

#endif // SEQUENCE_H
