#include "vector.h"

int main()
{
	vector<int> v1{ 5 };
	vector<int> v = {1, 23, 3, 4, 5};
	
	for (size_t i = 0; i < v.getSize(); i++)
	{
		cout << v[i] << endl;
	}

	cout << endl;
	vector<int>::iterator it ;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	
		
	for (auto el : v)
	{
		cout << el << endl;
	}

	auto it = find(v.begin(), v.end(), 3);
	cout << *it << endl;

}

