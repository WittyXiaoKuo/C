void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;
}

int main()
{
	f(0);
	f(NULL);//->��ͬ��f(0)
	f((int*)NULL);
	f(nullptr);//->��ͬ��f((int*)NULL)

	return 0;
}