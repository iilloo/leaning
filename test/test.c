#include<stdio.h>

// long test(int n)
// {
   
//     long result = 1;
//     long i = 1;
//     while(n-- > 2)
//     {
//         long j = result;
//         result +=  i;
//         i = j;
//     }
//     return result;
// }
#include<stdarg.h>
int sum(int n,...)
{
    va_list ap;
    int sum = 0;
    va_start(ap,n);
    for (int i = 0; i < n; i++)
    {
        sum += va_arg(ap,int);
    }
    va_end(ap);
    return  sum;
    
}
void test(char ch)
{
    return 1;
}
int main(void)
{
    test('a');
    
    
    
    return 0 ;
}

