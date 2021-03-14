# my_printf
Recode 'printf' in the C standard library

## Objectives

> **_int ft_printf(const char *, ...)_**

* Without buffer management
* _cspdiuxX%_
* flags will be only contain _-0.*_ 

## Implementation
![Untitled Diagram-2](https://user-images.githubusercontent.com/54715744/111077024-46f12580-8532-11eb-8070-9465e7f77626.png)
* A return value of _ft_printf_ is the number of characters printed.
-> Used global variable _g_count_ for easier approach.

### Set structure

```c
typedef struct s_option
{
    int flag_minus;
    int flag_zero;
    int width;
    int dot;	     // to know if there is precision
    int precision;   // initially set as -1 instead of 0
    int flag_pre_va; // if precision is a variable argument
    int num_m;	     // is number negative?
    char type;
 } t_option;
```

* Used structure to hold several data items of the same kind.
* _Precision_ is initially set as **-1** because _zero_ precision and _negative_ precision (which is considered as no precision) are different.
* _flag_pre_va_ is for distinguishing certain cases when obtaining precision from variable argument as -1.
-> _printf("%.d\n", 0)_ => \$
-> _printf("%.*d\n", -1, 0)_ => 0\$
* Returns last pointer to main function.

### Put in array

* Each type has quite different formatting based on flag, precision, and width.
* Divided into three functions based on where to pad: **left_blank**, **left_zero**, and **right_blank**.
* _Malloc_ final array to be printed.

### Print array

* Print array and increase _g_count_.
* _Free_ array.

## More explainations
https://velog.io/@ljiwoo59/ftprintf
