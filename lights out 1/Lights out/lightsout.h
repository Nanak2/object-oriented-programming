#include <iostream>

class LightsOut{
    int mat[5][5];

    public:
    LightsOut(){
        for(int r = 0; r < 5; r++){
            for(int c = 0; c < 5; c++){
                mat[5][5] = false;
            }
        }
    }

    void on(int row, int col){
        mat[row - 1][col -1] = 1;
    }

    int get(int row, int col); 

    void toggle(int row, int col){
        row = row - 1;
        col = col - 1;
        mat[row][col] = !mat[row][col];
        if((row - 1) >= 0){
            mat[row - 1][col] = !mat[row - 1][col];
        }
        if((row + 1) < 5){
            mat[row + 1][col] = !mat[row + 1][col];
        }
        if((col - 1) >= 0){
            mat[row][col - 1] = !mat[row][col - 1];
        }
        if((col + 1) < 5){
            mat[row][col + 1] = !mat[row][col + 1];
        }
    }

    bool success(){
        for(int r = 0; r < 5; r++){
            for(int c = 0; c < 5; c++){
                if(mat[r][c] != false){
                    return false;
                }
            }
        }
        return true;
    }
};

int LightsOut::get(int row, int col){
    if(row < 1 || row > 5 || col < 1 || col > 5){
        return false;
    }
    return mat[row -1][col - 1];
}