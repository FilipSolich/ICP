# ICP

## Autoři

- Filip Solich
- Marek Sechra

## Omezení v implementaci

### Obecné požadavky

Operace undo funguje pouze na změnu pozice tříd v diagramech.

### Diagram tříd

Implementováno bez omezení.

### Sekvenční diagram

Implementováno bez omezení.

### Řešení nekonzistence

V případě některých nekonzistencí se otevře okno informující uživatele o problému.
Jde vidět na souboru `examples/bad_example.json`

## Převzatý kód

- Třída `MainWindow`
 - Kód je částečně převzatý z příkladu v Qt dokumentaci
 - https://doc.qt.io/qt-6/qtwidgets-tutorials-notepad-example.html
- Třída `MoveCommand`
 - Kód je částečně převzatý z příkladu v Qt dokumentaci
 - https://doc.qt.io/qt-6/qtwidgets-tutorials-notepad-example.html
