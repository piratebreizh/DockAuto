#ifndef VIEWENTREPOT_H
#define VIEWENTREPOT_H
#include <QtWidgets>

class ViewEntrepot : public QDialog
{

public:
    ViewEntrepot(QWidget *parent = 0);
    void AffMap(int **tab, int size, QGraphicsScene *scene);
};

#endif // VIEWENTREPOT_H
