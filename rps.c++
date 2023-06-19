#include<iostream>
#include <time.h>
#include <limits>

class ai_play{
    public:
        char typePlay[3][9]= {"ROCK", "PAPER", "SCISSORS"};
        int score=0;
};ai_play AIGame;

class player{
    public:
        int play;
        std::string name;
        int scoreP=0;
};player player1;

int matrix_decision[3][3]={{2 ,0 ,1}, {1, 2, 0}, {0, 1, 2}};

int checkInput(int userInput){
        std::cin.clear(); //clears not acceptable input, alpha if int
        std::cin.ignore(1000,'\n'); //ignores it and contniues
        std::cout<<"Not valid, type in again:\n";
        std::cin>>userInput;
        return userInput;
}

void scoreDecision(int playerPlay, int aiPlay){
    switch (matrix_decision[playerPlay][aiPlay]){
        case 1:
            player1.scoreP+=1;
            std::cout<<"\n"<<player1.name<<" won by choosing "<<AIGame.typePlay[player1.play]
                <<" while the AI chose "<<AIGame.typePlay[aiPlay];
            break;
        case 0:
            AIGame.score+=1;
            std::cout<<"\n"<<player1.name<<" lost by choosing "<<AIGame.typePlay[player1.play]
                <<" while the AI chose "<<AIGame.typePlay[aiPlay];
            break;
        default:
            std::cout<<"\n"<<player1.name<<" drawed, by choosing "<<AIGame.typePlay[player1.play]
                <<" while the AI also chose "<<AIGame.typePlay[aiPlay];
    }
    std::cout<<"\n\nScore\n-----------------\n"<<player1.name<<":"<<player1.scoreP<<
        "  AI:"<<AIGame.score<<"\n-----------------\n";
};

int main(){
    int playing=0;
    std::cout<<"Rock, paper, scissors\nType in your name:\n";  
    getline(std::cin, player1.name);
    std::cout<<"Starting match with AI, "<<player1.name<<"\n";
    while (playing==0){
        std::cout<<"0=Rock, 1=Paper, 2=Scissors:\n";
        std::cin>>player1.play;
        while((player1.play<0) || (player1.play>2) || std::cin.fail()){ //isdigit(player1.play)==false
            player1.play=checkInput(player1.play);
        }
        srand(time(0));
        int playAi = rand() % 3;
        scoreDecision(player1.play, playAi);
        std::cout<<"\nPlay again? 0=yes 1=no:\n";
        std::cin>>playing;
        while ((playing!=0 && playing!=1) || std::cin.fail()){
            playing=checkInput(playing);
        }
    } 
    if (player1.scoreP>AIGame.score){
        std::cout<<player1.name<<"  WON\n";
    }
    else if (player1.scoreP<AIGame.score){
        std::cout<<"AI WON\n";
    }
    else{
        std::cout<<"TIE\n";
    }
     std::cout<<"\nScore\n-----------------\n"<<player1.name<<":"<<player1.scoreP<<
        "  AI:"<<AIGame.score<<"\n-----------------\n";
    return 0;
}