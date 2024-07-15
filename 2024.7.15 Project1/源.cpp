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
	f(NULL);//->等同于f(0)
	f((int*)NULL);
	f(nullptr);//->等同于f((int*)NULL)

	return 0;
}