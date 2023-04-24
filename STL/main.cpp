#include<iostream>
#include<array>
#include<vector>
using namespace std;


#define tab "\t"
//#define STL_ARRAY
#define STL_VECTOR


void main()
{
#ifdef STL_ARRAY

	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
#endif


#ifdef STL_VECTOR



#endif
}