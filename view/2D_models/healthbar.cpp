#include "healthbar.h"

healthBar::healthBar(bool shield): spriteSel(0)
{
    if(!shield){
        QPixmap hb(":/img/healthBar");
        for(int i=0; i<15; i++){
            QRect crop((i*64)%256,(i/4*64),64,64);
            QPixmap singleBar = hb.copy(crop);
            progress.push_back(singleBar);
        }
        setSprite();
    }
    else{
        QPixmap hb(":/img/shieldBar");
        for(int i=0; i<15; i++){
            QRect crop((i*64)%256,(i/4*64),64,64);
            QPixmap singleBar = hb.copy(crop);
            progress.push_back(singleBar);
        }
        setSprite();
    }
}

void healthBar::setSprite(unsigned int i){
    setPixmap(progress[i]);
}

void healthBar::updateHealth(unsigned int i){
    qDebug() << "sprite: "<<spriteSel<<" -> "<<spriteSel+i;
    spriteSel += i;
    if(spriteSel>14)
        spriteSel=14;
    setSprite(spriteSel);
}

void healthBar::restoreHealth()
{
    spriteSel = 0;
    setSprite(spriteSel);
}
