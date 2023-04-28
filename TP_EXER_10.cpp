#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;
bool check_desc(int& i, int& j)
{
	if (i > j)
	{
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	//1
	deque<int> dqs;
	//2
	while (true)
	{
		int i{};
		cin >> i;
		if (i == 1)
		{
			break;
		}
		dqs.push_back(i);
	}
	cout << "\n-----------------<<-----------------\n";
	//3
	for (auto it = dqs.rbegin(); it != dqs.rend(); it++)
	{
		cout << *it << ",";
	}

	//4
	if (!is_sorted(dqs.begin(), dqs.end(), check_desc))
	{
		sort(dqs.begin(), dqs.end());
	}

	//5
	cout << "\n-----------------<<-----------------\n";

	for (auto it = dqs.rbegin(); it != dqs.rend(); it++)
	{
		cout << *it << ",";
	}
	//6

	vector<int> vecs(dqs.size());
	copy(dqs.begin(), dqs.end(), vecs.begin());
	//7
	remove(dqs.begin(), dqs.end(), 0);
	cout << "\n-----------------<<-----------------\n";

	for (auto it = dqs.rbegin(); it != dqs.rend(); it++)
	{
		cout << *it << ",";
	}
	//8
	int i;
	cout << "enter la valeur pour rechercher :";
	cin >> i;
	auto it = find(dqs.begin(), dqs.end(), i);
	if (it != dqs.end())
	{
		cout << "valuer exist dans la position " << it - dqs.begin() << "\n";
	}
	else {
		cout << "Valeur n'exist pas\n";
	}

	pair<deque<int>::iterator, deque<int>::iterator> res = minmax_element(dqs.begin(), dqs.end());

	cout << "Valuer min est " << *res.first << '\n';
	cout << "Valuer max est " << *res.second << '\n';
	system("pause");
}
