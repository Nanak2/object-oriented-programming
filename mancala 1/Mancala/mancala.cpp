#include <iostream>
#include "mancala.h"
using namespace std;

Mancala::Mancala()
{
    board = new int[14];
	for(int i = 0; i < 14; i++){
		if(i == 0 || i == 7){
			board[i] = 0;
		}
		else{
			board[i] = 4;   
		}
	}
}

int Mancala::getScore(int player)
{
    if(player == 0)
    {
        return board[7];
    }
    else if(player == 1)
    {
        return board[0];
    }

    return 0;
}

bool Mancala::move(int n) 
{
    int pit = n; 
    int sp = 0; 

    if(players == 1) 
    {
        if(pit > 0 && pit < 7)
        {
            sp = pit;
            int size1 = board[sp];
            board[sp] = 0;
            int y = board[0];
            int end_pit = sp + size1; 
            int across_pit = end_pit + 7;
            int k = board[end_pit];
            for(int i = 1; i <= size1; i++)
            {
                if(sp == 0)
                {
                    sp = 8;
                    board[8]++;
                    if(y != board[0] && i == size1)
                    {
                        players = 1;
                    }
                    else
                    {
                        players = 0;
                    } 
                }
                else if(sp >= 1 && sp <= 7)
                {
                    sp--;
                    board[sp]++;
                    players = 0;
                }
                else if(sp >= 8 && sp < 13)
                {
                    sp++;
                    board[sp]++;
                    players = 0;
                }
                else if(sp >= 13)
                {
                    board[7]++;
                    sp = 7;
                    players = 0;
                } 

                if(k == 0 && i == size1)
                {
                    board[0] = board[0] + board[end_pit] + board[across_pit];
                    board[end_pit] = 0;
                    board[across_pit] = 0;

                    players = 0;
                }
            }
        }
        else
        {
            return false;
        }
    }
    else if(players == 0)
    {
        if(pit > 0 && pit < 7) 
        {
            sp = 14 - pit;
            int size2 = board[sp];
            board[sp] = 0;
            int x = board[7];
            int end_pit = sp + size2;
            int across_pit = end_pit - 7;
            int k = board[end_pit];
            for(int i = 1; i <= size2; i++)
            {
                if(sp == 0)
                {
                    board[7]++;
                    sp = 8;
                    players = 1;
                }
                else if(sp >= 1 && sp <= 7)
                {
                    sp--;
                    board[sp]++;
                    players = 1;
                }
                else if(sp >= 8 && sp < 13)
                {
                    sp++;
                    board[sp]++;
                    players = 1;
                }
                else if(sp >= 13)
                {
                    board[7]++;
                    sp = 7;
                    if(x != board[7] && i == size2)
                    {
                        players = 0;
                    }
                    else
                    {
                        players = 1;
                    }
                }

                if(k == 0 && i == size2)
                {
                    board[7] = board[7] + board[end_pit] + board[across_pit];
                    board[end_pit] = 0;
                    board[across_pit] = 0;

                    players = 1;                    
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }    
    return true;
}

ostream & operator<<(ostream &out, Mancala &m)
{
    out << " " << m.board[0] << " |";
    for (int i = 1; i < 7; i++)
        out << "  " << m.board[i];

    if(m.players == 0)
    {
        out << " |  *" << "\n";
        out << " - |";
    }
    else if(m.players == 1)
    {
        out << " |  -" << "\n";
        out << " * |";
    }

    for (int i = 8; i < 14; i++)
        out << "  " << m.board[i];
    out << " |  " << m.board[7] << "\n";
    cout << endl;

    return out;
}

int Mancala::getPlayer()
{
    return players;
}