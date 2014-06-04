#include "viewmap.h"

#include <QtWidgets>

using namespace std;

ViewMap::ViewMap(QWidget *parent) : QFrame(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);

}
