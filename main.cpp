#include <iostream>
#include <cctype>
#include <windows.h>
#include "Profile.h"
#include "Enemy.h"

using namespace std;

void levelSelect(const Profile &);
char level1();
char level2();
char level3();
char menuSelect();
char switchMenu(char, int);

Profile user; //user
Enemy boss; //boss of each level
Enemy underling; //fodder enemies to train on

int main()
{
    string name;
    char select='0'; // used for selecting in the menu

    cout << "Welcome to the world of wonder and lore. Please enter your name: \n";
    cin >> name;
    user.setProfile(name); //creates an object of Profile class

    cout << "Enter 's' to load your profile or 'n' to create a new profile\n";
    cin >> select;
    string welcome="Welcome to the first level!\n";
     /* while(true){
        if (GetAsyncKeyState(0x53)){
            Sleep(200);
            user.loadGame();
            cout << welcome;
            levelSelect(user);   not currently working how I want it to

        } else if (GetAsyncKeyState(0x4E)){

            cout << welcome;
            levelSelect(user);
        }
    } */

   // while(!(select=='s' || select=='n')){
        if(select=='s'){
            user.loadGame();
            cout << welcome;
            levelSelect(user);
        } else if (select=='n') {
            cout << welcome;
            levelSelect(user);
        } else {
            cout << "Try again.\nEnter 's' to load your profile or 'n' to create a new profile";
        }
    //}
    return 0;
}

void levelSelect(const Profile &right) {
    char selection='0';
    while(selection!='!'){
        int n=right.getLevelReached()+1;
        selection='0';
        while(selection!='q' && selection!='!')
            switch(n){
                case 1:
                    selection = level1();
                    break;
                case 2:
                    selection = level2();
                    break;
                case 3:
                    selection = level3();
                    break;
               /* case 4:
                    selection = level4();
                    break;
                case 5:
                    selection = level5();
                    break;
                    */
                default:
                    cout << "Error.";
                    break;
            }
    }
}

char level1() {
    boss.setEnemy("Steven", 22, 4, 20);
    underling.setEnemy("Goblin", 10, 2, 6);
    char s = menuSelect(); //runs the selection between attacking the different enemies
    return s; // returns the value given by menu select which is q if they die
}

char level2() {
    boss.setEnemy("John", 32, 7, 40);
    underling.setEnemy("Orc", 14, 4, 8);
    char s = menuSelect();
    return s;
}

char level3() {
    boss.setEnemy("Marc", 64, 4, 74);
    underling.setEnemy("High Orc", 18, 6, 12);
    char s = menuSelect();
    return s;
}

char menuSelect() {
    char selection='0', select='0';
    cout << "You may challenge the boss whenever you like.\n"
    << "You fight the underlings, " << underling.getName() <<"s, to gain xp and level up.\n";
    cout << "The boss of this level is " << boss.getName() <<".\n"
    << "Once you challenge the boss you cannot leave until one of you is dead.\n";
    int temp=user.getDeaths();
    do {
        if(user.getDeaths()>temp){
            return selection='q';
        }
        cout << "Enter 'a' to challenge the boss.\n"
        << "Enter 'b' to fight the underlings.\n"
        << "Enter 'l' to see your stats.\n"
        << "Enter 's' to save the game.\n"
        << "Enter 'q' to quit.\n";
        cin >> selection;
        selection = switchMenu(selection, temp);
        if(selection=='q'){
            select='1';
        }
    } while (selection!='q');
    if(select=='1'){
        return selection='!'; // used to quit the program;
    }
    return selection='0';
}

char switchMenu(char s, int temp) {
    switch(s){
        case 'a':
            while(boss.getHp()>0){
                boss.attack(user);
                Sleep(200);
                boss.userAttack(user);
                Sleep(200);
                if(user.getDeaths()>temp){
                    break; //returns if the user died
                } else if (boss.getHp()<=0){
                    ++user;
                    cout << user.getLevel();
                    char s='q';
                }
            }
            break;
        case 'b':
            underling.attack(user);
            Sleep(200);
            underling.userAttack(user);
            Sleep(200);
            if (underling.getHp()<=0){
                underling.setHp(underling.getMaxHp());
            }
            break;
        case 'l':
            user.stats();
        case 's':
            user.saveGame();
            if (user.saveGame()){
                cout << "You have successfully saved the game.\n";
            }
            else {
                cout << "Unexpected error.\n";
            }
            break;
        case 'q':
            cout << "You have quit the game.\n";
            break;
        default:
            cout << "Invalid selection.\n";
    }
    return s;
}
