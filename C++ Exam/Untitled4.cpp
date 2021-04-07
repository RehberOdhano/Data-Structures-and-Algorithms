#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()

{

	vector<int> data(5,1);

	int sum {0};

	cout << sum << endl;

	for(int i = 0; i < data.size(); i++)
	{
		sum += data[i];
	}
	cout << sum << endl;
	
	vector<int>::iterator it;
	for(it = ++data.begin(); it != --data.end(); ++it)
	{
		sum += *it;
	}
	cout << sum << endl;

	sum = 0;

	data.push_back(2);

	data.push_back(3);

	for(int j = 0; j < data.size(); j++)
	{
		sum += data[j];
	}
	cout << sum << endl;

	cout << accumulate(data.begin(), data.end(), data[0]) << endl;

}
