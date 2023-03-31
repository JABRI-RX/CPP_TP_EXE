#include <iostream>
#include <deque>
#include <algorithm>
#include <list>
#include <string>
#include <cstring>
using namespace std;
 
void maj_Let(string& st)
{
	if (st[0] >= 96 )
	//asci code 
		st[0] -=  32;
	 
}
bool check_a(string& st)
{
	int res = st.find("a");
	return (res != -1);
 
}
bool find_i(string& st)
{
	int res = st.find("i");
	return (res != -1);
}
int main()
{
	//1
	list<string> lst;
	//2
	while (true)
	{
		string st;
		getline(cin, st);
		if (st == "fin")
		{
			break;
		}
		lst.push_back(st);
	}
	//3
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << ",";
	}
	cout << "\n";
	//4
	for_each(lst.begin(), lst.end(),maj_Let);
	//5
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << ",";
	}
	cout << "\n";
	//6
	int a_count = count_if(lst.begin(), lst.end(), check_a);
	cout << "NOmbre d echaines qui cont a : " << a_count;
	cout << "\n";
	//7
	auto i_find = find_if(lst.begin(), lst.end(), find_i);
	cout << "la Premier chaine de la list qui commence par la letter i est " << *i_find;
	cout << "\n";
	system("pause");
}
