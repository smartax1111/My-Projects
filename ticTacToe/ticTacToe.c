#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

//        l       l
//    0   l   1   l   2
//        l       l
// ***********************
//        l       l
//    3   l   4   l   5
//        l       l
// ***********************
//        l       l
//    6   l   7   l   8
//        l       l


char space[9]={'p','p','p','p','p','p','p','p','p'};
unsigned int currentPlayer = 1;
int score, i;
int add = 2;

bool winner = false;
bool newGame = false;
bool draw = false;
bool gameOver = false;

bool playAgain();
bool win();

int player1();
int player2();
int board();
int minimaxAlg();
int bestMove();







bool win(){
    if(space[0] == 'x' && space[1] == 'x' && space[2] == 'x'){
        winner = true;
    }
    if(space[0] == 'x' && space[4] == 'x' && space[8] == 'x'){
        winner = true;
    }
    if(space[3] == 'x' && space[4] == 'x' && space[5] == 'x'){
        winner = true;
    }
    if(space[2] == 'x' && space[4] == 'x' && space[6] == 'x'){
        winner = true;
    }
    if(space[6] == 'x' && space[7] == 'x' && space[8] == 'x'){
        winner = true;
    }
    if(space[0] == 'x' && space[3] == 'x' && space[6] == 'x'){
        winner = true;
    }
    if(space[1] == 'x' && space[5] == 'x' && space[7] == 'x'){
        winner = true;
    }
    if(space[2] == 'x' && space[5] == 'x' && space[8] == 'x'){
        winner = true;
    }
    


    if(space[0] == 'o' && space[1] == 'o' && space[2] == 'o'){
        winner = true;
    }
    if(space[0] == 'o' && space[4] == 'o' && space[8] == 'o'){
        winner = true;
    }
    if(space[3] == 'o' && space[4] == 'o' && space[5] == 'o'){
        winner = true;
    }
    if(space[2] == 'o' && space[4] == 'o' && space[6] == 'o'){
        winner = true;
    }
    if(space[6] == 'o' && space[7] == 'o' && space[8] == 'o'){
        winner = true;
    }
    if(space[0] == 'o' && space[3] == 'o' && space[6] == 'o'){
        winner = true;
    }
    if(space[1] == 'o' && space[5] == 'o' && space[7] == 'o'){
        winner = true;
    }
    if(space[2] == 'o' && space[5] == 'o' && space[8] == 'o'){
        winner = true;
    }

    if(space[0] != 'p' && space[1] != 'p' && space[2] != 'p' && space[3] != 'p' && space[4] != 'p' && space[5] != 'p' && space[6] != 'p' && space[7] !='p' && space[8] != 'p'){
        draw = true;
        return draw;
    }
        
    else{
        return winner;
    }
    return winner;
}

int player1(int p1){
    bool sequence = false;
    printf("\n\n");
    while(sequence == false){
        if (space[p1] =='o' || space[p1] == 'x'){
            p1 = rand() % 9;
            
        }
        else{
            space[p1] = 'x';
            sequence = true;
        }
    }
    if(sequence = true){
        space[p1] = 'x';
    }
    win();//to refer back to the win function to see if win conditions are met
    if(winner == true){
        printf("Player 1 wins\n\n");
        return winner;
    }

    if(draw == true){
        printf("You draw\n\n");
        return draw;
    }

    else{
        currentPlayer = 2;
        return currentPlayer;
    }
        
}

int player2(int p2){
     printf("\n\n");

    if(space[p2] == 'x' || space[p2] == 'o'){
		printf("That space is already taken!\n\n");
    }
    if(space[p2] == 'p'){
        space[p2] = 'o';
        win();//to refer back to the win function to see if win conditions are met
        if(winner == true){
            printf("Player 2 wins\n\n");
            return winner;
        }

        if(draw == true){
            printf("You draw\n\n");
            return draw;
        }

        else{
            currentPlayer = 1;
            return currentPlayer;
        }
    }
    else{ 
        printf("invalid input\n\n");
    }
}

bool playAgain(){
    char Answer[3];
    char answerNo[3] = {'n','o'};
    char answerYes[3] = {'y','e','s'};


    printf("Would you like to play again?\n");
        scanf("%s", Answer);

        if(Answer[1] == answerNo[1]){
            printf("See you later then\n");
            gameOver = true;
            exit(0);
        }

        if(Answer[2] == answerYes[2]){

            newGame = true;

            return newGame;

        }
        else{
            printf("Invalid Input");
        }
}


int main(){
    
    int a,b;
    //For playing again [See Line XXX]
    while(gameOver == false){
        while(winner == false && draw == false){

            printf("       l       l       \n   %c   l   %c   l   %c   \n       l       l       \n***********************\n       l       l       \n   %c   l   %c   l   %c   \n       l       l       \n***********************\n       l       l       \n   %c   l   %c   l   %c   \n       l       l       \n\n",space[0], space[1], space[2], space[3], space[4], space[5], space[6], space[7], space[8]); 

            while(currentPlayer == 1 && winner == false && draw == false){//to keep the loop going if they make a wrong move
                
                a = rand() % 9;
                player1(a);

                
            }

            printf("       l       l       \n   %c   l   %c   l   %c   \n       l       l       \n***********************\n       l       l       \n   %c   l   %c   l   %c   \n       l       l       \n***********************\n       l       l       \n   %c   l   %c   l   %c   \n       l       l       \n\n",space[0], space[1], space[2], space[3], space[4], space[5], space[6], space[7], space[8]); 

            while(currentPlayer == 2 && winner == false && draw == false){//to keep the loop going if they make a wrong move
                printf("Player 2 its your turn what move would you like to make?");
                scanf("%d", &b);
                player2(b);
            }
        }
        playAgain(0);
        winner = false;
        currentPlayer = 1;
        for(int i = 0; i < 9; i++){
            space[i] = 'p';
        }
        
    }
    return(0);
}

