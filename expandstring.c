#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ExpandString(char *dst, const char* src, size_t tab_size)
{
    unsigned short i = 0;
    unsigned short j = i;
    size_t length = sizeof(src);

    while(1)
    {
        char c = src[i];
        if (c == '\t')
        {
            char* temp = realloc(dst, length + tab_size);
            if (temp)
            {
                for(unsigned short k = 0; k < tab_size; k++)
                {
                    dst[j++] = ' ';
                }
                j--;
            }
            else
            {
                printf("ERROR REALLOCATING MEMORY\n");
                return 0;
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

    printf("Size of dst: %zo\n", length);
    return 1;
}

int main(void)
{
    char* src = "A\tB\tC\t";
    char* dst = malloc(sizeof(src));

    if(!ExpandString(dst, src, (size_t)8))
        return EXIT_FAILURE;

    printf("size of dst: %zo\n\n", sizeof(dst));
    printf("After (src): \n%s\n", src);
    printf("After (dst): \n%s\n", dst);

    if (dst)
        free(dst);

    return EXIT_SUCCESS;
}