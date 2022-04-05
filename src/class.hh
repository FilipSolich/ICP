/**
 * \file class.hh
 *
 * \brief Header file for `Class` class.
 *
 * \date 4. 4. 2022
 * \author Filip Solich
 */

#ifndef CLASS_HH
#define CLASS_HH

#include <QString>

#include "cdclass.hh"
#include "sdclass.h"

class Diagram;
class CDEditor;
class SequenceEditor;

/**
 * This class encapsulate data about diagram "class" in all editors instances.
 */
class Class : public QObject
{
    Q_OBJECT

public:
    QString name;
    Diagram *diagram = nullptr;
    CDClass *cdClass = nullptr;
    SDClass *sdClass = nullptr;
    SequenceEditor *sequence = nullptr;

    //Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceEditor *> *sqEditors, QPointF pos = {0, 0});

    /**
     * Constructor create new class in `CDEditor` and all `SDEditor`.
     *
     * \param diagram Pointer to `Diagram``.
     * \param cdEditor Pointer to `CDEditor`.
     * \param sqEditor Pointer to `SequenceEditor`.
     * \param name Name of class.
     * \param pos Position of class in scene.
     */
    Class(Diagram *diagram, CDEditor *cdEditor, QVector<SequenceEditor *> *sqEditors, QString name = "", QPointF pos = {0, 0});

    /** Destructor */
    ~Class();

    /**
     * Set new name for class.
     *
     * \param newName New name for class.
     */
    void setName(QString newName);

    /**
     * Get class name.
     *
     * \return Class name.
     */
    QString getName();

signals:
    void setNameSignal(const QString &newName);
};

#endif // CLASS_HH
