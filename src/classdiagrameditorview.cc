#include "classdiagrameditorview.hh"
#include "diagram.hh"

#include <QDebug>

ClassDiagramEditorView::ClassDiagramEditorView(Diagram *diagram, QWidget *parent)
    : QGraphicsView(parent)
{
    this->diagram = diagram;

    //setMouseTracking(true);
    setRenderHint(QPainter::Antialiasing);
}

void ClassDiagramEditorView::mouseMoveEvent(QMouseEvent *ev)
{
    //if (diagram->currentEdge) {
    //    diagram->currentEdge->setMousePos(ev->pos());
    //    qDebug() << ev->pos();
    //}

    QGraphicsView::mouseMoveEvent(ev);
}
