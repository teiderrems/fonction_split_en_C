#include<string.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct ReturnType
{
    char ** array;
    int size;
    
}ReturnType;




ReturnType split(char * chaine,char c){
    int size=1;
    char ** result=malloc(sizeof(char*)*size);

    result[0]=chaine;
    int k=0;
    int t=0;
    while (chaine[k]!='\0')
    {
        char * word=NULL;
        int word_size=1;
        word=malloc(sizeof(char)*word_size);
        int i = k;
        while (chaine[i]!='\0' && chaine[i]!=c)
        {
            word[i-k]=chaine[i];
            word_size++;
            realloc(word,word_size);
            i++;  
        }
        word_size++;
        realloc(word,word_size-1);
        word[word_size]='\0';
        result[t++]=word;
        if (chaine[i]!='\0')
        {
            size++;
            realloc(result,size);
            k=i+1;
        }
        else
        {
            break;
        }
    }
    ReturnType response;
    response.array=result;
    response.size=size;
    return response;
}


int main(int argc,char* argv[]){

    ReturnType result=split("Hello.world.My.Dear\0",'.');
    for (int i = 0; i < result.size; i++)
    {
        printf("%s\n",result.array[i]);
    }
    
    for (int i = 0; i < result.size; i++)
    {
        free(result.array[i]);
    }
    free(result.array);
    
    return EXIT_SUCCESS;
}