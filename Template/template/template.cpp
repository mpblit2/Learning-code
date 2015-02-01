#include <iostream>

using std::cout;
using std::endl;

template<typename T>
T squre(T x)
{
	return x*x;
}

template<typename T>
T add(T x)
{
	return a+a;
}
//int squre(int x)
//{
//	return x*x;
//}

int main(void)
{
	cout << squre<double>(5.5) << endl;
	cout << squre<int>(5) << endl;
	getchar();
	return 0;
}