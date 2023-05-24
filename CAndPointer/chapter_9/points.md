#### 第九章 字符串、字符和字节

1. 头文件string.h包含了使用字符串函数所需的原型和声明
2. `size_t strlen( char const *string );`size_t类型是在stddef.h中定义的，是一个无符号数类型，在表达式中不能使用无符号数，看下面的例子:

   ```c
   if( strlen(x) - strlen(y) >= 0){;}
   if( strlen(x) >= strlen(y) ){;}
   if( (int))strlen(x) - (int)strlen(y) >= 0){;}
   ```

   上面的if里面的式子永远为真，strlen函数的返回值是一个无符号数，所以srelen(x) - strlen(y) 的结果也是一个无符号数，无符号数不可能是负的,把无符号数强转为int就行了，但要注意是否超出表示范围
3. 复制字符串的函数为strcpy,原型为 `char *strcpy( char *dst, char const *src);`

   必须保证目标字符数组的空间足以容纳需要复制的字符串，如果dst所指向的空间比src的短，多余的字符会被复制到紧接着dst所指空间的后面,所以在使用这个函数前确保目标参数足以容纳源字符串
4. 连接字符串函数为strcat，`char *strcat( char *dst, char const *src);`strcat 函数要求 dst 参数原先己经包含了一个字符串 （ 可以是空字符串 ）,它找到字符串的末尾，并把src字符串的一份拷贝添加到这个位置。

   必须保证目标字符串数组的剩余空间足以保存整个源字符串
5. strcpy和strcat返回的是第一个参数的拷贝(里面是一个地址)
6. 字符串比较函数strcmp，`int strcmp( char const *s1, char const *s2 );`如果s1< s2 ,函数返回大于零的值(不一定就是-1)，s1>s2返回大于0的值(不一定是1)，相等返回0
7. 长度受限的字符串字符串函数(strccpy、strncat、strncmp\)

   ```c
   char *strncpy( char *dst, char const *src, size_t len);
   char *strncat( char *dst, char const *src, size_t len);
   int strncmp( char const *s1, char const *s2, size_t len);
   ```

   * strncpy把源字符串的字符复制到目标数组，它总是向dst写入len个字符，如果src的长度小于len，dst数组就用额外的NUL字节填充到len长度；如果src的值大于或等于len，那么只有len个字符被复制到dst中，此时dst的结尾将没有NUL字节(需要自己加上)
   * strncat从src复制最多len个字符到目标数组的后面，并且strncat会在结果字符串的最后添加NUL字节，当src的长度<len时只会添加一个NUL字节不会进行NUL填充；当src的长度>=len时，strncat函数将src的前len个字符添加到dst的尾部(当然覆盖掉了源NUL字节了)，最后再在新的dst后面添加一个NUL字节
   * strncmp只比较前len个字符，前len个字符像strcmp一样的规则进行比较
8. 在一个字符串内查找一个特定字符使用strchr和strrchr函数，原型如下

   ```c
   char *strchr ( char const *str, int ch);
   char *strrchr ( char const *str, int ch );
   ```

   strchr在str中查找字符ch(存在类型的隐式转换)第一次出现的位置，返回一个指向该位置的指针，如果字符不存在则返回NULL;strrchr返回的是一个指向字符串中该字符最后一次出现的位置(最右边那个)
9. 查找一组字符中的任一字符第一次在目标字符串中出现的位置，原型如下：

   ```c
   char *strpbrk( char const *str, char const *group );
   ```

   exp:

   ```c
   char string[20] = "Hello there, honey." ;
   char* ans = strbpbrk(string , "aeiou") ;
   //ans所指向的位置是string+1
   ```
10. 在字符串中查找一个字串可以使用strstr函数，原型如下：

    ```c
    char *strstr( char *s1, char const *s2) ;
    ```

    在s1中查找整个s2第一次出现的起始位置，返回一个指向该位置的指针，如果没有出现返回NULL；如果第二个参数是一个空字符串，函数就返回s1
11. strspn和strcspn函数用于在字符串的起始位置对字符计数，原型如下：

    ```c
    size_t strspn( char const *str , char const *group );
    size_t strcspn( char const *str , char const *group );
    ```

    strspn返回str起始部分连续匹配group中任一字符的字符数（直到在str中第一次遇到不在gruop字符串里面存在的字符的位置的前面的字符的个数）

    exp:

    ```c
    int len1 ,len2 ;
    char a[] = "12,12,12,3333";
    len1 = strspn(a , "12")；
    len1 = strspn(a , ",12")；
    //len1的结果为2，len2的结果是9
    ```

    strcspn函数与strspn函数正好相反，strspn是连续匹配直到第一次遇到不匹配的位置之前的字符数；strcspn是连续不匹配直到第一次遇到匹配的位置之前的字符数
12. strtok用于分割字符串：

    * strtok函数用于分解字符串为一组子字符串，第一个参数是要分解的字符串，第二个参数是包含分隔符的字符串。
    * 首次调用strtok函数时，传递要分解的字符串和分隔符字符串，函数会在遇到分隔符时将其替换为’\0’，并返回第一个子字符串的指针。
    * 之后再次调用strtok函数时，传递NULL和分隔符字符串，函数会从上次结束的位置继续查找分隔符，并返回下一个子字符串的指针。
    * 如果没有可检索的子字符串，则返回一个空指针。

    exp:

    ```c
    #include <string.h>
    #include <stdio.h>
    int main () {
      char str[80] = "litianyi@hust.edu@cn";
      const char s[2] = ".@";
      char *token;
      //第一次调用strtok函数
      token = strtok(str, s);
      //循环调用strtok函数
      while( token != NULL ) {
        printf( "%s\n", token );
        token = strtok(NULL, s);
      }
      return(0);
    }
    /*输出结果如下：
    litianyi
    hust
    edu
    cn
    */
    ```

    你可以在第一次调用之后的strtok调用(第一个参数为NULL时)时，使用不同的分隔符集合；当一个字符串的不同部分由不同的字符集分割的时候，可以使用这个方法；strtok函数会保存第一次处理的源字符串的局部状态，所以不能同时分割两个字符串
13. strerror函数用于返回一个指向描述错误信息的字符串的指针；原型：

    ```c
    char *strerror(int error_number );
    ```

    当函数调用出现一些错误时，操作系统通过设置一个外部的整型变量errno进行错误代码的报告，strerrror将其中的一个errno作为参数，返回一个指向用于描述错误信息的字符串
14. 位于头文件ctype.h中的函数可以对字符进行操作，第一组函数用于对字符分类，第二组函数用于转换字符
15. 用于字符分类的函数，接受一个包含字符值的整形参数。函数测试这个字符并返回一个整型值，表示真或假

    |   函数   |                         如果他的参数符合下列条件就返回真                         |
    | :------: | :------------------------------------------------------------------------------: |
    | iscntrl |                                   任何控制字符                                   |
    | isspace | 空白字符(空格、换页'\\f'、换行、回车‘\r’、<br />制表符‘\t’、垂直制表符'\\v') |
    | isdigit |                                  十进制数字0~9                                  |
    | isxdigit |        十六进制数字，包括所有十进制数字，小写字母a\~f，<br />大写字母A\~F        |
    | islower |                                   小写字母a\~z                                   |
    | isupper |                                   大写字母A\~Z                                   |
    | isalnum |                           字母或数字，a\~z,A\~Z或0\~9                           |
    | ispunct |               标点符号，任何不属于数字或字母的图形字符(可打印字符)               |
    | isgraph |                                   任何图形字符                                   |
    | isprint |                      任何可打印字符，包括图形字符和空白字符                      |
    | isalpha |                                  字母a\~z,A\~Z                                  |
16. 字符转换。

    * 把大写字母转换为小写：`int tolower( int ch );`
    * 把小写字母转换为大学: `int toupper( int ch );`
    * 如果函数的参数不符合不符合要求，则直接返回该参数
17. 如果判断一个字符是否是大写字母，如果用ch>='A'&&ch<='Z'则只能在使用ASCII的机器上运行，如果用isupper函数来判断，则程序是可移植的

qq
