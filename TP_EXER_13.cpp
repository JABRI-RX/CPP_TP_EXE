#include <iostream>
#include <set>
using namespace std;
class Voiture
{
private:
	int id{};
	string marque{};
	float vitess{};
	float puisance{};
public:
	Voiture(){}
	Voiture(int id, string ma, float vi, float pu)
	{
		this->id = id;
		marque = ma;
		vitess = vi;
		puisance = pu;
	}
	//2
	void saisir()
	{
		cout << "Id : ";
		cin >> id;

		cout << "Marque : ";
		cin >> marque;

		cout << "Vitess : ";
		cin >> vitess;

		cout << "Puisance : ";
		cin >> puisance;
	}
	//3
	void affichier()
	{
		cout << "Id : " << id << "\n";
		cout << "Marque : " << marque << "\n";
		cout << "Vitess : " << vitess << "\n";
		cout << "Puisance : " << puisance <<"\n";
 
	}
	int getId() const
	{
		return id;
	}
	float getVitesse() const
	{
		return vitess;
	}
	float getPuissance() const {
		return puisance;
	}
	bool operator<(const Voiture& vt) const
	{
		return vitess < vt.vitess;
	}
	bool operator<(const Voiture& vt)  
	{	
		marque = vt.marque;
		vitess = vt.vitess;
		puisance = vt.puisance;

	}
	friend ostream& operator<<(ostream& o,const Voiture v)
	{
		o << v.id ;
		return o;
	}
	bool operator==(const Voiture& vt) const
	{
		return   marque == vt.marque && vitess == vt.vitess && puisance == vt.puisance;
	}
};
bool check_speed(const Voiture& v)
{
	return (v.getVitesse() >= 200);
	
}
bool check_Pui(const Voiture v)
{
	return (v.getPuissance() < 50);
}
int main()
{
	//4
	set<Voiture> vts;
	vts.insert(Voiture(1, "VOL", 180, 80));
	vts.insert(Voiture(2, "VOL", 190, 70));
	vts.insert(Voiture(3, "HHT", 100, 20));
	vts.insert(Voiture(4, "QWR", 103, 100));
	vts.insert(Voiture(5, "GGT", 203, 30));
	//5
	auto vt_find = find_if(vts.begin(), vts.end(),check_speed);
	if (vt_find != vts.end())
	{
		cout << "Voiutre de vitess 200 exist de id :"<<*vt_find;
	}
	else {
		cout << "Voiutre de vitess 200 n'exist pas ";

	}
	//5
	 
	remove_if(vts.begin(), vts.end(), check_Pui);
	
	cout << "\n";
	system("pause");
}
