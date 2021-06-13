#ifndef PLAYMODEL_H
#define PLAYMODEL_H

#include "model/vettore.h"
#include "model/spaceship.h"
#include "model/player.h"
#include "model/enemy.h"

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
    void setWave(const vettore<deep_ptr<spaceship>>&);
    unsigned int enemySize() const;
    unsigned int getScreenW() const;
    unsigned int getScreenH() const;
    void movePlayer(int =0, int =0);

public slots:
    void updateEnemyPosition();
};

#endif // PLAYMODEL_H
