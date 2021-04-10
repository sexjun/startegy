#include <iostream>
/** 
 * @description: c++的策略模式
 * @fileName: strategy.cpp 
 * @author: 陈东升 
 * @date: 2021-03-14 17:02:53
*/

// 定义一个抽象类，抽象类有一个抽象方法。
class StrategtBase{
public:
    virtual void strategy() = 0;
};

// 第一个抽象类的子类
class StrategtA : public StrategtBase{
public:
    void strategy() {
        std::cout << "A" << std::endl;
    }
};

// 第二个抽象类的子类
class StrategtB : public StrategtBase{
public:
    void strategy() {
        std::cout << "B" << std::endl;
    }
};

// 工具类
class Context {
public:
    // 根据传参进行初始化抽象类
    Context(StrategtBase *pStrategy):object(pStrategy)
    {
    }
    // 使用多态运行抽象类方法
    void contextInterface() {
        object->strategy(); 
    }

    private:
    // 放一个抽象类的对象
    StrategtBase *object;
};


int main(int argc, char const *argv[])
{
    StrategtBase *pA = new StrategtA;
    StrategtBase *pB = new StrategtB;
    Context a = new Context(pA);

    return 0;
}
