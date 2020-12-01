#include <stdio.h>
#include <stdlib.h>

char programScopeArray[10];
char* testArray = "ABCDEFG\tGGG";

int main(void)
{
    char functionscopeArray[10];
    char* dynamicArray = (char*)malloc(10);
    {
        char blockScopeArray[10];
        printf("Size of blockScope array: %zu\n", sizeof(blockScopeArray));
        {
            printf("Size of blockScope array (inner block): %zu\n", sizeof(blockScopeArray));
        }
    }

    printf("\n");

    printf("Size of global array: %zu\n", sizeof(programScopeArray));
    printf("Size of test array (pointer): %zu\n", sizeof(testArray));

    printf("\n");
    
    printf("Size of functionscope array: %zu\n", sizeof(functionscopeArray));
    printf("Size of dynamic array: %zu\n", sizeof(dynamicArray));

    printf("\n");

    char** stringPtr = &testArray;
    printf("Size of stringPtr (testArray): %zu\n", sizeof(*stringPtr));

    programScopeArray[0] = 'B';
    programScopeArray[1] = 'C';
    programScopeArray[2] = 'D';
    programScopeArray[3] = 0;

    char* charPtr = &(*programScopeArray);
    stringPtr = &charPtr;
    printf("Size of global array: %zu\n", sizeof(*stringPtr));
    printf("%s\n", *stringPtr);

    printf("%c\n", *testArray + 1);
    printf("%c\n", *(testArray + 1));

    if (dynamicArray)
        free(dynamicArray);
    
}