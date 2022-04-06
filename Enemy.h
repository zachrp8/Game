#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "Profile.h"

class Enemy
{
    private:
        std::string name;
        int hp;
        int atk;
        int xp;
        int maxHp;

    public:
        std::string getName() const {return name;};
        int getHp() const {return hp;};
        int getAtk() const {return atk;};
        int getXp() const {return xp;};
        int getMaxHp() const {return maxHp;};

        void setName(std::string newName) {name=newName;};
        void setHp(int newHp) {hp=newHp;};
        void setAtk(int newAtk) {atk=newAtk;};
        void setXp(int newXp) {xp=newXp;};
        

        void setEnemy(std::string, int, int, int);
        void attack(Profile &);
        void userAtk(profile &);

        Enemy();
        Enemy(std::string, int, int, int);
        virtual ~Enemy();




};

#endif // ENEMY_H
