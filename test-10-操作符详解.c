#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//P71-

//操作符

//本章重点
//1、各种操作符的介绍
//2、表达式求值

//操作符
//分类：
// 算数操作符
// 移位操作符
// 位操作符
// 赋值操作符
// 单目操作符
// 关系操作符
// 逻辑操作符
// 条件操作符
// 逗号操作符
// 下标引用、函数调用操作符


// 算数操作符
//int main()
//{
//	int a = 6 / 5;					//结果是1
//	printf("%d\n", a);
//
//	float b = 6 / 5;				//要用%f    结果依然是1
//	printf("%f\n", b);
//
//	float c = 6 / 5.0;				//除号两边只要有一个是小数，得出商就是小数形式
//	printf("%f\n", c);
//
//	//取模
//	int d = 7 % 3;					//%取模两边必须为整数
//	printf("%d\n", d);
//	return 0;
//}



// 移位操作符
//左移操作符：左边丢弃，右边补零
//右移操作符：1、算数右移：右边丢弃，左边补原符号位
//			  2、逻辑右移：右边丢弃，左边补0
//数据存放在内存中。整数的二进制表示形式：其实有三种
//原码：直接根据数值写出的二进制序列就是原码
//反码：原码的符号位不变，其他位按位取反就是反码
//补码：反码+1，就是补码
//int main()
//{
//	//左移
//	int a = 2;
//	//a= 00000000 00000000 00000000 00000010
//	int b = a << 1;					//  <<  左移操作符
//	//把a的二进制位向左移动一位
//	//a= 00000000 00000000 00000000 00000100
//	printf("%d左移一位是%d\n", a,b);
//
//	//右移 - 正数
//	int c = 10;
//	//a= 00000000 00000000 00000000 00001010
//	int d = c >> 1;
//	//把c的二进制位向右移动一位
//	//a= 00000000 00000000 00000000 00000101
//	printf("%d右移一位是%d\n",c, d);
//
//	//右移 - 负数
//	int e = -1;
//	//原码e= 10000000 00000000 00000000 00000001
//	//反码	 11111111 11111111 11111111 11111110
//	//补码	 11111111 11111111 11111111 11111111
//	int f = e >> 1;
//	
//
//	printf("%d右移一位是%d\n", e, f);					//结果还是为 -1
//	//说明当前的右移运算采用：算数右移
//	return 0;
//}
//移位操作符不会改变原数据，而会产生新的数据，存到新变量里面



//位操作符

//int main()
//{
	//& - 按（二进制）位与
	/*int a = 3;
	int b = 5;
	int c = a & 5;					//如果有0，则为0。都是1才是1。
	printf("%d", c);*/
	//a = 00000000000000000000000000000011
	//b = 00000000000000000000000000000101
	//c = 00000000000000000000000000000001
	
	//对于正数：原码、反码、补码都相同
	//对于负数：原码、反码、补码不相同。反码是原码的按位取反，补码是反码的+1


	//| - 按（二进制）位或
	//int a = 3;
	//int b = 5;
	//int c = a | b;					//如果有1，则为1。都是0才是0。
	//printf("%d", c);
	//a = 00000000000000000000000000000011
	//b = 00000000000000000000000000000101
	//c = 00000000000000000000000000000111


	//^ - 按（二进制）位异或
	//对应的二进制位进行异或
	//int a = 3;
	//int b = 5;
	//int c = a ^ b;						//如果不同为1，如果相同则为0。
	//printf("%d", c);
	//a = 00000000000000000000000000000011
	//b = 00000000000000000000000000000101
	//c = 00000000000000000000000000000110

	//操作数必须为整数


//	return 0;
//}



//作业：交换两个变量，不能使用第三个变量
//int main()
//{
//	//方法1
//	int a = 3;			//a = 00000000000000000000000000000011
//	int b = 5;			//b = 00000000000000000000000000000101
//	printf("a=%d  b=%d\n", a, b);
//	a = a + b;
//	b = a - b;			//和 - 去原来的b，等于原来的a，赋值给原来的b
//	a = a - b;			//和 - 去原来的a，等于原来的b，赋值给原来的a
//	printf("a=%d  b=%d\n", a, b);
//	//实现了不创建变量交换数值
//	//缺点：如果a和b太大，a = a + b可能会导致溢出，从而导致出错
//
//	//方法2
//	a = 3;				//a = 00000000000000000000000000000011
//	b = 5;				//b = 00000000000000000000000000000101
//	printf("a=%d  b=%d\n", a, b);
//	a = a ^ b;			//a = 00000000000000000000000000000110
//	b = a ^ b;			//b = 00000000000000000000000000000011		3
//	a = a ^ b;			//a=  00000000000000000000000000000101		5
//	printf("a=%d  b=%d\n", a, b);
//	//实现了交换，还不会溢出
//
//	return 0; 
//}

//任何两个相同的数字异或之后都是0		a^a=0
//任何数和 0 异或都是他自己				a^0=a
//所以 a ^ b ^ b = a ^ 0 = a


//作业：求一个整数存储在内存中的二进制中1的个数
//int main()
//{
//	int a = 13;
//	// 00000000000000000000000000001101
//	// 00000000000000000000000000000001
//	// 00000000000000000000000000000001
//	// &  >>		按位与，再右移
//	//运算的时候，符号位也会运算
//	return 0;
//}


//作业：将某一位变成1
//int main()
//{
//	int a = 13;
//	// 00000000000000000000000000001101
//	// 00000000000000000000000000010000				将第五位或1
//	// 00000000000000000000000000011101
//	// 1<<4		把 1 向左移动四位
//	a = a | (1 << 4);
//	printf("%d", a);
//
//	return 0;
//}




//赋值操作符
//赋值操作符是一个很棒的操作符，它可以让你得到一个你之前不满意的值。也就是你可以给自己重新赋值

//int main()
//{
//	int weight = 120;		//体重
//	weight = 89;			//不满意就赋值
//	double salary = 10000.0;
//	salary = 20000.0;		//使用赋值操作符赋值
//
//	//赋值操作符可以连续使用
//	int a = 10;
//	int x = 0;
//	int y = 20;
//	a = x = y + 1;			//连续赋值
//
//	//相当于
//	x = y + 1;
//	a = x;
//	//这种写法更加清晰而且易于调试
//
//	//复合赋值
//	a = 100;
//	a = a + 100;
//	a += 100;				//和上一句实现功能一样
//	a = a >> 3;
//	a >>= 3;				//和上一句实现功能一样
//
//	return 0;
//}
//	=	赋值
//	=	判断



//单目操作符			！	-	+	&	sizeof	~	--	++	*	（类型）
//！
//int main()
//{
//	int flag = 0;
//	//flag为真，打印hehe
//	if (flag)
//	{
//		printf("hehe\n");
//	}
//	//flag为假打印哈哈
//	if (!flag)
//	{
//		printf("haha\n");
//	}
//
//	printf("%d\n", !flag);			//如果flag为真，！flag的打印结果为0；如果flag为假，！flag的打印结果为1。
//	return 0;
//}

//int main ()
//{
//	int a = 10;
//	a = -a;
//	printf("%d\n", a);
//	return 0;
//}

//sizeof		计算和统计操作符长度（以字节为单位）
//int main()
//{
//	int a = 10;
//	
//	printf("%d\n", sizeof(a));			//计算a所占空间的大小，单位是字节		4
//	printf("%d\n", sizeof(int));		//a的类型是int，因此计算int的空间长度也是一样的
//	printf("%d\n", sizeof a );			//sizeof计算变量大小的时候，可以把两端的括号给省略掉，因此sizeof是操作符，不是函数
//	//int括号不能省略
//
//	char arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));		//计算arr所占空间的大小，单位是字节		10
//	int arr1[10] = { 0 };
//	printf("%d\n", sizeof(arr1));		//计算arr所占空间的大小，单位是字节		40
//
//	short s = 5;
//	int b = 10;
//	printf("%d\n", sizeof(s = b + 2));	//s = b + 2算都没有算，根据s的类型直接赋值了
//	printf("%d\n", s);
//	return 0;
//}

// ~ 对一个数的二进制位按位取反
//int main()
//{
//	int a = -1;
//	// 10000000 00000000 00000000 00000001	- 原码
//	// 11111111 11111111 11111111 11111110  - 反码
//	// 11111111 11111111 11111111 11111111  - 补码
//
//	// ~ 按位取反
//	// 11111111 11111111 11111111 11111111
//	// 00000000 00000000 00000000 00000000
//
//	int b = ~a;
//	printf("%d\n", a);			// -1 
//	printf("%d\n", b);			// 0 
//	return 0;
//}

// a++ 后置++，先使用，再++
//int main()
//{
//	int a = 10;
//	int b = a++;				//后置++，先使用，再++
//
//	printf("%d\n", a);			//11
//	printf("%d\n", b);			//10
//
//	int c = 10;
//	int d = ++c;				//前置++，先++，后使用
//	printf("%d\n", c);			//11
//	printf("%d\n", c);			//11
//
//	int e = 10;
//	printf("%d\n", e--);		//后置--，先使用，再减减
//	printf("%d\n", e);			//
//}

// & - 取地址操作符
//int main()
//{
//	int a = 10;
//	printf("%p\n", &a);			// & -取地址操作符
//	int*pa = &a;				//pa是用来存放地址的 - pa就是一个指针变量
//	*pa = 20;					// * - 解引用操作符 - 间接访问操作符
//	printf("%d\n", a);
//	return 0;
//}

//（强制类型转换操作符）
//int main()
//{
//	int a = (int)3.14;
//	printf("%d\n", a);
//	return 0;
//}

//sizeof和数组
//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));		//40
//	printf("%d\n", sizeof(ch));			//10
//	test1(arr);							//8
//	test2(ch);							//8
//	//test1和test2接收的是首地址，地址在32位是4字节，在64位机器上是8字节
//	return 0;
//}


//关系操作符
//int main()
//{
//	int a = 3;
//	int b = 5;
//	//if (a == b)
//	//if(a ! b)
//	//if(a > b)
//	//if(a < b)
//	if (a <= b)
//	{
//
//	}
//	return 0;
//}
//= 赋值，==判断相等
//比较两个字符串相等，不能使用==


//逻辑操作符
// && 逻辑与		|| 逻辑或
//逻辑与只看真假
//int main()
//{
//	int a = 3;
//	int b = 0;
//	if (a && b)							//只要有一个为假就是假
//	{
//		printf("hehe!");
//	}
//	if (a || b)							//只要有一个为真就是真
//	{
//		printf("haha!");
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i=a++ && ++b && d++;					//a&&b表达式，a为假，&&后面的表达式就不需要计算
//	printf("a=%d\nb=%d\nc=%d\nd=%d\ni=%d\n", a, b, c, d,i);
//	//后置++，先使用后++，&&前面的a++先当0使用，判断为0，后面表达式不进行计算，
//	i = a++ || ++b || d++;					//a||b表达式，a为真，||后面的表达式就不需要计算
//	printf("a=%d\nb=%d\nc=%d\nd=%d\ni=%d\n", a, b, c, d, i);
//	return 0;
//}



//条件操作符	三目操作符
//exp1 ? exp 2 : exp 3
//int main()
//{
//	int a = 3;
//	int b = 0;
//	if (a > 5)
//	{
//		b = 1;
//	}
//	else
//	{
//		b = -1;
//	}
//	printf("b=%d\n", b);
//
//	//三目操作符
//	b = (a > 5 ? 1 : -1);
//	printf("b=%d\n", b);
//	return 0;
//}


//逗号表达式
//exp1，exp2,exp3,... ...expN
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	//逗号表达式 - 要从左向右依次计算，但是整个表达式的结果是最后一个表达式的结果
//	int d = (c = 5, a = c + 3, b = a - 4, c += 5);
//	printf("d=%d\n", d);
//	return 0;
//}



//下标引用操作符
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//              0 1 2 3 4 5 6 7 8 9
//	printf("%d\n", arr[4]);					// [] - 就是下标引用操作符
//	// [] 的操作数是2个：arr ， 4
//	return 0;
//}


//函数调用操作符
//函数的定义
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 20;
//	int b = 10;
//	//函数的调用
//	int ret=Add(a, b);			//（） - 函数调用操作符，不可去掉
//
//	return 0;
//}




//访问一个结构的成员
//	.结构体.成员名
//	->结构体指针->成员名
// int float char short double long 
// 书：书名，书号，出版社，作者，定价
// 人：名字，年龄，性别

//创建了一个自定义的类型
//struct Book
//{
//	char name[20];
//	char id[20];
//	int price;
//};
//int main()
//{   //结构体变量名.成员名
//	struct Book b = {"C语言","20230412",154};
//	printf("书名：%s\n", b.name);
//	printf("书号：%s\n", b.id);
//	printf("价格：%d\n", b.price);
//
//
//	struct Book * pb = &b;
//	printf("书名：%s\n", (*pb).name);
//	printf("书号：%s\n", (*pb).id);
//	printf("价格：%d\n", (*pb).price);
//	//结构体指针->成员名
//	printf("书名：%s\n", pb->name);
//	printf("书号：%s\n", pb->id);
//	printf("价格：%d\n", pb->price);
//	return 0;
//}


//表达式求值
//表达式的求值顺序一部分是由操作符的优先级和结合性决定
//同样，有些表达式的操作数在求值的过程中可能需要转换为其他类型

//隐式类型转换
//C的整型算术运算总是以缺省整型类型的精度来进行的
//为了获得这个精度，表达式中的字符和短整型操作数在使用之前被转换为普通整型，这种转换成为 整型提升

//整型提升的意义
//表达式的整型运算要在CPU的相应运算器件内执行，CPU内整形运算器（ALU）的操作数的字节长度一般就是int的字节长度，
//同时也是CPU的通用寄存器的长度。因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整形操作数的标准长度。
//通用CPU是难以直接实现两个8比特字节直接相加运算（虽然机器指令中可能有这种字节相加指令）。
//所以，表达式中各种长度可能小于int长度的整型值，都必须先转换为int或unsigned int，然后才能送入CPU去执行运算。
//int main()
//{
//	char a = 3;
//	// 00000000 00000000 00000000 00000011
//	// 00000011
//	//整型提升是按照变量的数据类型的符号位来提升
//	char b = 127;
//	// 00000000 00000000 00000000 01111111
//	// 01111111  
//	char c = a + b;
//	//a	00000000 00000000 00000000 00000011			整型提升是按照变量的数据类型的符号位来提升
//	//b 00000000 00000000 00000000 01111111
//	//  00000000 00000000 00000000 10000010
//	//  10000010		截断
//	//  11111111 11111111 11111111 10000010			补码
//	//  11111111 11111111 11111111 10000001			反码
//	//  10000000 00000000 00000000 01111101			原码
//	printf("%d\n", c);			//-126
//	//发现a和b都是char类型的，都没有达到int的大小
//	//这里就会发生整型提升
//	return 0;
//}
//负数的整型提升	高位补1
//正数的整型提升	高位补0
//无符号位整型提升	高位补0


//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//
//	if (a == 0xb6)				//发生了整型提升
//		printf("a");
//	if (b == 0xb600)			//发生了整型提升
//		printf("b");
//	if (c = 0xb6000000)
//		printf("c");
//	return 0;
//}

//int main()
//{
//	char c = 1;
//	printf("%u\n", sizeof(c));			//1		%u，打印一个无符号数
//	printf("%u\n", sizeof(+c));			//4		整型提升
//	printf("%u\n", sizeof(-c));			//4
//	printf("%u\n", sizeof(!c));			//4		vs环境下测试结果是1，但是在gcc环境下测试结果为4，
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 5;
//	short s = 5;
//	sizeof(s = a + 3);
//	a + b;								//值属性，类型属性
//	return 0;
//}


//算数转换
//如果某个操作符的各个操作数属于不同的类型，那么除非其中一个操作数转换为另一个操作数的类型，否则操作就无法进行。
//向精度更高的转换


//操作符的属性
//复杂表达式的求值有三个影响因素
//1.操作符的优先级
//2.操作符的结合性
//3.是否控制求值顺序
//优先级决定了计算顺序
//int main()
//{
//	//int a, b, c, d, e, f;
//	//表达式1
//	//a* b + c * d + e * f;
//	//代码1在计算的时候，由于*比+优先级更高，只能保证*的计算比+早，但是优先级并不能决定第三个*比第一个+早执行
//
//	//表达式2
//	int c = 0;
//	c + --c;
//	//操作符的优先级只能觉得自减--的运算在+的运算的前面，
//	//但是我们并没有办法得知+操作符的左操作数的获取在右操作数之前还是之后求值，所以结果不可预测，是有歧义的
//
//	//代码3 - 非法表达式
//	int i = 10;
//	i = i-- - --i * (i = -3) * i++ + ++i;
//	printf("i=%d\n", i);
//	//c和指针			这段代码在不同编译器里的结果不同
//	return 0;
//}

//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//int main()
//{
//	int answer;
//	answer = fun() - fun() * fun();			//2-3*4=-10
//	//问题代码
//	printf("%d\n", answer);
//	return 0;
//}

//总结：我们写出的表达式如果不能通过操作符的属性确定唯一的计算路径，那这个表达式就是存在问题的


//int main()
//{
//	int arr[] = { 1,2,(3,4),5 };			//逗号表达式从左向右计算，返回右边的值，这个表达式相当于{1，2，4，5}
//	printf("%d\n", sizeof(arr));
//	return 0;
//}

//int main()
//{
//	char str[] = "hello world";
//	//hello world\0
//	printf("%d %d\n", sizeof(str), strlen(str));		//12 11
//	//strlen - 函数 - 求字符串长度		找、0之前的出现的字符个数
//	//sizeof - 操作符 - 计算变量/类型所占内存
//
//	char acX[] = "abcdefg";								//abcdefg\0
//	char acY[] = { 'a','b','c','d','e','f','g' };		//abcdefg
//	return 0;
//}

//实现函数init（）初始化数组全为0
//实现print（）打印数组的每个元素
//实现reverse（）函数完成元素的逆置
//void init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] =  0 ;
//	}
//}
//void print1(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while(left<right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print1(arr, sz);
//
//	reverse(arr, sz);
//
//	print1(arr, sz);
//
//	init(arr,sz);
//
//	print1(arr, sz);
//
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,10 };
//
//	/*int arr3[5] = { 0 };
//	arr3 = arr2;					//这种写法是错误的，因为数组名是地址，不是变量
//	arr2 = arr1;
//	arr1 = arr3;*/
//
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		int a = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = a;
//	}
//
//	return 0;
//}