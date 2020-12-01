#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* ExpandString(char *dst, const char* src, size_t length, size_t tab_size)
{
    unsigned short i = 0;
    unsigned short j = i;

    while(1)
    {
        char c = src[i];
        if (c == '\t')
        {
            length += tab_size;
            printf("New size: %zu\n", length);
            char* temp = realloc(dst, length);
            if (temp)
            {
                dst = temp;
                for(unsigned short k = 0; k < tab_size; k++)
                {
                    dst[j++] = ' ';
                }
                j--;
            }
            else
            {
                printf("ERROR REALLOCATING MEMORY\n");
                return NULL;
            }
            
        }
        else
        {
            dst[j] = src[i];
        }

        if (src[i] == 0)
            break;

        i++;
        j++;
    }

    printf("\nSize of dst: %zu\n", length);
    return dst;
}

int main(void)
{
    char* src = "A\tB\tC\tD\tE\tF\tG";
    size_t length = strlen(src) + 1;
    char* dst = malloc(strlen(src) + 1);

    printf("Size of src: %zu\n", length);
    printf("Size of dst: %zu\n", length);

    printf("\n");
    printf("Before (src): \n%s\n", src);
    printf("\n");

    dst = ExpandString(dst, src, length, (size_t)16);
    if (!dst)
        return EXIT_FAILURE;

    printf("\n");

    printf("Size of src: %zu\n", length);
    printf("Size of dst: %zu\n", length);

    printf("\n");

    printf("After (dst): \n%s\n", dst);

    if (dst)
        free(dst);

    return EXIT_SUCCESS;
}