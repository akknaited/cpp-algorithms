#include <iostream>
#include <vector>

using namespace std;

void printv(vector<int> a)
{
	for (int i : a) cout << i << " ";
	cout << endl;
}

vector<int> sortpod(vector<int> a)
{
	int maxel = a[0];
	for (int i : a) if (i > maxel) maxel = i;
	vector<int> cnt(maxel+1, 0);
	for (int i = 0; i < a.size(); i++) cnt[a[i]]++;
	for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i - 1];
	vector<int> res(a.size());
	for (int i = a.size() - 1; i >= 0; i--)
	{
		res[cnt[a[i]] - 1] = a[i];
		cnt[a[i]]--;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	printv(a);
	printv(sortpod(a));
	return 0;
}