
>  … 表示多个，此处 const Type&… args 表示任意类型的任意数量参数

```c++ 
// print()作为边界条件处理
void print()
{
}
  
template<typename T, typename... Types>
void print(const T& firstArg, const Type&... args)
{
	std::cout << firstArg << std::endl;
	print(args...);
}

```

```c++
// TEST
print(7.5, "hello", bitset<6>(377), 42);
```
