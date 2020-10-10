#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buf[10];
    for (int i = 0; i < 10; ++i)
        buf[i] = 'a';
    
    long l = strlen(buf);
    printf("%ld\n", l);
    printf("%s\n", buf);
    return 0;
}
