/**
 * \file edgecombobox.hh
 *
 * \brief Header file for `EdgeComboBox` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 */

#ifndef EDGECOMBOBOX_HH
#define EDGECOMBOBOX_HH

#include <QComboBox>

/**
 * Combo box for selecting edge type on current editor.
 */
class EdgeComboBox : public QComboBox
{
public:
    /**
     * Constructor.
     *
     * \param parent Pointer to parent widget.
     */
    EdgeComboBox(QWidget *parent = nullptr);

    /**
     * Set `CDEditor` edges type as values of combo box.
     */
    void setClassEditorEdges();

    /**
     * Set `SDEditor` edges type as values of combo box.
     */
    void setSequenceEditorEdges();
};

#endif // EDGECOMBOBOX_HH
