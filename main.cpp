#include <QApplication>
#include <FenetrePrincipale.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenetrePrincipale premierVue;

    premierVue.show();

    return app.exec();
}
