## decltype关键字

decltype是C++11新增关键字，编译时期进行自动类型推导。

```c++
auto varname = value;
decltype(exp) varname = value;
```

varname 表示变量名，value 表示赋给变量的值，exp 表示一个表达式。auto 根据=右边的初始值 value 推导出变量的类型，而 decltype 根据 exp 表达式推导出变量的类型，跟=右边的 value 没有关系。auto 要求变量必须初始化，而 decltype 不要求。这很容易理解，auto 是根据变量的初始值来推导出变量类型的，如果不初始化，变量的类型也就无法推导了。decltype 可以写成下面的形式：

```c++
decltype(exp) varname;
```

根据exp表达式进行推导。

### 推导例子

```c++
int a = 0;
decltype(a) b = 1;  //b 被推导成了 int
decltype(10.8) x = 5.5;  //x 被推导成了 double
decltype(x + 100) y;  //y 被推导成了 double
```

- 如果 exp 是一个不被括号( )包围的表达式，或者是一个类成员访问表达式，或者是一个单独的变量，那么 decltype(exp) 的类型就和 exp 一致，这是最普遍最常见的情况。
- 如果 exp 是函数调用，那么 decltype(exp) 的类型就和函数返回值的类型一致。
- 如果 exp 是一个左值，或者被括号( )包围，那么 decltype(exp) 的类型就是 exp 的引用；假设 exp 的类型为 T，那么 decltype(exp) 的类型就是 T&。

```c++
#include <typeinfo>
#include <iostream>
using namespace std;
template<typename T1, typename T2>
void Sum(T1& t1, T2& t2, decltype(t1 + t2)& s)
{
	s = t1 + t2;
}
int main()
{
	int a = 34;
	long int b = 5;
	float c = 1.0f;
	float d = 2.3f;
	long int e = 0;
	float f = 0;

	Sum(a, b, e);
}
```

`decltype(t1 + t2)& s`是C++中的一个声明语句，表示声明一个引用类型的变量`s`，该变量的类型是`decltype(t1 + t2)`的结果类型。`decltype`是一个C++关键字，它返回表达式的类型。

在这个例子中，`t1`和`t2`是函数的输入参数，它们的类型分别是`T1`和`T2`。表达式`t1 + t2`的结果类型是`T1`和`T2`的和的类型。通过使用`decltype`，我们可以获取该结果类型的引用，并将其赋给变量`s`。

在函数`Sum(T1& t1, T2& t2, decltype(t1 + t2)& s)`中，函数将计算`t1`和`t2`的和，并将结果存储在变量`s`中。由于`s`是引用类型，函数将直接修改其对应的变量的值。

在主函数中，变量`e`被传递给函数`Sum(a, b, e)`。由于`Sum`函数的模板参数类型是`long int`，因此表达式`a + b`的结果类型也是`long int`。因此，将结果赋给变量`e`是合法的，因为它们具有相同的类型。

对于数组版本的函数`Sum(int a[], int b[], int c[])`，它没有使用模板参数，因此它只能处理整数数组。在主函数中，变量`arr1`, `arr2`, 和 `arr3`都是整数数组，因此它们可以被传递给这个函数。