# Dashark_class_cpp_homework
胡大裟班cpp作业

1：soj上4个题，分别命名为cpp1-a.cxx、cpp1-b.cxx、cpp1-c.cxx、cpp2-a.cxx

2：超级素数SuperPrime.cxx。找到100-1000的超级素数仅有113、131、311，找到1000-10000的超级素数仅有2111。该代码首先初始化素数表，运用“欧拉筛”求素数。之后的流程十分自然，不赘述。只需static const int SZ = 10000;改数字为更大的，即可求出更大范围的超级素数。

3：Table1.cxx实现电子表格。我将电子表格一个格子的初始值设为字符串"null"。实现格子兼容多种类型的输入并转化为string，我认为最合理的方案是函数重载。std::to_string()方法需要c++11标准。
