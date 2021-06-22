#include "healthbar.h"

healthBar::healthBar(): spriteSel(0)
{
    QPixmap hb(":/img/healthBar");
    for(int i=0; i<15; i++){
        QRect crop((i*64)%256,(i/4*64),64,64);
        QPixmap singleBar = hb.copy(crop);
        progress.push_back(singleBar);
    }
    setSprite();
}

void healthBar::setSprite(unsigned int i){
    setPixmap(progress[i]);
}

void healthBar::updateHealth(unsigned int i){
    spriteSel += i;
    setSprite(spriteSel);
}
