#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Hotel {
private:
	string denumireHotel;
	float pretNoapte;
	int durataZileRezervare;
	int nrZileCazare;
	float* cheltuieliZilnice;
	static int NR_MAXIM_CAMERE;

public:
	// 1. Constructor fara parametrii
	Hotel()
	{
		this->denumireHotel = "Necunoscut";
		this->pretNoapte = 0;
		this->durataZileRezervare = 0;
		this->nrZileCazare = 0;
		this->cheltuieliZilnice = NULL;
	}

	// 2. Constructor cu parametri
	Hotel(string denumireHotel, float pretNoapte, int durataZileRezervare,
		int nrZileCazare, float* cheltuieliZilnice)
	{
		this->denumireHotel = denumireHotel;
		this->pretNoapte = pretNoapte;
		this->durataZileRezervare = durataZileRezervare;
		this->nrZileCazare = nrZileCazare;

		this->cheltuieliZilnice = new float[this->nrZileCazare];
		for (int i = 0; i < this->nrZileCazare; i++)
			this->cheltuieliZilnice[i] = cheltuieliZilnice[i];
	}

	// 3. Constructor de copiere
	Hotel(const Hotel& h)
	{
		this->denumireHotel = h.denumireHotel;
		this->pretNoapte = h.pretNoapte;
		this->durataZileRezervare = h.durataZileRezervare;
		this->nrZileCazare = h.nrZileCazare;

		this->cheltuieliZilnice = new float[h.nrZileCazare];
		for (int i = 0; i < h.nrZileCazare; i++)
			this->cheltuieliZilnice[i] = h.cheltuieliZilnice[i];
	}

	// Getteri
	string getDenumireHotel() { return this->denumireHotel; }
	float getPretNoapte() { return this->pretNoapte; }
	int getDurataRezervare() { return this->durataZileRezervare; }
	int getNrZileCazare() { return this->nrZileCazare; }
	float* getCheltuieliZilnice() { return this->cheltuieliZilnice; }

	// Metoda proprie
	void adaugaCheltuialaZilnica(float val)
	{
		float* copie = new float[this->nrZileCazare];
		for (int i = 0; i < this->nrZileCazare; i++)
			copie[i] = this->cheltuieliZilnice[i];

		delete[] this->cheltuieliZilnice;

		this->nrZileCazare++;
		this->cheltuieliZilnice = new float[this->nrZileCazare];
		for (int i = 0; i < this->nrZileCazare - 1; i++)
			this->cheltuieliZilnice[i] = copie[i];

		this->cheltuieliZilnice[this->nrZileCazare - 1] = val;
		delete[] copie;
	}

	int durataRamasaRezervare()
	{
		return this->durataZileRezervare - this->nrZileCazare;
	}

	// Operator =
	Hotel& operator=(const Hotel& h)
	{
		if (this != &h)
		{
			delete[] this->cheltuieliZilnice;

			this->denumireHotel = h.denumireHotel;
			this->pretNoapte = h.pretNoapte;
			this->durataZileRezervare = h.durataZileRezervare;
			this->nrZileCazare = h.nrZileCazare;

			this->cheltuieliZilnice = new float[h.nrZileCazare];
			for (int i = 0; i < h.nrZileCazare; i++)
				this->cheltuieliZilnice[i] = h.cheltuieliZilnice[i];
		}
		return *this;
	}

	// Operator <<
	friend ostream& operator<<(ostream& out, const Hotel& h)
	{
		out << "Hotel: " << h.denumireHotel << endl;
		out << "Pret/noapte: " << h.pretNoapte << endl;
		out << "Durata rezervare: " << h.durataZileRezervare << endl;
		out << "Zile cazare: " << h.nrZileCazare << endl;
		out << "Cheltuieli: ";
		for (int i = 0; i < h.nrZileCazare; i++)
			out << h.cheltuieliZilnice[i] << " | ";
		out << endl;
		return out;
	}

	// Operator >>
	friend istream& operator>>(istream& in, Hotel& h)
	{
		cout << "Denumire: ";
		in >> h.denumireHotel;
		cout << "Pret: ";
		in >> h.pretNoapte;
		cout << "Durata: ";
		in >> h.durataZileRezervare;
		cout << "Zile cazare: ";
		in >> h.nrZileCazare;

		delete[] h.cheltuieliZilnice;
		h.cheltuieliZilnice = new float[h.nrZileCazare];
		cout << "Cheltuieli: ";
		for (int i = 0; i < h.nrZileCazare; i++)
			in >> h.cheltuieliZilnice[i];

		return in;
	}

	// Operator +=
	Hotel& operator+=(float val)
	{
		this->adaugaCheltuialaZilnica(val);
		return *this;
	}

	// Operator []
	float operator[](int index)
	{
		if (index >= 0 && index < this->nrZileCazare)
			return this->cheltuieliZilnice[index];
		return -1;
	}

	// Destructor
	~Hotel()
	{
		delete[] this->cheltuieliZilnice;
	}
};


int Hotel::NR_MAXIM_CAMERE = 150;




void main()
{
	cout << "===== Constructor fara parametrii =====" << endl;
	Hotel h1;
	cout << h1 << endl;

	cout << "===== Constructor cu parametri =====" << endl;
	float chelt[] = { 100, 80, 90 };
	Hotel h2("Hotel Plaza", 400, 6, 3, chelt);
	cout << h2 << endl;

	cout << "===== Constructor de copiere =====" << endl;
	Hotel h3(h2);        
	cout << h3 << endl;

	cout << "===== Metoda proprie =====" << endl;
	h3.adaugaCheltuialaZilnica(120);
	cout << h3 << endl;

	cout << "===== Metoda durata ramasa =====" << endl;
	cout << "Zile ramase: " << h3.durataRamasaRezervare() << endl << endl;

	cout << "===== Operator = =====" << endl;
	Hotel h4;
	h4 = h3;
	cout << h4 << endl;

	cout << "===== Operator << =====" << endl;
	cout << h4 << endl;

	cout << "===== Operator >> =====" << endl;
	cin >> h4;
	cout << h4 << endl;

	cout << "===== Operator += =====" << endl;
	h4 += 75;
	cout << h4 << endl;

	cout << "===== Operator [] =====" << endl;
	cout << "Ziua 1: " << h4[0] << endl;
	cout << "Index invalid: " << h4[20] << endl;

	cout << "===== Destructorii se apeleaza  =====" << endl;
}
