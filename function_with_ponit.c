#include "stdio.h"
/** 
 * @description: 使用C语言的函数指针，实现策略模式。在选择行为上进行优化代码。
 * @fileName: function_with_ponit.c 
 * @author: 陈东升 
 * @date: 2021-03-14 15:48:30
*/
typedef enum {
    GET_MAX,
    GET_MIN
} MAX_OR_MIN;

// 定义一个函数指针 typedef [返回值类型][*函数名字][（函数形参）]
typedef int (*funcation_pointer)(int a, int b);

int Max(int a, int b) {
    return a > b ? a : b;
}

int Min(int a, int b) {
    return a > b ? b : a;
}

// 打印分界线
void printfSplit();
// 直接使用函数指针的例子
void using_funcation_pointer();
// 使用typedef函数指针
void using_typedef_fun_p(MAX_OR_MIN chose);

int main(int argc, char const *argv[])
{
    // 直接使用函数指针
    printfSplit();
    using_funcation_pointer();

    // 使用typedef
    printfSplit();
    using_typedef_fun_p(GET_MIN);

    
    return 0;
}

/** 
 * @description: 
 * @fileName: function_with_ponit.c 
 * @author: 陈东升 
 * @date: 2021-03-14 15:29:08
*/
void using_funcation_pointer() {
    int (*p)(int a, int b);
    p = Max;
    int reslut = (*p)(1, 3);
    int reslut2 = p(1, 3);
    printf("max is :%d \n", reslut);
}

void printfSplit() {
    printf("\n");
    printf("======================== \n");
}

void using_typedef_fun_p(MAX_OR_MIN chose) {
    funcation_pointer funcation_pointer;
    if (chose == GET_MIN)
    {
        funcation_pointer = Min;
        printf("最小值：");
    } else if(chose == GET_MAX) {
        funcation_pointer = Max;
        printf("最大值：");
    } else {
        printf("不能识别");
    }
    int result = funcation_pointer(1, 2);
    printf("1 和 2结果是：%d \n", result);
}