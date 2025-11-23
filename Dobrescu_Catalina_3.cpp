#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Farmacie
{
	int nrMedicamente;
	float* vectorPreturiMedicamente;

public:
	//Constructor cu toti parametrii
	Farmacie(int nrMedicamente, float* vectorPreturiMedicamente)
	{
		this->nrMedicamente = nrMedicamente;
		this->vectorPreturiMedicamente = new float[this->nrMedicamente];
		for (int i=0; i < this->nrMedicamente; i++)
		{
			this->vectorPreturiMedicamente[i] = vectorPreturiMedicamente[i];
		}
	}
	//Getteri
	int getnrMedicamente()
	{
		return this->nrMedicamente;
	}
	float* getvectorPreturiMedicamente()
	{
		return this->vectorPreturiMedicamente;
	}
	//Setteri
	void setMedicamente(int nrNouMedicamente, float* PreturiNoimedicamente)
	{
		if (this->vectorPreturiMedicamente != NULL)
		{
			delete[] this->vectorPreturiMedicamente;
		}
		this->nrMedicamente = nrNouMedicamente;
		this->vectorPreturiMedicamente = new float[this->nrMedicamente];
		for (int i = 0; i < this->nrMedicamente; i++)
		{
			this->vectorPreturiMedicamente[i] = PreturiNoimedicamente[i];
		}
	}
	~Farmacie() {
		if (vectorPreturiMedicamente != NULL)
			delete[] vectorPreturiMedicamente;
	}


};

void main()
{// Constructor cu toti parametrii
	cout << "--------------------Apel constructor cu toti parametrii------------------" << endl;
	float medicamente[] = { 12.3, 22.5, 30.6 };
		Farmacie f1(3, medicamente);
	cout << "Nr. Medicamente:" << f1.getnrMedicamente() << endl;
	cout << "Preturi Medicamente:";
	for (int i = 0; i < f1.getnrMedicamente();i++)
	{
		cout << f1.getvectorPreturiMedicamente()[i] << ";";

	}
	cout << endl;

	//Apel setteri

	
	float medicamente2[] = { 10.2,30.2 };
	f1.setMedicamente(2,medicamente2);


}