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
    addItem("Async");
    addItem("Sync");
    addItem("Create");
    addItem("Destroy");
}
