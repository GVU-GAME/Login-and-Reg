#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <fstream>

class UI {
public:
    UI();
    void start();

private:
    int promt();
    void createAcc();
    bool accessAcc();
};

#endif