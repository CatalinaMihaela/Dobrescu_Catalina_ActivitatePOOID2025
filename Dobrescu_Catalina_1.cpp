#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Dispozitiv
{

	string denumireDispozitiv;
	int nrBaterii;
	const int anInfiintare;
	char initialaDispozitiv;
	char* Brand;
public:
	//Constructor fara parametrii
	Dispozitiv() :anInfiintare(2024)
	{
		this->denumireDispozitiv = "Necunoscuta";
		this->nrBaterii = 0;
		this->initialaDispozitiv = 0;
		this->Brand = new char[strlen("Anonim") + 1];
		strcpy(this->Brand, "Anonim");

	}
	//Constructor cu un parametru
	Dispozitiv(string denumireDispozitiv) :anInfiintare(2024)
	{
		this->denumireDispozitiv = denumireDispozitiv;
		this->nrBaterii = 0;
		this->initialaDispozitiv = 0;
		this->Brand = new char[strlen("Anonim") + 1];
		strcpy(this->Brand, "Anonim");

	}
	//Constructor cu doi parametrii
	Dispozitiv(string denumireDispozitiv,int nrBaterii) :anInfiintare(2024)
	{
		this->denumireDispozitiv = denumireDispozitiv;
		this->nrBaterii = nrBaterii;
		this->initialaDispozitiv = 0;
		this->Brand = new char[strlen("Anonim") + 1];
		strcpy(this->Brand, "Anonim");

	}
	//Constructor cu trei parametrii
	Dispozitiv(string denumireDispozitiv, int nrBaterii, char initialaDispozitiv) :anInfiintare(2024)
	{
		this->denumireDispozitiv = denumireDispozitiv;
		this->nrBaterii = nrBaterii;
		this->initialaDispozitiv = initialaDispozitiv;
		this->Brand = new char[strlen("Anonim") + 1];
		strcpy(this->Brand, "Anonim");

	}
	//Constructor cu toti parametrii
	Dispozitiv(string denumireDispozitiv, int nrBaterii, char initialaDispozitiv, const char* Brand) :anInfiintare(2024)
	{
		this->denumireDispozitiv = denumireDispozitiv;
		this->nrBaterii = nrBaterii;
		this->initialaDispozitiv = initialaDispozitiv;
		this->Brand = new char[strlen(Brand) + 1];
		strcpy(this->Brand, Brand);

	}
	//METODE ACCESOR: GETTERI & SETTERI
//GETTERII 

	string getDenumireDispozitiv()
	{
		return this->denumireDispozitiv;
	}

	int getNrBaterii()
	{
		return this->nrBaterii;
	}

	char getInitialaDispozitiv()
	{
		return this->initialaDispozitiv;
	}

	int getAnInfiintare() // atribut constant -> doar GETTER
	{
		return this->anInfiintare;
	}

	char* getBrand()
	{
		return this->Brand;
	}

	//SETTERII
	

	void setDenumireDispozitiv(string denNoua)
	{
		this->denumireDispozitiv = denNoua;
	}

	void setNrBaterii(int nrNou)
	{
		this->nrBaterii = nrNou;
	}

	void setInitialaDispozitiv(char literaNoua)
	{
		this->initialaDispozitiv = literaNoua;
	}

	void setBrand(const char* brandNou)
	{
		
		delete[] this->Brand;

		
		this->Brand = new char[strlen(brandNou) + 1];
		strcpy(this->Brand, brandNou);
	}

};
void main()
{


	Dispozitiv d1;
	cout << "Denumire dispozitiv: " << d1.getDenumireDispozitiv() << endl;
	cout << "Nr baterii: " << d1.getNrBaterii() << endl;
	cout << "Initiala dispozitiv: " << d1.getInitialaDispozitiv() << endl;
	cout << "An infiintare: " << d1.getAnInfiintare() << endl;
	cout << "Brand: " << d1.getBrand() << endl;

	cout << endl;

	Dispozitiv d2("Telefon", 1, 'T', "Apple");
	cout << "Denumire dispozitiv: " << d2.getDenumireDispozitiv() << endl;
	cout << "Nr baterii: " << d2.getNrBaterii() << endl;
	cout << "Initiala dispozitiv: " << d2.getInitialaDispozitiv() << endl;
	cout << "An infiintare: " << d2.getAnInfiintare() << endl;
	cout << "Brand: " << d2.getBrand() << endl;

	cout << endl;

	// Testam setterii
	d1.setDenumireDispozitiv("Laptop");
	d1.setNrBaterii(1);
	d1.setInitialaDispozitiv('L');
	d1.setBrand("Dell");

	cout << "Dupa setteri -> Dispozitiv d1: " << endl;
	cout << "Denumire: " << d1.getDenumireDispozitiv() << endl;
	cout << "Nr baterii: " << d1.getNrBaterii() << endl;
	cout << "Initiala: " << d1.getInitialaDispozitiv() << endl;
	cout << "Brand: " << d1.getBrand() << endl;

	cout << endl << endl;
}
