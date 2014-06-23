#include "viewentrepot.h"

#include <QtWidgets>
#include "Map.h"

ViewEntrepot::ViewEntrepot(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(parent);
    QGraphicsScene *scene = new QGraphicsScene; //creation de la scene
    QGraphicsView vue(scene);
    //Map m;
    vue.setFixedSize(100,100);
    mainLayout->addWidget(&vue);
    this->setLayout(mainLayout);

}
//http://fr.openclassrooms.com/forum/sujet/jeu-2d-tile-mapping-qt-93098s
/*void viewEntrepot::initWindow()
{
  setWidth(520);
  setHeigth(520);
  setApple(0);
  setTete(0);
  setCorps(0);
  setQueue(0);
  setMur(0);
  scene = new QGraphicsScene;
}*/

void ViewEntrepot::AffMap(int **tab, int size, QGraphicsScene *scene)
{
  QGraphicsItem *item;
  QPixmap image;
  int   width = 0;
  int   heigth = 0;

  /*for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
        {
          if (tab[i][j] == 1)
            {
              image.load("./res/mur.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 4)
            {
              image.load("./res/tete.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 2)
            {
              image.load("./res/queue.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 3)
            {
              image.load("./res/corps.png", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 7)
            {
              image.load("./res/apple.jpg", 0, Qt::AutoColor);
              item = scene->addPixmap(image);
              item->setPos(width, heigth);
              width += 20;
            }
          if (tab[i][j] == 0)
            width += 20;
        }
      heigth += 20;
      width = 0;
    }*/
}
