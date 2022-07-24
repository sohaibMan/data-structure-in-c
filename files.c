#include <stdlib.h>
#include <stdio.h>

int main(){

// CRUD  CREATE READ UPDATE DELETE
// ! CREATE
// FILE *file;
// file = fopen("file.txt", "w");   

// create the file if not created and
// overwrite it if already created(delte the content of the file)
// if(file == NULL){
//     printf("Error opening file\n");
//     exit(1);//exit the program with error code 1
// }

// fprintf(file, "Hello World");
// f 
//fputs("hello", file);// write the string to the file first and then put the pointer to the file
//fputs(" world", file);// write the string to the file first and then put the pointer to the file

//?fseek() change the place of the cursor
//fseek(file, -5, SEEK_END);// move the pointer to //!the end of the file( negative number to get bac)
// fseek(file, 0, SEEK_SET);// move the pointer to //!the head of the file
// fseek(file, 0, SEEK_CUR);// move the pointer to //!the current position of the file
//rewind(file);// move the pointer to //!the head of the file
//printf("%d",ftell(file));// get the current position of the pointer
//char newname[20];
// printf("Enter the new name of the file: ");
// scanf("%s",newname);
// if(!rename("file.txt",newname))printf("success");
// else printf("can't rename the file");
// printf("Enter the  name of the file you wanna delete: ");
// scanf("%s",newname);
// if(!remove(newname))printf("success");
// else printf("can't remove the file");

//fclose(file);



    return 0;
}