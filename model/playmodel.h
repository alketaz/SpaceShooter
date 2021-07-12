#ifndef PLAYMODEL_H
#define PLAYMODEL_H

#include "model/vettore.h"
#include "model/spaceship.h"
#include "model/player.h"
#include "model/enemy.h"
#include "model/specialenemy.h"
#include "model/finalenemy.h"

class playModel: public QObject
{
private:
    vettore<deep_ptr<spaceship>> enemies;
    deep_ptr<player> p;
    static unsigned int screen_w, screen_h;

public:
    playModel();
    void FirstWave();
    void SecondWave();
    void FinalWave();
    unsigned int enemySize() const;
    unsigned int getScreenW() const;
    unsigned int getScreenH() const;

    vettore<deep_ptr<spaceship>>& getVettore();
    const vettore<deep_ptr<spaceship>>& getVettore() const;

    int getEnemyHealth(vettore<deep_ptr<spaceship>>::iterator) const;
    void damageEnemy(vettore<deep_ptr<spaceship>>::iterator);
    void damagePlayer(unsigned int);
    void movePlayer(int =0, int =0);
    void removeEnemy(unsigned int);
    bool enemiesCleared() const;
    bool playerDead() const;
    spaceship* getEnemy(unsigned int i);
    player* getPlayerPtr();

public slots:
    void updateEnemyPosition();
    void healPlayer();
    void shieldCooldown();
};

#endif // PLAYMODEL_H
