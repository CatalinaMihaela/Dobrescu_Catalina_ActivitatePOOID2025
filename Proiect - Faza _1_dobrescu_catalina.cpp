#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//--------------------CLASA DISPOZITIV---------------------

class Dispozitiv
{
public:
    // Atribute normale
    string denumireDispozitiv;
    int nrBaterii;
    char initialaDispozitiv;
    char* Brand;

    // Atribut constant
    const int anInfiintare;

    // Atribut static
    static int nrDispozitiveCreate;

    // Constructor fara parametri
    Dispozitiv() : anInfiintare(2024)
    {
        this->denumireDispozitiv = "Necunoscuta";
        this->nrBaterii = 0;
        this->initialaDispozitiv = '-';
        this->Brand = new char[strlen("Anonim") + 1];
        strcpy(this->Brand, "Anonim");

        nrDispozitiveCreate++;
    }

    // Constructor cu 2 parametri
    Dispozitiv(string denumireDispozitiv, int nrBaterii) : anInfiintare(2024)
    {
        this->denumireDispozitiv = denumireDispozitiv;
        this->nrBaterii = nrBaterii;
        this->initialaDispozitiv = denumireDispozitiv.empty() ? '-' : denumireDispozitiv[0];
        this->Brand = new char[strlen("Anonim") + 1];
        strcpy(this->Brand, "Anonim");

        nrDispozitiveCreate++;
    }

    // Constructor cu toti parametrii
    Dispozitiv(string denumireDispozitiv, int nrBaterii, char initialaDispozitiv, const char* Brand)
        : anInfiintare(2024)
    {
        this->denumireDispozitiv = denumireDispozitiv;
        this->nrBaterii = nrBaterii;
        this->initialaDispozitiv = initialaDispozitiv;
        this->Brand = new char[strlen(Brand) + 1];
        strcpy(this->Brand, Brand);

        nrDispozitiveCreate++;
    }

    // Destructor 
    ~Dispozitiv()
    {
        delete[] this->Brand;
    }

    // GETTERI
    string getDenumireDispozitiv() { return this->denumireDispozitiv; }
    int getNrBaterii() { return this->nrBaterii; }
    char getInitialaDispozitiv() { return this->initialaDispozitiv; }
    int getAnInfiintare() { return this->anInfiintare; }
    char* getBrand() { return this->Brand; }

    // SETTERI
    void setDenumireDispozitiv(string denNoua) { this->denumireDispozitiv = denNoua; }
    void setNrBaterii(int nrNou) { this->nrBaterii = nrNou; }
    void setInitialaDispozitiv(char literaNoua) { this->initialaDispozitiv = literaNoua; }
    void setBrand(const char* brandNou)
    {
        delete[] this->Brand;
        this->Brand = new char[strlen(brandNou) + 1];
        strcpy(this->Brand, brandNou);
    }

    // Functie de afisare
    void afisare()
    {
        cout << "Denumire dispozitiv: " << denumireDispozitiv << endl;
        cout << "Nr baterii: " << nrBaterii << endl;
        cout << "Initiala dispozitiv: " << initialaDispozitiv << endl;
        cout << "An infiintare: " << anInfiintare << endl;
        cout << "Brand: " << Brand << endl;
    }

    // FUNCTIE STATICA - exemplu: calculeaza un pret cu TVA 19%
    static float calculeazaPretCuTVA(float pretBaza)
    {
        return pretBaza * 1.19f;
    }
};

// Initializare atribut static
int Dispozitiv::nrDispozitiveCreate = 0;


// ------- CLASA CALCULATOR ------------
class Calculator
{
public:
    // Atribute normale
    string model;
    int RAM;
    float pret;
    char* procesor;

    // Atribut constant
    const int anProductie;

    // Atribut static
    static int nrCalculatoareCreate;

    // Constructor fara parametri
    Calculator() : anProductie(2024)
    {
        this->model = "Necunoscut";
        this->RAM = 8;
        this->pret = 2000.0f;
        this->procesor = new char[strlen("i3") + 1];
        strcpy(this->procesor, "i3");

        nrCalculatoareCreate++;
    }

    // Constructor cu 1 parametru
    Calculator(string model) : anProductie(2024)
    {
        this->model = model;
        this->RAM = 16;
        this->pret = 3000.0f;
        this->procesor = new char[strlen("i5") + 1];
        strcpy(this->procesor, "i5");

        nrCalculatoareCreate++;
    }

    // Constructor cu toti parametrii
    Calculator(string model, int RAM, float pret, const char* procesor)
        : anProductie(2024)
    {
        this->model = model;
        this->RAM = RAM;
        this->pret = pret;
        this->procesor = new char[strlen(procesor) + 1];
        strcpy(this->procesor, procesor);

        nrCalculatoareCreate++;
    }

    ~Calculator()
    {
        delete[] this->procesor;
    }

    void afisare()
    {
        cout << "Model calculator: " << model << endl;
        cout << "RAM: " << RAM << " GB" << endl;
        cout << "Pret: " << pret << " lei" << endl;
        cout << "Procesor: " << procesor << endl;
        cout << "An productie: " << anProductie << endl;
    }

    // FUNCTIE STATICA – reducere procentuala
    static float aplicaReducere(float pretInitial, float procent)
    {
        return pretInitial * (1 - procent / 100.0f);
    }
};

int Calculator::nrCalculatoareCreate = 0;


// ---------------------- CLASA MOUSE ----------------

class Mouse
{
public:
    // Atribute normale
    string tipMouse;
    int dpi;
    bool wireless;
    char* culoare;

    // Atribut constant
    const int aniGarantie;

    // Atribut static
    static int nrMouseCreate;

    // Constructor fara parametri
    Mouse() : aniGarantie(2)
    {
        this->tipMouse = "Office";
        this->dpi = 800;
        this->wireless = false;
        this->culoare = new char[strlen("Negru") + 1];
        strcpy(this->culoare, "Negru");

        nrMouseCreate++;
    }

    // Constructor cu 2 parametri
    Mouse(string tipMouse, int dpi) : aniGarantie(2)
    {
        this->tipMouse = tipMouse;
        this->dpi = dpi;
        this->wireless = false;
        this->culoare = new char[strlen("Gri") + 1];
        strcpy(this->culoare, "Gri");

        nrMouseCreate++;
    }

    // Constructor cu toti parametrii
    Mouse(string tipMouse, int dpi, bool wireless, const char* culoare)
        : aniGarantie(2)
    {
        this->tipMouse = tipMouse;
        this->dpi = dpi;
        this->wireless = wireless;
        this->culoare = new char[strlen(culoare) + 1];
        strcpy(this->culoare, culoare);

        nrMouseCreate++;
    }

    ~Mouse()
    {
        delete[] this->culoare;
    }

    void afisare()
    {
        cout << "Tip mouse: " << tipMouse << endl;
        cout << "DPI: " << dpi << endl;
        cout << "Wireless: " << (wireless ? "Da" : "Nu") << endl;
        cout << "Culoare: " << culoare << endl;
        cout << "Ani garantie: " << aniGarantie << endl;
    }

    // FUNCTIE STATICA – verifica daca un DPI este de gaming
    static bool esteGaming(int dpi)
    {
        return dpi >= 4000;
    }
};

int Mouse::nrMouseCreate = 0;


// ====================== FUNCTIA MAIN ======================

int main()
{
    cout << "====== DISPOZITIVE ======" << endl;
   
    Dispozitiv d1;                                            
    Dispozitiv d2("Telefon", 1);                              
    Dispozitiv d3("Tableta", 1, 'T', "Samsung");              

    d1.afisare();
    cout << endl;
    d2.afisare();
    cout << endl;
    d3.afisare();
    cout << endl;

    cout << "Numar dispozitive create: " << Dispozitiv::nrDispozitiveCreate << endl;
    cout << "Pret telefon 3000 lei cu TVA: "
        << Dispozitiv::calculeazaPretCuTVA(3000) << " lei" << endl << endl;


    cout << "====== CALCULATOARE ======" << endl;
    
    Calculator c1;                                
    Calculator c2("Laptop ASUS");                
    Calculator c3("PC Gaming", 32, 5500.0f, "Ryzen 7"); 

    c1.afisare();
    cout << endl;
    c2.afisare();
    cout << endl;
    c3.afisare();
    cout << endl;

    cout << "Numar calculatoare create: " << Calculator::nrCalculatoareCreate << endl;
    cout << "Pret PC Gaming dupa reducere 10%: "
        << Calculator::aplicaReducere(c3.pret, 10) << " lei" << endl << endl;


    cout << "====== MOUSE-URI ======" << endl;
    
    Mouse m1;                                     
    Mouse m2("Office", 1200);                     
    Mouse m3("Gaming", 6400, true, "RGB");        

    m1.afisare();
    cout << endl;
    m2.afisare();
    cout << endl;
    m3.afisare();
    cout << endl;

    cout << "Numar mouse-uri create: " << Mouse::nrMouseCreate << endl;
    cout << "Mouse m3 este gaming? "
        << (Mouse::esteGaming(m3.dpi) ? "DA" : "NU") << endl;

    return 0;
}
