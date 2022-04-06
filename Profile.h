#ifndef PROFILE_H
#define PROFILE_H
#include <iostream>
#include <string>
#include <fstream>
#include "Enemy.h"

class Profile
{
    private:
        std::string username;
        int level;
        int xp;
        int levelReached;
        int hp;
        int maxHp;
        int atk;
        int deaths;
        int checkpoint;

        const std::string FILE_NAME = "gameSave.dat";

    public:
        std::string getUsername() const {return username;};
        int getLevel() const {return level;};
        int getDeaths() const {return deaths;};
        int getHp() const {return hp;};
        int getXp() const {return xp;};
        int getAtk() const {return atk;};
        int getLevelReached() const {return levelReached;};
        int getCheckpoint() const {return checkpoint;};
        int getMaxHp() const {return maxHp;};

        void setUsername(std::string newname) {username=newname;};
        void setLevel(int newLevel) {level=newLevel;};
        void setDeaths(int newDeaths) {deaths=newDeaths;};
        void setHp(int newHp) {hp=newHp;};
        void setXp(int);
        void setAtk(int newAtk) {atk=newAtk;};
        void setLevelReached(int l) {levelReached=l;};

        void setProfile(std::string);
        void stats();
        void levelClear();
        void loadCheckpoint() {level=checkpoint;};
        bool saveGame();
        bool loadGame();
        bool deathCheck();
        void levelUp();

        Profile operator ++();

        Profile();
        Profile(std::string);
        virtual ~Profile();

};

#endif // PROFILE_H
