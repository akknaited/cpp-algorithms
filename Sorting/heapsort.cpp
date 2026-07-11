#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& a, int ind, int sz)
{
	int nmax = ind;
	if (2 * ind + 1 < sz && a[2 * ind + 1] > a[nmax]) nmax = 2 * ind + 1;
	if (2 * ind + 2 < sz && a[2 * ind + 2] > a[nmax]) nmax = 2 * ind + 2;
	if (nmax != ind)
	{
		swap(a[nmax], a[ind]);
		heapify(a, nmax, sz);
	}
}

void sortheap(vector<int>& a)
{
	for (int i = a.size() / 2 - 1;i >= 0;i--) heapify(a, i, a.size());
	for (int i = a.size() - 1;i > 0;i--)
	{
		swap(a[0], a[i]);
		heapify(a, 0, i);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	cout << endl;

	for (int i = 0;i < n;i++)
	{
		cout<< a[i] << " ";
	}
	cout << endl;

	sortheap(a);

	for (int i = 0;i < n;i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}
