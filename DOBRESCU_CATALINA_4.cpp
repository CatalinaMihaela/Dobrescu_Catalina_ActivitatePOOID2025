#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Magazin {

	string denumireMagazin;
	int nrAngajati;
	float suprafataMagazinMP;
	bool esteNonStop;
	const int anInfiintare;
	static int clasaCAEN;

	char* numeProprietar;
	int nrProduse;
	float* vectorPreturiProduse;
	string* vectorDenumiriProduse;
public:
	//Constructor fara parametrii
	Magazin() :anInfiintare(1990)
	{
		this->denumireMagazin = "Necunoscuta";
		this->nrAngajati = 0;
		this->suprafataMagazinMP = 0;
		this->esteNonStop = 0;

		//1.Alocarea de memorie
		this->numeProprietar = new char[strlen("Anonim") + 1]; 
		//2.Initializarea
		strcpy(this->numeProprietar, "Anonim"); 

		this->nrProduse = 0;
		this->vectorPreturiProduse = NULL; 
		this->vectorDenumiriProduse = NULL; 
	}

	//Constructorul cu un parametru
	Magazin(string denumireMagazin) :anInfiintare(1990)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = 0;
		this->suprafataMagazinMP = 0;
		this->esteNonStop = 0;

		//1.Alocarea de memorie
		this->numeProprietar = new char[strlen("Anonim") + 1]; 
		//2.Initializarea
		strcpy(this->numeProprietar, "Anonim"); 

		this->nrProduse = 0;
		this->vectorPreturiProduse = NULL; 
		this->vectorDenumiriProduse = NULL; 
	}

	//Constuctorul cu doi parametrii
	Magazin(string denumireMagazin, int nrAngajati) :anInfiintare(1990)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = nrAngajati;
		this->suprafataMagazinMP = 0;
		this->esteNonStop = 0;

		//1.Alocarea de memorie
		this->numeProprietar = new char[strlen("Anonim") + 1]; 
		//2.Initializarea
		strcpy(this->numeProprietar, "Anonim"); 

		this->nrProduse = 0;
		this->vectorPreturiProduse = NULL; 
		this->vectorDenumiriProduse = NULL; 
	}

	//Constructor cu toti parametrii
	Magazin(string denumireMagazin, int nrAngajati, float suprafataMagazinMP, bool esteNonStop, const char* numeProprietar, int nrProduse, float* vectorPreturiProduse, string* vectorDenumiriProduse) :anInfiintare(1990)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = nrAngajati;
		this->suprafataMagazinMP = suprafataMagazinMP;
		this->esteNonStop = esteNonStop;

		//Alocare de memorie
		this->numeProprietar = new char[strlen(numeProprietar) + 1];
		//Initializare
		strcpy(this->numeProprietar, numeProprietar);

		this->nrProduse = nrProduse;
		//alocare memorie
		this->vectorPreturiProduse = new float[this->nrProduse];
		this->vectorDenumiriProduse = new string[this->nrProduse];
		//Initializare
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->vectorPreturiProduse[i] = vectorPreturiProduse[i];
			this->vectorDenumiriProduse[i] = vectorDenumiriProduse[i];
		}


	}
	//GETTERI
	string getdenumireMagazin()
	{
		return this->denumireMagazin;
	}

	int getnrAngajati()
	{
		return this->nrAngajati;
	}
	float getsuparafataMagazinMP()
	{
		return this->suprafataMagazinMP;
	}
	bool getesteNonStop()
	{
		return this->esteNonStop;
	}
	char* getnumeProprietar()
	{
		return this->numeProprietar;
	}
	int getnrProduse()
	{
		return this->nrProduse;
	}
	float* getvectorPreturiProduse()
	{
		return this->vectorPreturiProduse;
	}
	string* getvectorDenumiriProduse()
	{
		return this->vectorDenumiriProduse;
	}

	//SETTERI
	void setDenumireMagazin(string denumireNouaMagazin)
	{
		this->denumireMagazin = denumireNouaMagazin;
	}
	void setnrAngajati(int nrNouAngajati)
	{
		this->nrAngajati = nrNouAngajati;
	}
	void setsuprafataMagazinMP(float suprafataNouaMagazinMP)
	{
		this->suprafataMagazinMP = suprafataNouaMagazinMP;
	}
	void setesteNonStop(bool esteNonStopValoareNoua)
	{
		this->esteNonStop = esteNonStopValoareNoua;
	}
	void setNumeProprietar(const char* numeProprietarNou)
	{
		//Scapam de vechea valoare
		if (this->numeProprietar != NULL)
		{
			delete[] this->numeProprietar;
		}
		//Realocam spatiu de memorie pentru noua valoare
		this->numeProprietar = new char[strlen(numeProprietarNou) + 1];
		//Reinitializam
		strcpy(this->numeProprietar, numeProprietarNou);
	}
	void setProduse(int nrNouProduse, float* preturiNoiProduse, string* denumiriNoiProduse)
	{
		//Scapam de vechii vectori
		if (this->vectorPreturiProduse != NULL)
		{
			delete[] this->vectorPreturiProduse;
		}
		if (this->vectorDenumiriProduse != NULL)
		{
			delete[] this->vectorDenumiriProduse;
		}
		this->nrProduse = nrNouProduse;
		//Realocam spatiu
		this->vectorPreturiProduse = new float[this->nrProduse];
		this->vectorDenumiriProduse = new string[this->nrProduse];
		//Reinitializare
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->vectorPreturiProduse[i] = preturiNoiProduse[i];
			this->vectorDenumiriProduse[i] = denumiriNoiProduse[i];

		}
	}
	//DESTRUCTOR
	~Magazin()
	{
		if (this->numeProprietar != NULL)
		{
			delete[] this->numeProprietar;
		}
		if (this->vectorPreturiProduse != NULL)
		{
			delete[] this->vectorPreturiProduse;
		}
		if (this->vectorDenumiriProduse != NULL)
		{
			delete[] this->vectorDenumiriProduse;
		}
		cout << "AICI SE APELEAZA DESTRUCTORUL" << endl;
	}
	//Constructorul de copiere
	Magazin(const Magazin& obj) : anInfiintare(obj.anInfiintare)
	{
		this->denumireMagazin = obj.denumireMagazin;
		this->nrAngajati = obj.nrAngajati;
		this->suprafataMagazinMP = obj.suprafataMagazinMP;
		this->esteNonStop = obj.esteNonStop;

		//Alocare de memorie
		this->numeProprietar = new char[strlen(obj.numeProprietar) + 1];
		//Initializare
		strcpy(this->numeProprietar, obj.numeProprietar);

		this->nrProduse = obj.nrProduse;
		//alocare memorie
		this->vectorPreturiProduse = new float[this->nrProduse];
		this->vectorDenumiriProduse = new string[this->nrProduse];
		//Initializare
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->vectorPreturiProduse[i] = obj.vectorPreturiProduse[i];
			this->vectorDenumiriProduse[i] = obj.vectorDenumiriProduse[i];
		}

	}
	//Operatorul =
	Magazin& operator=(const Magazin& obj)
	{
		if (this != &obj) 
		{
			if (this->numeProprietar != NULL)
			{
				delete[] this->numeProprietar;
			}
			if (this->vectorPreturiProduse != NULL)
			{
				delete[] this->vectorPreturiProduse;
			}
			if (this->vectorDenumiriProduse != NULL)
			{
				delete[] this->vectorDenumiriProduse;
			}

			this->denumireMagazin = obj.denumireMagazin;
			this->nrAngajati = obj.nrAngajati;
			this->suprafataMagazinMP = obj.suprafataMagazinMP;
			this->esteNonStop = obj.esteNonStop;
			this->numeProprietar = new char[strlen(obj.numeProprietar) + 1];
			strcpy(this->numeProprietar, obj.numeProprietar);
			this->nrProduse = obj.nrProduse;
			this->vectorPreturiProduse = new float[this->nrProduse];
			this->vectorDenumiriProduse = new string[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->vectorPreturiProduse[i] = obj.vectorPreturiProduse[i];
				this->vectorDenumiriProduse[i] = obj.vectorDenumiriProduse[i];
			}
		}
		return *this;
	}
	//Metode
	//Pret Minim
	//Sa se determine pretul cel mai mic din vectorul de preturi produse. (reprezentand produsul cel mai ieftin)
	float calculpretMini()
	{
		float pretMinim;
		pretMinim = this->vectorPreturiProduse[0];
		for (int i = 1; i < this->nrProduse; i++)
		{
			if (this->vectorPreturiProduse[1] < pretMinim)
			{
				pretMinim = this->vectorPreturiProduse[i];
			}
		}
		return pretMinim;
	}
	//APLICARE DISCOUNT
	//Sa se aplice un discount variabil pentru un produs ales la intamplare din magazin.
	void aplicareDiscount(float discount, int pozitieProdus)
	{
		if (pozitieProdus >= 0 && pozitieProdus < this->nrProduse)
		{
			this->vectorPreturiProduse[pozitieProdus] = this->vectorPreturiProduse[pozitieProdus] - this->vectorPreturiProduse[pozitieProdus] * discount;
		}
		else
		{
			cout << "Atentie!Pozitia produsului nu exista in magazin!";
		}
	}
};
int Magazin::clasaCAEN = 47;

void main()
{
	//constructorul fara parametrii
	Magazin m1;
	cout << "Denumire magazin:" << m1.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m1.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m1.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m1.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m1.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m1.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m1.getnrProduse(); i++) {
		cout << "Pret: " << m1.getvectorPreturiProduse()[i] << endl;
		cout << "Denumire: " << m1.getvectorDenumiriProduse()[i] << endl;
	}

	cout << endl << endl;

	//Constructor cu un parametru
	Magazin m2("Altex");
	cout << "Denumire magazin:" << m2.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m2.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m2.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m2.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m2.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m2.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m2.getnrProduse(); i++) {
		cout << "Pret: " << m2.getvectorPreturiProduse()[i] << endl;
		cout << "Denumire: " << m2.getvectorDenumiriProduse()[i] << endl;
	}

	cout << endl << endl;

	// Constructor cu doi parametrii
	Magazin m3("Zara",2);
	cout << "Denumire magazin:" << m3.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m3.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m3.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m3.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m3.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m3.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m3.getnrProduse(); i++) {
		cout << "Pret: " << m3.getvectorPreturiProduse()[i] << endl;
		cout << "Denumire: " << m3.getvectorDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	///CONSTRUCTORUL CU TOTI PARAMETRII
	float preturi1[] = { 11, 12, 30 };
	string denumiri1[] = { "Ciocolata", "Unt", "Inghetata" };
	Magazin m4("Profi", 2,100.2, 0, "Alin", 3, preturi1, denumiri1);
	cout << "Denumire magazin:" << m4.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m4.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m4.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m4.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m4.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m4.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m4.getnrProduse(); i++)
	{
		cout << "Pret: " << m4.getvectorPreturiProduse()[i] << endl;}
	for (int i = 0; i < m4.getnrProduse(); i++){
		cout << "Denumire: " << m4.getvectorDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	float preturi2[] = { 111.5, 120, 210.3 };
	string denumiri2[] = { "Bluza", "Pantaloni", "Colanti" };
	Magazin m5("H&M", 2, 100.2, 0, "Alin", 3, preturi2, denumiri2);
	cout << "Denumire magazin:" << m5.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m5.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m5.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m5.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m5.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m5.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m5.getnrProduse(); i++)
	{
		cout << "Pret: " << m5.getvectorPreturiProduse()[i] << endl;
	}
	for (int i = 0; i < m5.getnrProduse(); i++) {
		cout << "Denumire: " << m5.getvectorDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	cout << "--------------------------------APEL SETTERI--------------------------" << endl << endl;
	cout << "Obiectul m1 inainte de a fi modificat pe baza setterilor:" << endl << endl;
	cout << "Denumire magazin:" << m1.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m1.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m1.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m1.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m1.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m1.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m1.getnrProduse(); i++) {
		cout << "Pret: " << m1.getvectorPreturiProduse()[i] << endl;
		cout << "Denumire: " << m1.getvectorDenumiriProduse()[i] << endl;
	}

	cout << endl << endl;

	m1.setDenumireMagazin("Kaufland");
	m1.setnrAngajati(2);
	m1.setsuprafataMagazinMP(200.2);
	m1.setesteNonStop(1);
	m1.setNumeProprietar("Mircea");
	float preturi3[] = { 20.2, 22.2, 12.4 };
	string denumiri3[] = { "Banane", "Ciuperci", "Branza" };
	m1.setProduse(3, preturi3, denumiri3);

	cout << "Obiectul m1 dupa ce a fost modificat pe baza setterilor:" << endl << endl;
	cout << "Denumire magazin:" << m1.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m1.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m1.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m1.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m1.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m1.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m1.getnrProduse(); i++) {
		cout << "Pret: " << m1.getvectorPreturiProduse()[i] << endl;
	}
	for (int i = 0; i < m1.getnrProduse(); i++){
		cout << "Denumire: " << m1.getvectorDenumiriProduse()[i] << endl;
	}

	cout << endl << endl;
	//Constructorul de copiere
	cout << "--------------------------------APEL CONSTRUCTORUL DE COPIERE--------------------------" << endl << endl;
	Magazin m6(m5);
	cout << "Obiectul macheta m5:" << endl << endl;
	cout << "Denumire magazin:" << m5.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m5.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m5.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m5.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m5.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m5.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m5.getnrProduse(); i++)
	{
		cout << "Pret: " << m5.getvectorPreturiProduse()[i] << endl;
	}
	for (int i = 0; i < m5.getnrProduse(); i++) {
		cout << "Denumire: " << m5.getvectorDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;
	cout << "Obiectul nou creat m6 pe baza machetei m5:" << endl << endl;
	cout << "Denumire magazin:" << m6.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m6.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m6.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m6.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m6.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m6.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m6.getnrProduse(); i++)
	{
		cout << "Pret: " << m6.getvectorPreturiProduse()[i] << endl;
	}
	for (int i = 0; i < m6.getnrProduse(); i++) {
		cout << "Denumire: " << m6.getvectorDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	//Operatorul =
	cout << "--------------------------------APEL OPERATORUL = --------------------------" << endl << endl;
	cout << "Obiectul m4 - inainte de a fi modificat pe baza lui m5:" << endl << endl;
	cout << "Denumire magazin:" << m4.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m4.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m4.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m4.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m4.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m4.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m4.getnrProduse(); i++)
	{
		cout << "Pret: " << m4.getvectorPreturiProduse()[i] << endl;
	}
	for (int i = 0; i < m4.getnrProduse(); i++) {
		cout << "Denumire: " << m4.getvectorDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;
	cout << "Oniectul m5 - obiectul macheta:" << endl << endl;
	cout << "Denumire magazin:" << m5.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m5.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m5.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m5.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m5.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m5.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m5.getnrProduse(); i++)
	{
		cout << "Pret: " << m5.getvectorPreturiProduse()[i] << endl;
	}
	for (int i = 0; i < m5.getnrProduse(); i++) {
		cout << "Denumire: " << m5.getvectorDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;
	m4 = m5;
	cout << "Obiectul m4 - dupa ce a fost modificat pe baza lui m5:" << endl << endl;
	cout << "Denumire magazin:" << m4.getdenumireMagazin() << endl;
	cout << "Nr. Angajati:" << m4.getnrAngajati() << endl;
	cout << "Suprafata Magazin:" << m4.getsuparafataMagazinMP() << endl;
	cout << "Este deschis Non-stop:" << m4.getesteNonStop() << endl;
	cout << "Nume Proprietar:" << m4.getnumeProprietar() << endl;
	cout << "Nr. produse:" << m4.getnrProduse() << endl;

	cout << "Produse:" << endl;
	for (int i = 0; i < m4.getnrProduse(); i++)
	{
		cout << "Pret: " << m4.getvectorPreturiProduse()[i] << endl;
	}
	for (int i = 0; i < m4.getnrProduse(); i++) {
		cout << "Denumire: " << m4.getvectorDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;
	//metode
	cout << "--------------------------------METODE--------------------------" << endl << endl;
	cout << "Preturi magazin m5: ";
	for (int i = 0; i < m5.getnrProduse();i++)
	{
		cout << m5.getvectorPreturiProduse()[i] << ";";
	}
	cout << endl;
	cout << "Pretul minim din magazinul m5 este: " << m5.calculpretMini() << endl << endl;

	//APLICARE DISCOUNT
	//Sa se aplice un discount variabil pentru un produs ales la intamplare din magazin.
	m5.aplicareDiscount(0.20, 2);
	cout << "Preturi magazin m5 dupa aplicarea discount-ului: ";
	for (int i = 0; i < m5.getnrProduse(); i++)
	{
		cout << m5.getvectorPreturiProduse()[i] << " ; ";
	}
	cout << endl << endl;
}