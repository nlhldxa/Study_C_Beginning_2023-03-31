#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//实用调试技巧
//1.什么是bug
//2.调试是什么？有多重要？
//3.debug和release的介绍
//4.windows环境调试介绍
//5.一些调试的实例
//6.如何写出（易于调试）的代码
//7.编程常见的错误


//Debug通常称为调试版本，它包含调试信息，并且不作任何优化，便于程序员调试程序
//Release称为发布版本，它往往是进行了各类优化，使得程序在代码大小和运行速度上都是最优的，以便用户很好地使用。
int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i + 1;
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}
//断点
//常用的几个快捷键
//F5	启动调试，经常用来直接调到下一个断点处
//F9	创建断点和取消断点。可以在程序任意位置设置断点。这样就可以使得程序在想要的位置随意停止执行，继而一步步执行下去。
//F10	逐过程，通常用来处理一个过程，一个过程可以是一次函数调用，或者是一条语句。
//F11	逐语句，就是每次都执行一条语句，但是这个快捷键可以使我们的执行逻辑进入函数内部（这是最常使用的）。
//CTRL + F5		开始执行不调试，如果你想让程序直接运行起来而不调试就可以直接使用。
//Fn -	辅助功能键