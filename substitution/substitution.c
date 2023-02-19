#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isOnce(char[]);
int is_Alphabetic(char[]);
char* encryption(char[],char[]);

int main(int argc, char *argv[])
{
    //getting cmd line args and checking requirements
    char key[26];
    if(argc<=1 || argc>2){
        printf("Too many or less arguements!\n");
        return 1;
    }
    else{
        strcpy(key,argv[1]);
    }

    int len = strlen(key);
    //printf("key:%s\n",key);

    if( len<26 || !is_Alphabetic(key) || !isOnce(key)){
        printf("Key is unvalid!(Key should be 26 characters and alphabetic.)\n");
        return 1;
    }

    //getting plain text
    char text[50];
    printf("plaintext:");
    fgets(text,50,stdin);

    //output ciphertext
    printf("ciphertext:%s",encryption(key,text));

}
//does key have every letter once
int isOnce(char key[]){
    int once = 1;
    for(int i = 0; i<strlen(key); i++){
        for(int j = i+1; j<strlen(key); j++){
            if(key[i]==key[j]){
                once = 0;
            }
        }
    }
    return once;

}
//is every letter alphabetic
int is_Alphabetic(char key[]){
    int alpha = 1;
    for(int i=0; i<strlen(key);i++){
        if(!isalpha(key[i])){
            alpha = 0;
        }
    }
    return alpha;
}

//encryption of plaint text
char* encryption(char key[], char text[]){
    int upper = 0;
    int lower = 0;
    for(int i = 0; i<strlen(text);i++){
        if(!isalpha(text[i])){
            continue;
        }
        if(islower(text[i])){
            lower = 1;
        }else{
            upper = 1;
        }

        int alpNum = (int)toupper(text[i]);
        if(lower){
            text[i] = tolower(key[alpNum-65]);
        }else{
            text[i] = toupper(key[alpNum-65]);
        }

    }
    return text;
}
