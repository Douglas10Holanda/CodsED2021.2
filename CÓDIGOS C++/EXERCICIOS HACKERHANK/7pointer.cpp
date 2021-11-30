#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b)
{
    *a = *a + *b;
    *b = abs((*a - *b) - *b);
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;

    // soma de a e b
    // resultado absoluto da subtração de a e b
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
