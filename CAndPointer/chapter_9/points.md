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
7.
