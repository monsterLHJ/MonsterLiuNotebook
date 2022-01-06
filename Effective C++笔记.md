[toc]

# 1 让自己习惯C++(Accustoming Yourself to C++)

## 条款01： 视C++为一个语言联邦(View C++ as a federation of languages)

C++并不是一个带有一组守则的一体语言，它是从四个次语言组成的联邦政府，每个次语言都有自己的规约。

- C，C++以C为基础
- Object-Oriented C++，面向对象设计之古典守则在C++上的最直接实施。
- Template C++，泛型编程。
- STL，template 程序库。

C++高效编程守则视情况而变化，取决于使用C++的哪一部分。

## 条款02：尽量以` const, enum, inline`替换` #define`(Prefer `consts, enums`, and` inlines` to `#defines`)

- 对于单纯变量，最好以`const`对象或`enums`替换`#defines`
- 对于形似函数的宏(macros)，最好改用`inline`函数替换`#defines`。

## 条款03：尽可能使用`const`(Use `const` whenever possible)

```c++
char greeting[] = "Hello";
char* p = greeting;				// non-const pointer, non-const data
const char* p = greeting;		// non-const pointer, const data
char* const p = greeting;		// const pointer, non-const data
const char* const p = greeting;	// const pointer, const data
```

如果关键字`const`出现在星号左边，表示被指物是常量；如果出现在型号右边，表示指针自身是常量；如果出现在星号两边，表示被指物和指针两者都是常量。

- 将某些东西声明为`const`可帮助编译器侦测出错误用法。`const`可被施加于任何作用域内的对象、函数参数、函数返回类型、成员函数本体。
- 编译器强制实施bitwise constness​，但你编写程序时应该使用“概念上的常量性"(conceptual constness)。mutable释放掉      `non-static`成员变量的bitwise constness。
- 当`const`和`non-const`成员函数有着实质等价的实现时，令`non-const`版本调用`const`版本可避免代码重复。

## 条款04：确定对象被使用前已先被初始化(Make sure that objects are initialized before they're used)

- 为内置型对象进行手工初始化，因为C++不保证初始化它们。

- 构造函数最好使用成员初值列表(member initialization list)，而不要在构造函数本体内使用赋值操作(assignment)。初值列表列出的成员变量，其排列次序应该和它们在class中的声明次序相同。

- 为免除”跨编译单元之初始化次序“问题，请以 local static 对象替换 non-local static对象。**reference-returning函数**

  ```c++
  class FileSystem {...};
  FileSystem& FileSystem::tfs()
  {
      static FileSystem fs;
      return fs;
  }
  
  class Directory {...};
  Directory::Directory( params )
  {
      ...
      std::size_t disks = tfs().numDisks();	//使用tfs()而不是tfs.
      ...
  }
  ```

# 2 构造/析构/赋值运算(Constructors, Destructors, and Assignment Operators)

## 条款05：了解C++默默编写并调用哪些函数(Know what functions C++ silently writes and calls)

编译器可以暗自为class创建default构造函数、copy构造函数、copy assignment操作符，以及析构函数。

**注意：一般而言只有当生出的代码合法且有适当机会证明它有意义，编译器才会生成copy assignment操作符。万一两个条件有一个不符合，编译器会拒绝为class生出operator=。**

## 条款06：若不想使用编译器自动生成的函数，就该明确拒绝(Explicitly disallow the use of compiler-generated functions you do not want)

为驳回编译器自动（暗自）提供的机能，可将相应的成员函数声明为private并且不予实现。使用像Uncopyable这样的base class也是一种做法。

```c++
class Uncopyable{
protected:
    Uncopyable() {}
    ~Uncopyable() {}
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
}

//为求阻止HomeForSale对象被拷贝，我们唯一需要做的就是继承Uncopyable;
class HomeForSale: private Uncopyable {
    ...
}
```

## 条款07： 为多态基类声明virtual析构函数(Declare destructors virtual in polymorphic base classes)

- polymorphic (带多态性质的) base classes应该声明一个virtual析构函数。如果class带有任何virtual函数，它就应该用有一个virtual析构函数。
- Classes 的设计目的如果不是作为base classes 使用，或不是为了具备多态性(polymorphicallly) ，就不该声明virtual析构函数。

## 条款8：别让异常逃离析构函数(Prevent exceptions from leaving destructors)

- 析构函数绝对不要吐出异常。如果一个被析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下它们（不传播）或结束程序。
- 如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class应该提供一个普通函数（而非在析构函数中）执行该操作。

## 条款9：绝不在构造和析构过程中调用virtual函数(Never call virtual functions during construction or destruction)

- 在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class（比起当前执行构造函数和析构函数的那层）

## 条款10：令operator= 返回一个reference to *this(Have assignment operators return a reference to *this)

- 令赋值(assignment)操作符返回一个`reference to *this`。

## 条款11：在operator=中处理“自我赋值”(Handle assignment to self in operator=)

- 确保当对象自我赋值时operator=有良好行为。其中技术包括比较“来源对象”和“目标对象”的地址、精心周到的语句顺序、以及copy-and-swap。
- 确定任何函数如果操作一个一上的对象，而其中多个对象是同一个对象时，其行为仍然正确。

## 条款12：复制对象时勿忘其每一个成分(Copy all parts of an object)

- Copying函数应该确保复制"**对象内的所有成员变量**"及“所有base class成分”。
- 不要尝试以某个copying函数实现另一个copying函数。应该将共同机能放进第三个函数中，并由两个copying函数共同调用。

# 3 资源管理(Resource Management)

## 条款13： 以对象管理资源(Use objects to manage resources)

