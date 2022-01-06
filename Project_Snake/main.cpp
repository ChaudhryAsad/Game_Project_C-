#include "game.h"

#include <QApplication> ///De klasse QApplication beheert de besturingsstroom en de belangrijkste instellingen van de GUI-toepassing.
#include <QDesktopWidget> ///De klasse QDesktopWidget biedt toegang tot scherminformatie op systemen met meerdere koppen.


void center(QWidget &widget)
{
    int x, y;
    int screenWidth;
    int screenHeight;

    int WIDTH = 300;
    int HEIGHT = 500;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    widget.setGeometry(x, y, WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);
}




int main(int argc, char *argv[]) /* Dit start het gui scherm / 48 : Command line paramter , pass value*/
{
    QApplication app(argc, argv);/* 31 : Pointer declaration */

    Game w;
    w.setWindowTitle("Snake");
    w.show();
    center(w);

    return app.exec();
}

