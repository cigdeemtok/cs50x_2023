// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <stdio.h>
#include <string.h>

char* replace(char word[]){
    int len = strlen(word);
    for(int i=0; i<len; i++){
        switch(word[i]){
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case'o':
                word[i] = '0';
                break;
        }
    }
    return word;
}


int main(int argc, char *argv[])
{
    if(argc == 1 || argc>2){
        printf("Too many or less arguements!");
        return 1;
    }

    printf("%s\n",replace(argv[1]));
}

