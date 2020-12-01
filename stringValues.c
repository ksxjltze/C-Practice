#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char arrc[] = "4.7", animals[][10] = {"lion", "elephant", "tiger", "cat"};
    // char arrd[] = "4.7";
    char *pb = arrc;
    // animals[][10][10] = {{"lion", "elephant"}, {"tiger", "cat", "adads"}};
    char *pc = animals[0];
    int arri[10] = {1,2,3};

    printf("1. %zu\n", sizeof(arrc));
    printf("2. %zu\n", sizeof(animals));
    printf("3. %zu\n", sizeof(arri));
    printf("4. %zu\n", strlen(arrc + 1));
    printf("5. %zu\n", sizeof(*(animals + 3)));
    // printf("animals: %s\n", *(animals + 3));
    printf("6. %zu\n", strlen(pc));
    printf("7. %zu\n", strlen(pc + 12));
    printf("8. %zu\n", strlen(++pb));

    printf("Before: %zu\n", sizeof(arrc));
    char* temp = realloc(arrc, 8);
    if (temp)
    {
        printf("After: %zu\n", sizeof(arrc));
    }

}