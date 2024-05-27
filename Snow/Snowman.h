#include <iostream>
#include <string>

class GuessingGame{
    std::string answer, guess;
    int mistake = 0;
    int length;

    public:
    GuessingGame(std::string phrase){
        answer = phrase;
        length = answer.length();
        guess = answer;
        for(int i = 0; i < length; i++){
            if(guess[i] != ' '){
                guess[i] = '_';
            }
        };
    }

    void makeGuess(char letter){
        bool guessChecker = true;
        letter = toupper(letter);
        for(int i = 0; i < length; i++){
            if(toupper(letter) == toupper(answer[i])){
                guessChecker = false;
                guess[i] = answer[i];
            }
        }
        if(guessChecker == true){
            mistake++;
        }
    }

    bool isComplete(){
        if(answer == guess){
            return true;
        }
        else{
            return false;
        }
    }

    std::string getRevealed(){
        return guess;
    }
    int getMistakes(){ 
        return mistake;
    }
    std::string getAnswer(){
        return answer;
    }
};