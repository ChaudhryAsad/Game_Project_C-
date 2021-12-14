#include "game.h"

#include <QApplication> ///De klasse QApplication beheert de besturingsstroom en de belangrijkste instellingen van de GUI-toepassing.
#include <QDesktopWidget> ///De klasse QDesktopWidget biedt toegang tot scherminformatie op systemen met meerdere koppen.

int main(int argc, char *argv[]) /* Dit start het gui scherm*/
{
    QApplication a(argc, argv);
    Game w;
    w.show();
    return a.exec();
}

