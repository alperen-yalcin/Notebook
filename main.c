// Notebook app
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LETTER 50
char note[MAX_LETTER];
int num;
void read();
void add();
int main()
{
    while (1) {
    printf("1. Add a note\n2. Read notes\n3. Exit\nPlease enter the number of the item you want to make: ");
    scanf("%d", &num);
    getchar();
        switch(num) {
        case 1:
        add();
        break;
        case 2:
        read();
        break;
        case 3:
        printf("Exiting the program.");
        exit(0);
        
        default :
        printf("Please enter a valid number.");
    }
    }
    
    

    return 0;
}
void add() {
    FILE *fptr;
    fptr = fopen("note.txt", "a");
     if (fptr == NULL) {
        printf("Not able to open the file for writing");
        return;
    }
    printf("What do you want to write: ");
    fgets(note, sizeof(note), stdin);
    note[strcspn(note, "\n")] = '\0';
    fprintf(fptr, "%s\n", note);
    fclose(fptr);
    
}
void read() {
    FILE *fptr;
    fptr = fopen("note.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file");
        return;
    }
    while (fgets(note, MAX_LETTER, fptr) != NULL) {
    printf("%s", note);
    }
    fclose(fptr);
    
}