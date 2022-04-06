#include "Enemy.h"
#include "Profile.h"
#include <iostream>

Enemy::Enemy()
{
    //ctor
}
Enemy::Enemy(std::string n, int h, int a, int x)
{
    name=n;
    hp=h;
    atk=a;
    xp=x;
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::setEnemy(std::string n, int h, int a, int x)
{
    name=n;
    hp=h;
    atk=a;
    xp=x;
    maxHp=h;
}

void Enemy::attack(Profile &right)
{
    int temp=0;

    temp=right.getHp()-getAtk(); //the enemy atks
    right.setHp(temp);
    std::cout << "Steven attacked and dealt " << getAtk() << " damage. " << right.getUsername() << " has " << right.getHp() << " HP remaining.\n";
    if(right.deathCheck()){ // updates deaths if die
        right.deathCheck();
        std::cout << "You have died. You will be transported back to the nearest checkpoint. \n";
        return;
    }
}

void Enemy::userAttack(Profile &right){
    int temp=getHp()-right.getAtk(); //the user atks
    setHp(temp);
    temp=getHp()+(.1*getAtk());
    right.setHp(temp);

    std::cout << "You have attacked and dealt " << getAtk() << " damage. " << right.getName() << " has " << right.getHp() << " HP remaining.\n";
    if(getHp()<=0) {
        std::cout << "You have beaten " << getName() << " . You will gain "
        << getXp() << " xp from this fight. \n";
        xp+=right.getXp();
    }
}