#include <iostream>
#include <string>

class Mancala
{
public:
    Mancala();
    int getPlayer(); // 0,1, or -1 if game over
    int getScore(int player);
    bool move(int n); // could we do it?
    friend std::ostream & operator<<(std::ostream &out, Mancala &m);
private:
    int mancala_players = 0;
    int boardvalue[14] = {0,4,4,4,4,4,4,0,4,4,4,4,4,4};
};