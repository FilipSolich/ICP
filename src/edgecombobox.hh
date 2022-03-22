#ifndef EDGECOMBOBOX_HH
#define EDGECOMBOBOX_HH

#include <QComboBox>

class EdgeComboBox : public QComboBox
{
public:
    EdgeComboBox(QWidget *parent = nullptr);

    void setClassEditorEdges();
    void setSequenceEditorEdges();
};

#endif // EDGECOMBOBOX_HH
