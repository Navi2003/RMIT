#include <stdio.h>
int main()
{
    //Declare variables
    float result;
    
    //Input result until in correct range
    do {
        printf("Enter your final result: ");
        scanf("%f",&result);
        if(result>100 || result<0){
        printf("The final result must be between 0 and 100.\nTry again.\n");
    }
    } while (result>100 || result<0);
    
    //Print final result based on score
    if (result>=80) {
        printf("Final result: HD");
        } else if (result>=70) {
            printf("Final result: DI");
            } else if (result>=60) {
                printf("Final result: CR");
                } else if (result>=50) {
                    printf("Final result: PA");
                    } else {
                        printf("Final result: NN");
    }
    return 0;
}
