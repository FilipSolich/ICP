/**
 * \file fileprocessor.hh
 *
 * \brief Header file for `FileProcessor` class.
 *
 * \date 5. 4. 2022
 * \author Filip Solich
 * \author Marek Sechra
 */

#ifndef FILEPROCESSOR_HH
#define FILEPROCESSOR_HH

#include <QString>

#include "diagram.hh"
#include "diagramtabwidget.hh"

/**
 * Class for reading diagram content from file or writing diagram content into file.
 */
class FileProcessor
{
    Diagram *diagram = nullptr;
    MainWindow *mainWindow = nullptr;

    /**
     * Genererate `CDEditor` content from diagram into JSON object.
     *
     * \return JSON object with `CDEditor` content.
     */
    QJsonObject genCD();

    /**
     * Genererate `SDEditor` content from diagram into JSON object.
     *
     * \return JSON object with `SDEditor` content.
     */
    QJsonObject genSD();

    /**
     * Genererate `CDClass` content from class into JSON object.
     *
     * \param cdClass Pointer to `CDClass` object.
     * \return JSON object with `CDClass` content.
     */
    QJsonObject genCDClass(CDClass *cls);

    /**
     * Genererate `CDClassProperty` content from class into JSON object.
     *
     * \param property Pointer to `CDClassProperty` object.
     * \return JSON object with `CDClassProperty` content.
     */
    QJsonObject genCDProperty(CDClassProperty *property);

    /**
     * Genererate `CDEdge` content from socket edge into JSON object.
     *
     * \param edge Pointer to `CDEdge` object.
     * \return JSON object with `CDEdge` content.
     */
    QJsonObject genCDEdge(CDEdge *edge);

    /**
     * Parse JSON object into `CDEditor` schema.
     *
     * \param data JSON object with `CDEditor` content.
     */
    void parseCD(QJsonObject data);

    /**
     * Create class based on JSON object.
     *
     * \param data JSON object with `CDClass` content.
     */
    void createClass(QJsonObject data);

    /**
     * Create edge based on JSON object.
     *
     * \param data JSON object with `CDEdge` content.
     */
    void createCDEdge(QJsonObject data);

    /**
     * Parse JSON object into `SDEditor` schema.
     *
     * \param data JSON object with `SDEditor` content.
     */
    void parseSD(QJsonObject data);

    /**
     * Create tabs for SD.
     *
     * \param data JSON object with `SDEditor` content.
     */
    void createTabs(QJsonObject data);
    /**
     * Create SDedge based on JSON object.
     *
     * \param data JSON object with `SDEdge` content.
     */
    void createSDEdge(QJsonObject data, int tab);

    /**
     * Genererate `SequenceEditor` content from class into JSON object.
     *
     * \param property Pointer to `SequenceEditor` object.
     * \return JSON object with `SequenceEditor` content.
     */
    QJsonObject genSDEditor(SDEditor *sequence_editor);

    /**
     * Genererate `SDEdge` content from socket edge into JSON object.
     *
     * \param edge Pointer to `SDEdge` object.
     * \return JSON object with `SDEdge` content.
     */
    QJsonObject genSdEdge(SDEdge *SDEdge);

    /**
     * Genererate `SDClass` content from class into JSON object.
     *
     * \param SDclass Pointer to `SDClass` object.
     * \return JSON object with `SDClass` content.
     */
    QJsonObject genSDClass(SDClass *SDclass);


public:
    /**
     * Inconsistency in input file dialog
     */
    void inputFileInconsistency(void);
    /**
     * Constructor.
     *
     * \param mainWindow Pointer to `MainWindow` object.
     */
    FileProcessor(MainWindow *mainWindow) : mainWindow{mainWindow} {};

    /**
     * Generate string with JSON object of diagram content.
     *
     * \param diagram Pointer to `Diagram` object.
     * \return String with JSON object of diagram content.
     */
    QString generateFile(Diagram *diagram);

    /**
     * Generate `Diagram` from string with JSON object.
     *
     * \param tabs Pointer to `DiagramTabWidget` object.
     * \param text String with JSON object of diagram content.
     * \return Pointer to `Diagram` object.
     */
    Diagram *parseFile(DiagramTabWidget *tabs, QString *text);
};

#endif // FILEPROCESSOR_HH
