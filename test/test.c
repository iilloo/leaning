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

// void test(void)
// {
//     int c = 0 ;
//     int e = 0 ;
//     int *a = &c;
//     int *b = a+1 ; 
//     int d = a[1] ;
//     printf("%d,%d\n",*b,d);
// }
void test(void)
{
    int a[2][2][3] = {0};
    int (*p)[2][3] = a;
    printf("%d\n",p[0][0][0]);
}

int main(void)
{
    test();//(void)test();
    return 0 ;
}

