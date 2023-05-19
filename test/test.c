#include<stdio.h>

long test(int n)
{
   
    long result = 1;
    long i = 1;
    while(n-- > 2)
    {
        long j = result;
        result +=  i;
        i = j;
    }
    return result;
}
int main(void)
{
    printf("%ld\n",test(2));
    return 0 ;
}

