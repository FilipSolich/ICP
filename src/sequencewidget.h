#ifndef SEQUENCEWIDGET_H
#define SEQUENCEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class SDClass;
/**
 * \brief The SequenceWidget class
 */
class SequenceWidget : public QWidget
{
    Q_OBJECT
    QGridLayout *seq_layout = nullptr;
    QLabel *seq_name = nullptr;
    QLabel *seq_line = nullptr;
    QLabel *seq_circle = nullptr;

public:
    SDClass *sequence_parent = nullptr;
    /**
     * \brief SequenceWidget constructor.
     * \param sequence_parent pointer on SDClass(parent)
     * \param name name of the class
     * \param parent pointer on QWidget
     */
    SequenceWidget(SDClass *sequence_parent, QString name = "class", QWidget *parent = nullptr);

};

#endif // SEQUENCEWIDGET_H
