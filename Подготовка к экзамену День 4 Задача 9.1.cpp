#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

vector<int> merge(vector<int> a, vector<int>b)
{
	vector<int> sort;
	int i = 0;
	int j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i] < b[j])
		{
			sort.push_back(a[i]);
			i++;
		}
		else
		{
			sort.push_back(b[j]);
			j++;
		}
	}
	while (i < a.size())
	{
		sort.push_back(a[i]);
		i++;
	}
	while (j < b.size())
	{
		sort.push_back(b[j]);
		j++;
	}
	return sort;
}

vector<int> sortsl(vector<int> a)
{
	if (a.size() <= 1) return a;
	int mid = a.size() / 2;
	vector<int> l(a.begin(), a.begin() + mid);
	vector<int> r(a.begin() + mid, a.end());
	l = sortsl(l);
	r = sortsl(r);
	return merge(l, r);
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	print(a);
	a = sortsl(a);
	print(a);
	return 0;
}