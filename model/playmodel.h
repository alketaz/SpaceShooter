#ifndef PLAYMODEL_H
#define PLAYMODEL_H

#include "model/vettore.h"
#include "model/spaceship.h"
#include "model/player.h"
#include "model/enemy.h"

class playModel
{
friend class gameScene;
private:
    vettore<deep_ptr<spaceship>> enemies;
    deep_ptr<player> p;

public:
    void FirstWave(unsigned int);
    void setWave(const vettore<deep_ptr<spaceship>>&);
    unsigned int enemySize() const;
    playModel();

public slots:
    void updateEnemyPosition();
};

#endif // PLAYMODEL_H
