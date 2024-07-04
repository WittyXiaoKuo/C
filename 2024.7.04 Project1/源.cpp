int main()
{
	//权限的方法
	// m只能读
	// n变成我的别名,可读可写,权限的放大,不可以
	//const int m = 0;
	////int& n = m;
	

	//权限的平移,可以
	//const int m = 0;
	//const int& n = m;


	////权限的平移,可以
	int q5 = 0;
	int& p5 = q5;


	//权限的缩小,可以
	int a = 0;//可读可写
	const int& b = a;//可读


	//权限缩小
	int q = 0;//可读可写
	int& p = q;//可读可写
	const int& w = p;//只是不能通过w去修改(可读)
	p++;


	// p1可以修改 *p1不可以，const修饰是的*p1
	const int m = 0;//可读
	const int* p1 = &m;//可读
	p1++;
	// 权限的放大
	//int* p2 = p1;//可读可写
	//权限的平移
	const int* p2 = p1;
	p2++;

	// 权限的缩小
	int x = 0;//可读可写
	int* p3 = &x;//可读可写
	const int* p4 = p3;//可读

	return 0;	
}
