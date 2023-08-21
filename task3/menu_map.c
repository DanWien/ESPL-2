#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  /* TODO: Complete during task 2.a */
  for(int i = 0 ; i < array_length ; i++)
    mapped_array[i] = f(array[i]);
  return mapped_array;
}

/* Ignores c, reads and returns a character from stdin using fgetc. */
char my_get(char c){
    char out = fgetc(stdin);
    return out;
}
/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */
char cprt(char c){
    if((0x20 <= c) && (c <= 0x7E))
        printf("%c\n",c);
    else
        printf(".\n");
    return c;
}

/* Gets a char c and returns its encrypted form by adding 1 to its value. If c is not between 0x20 and 0x7E it is returned unchanged */
char encrypt(char c) {
    if(0x20 <= c && c <= 0x7E)
        return c+3;
    return c;
}

/* Gets a char c and returns its decrypted form by reducing 1 from its value. If c is not between 0x20 and 0x7E it is returned unchanged */
char decrypt(char c){
    if(0x20 <= c && c <= 0x7E)
        return c-3;
    return c;
}

/* xprt prints the value of c in a hexadecimal representation followed by a new line, and returns c unchanged. */ 
char xprt(char c){
    printf("%x\n",c);
    return c;
}

struct fun_desc {
char *name;
char (*fun)(char);
}; 

struct fun_desc menu[] =  {
    {"Get String" , my_get} ,
    {"Print String" , cprt} ,
    {"Encrypt" , encrypt} ,
    {"Decrypt" , decrypt} ,
    {"Print Hex" , xprt} ,
    {NULL , NULL}
};

int main (int argc , char **argv) {
    char *carray = malloc(5);
    char input[100];
    int len = sizeof(menu) / sizeof(menu[0]);
    // printf("%d",len);
    while(1) {
        printf("Select operation from the following menu:\n");
        for(int i = 0 ; i < len-1 ; i++) {
            printf("%d",i);
            printf(".");
            printf("%s\n" , menu[i].name);
        }
        printf("Please choose a function by its number\nOption: ");
        if (fgets(input , 100 , stdin) == NULL)
            exit(1);
        int user_choice = atoi(input);
        if (0 <= user_choice && user_choice < len-1)
            printf("Within Bounds\n");
        else {
            printf("Not Within Bounds\n");
            exit(1);
        }
        carray = map(carray, 5 , menu[user_choice].fun);
    }
    free(carray);
    return 0;
}