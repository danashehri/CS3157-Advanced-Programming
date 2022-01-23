#include <stdio.h>
#include "convert.h"
int main()
{
    int x;
    scanf("%d", &x);

    printf("signed dec:     %d\n", x);
    printf("unsigned dec:   %u\n", x);
    printf("hex:            %x\n", x);
    convert(x);
    return 0;
}
