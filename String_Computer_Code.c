#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>

void str_comp(char[], char[]);
void insert(char[],char[]);
void dlt(char[],char[]);
void change(char[],char[]);

int main(){
    system("color Ba");
    char line[100][20];
    char str[100];
    printf("\n\n\t\t\t\t**************************\n\t\t\t\tWELCOME TO STRING COMPUTER\n\t\t\t\t**************************");
    printf("\n\n\t\tEnter the input string and modified output splitted by a space: \n\n");
    int i=-1;
    int j=0;
    int count=0;
    printf("\t\t\t");
    do
    {
        printf("\t\t\t");
        i=i+1;
        scanf("%s",&line[i][20]);
        count=count+1;    
    }while (line[i][20]!= '#');
    printf("\n\n\t\t\t\t***************************\n\t\t\t\tMODIFICATIONS IN THE STRING\n\t\t\t\t***************************\n\n");
    printf("\t\t\t\t\t");
    for(j=0;j<count-1;j++){
        str_comp(line[j+1],line[j+2]);
        j=j+1;
        printf("\n\t\t\t\t\t");
    }
    printf("E");
}

void str_comp(char word1[],char word2[]){
    
    dlt(word1,word2);
    change(word1,word2);
    insert(word1,word2);
}

void dlt(char word1[],char word2[]){
    int i,x=0;
    int len;
    if (strlen(word1)>strlen(word2)){
        len=strlen(word1);
    }
    else{
        len=strlen(word2);
    }
    for(i=0;i<len;i++){
        while (x!=len){
        if(word1[i]!=word2[i])
        {
            if ((word1[i+1]==word2[i]) || (word1[i-1]==word2[i])){
                printf("D%c0%d ",word1[i],i+1);
                break;
            }
            else if ((strlen(word1) > strlen(word2))  && (x >=strlen(word2) ))
            {
                printf("D%c0%d ",word1[x],x+1);
                break;
            }
        }
        x=x+1;
        }
    }
    return;
}

void change(char word1[],char word2[]){
    int i ,x=0;
    int len;
    len=strlen(word1);
    for (i=0;i<=len;i++)
    {
        while (x!=len){
        if(word1[i]!=word2[i]){
            if((word1[i+1]==word2[i+1]) && (word1[i-1]==word2[i-1])){
                printf("C%c0%d* ",word2[i],i+1);
                break;
            }
            else if ((word1[i-1]!=word2[i-1]) && (word1[i+1]==word2[i+1])   && (word1[i]!=word2[i+1]) && (strlen(word1)>strlen(word2))){
                printf("C%c0%d ",word2[i],i+1);
                break;
            }
            else if (((word1[i+1]==word2[i+1]) && (word1[i-1]==word2[i-1]))){
                printf("C%c0%d ",word2[i],i+1);
                break;
            }
            else if (((word1[i+1]==word2[i+1]) && (word1[i]!=word2[i+1])) && (word1[i+1]==word2[i+1] && word1[i-1]!=word2[i] && word1[i]!=word2[i+1])   && (word1[i]!=word2[i+1]) && (strlen(word1)>strlen(word2))){
                printf("C%c0%d ",word2[i-1],i);
                break;
            }
            else if ((word1[i+1]!=word2[i] ) || ((word1[i-1]!= word1[i-1])) && (word1[i+1] != word2[i+1]) ){
                printf("C%c0%d ",word2[i],i+1);
                break;
            }
        }
        x+=1;
    }
    }
    return;    
}

void insert(char word1[] ,char word2[]){
    int i=0;
    int len;
    if (strlen(word1)>strlen(word2)){
        len=strlen(word1);
    }
    else{
        len=strlen(word2);
    }
    for(i=0;i<len;i++){
        if(word1[i]!=word2[i]){
            if ((word1[i+1]==word2[i+1]) && (word1[i-1]!=word2[i-1]) && (word1[i]==word2[i+1])){
                printf("I%c0%d ",word2[i],i+1);
                break;
            }
            else if((word1[i]==word2[i+1]) && (word1[i+1]==word2[i+1])){
                printf("I%c0%d ",word2[i],i+1);
                break;
            }
 
        }
    }
    return;
}