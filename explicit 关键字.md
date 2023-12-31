## C++ explicit 关键字

```c++
#include <iostream>
using namespace std;
class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0)
        : x(x), y(y) {}
};
void displayPoint(const Point& p) 
{
    cout << "(" << p.x << "," 
         << p.y << ")" << endl;
}
int main()
{
    displayPoint(1);
    Point p = 1;
}
```

我们定义了一个再简单不过的`Point`类, 它的构造函数使用了默认参数. 这时主函数里的两句话都会触发该构造函数的隐式调用. (如果构造函数不使用默认参数, 会在编译时报错)

显然, 函数`displayPoint`需要的是`Point`类型的参数, 而我们传入的是一个`int`, 这个程序却能成功运行, 就是因为这隐式调用. 另外说一句, 在对象刚刚定义时, 即使你使用的是赋值操作符`=`, 也是会调用构造函数, 而不是重载的`operator=`运算符.

1. 指定构造函数或转换函数 (C++11起)为显式, 即它不能用于[隐式转换](https://link.zhihu.com/?target=https%3A//zh.cppreference.com/w/cpp/language/implicit_conversion)和[复制初始化](https://link.zhihu.com/?target=https%3A//zh.cppreference.com/w/cpp/language/copy_initialization).
2. explicit 指定符可以与常量表达式一同使用. 函数若且唯若该常量表达式求值为 true 才为显式. (C++20起)

这篇文章我们关注的就是第一点. 构造函数被`explicit`修饰后, 就不能再被隐式调用了. 也就是说, 之前的代码, 在`Point(int x = 0, int y = 0)`前加了`explicit`修饰, 就无法通过编译了