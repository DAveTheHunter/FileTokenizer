#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define buffer 1024
#define Delim " \n\t\r\a,"

int size = buffer; 


char** Tokenize(char* Readed){
    char* Token;
    char** tokens = malloc(sizeof(char) * size);
     if (!tokens) {
       fprintf(stderr, "Allocation error");
       exit(EXIT_FAILURE);
     }  
     int pos = 0;  
    Token = strtok(Readed,Delim);
   while (Token != NULL) {
       tokens[pos] = Token;
       if (pos >= size) {
         size+=buffer;    
         tokens = realloc(tokens, sizeof(char*) * size);
       }
      Token = strtok(NULL,Delim);
    }
  return tokens;
}

void Sort(char** tokens){
  for (int i = 0;i < sizeof(tokens)/sizeof(tokens[0]); i++) {
   for (int j = i + 1;j < sizeof(tokens)/sizeof(tokens[0]); j++) {
       if (tokens[i] > tokens[j]) {
         char *temp = tokens[i];
        tokens[i] = tokens[j];
        tokens[j] = temp;
       }
     } 
  }
}

void PrintTokens(char **tokens){
   for (int i = 0;i < sizeof(tokens)/sizeof(tokens[0]);i++) {
     printf("%s", tokens[i]); 
   }
}

int main(int argc,char* argv[]){
   if(argc != 2){
     printf("Wrong Number of arguments");
}
   FILE* Tobe = fopen(argv[1], "r");
   char *Readed = malloc(sizeof(char*) * size);
   fgets(Readed, sizeof(Readed), Tobe);
  //tokenize the readed value
  char** val =Tokenize(Readed);  
  //sort the tokens
  Sort(val); 
  //Print the tokens
  PrintTokens(val);
  return 0;
}
