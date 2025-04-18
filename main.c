#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " \t\n\r\a"
#define SIZE 1024

char** tokenize(char *readed){
  char* token;
   int size = SIZE;
  int pos = 0;
  char** tokens = malloc(sizeof(char*) * size);
   token = strtok(readed, DELIM);
  while(token != NULL){
   tokens[pos] = token;
   pos++;
   if(pos >= size){
    size += 1024;
    tokens = realloc(tokens, sizeof(char*) * size);
 } 
  token = strtok(NULL, DELIM);
  } 
  tokens[pos] = NULL; 
 return tokens;
}


void sort(char** tokens){
  for(int i = 0;tokens[i] != NULL;i++)   
   for(int j = i + 1;tokens[j] != NULL;j++){
    if(strcmp(tokens[i], tokens[j]) > 0){
     char* temp = tokens[i];
     tokens[i] = tokens[j];
     tokens[j] = temp;
}
  }
 }

int main(int argc,char *argv[]){
  if (argc != 2) printf("Incorrect number of arguments");
  FILE* file = fopen(argv[1], "r");  
  int size = SIZE; 
  char *readed = malloc(sizeof(char*) * size); 
  int pos = 0;
  char cur = fgetc(file);
 
 while (cur != EOF) {
   readed[pos] = cur;
   pos++;
   cur = fgetc(file);
   if(pos > size){
    size += 1024;
    readed = realloc(readed, sizeof(char*) * size);
}
  }
  fclose(file);
  readed[pos] = '\0';
  char** tokens = tokenize(readed);
  sort(tokens);   
   
   for(int i = 0;tokens[i] != NULL;i++)
     printf("%s\n", tokens[i]);
 
  free(tokens);
  return 0;
}

