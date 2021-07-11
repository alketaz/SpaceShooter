#include "tutorialscene.h"

void tutorialScene::loadBG()
{
    QPixmap bg(":/img/game_bg.png");
    QBrush brush(bg);
    setBackgroundBrush(brush);
}

void tutorialScene::loadTitle()
{

}

void tutorialScene::loadText()
{
    QFont* i=new QFont();
    QFont* s=new QFont();
    QFont* t=new QFont();
    i->setPointSize(40);
    s->setPointSize(32);
    t->setPointSize(26);

    QGraphicsRectItem* bgrect = new QGraphicsRectItem(width()/32 - 10, height()/18 - 10, 15*width()/16 + 20, 8*height()/9 + 20);
    QColor black(0,0,0,100);
    QBrush bg(black);
    bgrect->setBrush(bg);
    addItem(bgrect);

    QGraphicsTextItem* title = addText("Benvenuto in QSpaceShooter!");
    title->setPos(width()/32, height()/18);
    title->setFont(*i);
    title->setDefaultTextColor(QColor(255,165,0));

    QGraphicsTextItem* text = addText("Il tuo obiettivo è quello di distruggere le astronavi aliene senza morire e senza farle arrivare in "
                               "fondo allo schermo.");
    text->setPos(width()/32, title->y() + 100);
    text->setFont(*s);
    text->setTextWidth(15*width()/16);
    text->setDefaultTextColor(QColor(255,165,0));

    QGraphicsPixmapItem* arrows = new QGraphicsPixmapItem(QPixmap(":/img/arrows"));
    arrows->setPos(width()/32 + 10, text->y() + 150);
    addItem(arrows);

    QGraphicsTextItem* arrowsText = addText("Usa solo le frecce direzionali per muoverti,\nl'astronave spara da sola");
    arrowsText->setPos(370, arrows->y() + 10);
    arrowsText->setFont(*t);
    arrowsText->setTextWidth(width()/4);
    arrowsText->setDefaultTextColor(QColor(255,165,0));

    QGraphicsPixmapItem* enemy = new QGraphicsPixmapItem(QPixmap(":/img/enemy1.png"));
    enemy->setPos(width()/32 + 70, arrows->y() + 230);
    addItem(enemy);

    QGraphicsTextItem* enemyText = addText("Questo è il tuo nemico di base\nVita = 4, Danni = 1");
    enemyText->setPos(370, enemy->y() + 10);
    enemyText->setFont(*t);
    enemyText->setTextWidth(width()/2);
    enemyText->setDefaultTextColor(QColor(255,165,0));

    QPixmap original(":/img/se");
    QRect crop(0,0, 256, 128);
    QGraphicsPixmapItem* spEnemy = new QGraphicsPixmapItem(original.copy(crop));
    spEnemy->setPos(width()/32 + 10, enemy->y() + 150);
    addItem(spEnemy);

    QGraphicsTextItem* spEnemyText = addText("Questo è un nemico speciale\nUna volta eliminato si divide e dà\nvita a due mini nemici\nVita = 8 | (4 se mini),\nDanni = 2 | (1 se mini)");
    spEnemyText->setPos(370, spEnemy->y() + 10);
    spEnemy->setPos(width()/32 + 10, spEnemy->y() + 50);
    spEnemyText->setFont(*t);
    spEnemyText->setTextWidth(width()/2);
    spEnemyText->setDefaultTextColor(QColor(255,165,0));

    QGraphicsPixmapItem* player = new QGraphicsPixmapItem(QPixmap(":/img/user1"));
    player->setScale(2);
    player->setPos(31*width()/32 - 288, arrows->y());
    addItem(player);

    QGraphicsTextItem* playerText = addText("Questa è la tua navicella\nVita = 14, Danni = 2");
    playerText->setPos(width()/2+80, player->y() + 10);
    playerText->setFont(*t);
    playerText->setTextWidth(width()/2);
    playerText->setDefaultTextColor(QColor(255,165,0));

    QPixmap fioriginal(":/img/final");
    QRect ficrop(0,0, 1024, 512);
    QGraphicsPixmapItem* fiEnemy = new QGraphicsPixmapItem(fioriginal.copy(ficrop));
    fiEnemy->setScale(0.33);
    fiEnemy->setPos(31*width()/32 - 400, enemyText->y());
    addItem(fiEnemy);

    QGraphicsTextItem* fiEnemyText = addText("Questo è il nemico finale\nHa a disposizione uno scudo che si ricarica\nElimina lo scudo per danneggiare\nla sua vita\nVita = 28,\nScudo = 14,\nDanno = 4");
    fiEnemyText->setPos(width()/2+80, fiEnemy->y());
    fiEnemy->setPos(fiEnemy->x(), fiEnemy->y()+170);
    fiEnemyText->setFont(*t);
    fiEnemyText->setTextWidth(width()/2);
    fiEnemyText->setDefaultTextColor(QColor(255,165,0));

}

void tutorialScene::loadButtons()
{
    QPushButton* menu = new QPushButton("Torna al\nmenu");
    menu->setGeometry(width()/2 - 90, height()-150, 180, 90);
    menu->setStyleSheet("QPushButton {color: orange;"
                          "font-size: 20px;"
                          "font-weight: bold;"
                          "background-color: rgba(0, 0, 0, 50);"
                          "border: 5px solid orange;"
                          "border-radius: 10px;"
                          "outline: none;"
                          "outline-radius: 10px;"
                          "opacity: 0.9;}"
                          "QPushButton:hover {"
                          "background-color: rgba(150, 150, 150, 50);}");
    addWidget(menu);
    connect(menu, &QPushButton::clicked, this, &tutorialScene::menuPressed);
}

tutorialScene::tutorialScene():
{
    setSceneRect(0,0,1920,1080);
    loadBG();
    loadTitle();
    loadText();
    loadButtons();
}
