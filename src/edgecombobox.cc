#include "edgecombobox.hh"

EdgeComboBox::EdgeComboBox(QWidget *parent)
    : QComboBox{parent}
{
    setClassEditorEdges();
}

void EdgeComboBox::setClassEditorEdges()
{
    clear();
    addItem("Association");
    addItem("Aggregation");
    addItem("Composition");
    addItem("Generalization");
}

void EdgeComboBox::setSequenceEditorEdges()
{
    clear();
    // TODO;
}
