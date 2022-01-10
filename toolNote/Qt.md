## 1、Qt信号槽机制的优势

（1）类型安全。需要关联的信号和槽的签名必须是等同的，即信号的参数类型和参数个数同接收该信号的槽的参数类型和参数个数相同。不过，一个槽的参数个数是可以少于信号的参数个数的，但缺少的参数必须是信号参数的最后一个或几个参数。如果信号和槽的签名不符，编译器就会报错。
（2）松散耦合。信号和槽机制减弱了Qt对象的耦合度。激发信号的Qt对象无需知道是哪个对象的哪个槽需要接收它发出的信号，它只需在适当的时间发送适当的信号就可以了，而不需要知道也不关心它的信号有没有被接收到，更不需要知道是哪个对象的哪个槽收到了信号。同样的，对象的槽也不知道是哪些信号关联了自己，而一旦关联信号和槽，Qt就保证了适合的槽得到了调用。即使关联的对象在运行时被删除，应用程序也不会崩溃。
（3）信号和槽机制增强了对象间通信的灵活性。一个信号可以关联多个槽，也可以多个信号关联一个槽。

## 2、Qt信号槽机制的不足

同回调函数相比，信号和槽机制运行速度有些慢。通过传递一个信号来调用槽函数将会比直接调用非虚函数运行速度慢10倍。原因如下：
（1）需要定位接收信号的对象；
（2）安全地遍历所有的关联（如一个信号关联多个槽的情况）；
（3）编组/解组传递的参数；
（4）多线程的时候，信号可能需要排队等待。
然而，与创建对象的new操作及删除对象的delete操作相比，信号和槽的运行代价只是他们很少的一部分。信号和槽机制导致的这点性能损耗，对实时应用程序是可以忽略的。

## 3、 描述过程, 如何实现一个自定义按钮, 使其在光标进入,按下,离开三种状态下显示不同的图片. 

创建一个类, 让其从QPushButton类派生, 重写该类中的事件处理器函数 

方法1：
1>. enterEvent() – 光标进入 
2>. leaveEvent() – 光标离开 
3>. mousePressEvent() – 鼠标按下 
4>. paintEvent() – 刷新背景图 

方法二：

通过setstylesheet设置

## 4. Qt信号和槽的本质是什么

回调函数

## 5、描述QT中的文件流(QTextStream)和数据流(QDataStream)的区别, 他们都能帮助我们完成一些什么事情. 

QTextStream – 文本流, 操作轻量级数据(int, double, QString), 数据写入文件中之后以文本的方式呈现。 
QDataStream – 数据流, 通过数据流可以操作各种数据类型, 包括类对象, 存储到文件中数据可以还原到内存（二进制）。 
QTextStream, QDataStream可以操作磁盘文件, 也可以操作内存数据, 通过流对象可以将数据打包到内存, 进行数据的传输.

## 6、描述Qt下Tcp通信的整个流程 

服务器端: 

1. 创建用于监听的套接字 
2. 给套接字设置监听 
3. 如果有连接到来, 监听的套接字会发出信号newConnected 
4. 接收连接, 通过nextPendingConnection()函数, 返回一个QTcpSocket类型的套接字对象(用于通信) 
5. 使用用于通信的套接字对象通信 
   1>. 发送数据: write 
   2>. 接收数据: readAll/read 

客户端: 

1. 创建用于通信的套接字 
2. 连接服务器: connectToHost 
3. 连接成功与服务器通信 
   1>. 发送数据: write 
   2>. 接收数据: readAll/read

## 7、 描述QT下udp通信的整个流程 

QT下udp通信服务器端和客户端的关系是对等的, 做的处理也是一样的. 

1. 创建套接字对象 
2. 如果需要接收数据, 必须绑定端口 
3. 发送数据: writeDatagram 
4. 接收数据: readDatagram 

## 8、 描述QT下多线程的两种使用方法, 以及注意事项

方法-：

\1. 创建一个类从QThread类派生 
\2. 在子线程类中重写 run 函数, 将处理操作写入该函数中 
\3. 在主线程中创建子线程对象, 启动子线程, 调用start()函数 
方法二： 
\1. 将业务处理抽象成一个业务类, 在该类中创建一个业务处理函数 
\2. 在主线程中创建一QThread类对象 
\3. 在主线程中创建一个业务类对象 
\4. 将业务类对象移动到子线程中 
\5. 在主线程中启动子线程 
\6. 通过信号槽的方式, 执行业务类中的业务处理函数 

方法三：

QFuture<void> fut1 = QtConcurrent::run(processFun, command);

processFun为线程回调函数

多线程使用注意事项: 
\* 1. 业务对象, 构造的时候不能指定父对象 
\* 2. 子线程中不能处理ui窗口(ui相关的类) 
\* 3. 子线程中只能处理一些数据相关的操作, 不能涉及窗口

## 9、**多线程下，信号槽分别在什么线程中执行，如何控制**

可以通过connect的第五个参数进行控制信号槽执行时所在的线程

　　connect有几种连接方式，直接连接和队列连接、自动连接

　　直接连接：信号槽在信号发出者所在的线程中执行

　　队列连接：信号在信号发出者所在的线程中执行，槽函数在信号接收者所在的线程中执行

　　自动连接：多线程时为队列连接函数，单线程时为直接连接函数。

## 10、如何使用C++模拟Qt信号和槽

Qt的信号和槽原理就是回调函数。所以，我们需要保存对象绑定的回调函数

\1. 创建槽类Slot，该类的功能是保存对象和对象绑定的回调函数

template<class T>
class SlotBase
{
public:
   virtual void Exec(T param1) = 0;  //纯虚函数
   virtual ~SlotBase(){}
};


/*
\* func: 槽函数
\* parm:
\* return:
*/
template<class T, class T1>
class Slot : public SlotBase<T1>
{
public:

   /* 定义Slot的时候，获取槽函数信息 */
   Slot(T* pObj, void (T::*func)(T1))
   {
     m_pSlotBase = pObj;
     m_Func = func;
   }

   /* signal触发时，调用 */
   void Exec(T1 param1)
   {
     (m_pSlotBase->*m_Func)(param1);
   }

private:
   /* 槽函数信息 暂存 */
   T* m_pSlotBase;
   void (T::*m_Func)(T1);
};
 

\2. 创建signal类

重要阐述：

1.创建一个Signal 类，该类保主要是保存多个Slot对象，当一个信号发送时，会遍历这个表，对每一个slot绑定的回调函数进行调用。

2.重载运算符(), 遍历这个表，调用回调函数，即signal触发机制

3.写一个绑定函数Bind，用于将Slot对象添加到槽表中

template<class T1>
class Signal
{
public:

   /* 模板函数 -> Bind时获取槽函数指针 */
   template<class T>
   void Bind(T* pObj, void (T::*func)(T1))
   {
     m_pSlotSet.push_back(new Slot<T,T1>(pObj,func));
   }

   /* 重载操作符 -> signal触发机制 */
   void operator()(T1 param1)
   {
     for(int i=0;i<(int)m_pSlotSet.size();i++)
     {
       m_pSlotSet[i]->Exec(param1);
     }
   }

   ~Signal()
   {
     for(int i=0;i<(int)m_pSlotSet.size();i++)
     {
       delete m_pSlotSet[i];
     }
   }

private:
   vector<SlotBase<T1>*> m_pSlotSet; //这一句很重要，靠基类的指针来存储 信号槽指针
};

3.测试类

测试类包含多个signal 当调用接口就将调用signal的()函数，从而调用slot

class TestSignal
{
public:
   TestSignal()
   {
   }
   void setValue(int value)
   {
     emit ValueChanged(value);
   }

   void setfValue(int value)
   {
     emit ValueChanged_f(value);
   }

public slots:
   void FuncOfA(int parm)
   {
     printf("enter FuncOfA parm = %d\n", parm);
   }

   void FuncOfB(int parm)
   {
     printf("enter FuncOfB parm = %d\n", parm);
   }

signals:
   Signal<int> ValueChanged;
   Signal<float> ValueChanged_f;
};

4.定义一个链接函数
\#define Connect(sender, signal, receiver, method) ((sender)->signal.Bind(receiver, method))

## 11、QVariant使用

1、用户自定义需要先注册一个类型，即使用qRegisterMetaType，注册到QT的一个Vector中

2、QVariant里面会new一个用户自定义类型的内存，并调用拷贝构造函数，QVariant自身的赋值会使用共享内存管理

所以用户可以传入一个临时变量地址，如果用户传入的是一个指针，这个指针需要用户自己析构，改变这个指针的值，并不会改变QVariant，因为是两个不同的空间了

而如果QVariant a1=b1(b1是QVariant)，改变b1的值会改变a1的。因为这样用的是shared指针

初看2以为是对的，验证发现不准确，改变b1并没有改变a1的值，细看发现这里面有QT使用了个小技巧，要取b1的值然后改变时，会调用data函数

CVariantHelp* pBTemp =  reinterpret_cast<CVariantHelp*>(b1.data());
pBTemp->j_ = 99;

而data的实现会调用detach将shared分离

void* QVariant::data()
{
  detach();
  return const_cast<void *>(constData());
}

void QVariant::detach()
{
  if (!d.is_shared || d.data.shared->ref == 1)
    return;


  Private dd;
  dd.type = d.type;
  handler->construct(&dd, constData());
  if (!d.data.shared->ref.deref())
    handler->clear(&d);
  d.data.shared = dd.data.shared;
}