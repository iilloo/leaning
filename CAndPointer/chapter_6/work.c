#include <stdio.h>
char *find_char(char const *source, char const *chars)
{
    if (source == NULL || chars == NULL)
    {
        return NULL;
    }
    const char *s = &source[0];
    while (*(s++) != '\0')
    {
        if (*s == '\0')
        {
            break;
        }
        const char *c = &chars[0];
        while (*(c++) != '\0')
        {
            if (*s == '\0')
            {
                break;
            }
            if (*s == *c)
            {
                return (char *)s;
            }
        }
    }
    // printf("aaaa");
    return NULL;
}
void test_1(void)
{
    const char *source = "ABCDEF";
    // char so[] = {'A','B','C' ,'\0'} ;
    // so[0] = 'a';
    // printf("%s",so) ;
    const char *chars = "XRQVV";
    const char *reslut = find_char(source, chars);
    if (reslut == NULL)
    {
        printf("没有\n");
    }
    else
    {
        printf("是%c\n", *reslut);
    }
}

int del_substr(char *str, char const *substr)
{
    if (substr == "")
    {
        return 1;
    }
    char *s = str;          // 123465
    const char *c = substr; // 345

    for (int i = 0; *s != '\0'; ++i, ++s)
    {
        if (*s == *c)
        {
            int j = 1;
            for (++s, ++c; *c != '\0'; ++j, ++s, ++c)
            {
                if (*s != *c)
                {
                    return 0;
                }
            }
            printf("i:%d,j:%d\n", i, j);
            char *m = NULL, *n = NULL;
            for (m = str + i, n = str + i + j; *n != '\0'; ++m, ++n)
            {
                *m = *n;
            }
            // printf("%c\n",*(m));
            *m = '\0';
            return 1;
        }
    }
    return 0;
}
void test_2(void)
{
    char str[] = {'1', '2', '3', '2', '3', '6', '\0'};
    char *substr = "";
    if (del_substr(str, substr))
    {
        printf("1\n");
        printf("%s\n", str);
    }
    else
    {
        printf("0\n");
    }
}

void reverse_string(char *string)
{
    int l = 0;
    for (char *c = string; *c != '\0'; ++c)
    {
        ++l;
    }
    // printf("%d\n",l);
    char *f = string;
    char *e = string + l - 1;
    while (f <= e)
    {
        char n = *f;
        *f = *e;
        *e = n;
        ++f;
        --e;
    }
    // printf("%s\n", string);
}
void test_3(void)
{
    char ch[] = {'A', 'B', 'C', 'D', 'E', '\0'};
    reverse_string(ch);
    printf("%s\n", ch);
}

void test_4(void)
{
#define size 1000
    int a[size] = {0};
    for (int i = 0; i < size; ++i)
    {
        a[i] = 1;
    }
    for (int j = 0; j < size; j++)
    {
        if (a[j] == 1)
        {
            for (int i = 2 * (j + 2); i < size + 2; i += j + 2)
            {
                a[i - 2] = 0;
            }
        }
    }
    for (int i = size - 1; i >= 0; --i)
    {
        if (a[i] == 1)
        {
            printf("%d ", i + 2);
            // break;
        }
    }
    printf("\n");
}
void test_5(void)
{
    //寻找该系统上最大的质数
}
void test_6(void)
{
    //不做了
}
int main(void)
{
    test_4();
    return 0;
}