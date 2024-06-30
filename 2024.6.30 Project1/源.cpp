#include<stdio.h>
#include<stdlib.h>
namespace bit//自定义命名空间
{
	int rand = 0;
}
//域作用限定符"::"前面为空默认全局域

//// 展开命名空间 (一般不展开)
////using namespace bit;
// // 编译默认查找顺序
// // a、当前局部域				： 自留地
// // b、全局域找				： 村子野地
// // c、到展开的命名空间中查找  ： 相当于张大爷在自己的自留地加了声明，谁需要就来摘
int main()
{
	int rand = 1;
	printf("%d\n", rand);//局部域
	printf("%d\n", bit::rand);//自定义域
	printf("%p\n", ::rand);//全局域
	return 0;
}