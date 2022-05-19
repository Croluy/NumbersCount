#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MIN_NUMBER 0
#define MAX_NUMBER 9
#define MIN_ITER 1
#define MAX_ITER 10

int main(){
    unsigned short int n;       //1st number of the algorithm
    unsigned short int iter;    //Number of iterations

    /** Gets "n" */
    printf("Hello, please provide a number between %d and %d:\t",MIN_NUMBER,MAX_NUMBER);
    scanf("%hu", &n);
    if(n < MIN_NUMBER || n > MAX_NUMBER){
        do{
            printf("Number %hu is invalid, please provide a number between %d and %d:\t",n,MIN_NUMBER,MAX_NUMBER);
            scanf("%hu", &n);
        }while(n < MIN_NUMBER || n > MAX_NUMBER);
    }
    printf("You've chosen %hu.\nThis will be the 1st number of the algorithm.\n",n);

    /** Gets "iter" */
    printf("\nNow please provide a number between %d and %d:\t",MIN_ITER,MAX_ITER);
    scanf("%hu", &iter);
    if(iter < MIN_ITER || iter > MAX_ITER){
        do{
            printf("Number %hu is invalid, please provide a number between %d and %d:\t",iter,MIN_ITER,MAX_ITER);
            scanf("%hu", &iter);
        }while(iter < MIN_ITER || iter > MAX_ITER);
    }
    printf("You've chosen %hu.\nThis number represents the iterations of the algorithm.",iter);

    /** Communicate "n" and "iter" */
    printf("\n\n\nStarting number:\t%hu\nNumber of Iterations:\t%hu\n\n\n",n,iter);

    char attuale;               //Current verified char
    unsigned int contatore=1;   //Times the current char repeats.. always at least 1
    unsigned int s_len=1;       //Length of string to print.. always at least 1
    unsigned int old_len=1;     //Length of old string (1st iteration is equal to 1)
    unsigned int i=0;           //Counter of current char

    char s[122];        //Old string-line above
    char coppia[3];     //Couple of numbers to concatenate
    char new[122]="";   //String to print
    
    snprintf(s, 120, "%hu", n); //Inserts "n" to s[0]

    printf("\n%c\n",s[0]);  //Print the 1st line of algorithm (which is equal to "n")

    for(unsigned int k=1;k<iter;k++){
        //check each char of the line above
        do{
            attuale=s[i];   //Sets current char to verify
            //Check if current char repeats at least once
            while(attuale==s[i+contatore]){
                contatore++;    //Increase counter of current char repeatition
                s_len++;        //Increase the length of the string to print
            }
            sprintf(coppia,"%u%c",contatore,attuale);   //Insert in couple string the repetitions and the char
            strcat(new,coppia);     //Append couple string to string to print
            i+=contatore;       //Increases "i" until next different char
            contatore=1;    //Reset counter of current char repeatition
        }while(i<old_len);

        //Print string
        for(unsigned int j=0;j<strlen(new);j++) printf("%c ",new[j]);
        printf("\n");

        strcpy(s,new);                      //Copies new string to old one
        memset(coppia,0,sizeof(coppia));    //Clears couple string
        old_len=strlen(new);                //Sets length of old string
        memset(new,0,sizeof(new));          //Clears new string
        i=0;                                //Resets counter to char to verify
    }
    return 0;
}