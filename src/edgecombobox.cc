/**
 * \file edgecombobox.cc
 *
 * \brief Source code file for `EdgeComboBox` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 * \author Marek Sechra
 */

#include "edgecombobox.hh"

EdgeComboBox::EdgeComboBox(QWidget *parent)
    : QComboBox{parent}
{
    setClassEditorEdges();
}

void EdgeComboBox::setClassEditorEdges()
{
    clear();
    addItem(QIcon(":/imgs/icons/association.png"), "Association");
    addItem(QIcon(":/imgs/icons/aggregation.png"), "Aggregation");
    addItem(QIcon(":/imgs/icons/composition.png"), "Composition");
    addItem(QIcon(":/imgs/icons/generalization.png"), "Generalization");
}

void EdgeComboBox::setSequenceEditorEdges()
{
    clear();
    addItem("Async");
    addItem("Sync");
    addItem("Create");
    addItem("Destroy");
    addItem("Activate");
}
