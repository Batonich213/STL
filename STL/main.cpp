#include<iostream>
#include<array>
using namespace std;


#define tab "\t"
#define STL_ARRAY


void main()
{
#ifdef STL_ARRAY

	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
#endif
}