// Notebook
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fptr;
    fptr = fopen("notebook.txt", "a");
   
    char note[50];
    printf("What do u want to write? ");
    fgets(note, sizeof(note), stdin);
    note[strcspn(note, "\n")] = '\0' ;
   
    printf("%s\n", note);
    printf("%lu", strlen(note));
    fprintf(fptr, "%s\n", note);
    fclose(fptr); 

    return 0;
}