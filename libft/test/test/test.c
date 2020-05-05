#include <stdio.h>

int main()
{
    int get(int v)
    {
        return 1 + v;
    } 

    int len = 3;

    int arr[len];
    int i = 0;
    while(i < len)
    {
        arr[i] = get(i);
        ++i;
    }

    int i2 = 0;
    while(i2 < len)
    {
    printf("%d\n", arr[i2]);
        ++i2;
    }
       
    return 0;
}