#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


int count_letters(char[]);

int count_words(char[]);

int count_sentences(char[]);


int main(void)
{
    //getting text
    char text[500];
    printf("Text:");
    fgets(text,500,stdin);
    //printf("%s",text);

    //counting letters,words and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //computing grade using Coleman-Liau index
    float L = (float)(letters)/(float)(words)*100.0; //L is the average number of letters per 100 words in the text
    float S = (float)(sentences)/(float)(words)*100.0; //S is the average number of sentences per 100 words in the text
    //formula: index = 0.0588 * L - 0.296 * S - 15.8
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("index: %f\n",index);

    if((int)round(index)<1){
        printf("Before Grade 1\n");
    }
    else if((int)round(index)>16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %d\n",(int)round(index));
    }
}

//count letters
int count_letters(char text[]){
    int letters = 0;
    for(int i =0; i<strlen(text);i++){
        if(isalpha(text[i])){
            letters++;
        }
    }
    return letters;
}

//count words
int count_words(char text[]){
    int words = 0;
    for(int i =1; i<strlen(text);i++){
        if(text[i]==' '){
            words++;
        }
    }
    return words+1;
}

//count sentences
int count_sentences(char text[]){
    int sentences = 0;
    for(int i = 0; i<strlen(text); i++){
        if(text[i] == '.' || text[i] == '!' || text[i] == '?'){
            sentences++;
        }
    }
    return sentences;

}
