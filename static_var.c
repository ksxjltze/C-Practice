#include <stdio.h>

int find_max(int a, int b)
{
    // int max = (*a > *b) ? *a: *b;
    static int max = a + b;
    return &max;
}

int find_min(int a, int b)
{
    return a < b ? a : b;
}

int main(void)
{
    int x = 10, y = 20, *max, min;
    max = find_max(x, y);
    min = find_min(x, y);
    printf("Max: %d | Min :%d\n", *max, min);
    return 0;
}
