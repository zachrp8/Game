#include "Profile.h"
#include <fstream>
#include <iostream>

Profile::Profile()
{
    this->username="";
    this->level=0;
    this->xp=0;
    this->levelReached=0;
    this->hp=0;
    this->atk=0;
    this->deaths=0;
    this->checkpoint=0;
    this->maxHp=0;
    //ctor
}

Profile::Profile(std:: string n) :Profile()
{
    this->username=n;
    this->level=1;
    this->hp=12;
    this->atk=3;

}

Profile::~Profile()
{
    //dtor
}

void Profile::setXp(int newXp)
{
    this->xp=newXp;
    while (this->xp>10) //level up while xp is greater than 10
    {             // 10 is the level up requirement
        this->level+=1;
        this->xp-=10;
        levelUp();
    }
}

void Profile::setProfile(std::string n)
{
    username=n;
    level=1;
    hp=10;
    atk=3;
    maxHp=hp;
}

void Profile::stats()
{
    std::cout << "Your username is " << this->username << ".\n";
    std::cout << "Your level is " << this->level<< ".\n";
    std::cout << "Your XP is at " << this->xp << ".\n";
    std::cout << "You have reached level " << this->levelReached << ".\n";
    std::cout << "Your HP is at " << this->hp << ".\n";
    std::cout << "Your maximum HP is " << this->maxHp << ".\n";
    std::cout << "Your attack damage is " << this->atk << ".\n";
    std::cout << "You have died " << this->deaths << " times.\n";
    std::cout << "Your checkpoint is currently level " << this->checkpoint << ".\n";
}

void Profile::levelClear()
{
    int n=levelReached/3;
    if(n==1){
        checkpoint=3;
    }
}

bool Profile::saveGame()
{
    std::fstream saveData;
    saveData.open(FILE_NAME, std::ios::out);
    /*
    Ways to save the data:
    1) use a separator ,;tab
    2) have a value on each line
    3) parse the data using word or phrase
        weapon: axe
        playerName: Fred
        playerLevel: 15
        */
    bool retVal=true;
    if(!saveData.fail())
    {
        saveData << this->username << '\n'; //saving all the data on a new line
        saveData << this->level << '\n';
        saveData << this->xp << '\n';
        saveData << this->levelReached << '\n';
        saveData << this->hp << '\n';
        saveData << this->maxHp << '\n';
        saveData << this->atk << '\n';
        saveData << this->deaths << '\n';
        saveData << this->checkpoint << '\n';
    } else
    {
        retVal=false; //when opening the file fails
    }
    return retVal;
}
bool Profile::loadGame()
{
    std::fstream saveData;
    saveData.open(FILE_NAME, std::ios::in);
    std::string input;
    bool retVal=true;
    if(!saveData.fail())
    {
        //loading all the data
        getline(saveData, input);
        this->username=input;
        getline(saveData, input);
        this->level=std::stoi(input);
        getline(saveData, input);
        this->xp=std::stoi(input);
        getline(saveData, input);
        this->levelReached=std::stoi(input);
        getline(saveData, input);
        this->hp=std::stoi(input);
        getline(saveData, input);
        this->maxHp=std::stoi(input);
        getline(saveData, input);
        this->atk=std::stoi(input);
        getline(saveData, input);
        this->deaths=std::stoi(input);
        getline(saveData, input);
        this->checkpoint=std::stoi(input);
    } else {retVal=false;}
    return retVal;
}

bool Profile::deathCheck()
{
    bool ret=false;
    if (this->hp<=0)
    {
        this->deaths+=1;
        ret=true; // returns true saying that the character has died
        loadCheckpoint(); // sends back to checkpoint
        this->hp=this->maxHp; // restores health to full
    } return ret;
}

Profile Profile::operator ++()
{
    ++levelReached;
    if (this->levelReached>5){
        std::cout << "Congrats you have beat the game \n";
        this->levelReached=5;
    }
    levelClear(); //updates checkpoint if the levelReached passes 5 or 10
    return *this;
}

void Profile::levelUp()
{
    if(this->level<7){
        this->maxHp+=3;
        this->hp+=3;
        this->atk+=2;
    } else if (this->level >=7 && this->level < 15) {
        this->maxHp+=2;
        this->hp+=2;
        this->atk+=1;
    } else {
        this->maxHp+=1;
        this->hp+=1;
        this->atk+=1;
    }
}

