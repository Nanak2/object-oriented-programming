#include <iostream>
#include "lightsout.h"
#include <random>
using namespace std;


int main (int argc, char*argv[])
{   
    int rows = 0;
    int cols = 0;
    bool i = 0;
    LightsOut play;
    int randomnumber = 0;
    

    if(argc>1){
        randomnumber = stoi(argv[1]);
    }
    else{
        random_device roll;
        randomnumber = roll();
    }

    for(int row = 1; row <= 5; row++){
        for(int column = 1; column <= 5; column++){
            if(randomnumber % 2 != 0){
                play.on(row, column);
            }
        randomnumber >>= 1;
        }
    }

    int row, col;
    while(i == 0)
    {
        if(play.success())
        {
        cout << "Congratulations!";
        i = true;
        exit(0);
        }
    
        cout<< "   1 2 3 4 5\n";
         for (row = 1; row <= 5; row++){
             cout << row << " ";
            for (col = 1; col <= 5; col++){
                if(play.get(row, col)){
                cout << "##";
                }
                else{
                    cout << "  ";
                }
            }
            cout << "\n";
        }

        cout << "R C:"; 
        cin >> rows >> cols;
        if(rows == 0 && cols == 0) {
            exit(0);
        } else {
            play.toggle(rows ,cols);
        }
    }
}