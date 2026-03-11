#include <stdio.h>
#include <string.h>

#define MAX 100
#define SIZE 100

char stackA[MAX][SIZE];
char stackB[MAX][SIZE];
int topA = -1;
int topB = -1;

void pushA(char word[]) {
    if(topA < MAX-1) {
        topA++;
        strcpy(stackA[topA], word);
    }
}

void undo() {
    if(topA >= 0) {
        strcpy(stackB[++topB], stackA[topA]);
        topA--;
    }
}

void redo() {
    if(topB >= 0) {
        strcpy(stackA[++topA], stackB[topB]);
        topB--;
    }
}

void showStacks() {
    printf("PileA:");
    for(int i=0;i<=topA;i++) {
        printf("%s,", stackA[i]);
    }

    printf("\nPileB:");
    for(int i=0;i<=topB;i++) {
        printf("%s,", stackB[i]);
    }

    printf("\n");
}

int main() {

    char command[50];
    char word[100];

    while(1) {

        scanf("%s", command);

        if(strcmp(command,"push")==0) {
            scanf("%s", word);
            pushA(word);
        }

        else if(strcmp(command,"undo")==0) {
            undo();
        }

        else if(strcmp(command,"redo")==0) {
            redo();
        }

        else if(strcmp(command,"show")==0) {
            showStacks();
        }

        else if(strcmp(command,"exit")==0) {
            break;
        }
    }

    return 0;
}
