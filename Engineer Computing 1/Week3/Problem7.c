#include <stdio.h>
#include <stdlib.h>
int main(){
    int user=-1;
    do {
        int comp = rand() % (2+1);
        do {
            printf("Welcome to Rock Paper Scissors!\n");
            printf("Rock: 2, Paper: 1, Scissors: 0, Exit:-1\n");
            printf("Your choice: ");
            scanf("%d",&user);
            if (user>2 || user<-1) {
                printf("Please choose from the given choices!\n");
            }
        } while (user>2 || user<-1);
        if (user!=-1){
            switch (user){
                case 2:
                    printf("You chose Rock!\n");
                    break;
                case 1:
                    printf("You chose Paper!\n");
                    break;
                case 0:
                    printf("You chose Scissors!\n");
                    break;
            }
            switch (comp){
                case 2:
                    printf("Computer chose Rock!\n");
                    break;
                case 1:
                    printf("Computer chose Paper!\n");
                    break;
                case 0:
                    printf("Computer chose Scissors!\n");
                    break;
            }
            if (user==comp){
                printf("It's a draw\n");
            } else if(comp-user==1||comp-user==-2){
                printf("You win!\n");
            } else if(user-comp==1||user-comp==-2){
                printf("You lost!\n");
            }
            printf("\n");
        }
    } while (user!=-1);
    printf("Goodbye!");
    return 0;
}