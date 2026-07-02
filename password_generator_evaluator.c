/*
Program: Password Generator and Evaluator
creator: Husain Chatiwala
Concepts Used: Functions, Arrays, Strings, Pointers, Modular Programming
Description: Generates strong passwords and evaluates password strength
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

//For generating password

int generator(char *password, int length ){

    char upper[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char lower[27] = "qwertyuiopasdfghjklzxcvbnm";
    char number[11] = "1234567890";
    char special[] = "!@#$%&*-_";

    password[0]=upper[rand()%26];
    password[1] = lower[rand()%26];
    password[2] = number[rand()%10];
    password[3] = special[rand()%9];

    for(int i=4; i<length; i++){
        int type = rand()%4;
        if(type==0){
            password[i] = upper[rand()%26];
        }
        else if(type==1){
            password[i] = lower[rand()%26];
        }
        else if(type==2){
            password[i] = number[rand()%10];
        }
        else{
            password[i] = special[rand()%(sizeof(special)-1)];
        }
    }
    for(int i=0; i<length; i++){
        int j = rand()%length;
        char temp = password[i];
        password[i] = password[j];
        password[j] =temp;
    }
    password[length] = '\0';
    return 0;
}

//For evaluating password

int evaluation(char *evaluate, int length){
    int str[4] = {0};
    int score=0, check=0;
    for(int i=0; i<length; i++){
        if(isupper(evaluate[i])){
            str[0]=1;
        }
        if(islower(evaluate[i])){
            str[1]=1;
        }
        if(isdigit(evaluate[i])){
            str[2]=1;
        }
        if(!isalnum(evaluate[i])){
            str[3]=1;
        }
    }

    for(int i=0; i<4; i++){
       check += str[i];
    }

    if(check==4){
        score+=40;
    }
    else if(check==2 || check==3){
        score+=30;
    }
    else{
        score+=15;
    }

    int pass[3];
    if(length < 6) {
        score += 0;
    }
    else if(length >= 6 && length < 8) {
        score += 10;
    }
    else if(length >= 8 && length < 12) {
        score += 20;
    }
    else if(length >= 12 && length < 18) {
        score += 35;
    }
    else {
        score += 50;
    }

    // Penalty for repeated patterns

    int repeatPenalty = 0;

    for (int i = 0; i < length - 2; i++) {
        if (evaluate[i] == evaluate[i+1] && evaluate[i] == evaluate[i+2]) {
            repeatPenalty += 10;
            break;
        }
    }

    for (int i = 0; i < length - 3; i++) {
        if (evaluate[i] == evaluate[i+2] && evaluate[i+1] == evaluate[i+3]) {
            repeatPenalty += 10;
            break;
        }
    }

    score -= repeatPenalty;

    if(score>=80){
        printf("\nStrength passsword is strong!!!\n");
    }
    if(score>=40 && score<80){
        printf("\nStrength passsword is Medium\n");
    }
    if(score<40){
        printf("\nStrength passsword is weak~~\n");
    }

    if (score < 40) printf("Try adding more characters, numbers, and symbols.\n");
    else if (score < 80) printf("Good, but could be stronger with more mix.\n");
    else printf("Excellent! Your password is highly secure.\n");

    return 0;
}

int main() {

    srand(time(0));
    int z=1 , ask;
    while(z) {
        //your function here
        int choice, len;
        char password[26], evaluate[26];
        printf("Your Password tools\n");
        printf("1) Password Generator.\n");
        printf("2) Password Evaluator.\n");
        printf("Enter your choice --> (1) or (2): ");
        scanf("%d",&choice);

        if(choice==1){
            printf("Enter the length of your desire password (8-25): ");
            scanf("%d",&len);
            if(len<8 || len>25){
                printf("Invalid length..\n");
                printf("Changing the length to 12....\n");
                len=12;
            }
            printf("\nGenerating Password....\n");
            printf("Your password is: ");
            generator(password, len);
            printf("%s",password);
        }

        else{
            printf("Enter the password for evaluation: ");
            scanf("%25s",evaluate);
            int evlen = strlen(evaluate);

            int score = evaluation(evaluate, evlen);

        }

        printf("\n \nDo you want to run this program again?:\nPress 1 for run again and press 0 to exit: ");
        scanf("%d" , &ask);
        printf("\n");

        if(ask) {
            z=1;
        }
        else {
            printf("Thank you for using this program, do visit again.\n \n");
            z=0;
        }
        printf("-------------------------------------------------------------------------------------------------------\n\n");

    }
    
    return 0;
}
