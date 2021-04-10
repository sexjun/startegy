@[toc]
## 一、策略模式介绍
> 1. 策略模式（Strategy Pattern） 是属于设计模式中的 **行为模式** 中的一种，关注的是对象之间通信的方式。
> 2. 策略模式主要解决选项过多的问题，避免大量的`if else` 和 `switch`下有太多的`case`
> 3. c语言主要通过函数指针来实现， 
> 4. java pytho等面向对象的语言主要是通过 **多态和函数重载** 来完成的。




在策略模式（Strategy Pattern）中，一个类的行为或其算法可以在运行时更改。这种类型的设计模式属于行为型模式。

在策略模式中，我们创建表示各种策略的对象和一个行为随着策略对象改变而改变的 context 对象。策略对象改变 context 对象的执行算法。

**策略模式的的出现原因：**

意图：定义一系列的算法,把它们一个个封装起来, 并且使它们可相互替换。

**主要解决：** **在有多种算法相似的情况下，使用 if...else 所带来的复杂和难以维护。**

何时使用：一个系统有许多许多类，而区分它们的只是他们直接的行为。

如何解决：将这些算法封装成一个一个的类，任意地替换。

关键代码：实现同一个接口。

应用实例： 策略模式（Strategy），定义了一组算法，将每个算法都封装起来，并且使它们之间可以互换。

## 二、注意事项
- 何时使用
  一个系统有许多类，而区分它们的只是他们直接的行为时
 - 方法
    将这些算法封装成一个一个的类，任意的替换
  - 优点
    算法可以自由切换
    避免使用多重条件判断（如果不用策略模式我们可能会使用多重条件语句，不利于维护）
    扩展性良好，增加一个策略只需实现接口即可
  - 缺点
    策略类数量会增多，每个策略都是一个类，复用的可能性很小
    所有的策略类都需要对外暴露
  - 使用场景
    多个类只有算法或行为上稍有不同的场景
    算法需要自由切换的场景
    需要屏蔽算法规则的场景
  - 应用实例
    出行方式，自行车、汽车等，每一种出行方式都是一个策略
    商场促销方式，打折、满减等
    Java AWT中的LayoutManager，即布局管理器
  - 注意事项
    如果一个系统的策略多于四个，就需要考虑使用混合模式来解决策略类膨胀的问题

## 三、C语言代码示例
### 1. 源码
```c
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
```

### 2. 运行结果
```bash
(base) chendongsheng@chendongshengdeMacBook-Pro cpp % cd "/Users/chendongsheng/VsCodeWorkSpace/cpp/" && gcc function_with_ponit.c -o function_with_ponit && "/Users/chendongsheng/VsCodeWorkSpace/cpp/"function_with_ponit

======================== 
max is :3 

======================== 
最小值：1 和 2结果是：1 

======================== 
```

## 四、java的代码示例

可以参考菜鸟教程的demo即可，这里不做重复。[菜鸟教程-策略模式](https://www.runoob.com/design-pattern/strategy-pattern.html)
 
## 五、C++的代码示例


## 六、pyhton的代码示例



**参考：**
[1]:	[菜鸟教程-策略模式](https://www.runoob.com/design-pattern/strategy-pattern.html)
[2]:   [博客园-博主](https://www.cnblogs.com/adamjwh/p/11011095.html)
[3]