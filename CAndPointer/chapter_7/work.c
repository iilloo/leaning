#include<stdio.h>
int ascii_to_integer(char *string);
int ascii_to_integer(char *string)
{
    char ch ;
    int i = 0 , sum =0 ;
    while((ch = string[i++] ) != '\0')
    {
        if(ch >= '0' && ch <= '9')
        {
            sum = sum * 10 + (ch - '0');
        }
        else{
            return -1 ;
        }
    }
    return sum ;

}
int test_3(void)
{
    printf("%d\n",ascii_to_integer("1 2345"));
}

#include<stdarg.h>
int max_list(int len , ...)
{
    va_list ap ;
    int i = 0 ;
    va_start(ap , len);
    int max = va_arg(ap , int) ;  
    for(i = 0 ; i < len - 1 ; i++)
    {
        if(max < va_arg(ap , int))
        {
            max = va_arg(ap , int);
        }
    }
    va_end(ap);
    return max ;

}
void test_4(void)
{
    printf("%d\n" , max_list(3 , 1 , 2 , 3));
}

#include<string.h>
void print_integer(int num);
void print_float(float num);
int printf_overload(const char *format , ...)
{
    va_list ap ;    
    va_start(ap , format);
    int i = 0 ;
    int sum = 0 ;
    while(format[i++] != '\0')
    {
        if(format[i-1] == '%')
        {
            if(format[i] == 'd')
            {
                print_integer(va_arg(ap , int));
                ++sum ;
            }else if (format[i] == 'f')
            {
                print_float(va_arg(ap , double));
                ++sum ;
            }else if(format[i] == 'c')
            {
                putchar((char)va_arg(ap , int));
                ++sum ;
            }else if(format[i] == 's')
            {
                char* ch = (char *)va_arg(ap , char *);
                ++sum ;
                puts(ch);
            }
            else{
                putchar(format[i-1]);
            }
            
        }else{
            putchar(format[i-1]);
        }
    }
    va_end(ap);
    return sum ;

}
void test_5(void)
{
    printf("printf_overload的返回值:%d\n" , printf_overload("abc%c%s%s" , '1' , "2.3" , "hello"));
}
int main(void)
{
    test_5();
    return 0;
}