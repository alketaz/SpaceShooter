#ifndef PLAYMODEL_H
#define PLAYMODEL_H

#include "model/vettore.h"
#include "model/spaceship.h"
#include "model/player.h"
#include "model/enemy.h"
#include "model/specialenemy.h"

class playModel: public QObject
{
friend class gameScene;
private:
    vettore<deep_ptr<spaceship>> enemies;
    deep_ptr<player> p;
    unsigned int screen_w, screen_h;

public:
    playModel(unsigned int w =1920, unsigned int h =1080);
    void FirstWave();
    void SecondWave();
    unsigned int enemySize() const;
    unsigned int getScreenW() const;
    unsigned int getScreenH() const;
    int getEnemyHealth(vettore<deep_ptr<spaceship>>::iterator) const;
    void damagePlayer(vettore<deep_ptr<spaceship>>::iterator);
    void movePlayer(int =0, int =0);
    void removeEnemy(unsigned int);
    bool enemiesCleared() const;

public slots:
    void updateEnemyPosition();
};

#endif // PLAYMODEL_H
