#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

enum tipPlan { Basic, Standard, Premium };

class Abonament {
	int idClient;
	char* numeClient;
	double costLunar;
	int anStart;
protected:
	tipPlan tip;
	int nrLuniContract;
public:
	// Constructor fara parametrii
	Abonament() {
		idClient = 0;
		numeClient = new char[strlen("Anonim") + 1];
		strcpy(numeClient, "Anonim");
		costLunar = 0;
		anStart = 2000;
		tip = Basic;
		nrLuniContract = 0;
	}

	// Constructor cu parametri
	Abonament(int id, const char* nume) {
		idClient = id > 0 ? id : 0;
		numeClient = new char[strlen(nume) + 1];
		strcpy(numeClient, nume);
		costLunar = 0;
		anStart = 2000;
		tip = Basic;
		nrLuniContract = 0;
	}

	// Constructor complet
	Abonament(int id, const char* nume, double cost, int an, tipPlan t, int luni) {
		idClient = id;
		numeClient = new char[strlen(nume) + 1];
		strcpy(numeClient, nume);
		costLunar = cost;
		anStart = an;
		tip = t;
		nrLuniContract = luni;
	}

	// Copy constructor
	Abonament(const Abonament& a) {
		idClient = a.idClient;
		numeClient = new char[strlen(a.numeClient) + 1];
		strcpy(numeClient, a.numeClient);
		costLunar = a.costLunar;
		anStart = a.anStart;
		tip = a.tip;
		nrLuniContract = a.nrLuniContract;
	}

	// Operator =
	Abonament& operator=(const Abonament& a) {
		if (this != &a) {
			delete[] numeClient;
			numeClient = new char[strlen(a.numeClient) + 1];
			strcpy(numeClient, a.numeClient);
			idClient = a.idClient;
			costLunar = a.costLunar;
			anStart = a.anStart;
			tip = a.tip;
			nrLuniContract = a.nrLuniContract;
		}
		return *this;
	}

	double getCost() { return costLunar; }
	int getNrLuni() { return nrLuniContract; }

	// Operator <
	bool operator<(const Abonament& a) {
		return costLunar < a.costLunar;
	}

	// Operator ()
	double operator()() {
		return costLunar * nrLuniContract;
	}

	friend ostream& operator<<(ostream& out, const Abonament& a) {
		out << "ID client: " << a.idClient << endl;
		out << "Nume: " << a.numeClient << endl;
		out << "Cost lunar: " << a.costLunar << endl;
		out << "An start: " << a.anStart << endl;
		out << "Nr luni: " << a.nrLuniContract << endl;
		return out;
	}

	friend ofstream& operator<<(ofstream& out, const Abonament& a) {
		out << a.idClient << endl << a.numeClient << endl
			<< a.costLunar << endl << a.anStart << endl
			<< a.nrLuniContract << endl;
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Abonament& a) {
		delete[] a.numeClient;
		char aux[50];
		in >> a.idClient >> aux >> a.costLunar >> a.anStart >> a.nrLuniContract;
		a.numeClient = new char[strlen(aux) + 1];
		strcpy(a.numeClient, aux);
		return in;
	}

	~Abonament() {
		delete[] numeClient;
	}
};

// CLASA ABSTRACTA
class CalculCost {
public:
	virtual void calculeaza() = 0;
};

// Clasa derivata
class PlanCuReducere : public Abonament, public CalculCost {
protected:
	double reducere;
	double* costuriLunare;
public:
	PlanCuReducere() : Abonament() {
		reducere = 0;
		costuriLunare = NULL;
	}

	PlanCuReducere(int id, const char* nume, double cost, int an, tipPlan t, int luni, double r)
		: Abonament(id, nume, cost, an, t, luni) {
		reducere = r;
		costuriLunare = new double[luni];
		for (int i = 0; i < luni; i++)
			costuriLunare[i] = 0;
	}

	PlanCuReducere(const PlanCuReducere& p) : Abonament(p) {
		reducere = p.reducere;
		costuriLunare = new double[getNrLuni()];
		for (int i = 0; i < getNrLuni(); i++)
			costuriLunare[i] = p.costuriLunare[i];
	}

	PlanCuReducere& operator=(const PlanCuReducere& p) {
		if (this != &p) {
			Abonament::operator=(p);
			delete[] costuriLunare;
			reducere = p.reducere;
			costuriLunare = new double[getNrLuni()];
			for (int i = 0; i < getNrLuni(); i++)
				costuriLunare[i] = p.costuriLunare[i];
		}
		return *this;
	}

	void calculeaza() {
		for (int i = 0; i < getNrLuni(); i++)
			costuriLunare[i] = getCost() - reducere * getCost();
	}

	double& operator[](int i) {
		static double err = -1;
		return (i >= 0 && i < getNrLuni()) ? costuriLunare[i] : err;
	}

	friend ostream& operator<<(ostream& out, const PlanCuReducere& p) {
		out << (Abonament&)p;
		out << "Reducere: " << p.reducere << endl;
		return out;
	}

	~PlanCuReducere() {
		delete[] costuriLunare;
	}
};

// TEMPLATE
template<typename T>
void sortare(int n, T* v) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (v[i] < v[j]) swap(v[i], v[j]);
}

void main() {
	Abonament a1;
	Abonament a2(1, "Ion");
	Abonament a3(2, "Ana", 40, 2021, Premium, 12);

	cout << a3 << endl;
	cout << "Cost total: " << a3() << endl;

	PlanCuReducere p1(3, "Maria", 50, 2022, Standard, 6, 0.1);
	p1.calculeaza();
	cout << p1 << endl;
	cout << "Luna 2: " << p1[1] << endl;

	PlanCuReducere v[2];
	v[0] = p1;
	v[1] = PlanCuReducere(4, "Alex", 30, 2023, Basic, 12, 0.2);

	sortare(2, v);
	for (int i = 0; i < 2; i++)
		cout << v[i] << endl;
}
