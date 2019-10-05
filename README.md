# vdebug
#### 开发记录
之前一直用的微软自家的windbg调试器，有些功能用的不大习惯，比如windbg的条件断点，语法畸形并且效率很低，于是就有了自己开发一个的念头，正好开发的过程中自己也学习调试方面的相关知识，于是就有了这个项目，然后业余时间做了很久，后来由于转android开发了，一直搁置，部分功能尚未完成，自己也没有很多时间开发，于是就想将这个项目开源，让大家一起来完善这个项目。欢迎调试大牛来帮忙完善这个调试器，新人也可以通过这个项目来学习调试的相关知识。

#### 功能介绍

```
vdebug是一个windows平台的调试器，主要特点(部分正在开发)如下：
1.绿色，小巧，不依赖额外的库
2.支持32/64位程序调试
3.支持分析dump内存影像文件
4.内置简洁易用的调试脚本,可以方便的写调试脚本
5.可以自行导入C语言格式的函数类型解析函数参数
6.漂亮的语法高亮控件

该调试器中用到的库有:
Scintilla 强大开源的语法高亮控件
capstone 反汇编引擎
sqlite3 文件数据库
jsoncpp json解析库
TitanEngine 调试脚本引擎
deelx 正则表达式引擎
感谢这些开源组件的作者!
```

主界面截图：
![输入图片说明](https://images.gitee.com/uploads/images/2019/1005/115408_46baa519_498054.png "111.png")
![输入图片说明](https://images.gitee.com/uploads/images/2019/1005/115433_27b265bf_498054.png "222.png")

#### 软件架构
```
├─ComLib     项目公共动态库，实现各个项目通用的功能。
├─dbg        调试器核心功能模块，实现调试器的核心功能
├─DbgCtrl    调试功能代理中间件，调试控制层和调试实现层的中间件
├─mq         消息中间件，用于不同的进程，不同的组件之间实时通讯
├─runner     功能启动器，用于通过服务启动调试器的各个组件来提升调试组件的权限
└─vdebug     调试器的控制层和展示层，用于数据展示以及与dbg进行调试交互
```

#### 接下来可能要做的功能

```
1.反汇编关联pdb符号。
2.内存搜索，内存读写断点等基本功能。
3.64位程序调试支持，dump分析支持。
4.丰富调试脚本引擎，加入更加丰富的内置函数。

```

#### 作者信息