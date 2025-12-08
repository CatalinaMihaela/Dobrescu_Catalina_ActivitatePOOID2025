#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Pizzerie {
private:
	string denumirePizzerie;
	int nrAngajati;
	float suprafataPizzerieMP;
	bool areLivrare;
	const int anInfiintare;
	static int codCAEN;

	char* numeProprietar;
	int nrPizza;
	float* vectorPreturiPizza;
	string* vectorDenumiriPizza;

public:
	// CONSTRUCTOR FARA PARAMETRII
	Pizzerie() : anInfiintare(2000)
	{
		denumirePizzerie = "Necunoscuta";
		nrAngajati = 0;
		suprafataPizzerieMP = 0;
		areLivrare = 0;

		numeProprietar = new char[strlen("Anonim") + 1];
		strcpy(numeProprietar, "Anonim");

		nrPizza = 0;
		vectorPreturiPizza = NULL;
		vectorDenumiriPizza = NULL;
	}

	//  CONSTRUCTOR CU TOTI PARAMETRII
	Pizzerie(string denumireP, int nrA, float suprafata, bool livrare,
		const char* numeProp, int nrP, float* preturi, string* denumiri)
		: anInfiintare(2000)
	{
		denumirePizzerie = denumireP;
		nrAngajati = nrA;
		suprafataPizzerieMP = suprafata;
		areLivrare = livrare;

		numeProprietar = new char[strlen(numeProp) + 1];
		strcpy(numeProprietar, numeProp);

		nrPizza = nrP;
		vectorPreturiPizza = new float[nrPizza];
		vectorDenumiriPizza = new string[nrPizza];

		for (int i = 0; i < nrPizza; i++)
		{
			vectorPreturiPizza[i] = preturi[i];
			vectorDenumiriPizza[i] = denumiri[i];
		}
	}

	// DESTRUCTOR
	~Pizzerie()
	{
		if (numeProprietar)
			delete[] numeProprietar;
		if (vectorPreturiPizza)
			delete[] vectorPreturiPizza;
		if (vectorDenumiriPizza)
			delete[] vectorDenumiriPizza;

		cout << "Destructor Pizzerie apelat" << endl;
	}

	// GETTERI 
	string getDenumire() { return denumirePizzerie; }
	int getNrAngajati() { return nrAngajati; }
	float getSuprafata() { return suprafataPizzerieMP; }
	bool getAreLivrare() { return areLivrare; }
	char* getNumeProprietar() { return numeProprietar; }
	int getNrPizza() { return nrPizza; }
	float* getPreturi() { return vectorPreturiPizza; }
	string* getDenumiri() { return vectorDenumiriPizza; }

	// SETTERI 
	void setDenumire(string denumireNoua)
	{
		denumirePizzerie = denumireNoua;
	}

	void setNrAngajati(int nrNou)
	{
		if (nrNou >= 0)
			nrAngajati = nrNou;
	}

	void setSuprafata(float suprafataNoua)
	{
		if (suprafataNoua > 0)
			suprafataPizzerieMP = suprafataNoua;
	}

	void setAreLivrare(bool livrare)
	{
		areLivrare = livrare;
	}

	void setNumeProprietar(const char* numeNou)
	{
		if (numeProprietar)
			delete[] numeProprietar;

		numeProprietar = new char[strlen(numeNou) + 1];
		strcpy(numeProprietar, numeNou);
	}

	void setPizza(int nrNou, float* preturiNoi, string* denumiriNoi)
	{
		if (vectorPreturiPizza)
			delete[] vectorPreturiPizza;
		if (vectorDenumiriPizza)
			delete[] vectorDenumiriPizza;

		nrPizza = nrNou;
		vectorPreturiPizza = new float[nrPizza];
		vectorDenumiriPizza = new string[nrPizza];

		for (int i = 0; i < nrPizza; i++)
		{
			vectorPreturiPizza[i] = preturiNoi[i];
			vectorDenumiriPizza[i] = denumiriNoi[i];
		}
	}

	
	float pretMinim()
	{
		if (nrPizza == 0)
			return 0;

		float minim = vectorPreturiPizza[0];
		for (int i = 1; i < nrPizza; i++)
			if (vectorPreturiPizza[i] < minim)
				minim = vectorPreturiPizza[i];
		return minim;
	}

	void aplicaDiscount(float discount, int pozitie)
	{
		if (pozitie >= 0 && pozitie < nrPizza)
			vectorPreturiPizza[pozitie] -= vectorPreturiPizza[pozitie] * discount;
	}

	void adaugaPizzaNoua(string denumireNoua, float pretNou)
	{
		float* preturiNoi = new float[nrPizza + 1];
		string* denumiriNoi = new string[nrPizza + 1];

		for (int i = 0; i < nrPizza; i++)
		{
			preturiNoi[i] = vectorPreturiPizza[i];
			denumiriNoi[i] = vectorDenumiriPizza[i];
		}

		preturiNoi[nrPizza] = pretNou;
		denumiriNoi[nrPizza] = denumireNoua;

		delete[] vectorPreturiPizza;
		delete[] vectorDenumiriPizza;

		nrPizza++;
		vectorPreturiPizza = preturiNoi;
		vectorDenumiriPizza = denumiriNoi;
	}
};

int Pizzerie::codCAEN = 56;

void main()
{
	
	Pizzerie p0;
	cout << "Pizzerie default: " << p0.getDenumire() << endl << endl;


	float preturi[] = { 28.5, 32.0, 35.5 };
	string denumiri[] = { "Margherita", "Diavola", "Capricciosa" };

	Pizzerie p1("Pizza Napoli", 5, 120.5, 1, "Andrei", 3, preturi, denumiri);

	cout << "Pizzerie initiala:" << endl;
	for (int i = 0; i < p1.getNrPizza(); i++)
		cout << p1.getDenumiri()[i] << " - " << p1.getPreturi()[i] << " lei" << endl;

	cout << endl << "TEST SETTERI:" << endl;
	p1.setDenumire("Pizza Milano");
	p1.setNrAngajati(10);
	p1.setSuprafata(200);
	p1.setAreLivrare(0);
	p1.setNumeProprietar("Mihai");

	float preturiNoi[] = { 30, 36 };
	string denumiriNoi[] = { "Prosciutto", "Quattro Stagioni" };
	p1.setPizza(2, preturiNoi, denumiriNoi);

	cout << "Dupa setteri:" << endl;
	for (int i = 0; i < p1.getNrPizza(); i++)
		cout << p1.getDenumiri()[i] << " - " << p1.getPreturi()[i] << " lei" << endl;

	
	p1.aplicaDiscount(0.1, 0);
	p1.adaugaPizzaNoua("Vegetariana", 29);

	cout << endl << "Dupa metode:" << endl;
	for (int i = 0; i < p1.getNrPizza(); i++)
		cout << p1.getDenumiri()[i] << " - " << p1.getPreturi()[i] << " lei" << endl;

	cout << "Pret minim: " << p1.pretMinim() << endl;
}
