#ifndef EDGECOMBOBOX_HH
#define EDGECOMBOBOX_HH

#include <QComboBox>

class EdgeComboBox : public QComboBox
{
public:
    EdgeComboBox(QWidget *parent = nullptr);

    void setClassEditorEdges(void);
    void setSequenceEditorEdges(void);
};

#endif // EDGECOMBOBOX_HH
