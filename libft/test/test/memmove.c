#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void pnt(char *str)
{
    int i = 0;
    while(str[i] != 0)
    {
        write(1, &str[i], 1);
        ++i;
    }
    write(1, "\n", 1);
}

int main()
{
    char *str = "test";
    char *dest = malloc(10 * sizeof(char));
    printf("%p\n", &str[0]);
    printf("%p\n", &str[1]);
    if(&str[0] >= &str[1])
    {
        printf("more\n");
    }
    else
    {
        printf("less\n");
    }
    
    return 0;
    int x = 0;
    while(x < 9)
    {
        dest[x] = x + 48;
        ++x;
    }
    dest[9] = 0;
    pnt(dest);

    char *answer = memmove(dest, str, 6);
    pnt(answer);
    return 0;
}

void *memmove(void *dest, const void* src, size_t n)
{
    size_t i;
    unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;

    i = 0;
    while(i < n)
    {
        ptr[i] = ptr2[i];
        ++i;
    }
    return ptr;
}