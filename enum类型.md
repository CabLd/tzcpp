## enum类型

在C++中，枚举（enum）是一种用户自定义的数据类型，它包含了一组整数值的命名常量。使用enum类型可以提高代码的可读性和可维护性。

下面是一个简单的C++枚举类型的示例：

```cpp
enum Color {  
    RED,  
    GREEN,  
    BLUE  
};
```

这个枚举定义了一个名为 `Color` 的类型，它包含了三个整数值 `RED`、`GREEN` 和 `BLUE`。你可以使用 `Color` 类型的变量来表示颜色，例如：

```cpp
cpp复制代码

Color c = RED;
```

你还可以使用枚举值进行比较和算术运算，例如：

```cpp
Color c1 = RED;  
Color c2 = GREEN;  
if (c1 == c2) {  
    cout << "c1 and c2 are the same color" << endl;  
} else {  
    cout << "c1 and c2 are different colors" << endl;  
}
```

输出结果为：`c1 and c2 are different colors`。

你还可以使用枚举值作为数组的索引，例如：

```cpp
int arr[3];  
arr[RED] = 10;  
arr[GREEN] = 20;  
arr[BLUE] = 30;  
cout << arr[RED] << endl;  // 输出 10  
cout << arr[GREEN] << endl;  // 输出 20  
cout << arr[BLUE] << endl;  // 输出 30
```

输出结果为：`10`、`20` 和 `30`。