#include <stdio.h>

#define _size_  (5)

int main()
{
    int array[_size_] = {0};

    printf("        array = %p\n", array); 
    printf("       &array = %p\n", &array); 
    printf("    array + 1 = %p\n", array + 1);
    printf("&array[0] + 1 = %p\n",&array[0] + 1);
    printf("   &array + 1 = %p\n", &array + 1);

    printf("\n");

    printf(" sizeof(array) = %ld\n",sizeof(array)); 
    printf("sizeof(&array) = %ld\n",sizeof(&array));

    printf("\n");   


    char str[]  = "123";
    int x = 48;
    char *ptr = (char*)&x;
    printf("%ld\n", sizeof(str));
    printf("%c", *ptr);
    return 0;
}