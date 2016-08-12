#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> VecT;
VecT input;
VecT flist;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		input.push_back(str);
	}
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		flist.push_back(str);
	}
	

	for (int i = 0; i < flist.size(); ++i)
	{
		size_t max = 0;
		for (int j = 0; j < input.size(); ++j)
		{
			size_t len = input[j].find(flist[i]);
			if (len > max) max = len;
		}
		cout << max << endl;
	}

    return 0;
}

