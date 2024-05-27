#include <iostream>
#include "mancala.h"

using namespace std;

int main()
{
    Mancala g;
    cout << g;

    g.move(4);
    cout << g;

    g.move(6);
    cout << g;

    g.move(6);
    cout << g;

    cout << "player: " << g.getPlayer() << "\n";
    cout << "score: " << g.getScore(0) << " to " << g.getScore(1) << "\n";
}

Mancala::Mancala()
{
    //default constructor
}

int Mancala::getPlayer()
{
    return mancala_players;
}

int Mancala::getScore(int player)
{
    //get score
    if(player == 0)
    {
        return boardvalue[7];
    }
    else if(player == 1)
    {
        return boardvalue[0];
    }
    else
    {
        //code
    }
    return 0;
}

bool Mancala::move(int n) 
{
    int pit = n; 
    int start_pit = 0; 

    if(mancala_players == 1) 
    {
        if(pit > 0 && pit < 7)
        {
            start_pit = pit;
            int size1 = boardvalue[start_pit];
            boardvalue[start_pit] = 0;
            int y = boardvalue[0];
            int end_pit = start_pit + size1;
            int across_pit = end_pit + 7;
            int k = boardvalue[end_pit];
            for(int z = 1; z <= size1; z++)
            {
                if(start_pit == 0)
                {
                    start_pit = 8;
                    boardvalue[8]++;
                    if(y != boardvalue[0] && z == size1)
                    {
                        mancala_players = 1;
                    }
                    else
                    {
                        mancala_players = 0;
                    } 
                }
                else if(start_pit >= 1 && start_pit <= 7)
                {
                    start_pit--;
                    boardvalue[start_pit]++;
                    mancala_players = 0;
                }
                else if(start_pit >= 8 && start_pit < 13)
                {
                    start_pit++;
                    boardvalue[start_pit]++;
                    mancala_players = 0;
                }
                else if(start_pit >= 13)
                {
                    boardvalue[7]++;
                    start_pit = 7;
                    mancala_players = 0;
                }
                else
                {
                    //code
                }
                if(k == 0 && z == size1)
                {
                    boardvalue[0] = boardvalue[0] + boardvalue[end_pit] + boardvalue[across_pit];
                    boardvalue[end_pit] = 0;
                    boardvalue[across_pit] = 0;

                    mancala_players = 0;

                    //READABLE ARRAY-INDEX GUIDE:
                    // 0 |  1  2  3   4   5   6  |  *
                    // - |  8  9  10  11  12  13 |  7
                    
                }
                else
                {
                    //code
                }
            }
        }
        else
        {
            cout << "This pit is empty" << "\n";
        }
    }
    else if(mancala_players == 0)
    {
        if(pit > 0 && pit < 7) 
        {
            start_pit = 14 - pit;
            int size2 = boardvalue[start_pit];
            boardvalue[start_pit] = 0;
            int x = boardvalue[7];
            int end_pit = start_pit + size2;
            int across_pit = end_pit - 7;
            int k = boardvalue[end_pit];
            for(int z = 1; z <= size2; z++)
            {
                if(start_pit == 0)
                {
                    boardvalue[7]++;
                    start_pit = 8;
                    mancala_players = 1;
                }
                else if(start_pit >= 1 && start_pit <= 7)
                {
                    start_pit--;
                    boardvalue[start_pit]++;
                    mancala_players = 1;
                }
                else if(start_pit >= 8 && start_pit < 13)
                {
                    start_pit++;
                    boardvalue[start_pit]++;
                    mancala_players = 1;
                }
                else if(start_pit >= 13)
                {
                    boardvalue[7]++;
                    start_pit = 7;
                    if(x != boardvalue[7] && z == size2)
                    {
                        mancala_players = 0;
                    }
                    else
                    {
                        mancala_players = 1;
                    }
                }
                else
                {
                    //code
                }
                if(k == 0 && z == size2)
                {
                    boardvalue[7] = boardvalue[7] + boardvalue[end_pit] + boardvalue[across_pit];
                    boardvalue[end_pit] = 0;
                    boardvalue[across_pit] = 0;

                    mancala_players = 1;

                    //READABLE ARRAY-INDEX GUIDE:
                    // 0 |  1  2  3   4   5   6  |  *
                    // - |  8  9  10  11  12  13 |  7
                    
                }
                else
                {
                    //code
                }
            }
        }
        else
        {
            cout << "This pit is empty" << "\n";
        }
    }
    else
    {
        cout << "[Error message]" << "\n";
        return false;
    }
    
    return true;
}

ostream & operator<<(ostream &out, Mancala &m)
{
    //out << "Current player: " << m.mancala_players << "\n";
    //out << "Canvas Board: " << "\n";
    //out << " 0 |  4  4  4  4  4  4 |  *\n - |  4  4  0  5  5  5 |  1\n";
    //out << "My Board: " << "\n";

    out << " " << m.boardvalue[0] << " |";
    for (int i = 1; i < 7; i++)
        out << "  " << m.boardvalue[i];

    if(m.mancala_players == 0)
    {
        out << " |  *" << "\n";
        out << " - |";
    }
    else if(m.mancala_players == 1)
    {
        out << " |  -" << "\n";
        out << " * |";
    }
    else
    {
        //code
    }

    for (int i = 8; i < 14; i++)
        out << "  " << m.boardvalue[i];
    out << " |  " << m.boardvalue[7] << "\n";

    //out << "Current player: " << m.mancala_players << " END OF LOOP" << "\n";

    return out;
}

/*
    MANCALA BOARD FORMAT NOTES:
        FIRST LINE:
            - print ONE space
            - print zero
            - print ONE space
            - print dividing line (aka this thing --> | )
            - print TWO spaces (part a)
            - print "4" (part b)
            - repeat (part a) and (part b) FIVE times
            - print ONE space (after the 6th "4" that has been printed)
            - print dividing line (aka this thing --> | )
            - print TWO spaces
            - print "*" (this is a character that articulates the player on the RIGHT side of the Mancala board)
            - print new line (using the character literal "\n")
        SECOND LINE
            - print ONE space
            - print "-" (this is a character that articulates the player on the LEFT side of the Mancala board)
            - print ONE space
            - print dividing line (aka this thing --> | )
            - print TWO spaces (part a)
            - print "4" (part b)
            - repeat (part a) and (part b) FIVE times
            - print ONE space (after the 6th "4" that has been printed)
            - print dividing line (aka this thing --> | )
            - print TWO spaces
            - print zero
            - print new line (using the character literal "\n")
*/