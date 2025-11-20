#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Dispozitiv;
class Calculator;
class Mouse;

bool auAcelasiBrand(const Dispozitiv& d1, const Dispozitiv& d2);
float pretTotalCalculatoare(const Calculator& c1, const Calculator& c2);

//--------------------CLASA DISPOZITIV---------------------

class Dispozitiv
{
private:
    string denumireDispozitiv;
    int nrBaterii;
    char initialaDispozitiv;
    char* Brand;
    const int anInfiintare;
    static int nrDispozitiveCreate;

public:
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

    // Constructor de copiere
    Dispozitiv(const Dispozitiv& d) : anInfiintare(d.anInfiintare)
    {
        this->denumireDispozitiv = d.denumireDispozitiv;
        this->nrBaterii = d.nrBaterii;
        this->initialaDispozitiv = d.initialaDispozitiv;
        this->Brand = new char[strlen(d.Brand) + 1];
        strcpy(this->Brand, d.Brand);

        nrDispozitiveCreate++;
    }

    // Destructor 
    ~Dispozitiv()
    {
        delete[] this->Brand;
    }

    // GETTERI
    string getDenumireDispozitiv() 
    { return this->denumireDispozitiv; }
    int getNrBaterii() 
    { return this->nrBaterii; }
    char getInitialaDispozitiv() 
    { return this->initialaDispozitiv; }
    int getAnInfiintare() 
    { return this->anInfiintare; }
    char* getBrand() 
    { return this->Brand; }

    // SETTERI
    void setDenumireDispozitiv(string denNoua) 
    { this->denumireDispozitiv = denNoua; }
    void setNrBaterii(int nrNou) 
    { this->nrBaterii = nrNou; }
    void setInitialaDispozitiv(char literaNoua)
    { this->initialaDispozitiv = literaNoua; }
    void setBrand(const char* brandNou)
    {
        delete[] this->Brand;
        this->Brand = new char[strlen(brandNou) + 1];
        strcpy(this->Brand, brandNou);
    }

    // Functii statice pentru atributul static
    static int getNrDispozitiveCreate() { return nrDispozitiveCreate; }
    static void setNrDispozitiveCreate(int val) { nrDispozitiveCreate = val; }

    // Functie de afisare (foloseste getteri)
    void afisare()
    {
        cout << "Denumire dispozitiv: " << getDenumireDispozitiv() << endl;
        cout << "Nr baterii: " << getNrBaterii() << endl;
        cout << "Initiala dispozitiv: " << getInitialaDispozitiv() << endl;
        cout << "An infiintare: " << getAnInfiintare() << endl;
        cout << "Brand: " << getBrand() << endl;
    }

    // FUNCTIE STATICA - exemplu: calculeaza un pret cu TVA 19%
    static float calculeazaPretCuTVA(float pretBaza)
    {
        return pretBaza * 1.19f;
    }

    // Functie globala prietena
    friend bool auAcelasiBrand(const Dispozitiv& d1, const Dispozitiv& d2);
};

// Initializare atribut static
int Dispozitiv::nrDispozitiveCreate = 0;


// ------- CLASA CALCULATOR ------------

class Calculator
{
private:
   
    string model;
    int RAM;
    float pret;
    char* procesor;
    const int anProductie;
    static int nrCalculatoareCreate;

public:
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

    // Constructor de copiere
    Calculator(const Calculator& c) : anProductie(c.anProductie)
    {
        this->model = c.model;
        this->RAM = c.RAM;
        this->pret = c.pret;
        this->procesor = new char[strlen(c.procesor) + 1];
        strcpy(this->procesor, c.procesor);

        nrCalculatoareCreate++;
    }

    ~Calculator()
    {
        delete[] this->procesor;
    }

    // GETTERI
    string getModel() { return this->model; }
    int getRAM() { return this->RAM; }
    float getPret() { return this->pret; }
    char* getProcesor() { return this->procesor; }
    int getAnProductie() { return this->anProductie; }

    // SETTERI
    void setModel(string m) { this->model = m; }
    void setRAM(int r) { this->RAM = r; }
    void setPret(float p) { this->pret = p; }
    void setProcesor(const char* p)
    {
        delete[] this->procesor;
        this->procesor = new char[strlen(p) + 1];
        strcpy(this->procesor, p);
    }

    // FUNCTII STATICE – acces la atributul static
    static int getNrCalculatoareCreate() { return nrCalculatoareCreate; }
    static void setNrCalculatoareCreate(int val) { nrCalculatoareCreate = val; }

    void afisare()
    {
        cout << "Model calculator: " << getModel() << endl;
        cout << "RAM: " << getRAM() << " GB" << endl;
        cout << "Pret: " << getPret() << " lei" << endl;
        cout << "Procesor: " << getProcesor() << endl;
        cout << "An productie: " << getAnProductie() << endl;
    }

    // FUNCTIE STATICA – reducere procentuala
    static float aplicaReducere(float pretInitial, float procent)
    {
        return pretInitial * (1 - procent / 100.0f);
    }

    // Functie globala prietena
    friend float pretTotalCalculatoare(const Calculator& c1, const Calculator& c2);
};

int Calculator::nrCalculatoareCreate = 0;


// ---------------------- CLASA MOUSE ----------------

class Mouse
{
private:
  
    string tipMouse;
    int dpi;
    bool wireless;
    char* culoare;
    const int aniGarantie;
    static int nrMouseCreate;

public:
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

    // Constructor de copiere
    Mouse(const Mouse& m) : aniGarantie(m.aniGarantie)
    {
        this->tipMouse = m.tipMouse;
        this->dpi = m.dpi;
        this->wireless = m.wireless;
        this->culoare = new char[strlen(m.culoare) + 1];
        strcpy(this->culoare, m.culoare);

        nrMouseCreate++;
    }

    ~Mouse()
    {
        delete[] this->culoare;
    }

    // GETTERI
    string getTipMouse() { return this->tipMouse; }
    int getDpi() { return this->dpi; }
    bool getWireless() { return this->wireless; }
    char* getCuloare() { return this->culoare; }
    int getAniGarantie() { return this->aniGarantie; }

    // SETTERI
    void setTipMouse(string t) { this->tipMouse = t; }
    void setDpi(int d) { this->dpi = d; }
    void setWireless(bool w) { this->wireless = w; }
    void setCuloare(const char* c)
    {
        delete[] this->culoare;
        this->culoare = new char[strlen(c) + 1];
        strcpy(this->culoare, c);
    }

    // FUNCTII STATICE – acces la atributul static
    static int getNrMouseCreate() { return nrMouseCreate; }
    static void setNrMouseCreate(int val) { nrMouseCreate = val; }

    void afisare()
    {
        cout << "Tip mouse: " << getTipMouse() << endl;
        cout << "DPI: " << getDpi() << endl;
        cout << "Wireless: " << (getWireless() ? "Da" : "Nu") << endl;
        cout << "Culoare: " << getCuloare() << endl;
        cout << "Ani garantie: " << getAniGarantie() << endl;
    }

    // FUNCTIE STATICA – verifica daca un DPI este de gaming
    static bool esteGaming(int dpi)
    {
        return dpi >= 4000;
    }
};

int Mouse::nrMouseCreate = 0;


// ====================== FUNCTII GLOBALE FRIEND ======================

// 1) verifică dacă două dispozitive au același brand
bool auAcelasiBrand(const Dispozitiv& d1, const Dispozitiv& d2)
{
    return strcmp(d1.Brand, d2.Brand) == 0;
}

// 2) calculează prețul total a două calculatoare
float pretTotalCalculatoare(const Calculator& c1, const Calculator& c2)
{
    return c1.pret + c2.pret;
}



// ====================== FUNCTIA MAIN ======================

void main()
{
    cout << "====== DISPOZITIVE ======" << endl;

    Dispozitiv d1;
    Dispozitiv d2("Telefon", 1);
    Dispozitiv d3("Tableta", 1, 'T', "Samsung");
    Dispozitiv d4 = d3;  

    d1.afisare();
    cout << endl;
    d2.afisare();
    cout << endl;
    d3.afisare();
    cout << endl;
    d4.afisare();
    cout << endl;

    // testam setterii + geterii
    d1.setDenumireDispozitiv("Smartwatch");
    d1.setNrBaterii(1);
    d1.setInitialaDispozitiv('S');
    d1.setBrand("Garmin");

    cout << "Dupa seteri, d1: "
        << d1.getDenumireDispozitiv() << ", "
        << d1.getNrBaterii() << ", "
        << d1.getInitialaDispozitiv() << ", "
        << d1.getAnInfiintare() << ", "
        << d1.getBrand() << endl << endl;

    cout << "Numar dispozitive create (static): "
        << Dispozitiv::getNrDispozitiveCreate() << endl;

    cout << "Pret telefon 3000 lei cu TVA: "
        << Dispozitiv::calculeazaPretCuTVA(3000) << " lei" << endl;

    cout << "d3 si d4 au acelasi brand? "
        << (auAcelasiBrand(d3, d4) ? "DA" : "NU") << endl << endl;


    cout << "====== CALCULATOARE ======" << endl;

    Calculator c1;
    Calculator c2("Laptop ASUS");
    Calculator c3("PC Gaming", 32, 5500.0f, "Ryzen 7");
    Calculator c4 = c3;  

    c1.afisare();
    cout << endl;
    c2.afisare();
    cout << endl;
    c3.afisare();
    cout << endl;
    c4.afisare();
    cout << endl;

    // test seteri + geteri
    c1.setModel("Laptop Dell");
    c1.setRAM(16);
    c1.setPret(3800);
    c1.setProcesor("i7");

    cout << "Dupa seteri, c1: "
        << c1.getModel() << ", "
        << c1.getRAM() << ", "
        << c1.getPret() << ", "
        << c1.getProcesor() << ", "
        << c1.getAnProductie() << endl << endl;

    cout << "Numar calculatoare create (static): "
        << Calculator::getNrCalculatoareCreate() << endl;

    cout << "Pret PC Gaming dupa reducere 10%: "
        << Calculator::aplicaReducere(c3.getPret(), 10) << " lei" << endl;

    cout << "Pret total c2 + c3 (functie friend): "
        << pretTotalCalculatoare(c2, c3) << " lei" << endl << endl;


    cout << "====== MOUSE-URI ======" << endl;

    Mouse m1;
    Mouse m2("Office", 1200);
    Mouse m3("Gaming", 6400, true, "RGB");
    Mouse m4 = m3;   

    m1.afisare();
    cout << endl;
    m2.afisare();
    cout << endl;
    m3.afisare();
    cout << endl;
    m4.afisare();
    cout << endl;

    // test seteri + geteri
    m1.setTipMouse("Ergonomic");
    m1.setDpi(2400);
    m1.setWireless(true);
    m1.setCuloare("Albastru");

    cout << "Dupa seteri, m1: "
        << m1.getTipMouse() << ", "
        << m1.getDpi() << ", "
        << (m1.getWireless() ? "Wireless" : "Cu fir") << ", "
        << m1.getCuloare() << ", "
        << m1.getAniGarantie() << endl << endl;

    cout << "Numar mouse-uri create (static): "
        << Mouse::getNrMouseCreate() << endl;

    cout << "Mouse m3 este gaming? "
        << (Mouse::esteGaming(m3.getDpi()) ? "DA" : "NU") << endl;

    
}
