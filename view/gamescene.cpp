#include "gamescene.h"

gameScene::gameScene(playModel* m): match(m), phase(gamePhase::base), enemyItems(), enemyHealth(), p(new playerModel()), hp(new healthBar()), playerActions(new bool[5]) //, moveTimer(new QTimer())
{
    for(int i=0;i<5;i++)
        playerActions[i]=false;
    setSceneRect(0,0,m->getScreenW(),m->getScreenH());
    loadBG();
    //loadInfoBox();
    loadPlayer();
    loadWave();
    loadEnemies();
}

void gameScene::loadBG()
{
    QPixmap bg(":/img/game_bg.png");
    QBrush brush(bg);
    setBackgroundBrush(brush);
}

void gameScene::loadInfoBox(){
    QGraphicsRectItem infoLeft(0,0,320,1080);
    QGraphicsRectItem infoRight(1600,0,320,1080);
    QBrush grey(QColor::fromRgb(255,255,255));
    infoLeft.setBrush(grey);
    infoRight.setBrush(grey);
    addItem(&infoLeft);
    addItem(&infoRight);
    //Non funziona
}

void gameScene::loadPlayer()
{
    p->setPos(width()/2-32, height()-96);
    hp->setPos(p->x(), p->y()+54);
    addItem(p);
    addItem(hp);
}

void gameScene::loadWave(){
    QTimer* eTimer = new QTimer();
    eTimer->setSingleShot(true);
    eTimer->start(3000);
    QGraphicsPixmapItem* title;
    if(phase == gamePhase::won){
        QPixmap text(":/img/win.png");
        QPixmap subtext(":/img/sub.png");
        title = new QGraphicsPixmapItem(text);
        QGraphicsPixmapItem* subtitle = new QGraphicsPixmapItem(subtext);
        title->setPos(match->getScreenW()/2 - text.width()/2, 200);
        subtitle->setPos(match->getScreenW()/2 - subtext.width()/2, 300);
        addItem(title);
        addItem(subtitle);
        connect(eTimer, &QTimer::timeout, this, &gameScene::gameWon); //cambiare con reindirizzamento a menu
    }
    else{
        QPixmap text(":/img/fw.png");
        title = new QGraphicsPixmapItem(text);
        title->setPos(match->getScreenW()/2 - text.width()/2, 200);
        addItem(title);
        connect(eTimer, &QTimer::timeout, this, [=](){emit removeItem(title);});
    }
}

void gameScene::loadEnemies()
{
    switch(phase){
    case gamePhase::base:
        match->FirstWave();
        for(auto cit = match->enemies.begin(); cit!=match->enemies.end(); cit++){
            enemyModel* eM = new enemyModel(enemyType::base);
            healthBar* hB = new healthBar();
            eM->setPos((*cit)->getX(), (*cit)->getY());
            hB->setPos(eM->x() + eM->getWidth()/2 - 32, eM->y()-42);
            enemyItems.push_back(eM);
            enemyHealth.push_back(hB);
            addItem(eM);
            addItem(hB);
        }
        break;
    case gamePhase::special:
        match->SecondWave();
        for(auto cit = match->enemies.begin(); cit!=match->enemies.end(); cit++){
            enemyModel* eM;
            if(dynamic_cast<specialEnemy*>(cit->get())){
                eM = new enemyModel(enemyType::special);
            }
            else
                eM = new enemyModel(enemyType::base);
            healthBar* hB = new healthBar();
            eM->setPos((*cit)->getX(), (*cit)->getY());
            hB->setPos(eM->x() + eM->getWidth()/2 - 32, eM->y()-42);
            enemyItems.push_back(eM);
            enemyHealth.push_back(hB);
            addItem(eM);
            addItem(hB);
        }
        break;
    /*case gamePhase::final:
        break;*/
    }
}

enemyModel* gameScene::getEnemyByPos(unsigned int i) const {return enemyItems[i];}

/*unsigned int gameScene::getEnemyHit() const
{
    for(int f=0; f<bulletItems.size();f++){
        if(bulletItems[f]->gotHit())
            return f;
    }
    return 999999;
}*/

void gameScene::checkCollisions()
{
    auto health_it = enemyHealth.begin();
    auto match_it = match->enemies.begin();
    auto it = enemyItems.begin();
    bool hit = false;
    unsigned int pos=0;
    while(it!= enemyItems.end() && pos<enemyItems.size()){
        if(hit){
            auto h_it_copy = health_it;
            auto m_it_copy = match_it;
            auto it_copy = it;
            --h_it_copy, --m_it_copy, --it_copy;
            if(match->getEnemyHealth(m_it_copy)<=0){
                if(typeid(**m_it_copy) == typeid (specialEnemy) && static_cast<specialEnemy*>(m_it_copy->get())->divides()){
                    for(int i=0; i<2; i++){
                        enemy* e = new enemy();
                        e->setX((*m_it_copy)->getX() + i*((*m_it_copy)->getSpaceshipWidth() - e->getSpaceshipWidth()));
                        e->setY((*m_it_copy)->getY());
                        enemyModel* eM = new enemyModel(enemyType::mini);
                        eM->setPos(e->getX(), e->getY());
                        healthBar* hB = new healthBar();
                        hB->setPos(eM->x() + eM->getWidth()/2 - 32, eM->y()-42);
                        match->enemies.push_back(e);
                        enemyItems.push_back(eM);
                        enemyHealth.push_back(hB);
                        addItem(eM);
                        addItem(hB);
                    }
                }
                removeItem(*it_copy);
                enemyItems.erase(it_copy);
                removeItem(*h_it_copy);
                enemyHealth.erase(h_it_copy);
                match->enemies.erase(pos-1);
            }
            else{
                if(typeid (enemy) == typeid (**m_it_copy))
                    (*h_it_copy)->updateHealth(7);
                else if(typeid (specialEnemy) == typeid (**m_it_copy))
                    (*h_it_copy)->updateHealth(4);
                /*else if(typeid (specialEnemy) == typeid (**match_it))
                    (*h_it_copy)->updateHealth(2); */
            }
            hit=false;
        }

        if((*it)->getHit()){
            match->damageEnemy(match_it);
            (*it)->setHit(false);
            hit=true;
        }
        ++it, ++health_it, ++match_it, ++pos;
    }
    if(hit){
        auto h_it_copy = health_it;
        auto m_it_copy = match_it;
        auto it_copy = it;
        --h_it_copy, --m_it_copy, --it_copy;
        if(match->getEnemyHealth(--match_it)<=0){
            if(typeid(**m_it_copy) == typeid (specialEnemy) && static_cast<specialEnemy*>(m_it_copy->get())->divides()){
                for(int i=0; i<2; i++){
                    enemy* e = new enemy();
                    e->setX((*m_it_copy)->getX() + i*((*m_it_copy)->getSpaceshipWidth() - e->getSpaceshipWidth()));
                    e->setY((*m_it_copy)->getY());
                    enemyModel* eM = new enemyModel(enemyType::mini);
                    eM->setPos(e->getX(), e->getY());
                    healthBar* hB = new healthBar();
                    hB->setPos(eM->x() + eM->getWidth()/2 - 32, eM->y()-42);
                    match->enemies.push_back(e);
                    enemyItems.push_back(eM);
                    enemyHealth.push_back(hB);
                    addItem(eM);
                    addItem(hB);
                }
            }
            removeItem(*it_copy);
            enemyItems.erase(it_copy);
            removeItem(*h_it_copy);
            enemyHealth.erase(h_it_copy);
            match->enemies.erase(pos-1);
        }
        else{
            if(typeid (enemy) == typeid (**m_it_copy))
                (*h_it_copy)->updateHealth(7);
            else if(typeid (specialEnemy) == typeid (**m_it_copy))
                (*h_it_copy)->updateHealth(4);
            /*else if(typeid (specialEnemy) == typeid (**match_it))
                (*h_it_copy)->updateHealth(2); */
        }
        hit=false;
    }


}

int* gameScene::getPlayerBulletPos() const{
    int* aux = new int[2];
    aux[0] = p->x() + static_cast<playerModel*>(p)->getWidth()/2 - 2;
    aux[1] = p->y();
    return aux;
}

int* gameScene::getEnemyBulletPos(unsigned int i) const{
    int* aux = new int[2];
    aux[0] = enemyItems[i]->x() + enemyItems[i]->getWidth()/2 - 2;
    aux[1] = enemyItems[i]->y() + enemyItems[i]->getHeight();
    return aux;
}

bool gameScene::enemiesCleared() const{
    return enemyItems.size()==0;
}

void gameScene::changeState(){
    if(phase == gamePhase::base)
        phase = gamePhase::special;
    else if(phase == gamePhase::special)
    /*    phase = gamePhase::final;
    else*/
        phase = gamePhase::won;
    loadWave();
    loadEnemies();
}

void gameScene::move(){
    for(std::vector<enemyModel*>::iterator it = enemyItems.begin(); it!=enemyItems.end(); it++)
        (*it)->setPos((*it)->x(), (*it)->y()+16);
    for(std::vector<healthBar*>::iterator it = enemyHealth.begin(); it!=enemyHealth.end(); it++)
        (*it)->setPos((*it)->x(), (*it)->y()+16);
}

int gameScene::movePlayerX() const{
    int res =0;
    if(playerActions[0])
        res-=8;
    if(playerActions[2])
        res+=8;
    return res;
}

int gameScene::movePlayerY() const{
    int res =0;
    if(playerActions[1])
        res-=8;
    if(playerActions[3])
        res+=8;
    return res;
}

bool gameScene::spawnBullet() const{
    return playerActions[4];
}

void gameScene::removeEnemy(unsigned int i){ std::vector<enemyModel*>::iterator it; enemyItems.erase(it+i); match->removeEnemy(i);}

void gameScene::keyPressEvent(QKeyEvent* event){
    switch (event->key()){
    case Qt::Key_Left:
        playerActions[0] = true;
        break;
    case Qt::Key_Up:
        playerActions[1] = true;
        break;
    case Qt::Key_Right:
        playerActions[2] = true;
    break;
    case Qt::Key_Down:
        playerActions[3] = true;
    break;
    case Qt::Key_Space:
        playerActions[4] = true;
    break;
    }
}

void gameScene::keyReleaseEvent(QKeyEvent* event){
    switch (event->key()){
    case Qt::Key_Left:
        playerActions[0] = false;
        break;
    case Qt::Key_Up:
        playerActions[1] = false;
        break;
    case Qt::Key_Right:
        playerActions[2] = false;
    break;
    case Qt::Key_Down:
        playerActions[3] = false;
    break;
    case Qt::Key_Space:
        playerActions[4] = false;
    break;
    }
}

void gameScene::updatePlayer(int w, int h){
    p->setPos(p->x()+ w, p->y() + h);
    if(p->x() + static_cast<playerModel*>(p)->getWidth() > width())
        p->setPos(width() - static_cast<playerModel*>(p)->getWidth(), p->y());

    if(p->x() < 0)
        p->setPos(0, p->y());

    if(p->y() + static_cast<playerModel*>(p)->getHeight() + 14 > height())
        p->setPos(p->x(), height()- static_cast<playerModel*>(p)->getHeight() - 14);

    if(p->y() < 0)
        p->setPos(p->x(), 0);

    hp->setPos(p->x(), p->y() + 54);
}
