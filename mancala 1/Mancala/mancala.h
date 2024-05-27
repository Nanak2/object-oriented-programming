#include <iostream>
#include <string>

class Mancala{
    private:
    int players = 0;
    int *board;

public:
    Mancala();
    int getPlayer();
    int getScore(int player);
    bool move(int n);
    friend std::ostream & operator<<(std::ostream &out, Mancala &m);
};