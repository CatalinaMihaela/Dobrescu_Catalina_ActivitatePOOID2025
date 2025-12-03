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
bool esteMaiPuternic(const Calculator& c, const Mouse& m);

//
// ----------------------- CLASA DISPOZITIV ---------------------------------
//

class Dispozitiv
{
private:
    string denumireDispozitiv;
    int numarBaterii;
    char initialaDispozitiv;
    char* brandDispozitiv;
    const int anInfiintare;
    static int numarDispozitiveCreate;

public:

    Dispozitiv() : anInfiintare(2024)
    {
        this->denumireDispozitiv = "Necunoscuta";
        this->numarBaterii = 0;
        this->initialaDispozitiv = '-';

        this->brandDispozitiv = new char[strlen("Anonim") + 1];
        strcpy(this->brandDispozitiv, "Anonim");

        numarDispozitiveCreate++;
    }

    Dispozitiv(string denumireDispozitiv, int numarBaterii)
        : anInfiintare(2024)
    {
        this->denumireDispozitiv = denumireDispozitiv;
        this->numarBaterii = numarBaterii;
        this->initialaDispozitiv = denumireDispozitiv.empty() ? '-' : denumireDispozitiv[0];

        this->brandDispozitiv = new char[strlen("Anonim") + 1];
        strcpy(this->brandDispozitiv, "Anonim");

        numarDispozitiveCreate++;
    }

    Dispozitiv(string denumireDispozitiv, int numarBaterii, char initialaDispozitiv, const char* brand)
        : anInfiintare(2024)
    {
        this->denumireDispozitiv = denumireDispozitiv;
        this->numarBaterii = numarBaterii;
        this->initialaDispozitiv = initialaDispozitiv;

        this->brandDispozitiv = new char[strlen(brand) + 1];
        strcpy(this->brandDispozitiv, brand);

        numarDispozitiveCreate++;
    }

    Dispozitiv(const Dispozitiv& obj) : anInfiintare(obj.anInfiintare)
    {
        this->denumireDispozitiv = obj.denumireDispozitiv;
        this->numarBaterii = obj.numarBaterii;
        this->initialaDispozitiv = obj.initialaDispozitiv;

        this->brandDispozitiv = new char[strlen(obj.brandDispozitiv) + 1];
        strcpy(this->brandDispozitiv, obj.brandDispozitiv);

        numarDispozitiveCreate++;
    }

    ~Dispozitiv()
    {
        if (this->brandDispozitiv != NULL)
            delete[] this->brandDispozitiv;
    }

    // GETTERI
    string getDenumireDispozitiv() { return this->denumireDispozitiv; }
    int getNumarBaterii() { return this->numarBaterii; }
    char getInitialaDispozitiv() { return this->initialaDispozitiv; }
    int getAnInfiintare() { return this->anInfiintare; }
    char* getBrandDispozitiv() { return this->brandDispozitiv; }

    // SETTERI
    void setDenumireDispozitiv(string denNoua) { this->denumireDispozitiv = denNoua; }
    void setNumarBaterii(int nrNou) { this->numarBaterii = nrNou; }
    void setInitialaDispozitiv(char literaNoua) { this->initialaDispozitiv = literaNoua; }

    void setBrandDispozitiv(const char* brandNou)
    {
        delete[] this->brandDispozitiv;
        this->brandDispozitiv = new char[strlen(brandNou) + 1];
        strcpy(this->brandDispozitiv, brandNou);
    }

    // STATIC
    static int getNumarDispozitiveCreate() { return numarDispozitiveCreate; }

    static float calculeazaPretCuTVA(float pretBaza)
    {
        return pretBaza * 1.19f;
    }

    void afisare()
    {
        cout << "Denumire: " << this->denumireDispozitiv << endl;
        cout << "Numar baterii: " << this->numarBaterii << endl;
        cout << "Initiala: " << this->initialaDispozitiv << endl;
        cout << "An infiintare: " << this->anInfiintare << endl;
        cout << "Brand: " << this->brandDispozitiv << endl;
    }

    Dispozitiv& operator=(const Dispozitiv& obj)
    {
        if (this != &obj)
        {
            this->denumireDispozitiv = obj.denumireDispozitiv;
            this->numarBaterii = obj.numarBaterii;
            this->initialaDispozitiv = obj.initialaDispozitiv;

            delete[] this->brandDispozitiv;
            this->brandDispozitiv = new char[strlen(obj.brandDispozitiv) + 1];
            strcpy(this->brandDispozitiv, obj.brandDispozitiv);
        }
        return *this;
    }

    bool operator==(const Dispozitiv& obj) const
    {
        return this->numarBaterii == obj.numarBaterii &&
            strcmp(this->brandDispozitiv, obj.brandDispozitiv) == 0;
    }

    bool operator>(const Dispozitiv& obj) const
    {
        return this->numarBaterii > obj.numarBaterii;
    }

    Dispozitiv& operator++()
    {
        this->numarBaterii++;
        return *this;
    }

    friend bool auAcelasiBrand(const Dispozitiv&, const Dispozitiv&);
};

int Dispozitiv::numarDispozitiveCreate = 0;



//
// ----------------------------- CLASA CALCULATOR ------------------------------
//

class Calculator
{
private:
    string modelCalculator;
    int memorieRAM;
    float pretCalculator;
    char* tipProcesor;
    const int anProductie;

    static int numarCalculatoareCreate;

public:

    Calculator() : anProductie(2024)
    {
        this->modelCalculator = "Necunoscut";
        this->memorieRAM = 8;
        this->pretCalculator = 2000;

        this->tipProcesor = new char[strlen("i3") + 1];
        strcpy(this->tipProcesor, "i3");

        numarCalculatoareCreate++;
    }

    Calculator(string modelCalculator) : anProductie(2024)
    {
        this->modelCalculator = modelCalculator;
        this->memorieRAM = 16;
        this->pretCalculator = 3000;

        this->tipProcesor = new char[strlen("i5") + 1];
        strcpy(this->tipProcesor, "i5");

        numarCalculatoareCreate++;
    }

    Calculator(string modelCalculator, int memorieRAM, float pretCalculator, const char* tipProcesor)
        : anProductie(2024)
    {
        this->modelCalculator = modelCalculator;
        this->memorieRAM = memorieRAM;
        this->pretCalculator = pretCalculator;

        this->tipProcesor = new char[strlen(tipProcesor) + 1];
        strcpy(this->tipProcesor, tipProcesor);

        numarCalculatoareCreate++;
    }

    Calculator(const Calculator& obj) : anProductie(obj.anProductie)
    {
        this->modelCalculator = obj.modelCalculator;
        this->memorieRAM = obj.memorieRAM;
        this->pretCalculator = obj.pretCalculator;

        this->tipProcesor = new char[strlen(obj.tipProcesor) + 1];
        strcpy(this->tipProcesor, obj.tipProcesor);

        numarCalculatoareCreate++;
    }

    ~Calculator()
    {
        delete[] this->tipProcesor;
    }

    string getModelCalculator() { return this->modelCalculator; }
    int getMemorieRAM() { return this->memorieRAM; }
    float getPretCalculator() { return this->pretCalculator; }
    char* getTipProcesor() { return this->tipProcesor; }
    int getAnProductie() { return this->anProductie; }

    void setModelCalculator(string modelNou) { this->modelCalculator = modelNou; }
    void setMemorieRAM(int ramNou) { this->memorieRAM = ramNou; }
    void setPretCalculator(float pretNou) { this->pretCalculator = pretNou; }

    void setTipProcesor(const char* procNou)
    {
        delete[] this->tipProcesor;
        this->tipProcesor = new char[strlen(procNou) + 1];
        strcpy(this->tipProcesor, procNou);
    }

    static int getNumarCalculatoareCreate() { return numarCalculatoareCreate; }

    void afisare()
    {
        cout << "Model calculator: " << this->modelCalculator << endl;
        cout << "RAM: " << this->memorieRAM << endl;
        cout << "Pret: " << this->pretCalculator << endl;
        cout << "Procesor: " << this->tipProcesor << endl;
        cout << "An productie: " << this->anProductie << endl;
    }

    Calculator& operator=(const Calculator& obj)
    {
        if (this != &obj)
        {
            this->modelCalculator = obj.modelCalculator;
            this->memorieRAM = obj.memorieRAM;
            this->pretCalculator = obj.pretCalculator;

            delete[] this->tipProcesor;
            this->tipProcesor = new char[strlen(obj.tipProcesor) + 1];
            strcpy(this->tipProcesor, obj.tipProcesor);
        }
        return *this;
    }

    float operator+(const Calculator& obj) const
    {
        return this->pretCalculator + obj.pretCalculator;
    }

    bool operator>(const Calculator& obj) const
    {
        return this->pretCalculator > obj.pretCalculator;
    }

    operator float() const
    {
        return this->pretCalculator;
    }

    friend float pretTotalCalculatoare(const Calculator&, const Calculator&);
    friend bool esteMaiPuternic(const Calculator&, const Mouse&);
};

int Calculator::numarCalculatoareCreate = 0;




//
// ----------------------------- CLASA MOUSE ------------------------------
//

class Mouse
{
private:
    string tipMouse;
    int valoareDPI;
    bool esteWireless;
    char* culoareMouse;
    const int aniGarantie;

    static int numarMouseCreate;

public:

    Mouse() : aniGarantie(2)
    {
        this->tipMouse = "Office";
        this->valoareDPI = 800;
        this->esteWireless = false;

        this->culoareMouse = new char[strlen("Negru") + 1];
        strcpy(this->culoareMouse, "Negru");

        numarMouseCreate++;
    }

    Mouse(string tipMouse, int valoareDPI) : aniGarantie(2)
    {
        this->tipMouse = tipMouse;
        this->valoareDPI = valoareDPI;
        this->esteWireless = false;

        this->culoareMouse = new char[strlen("Gri") + 1];
        strcpy(this->culoareMouse, "Gri");

        numarMouseCreate++;
    }

    Mouse(string tipMouse, int valoareDPI, bool esteWireless, const char* culoare)
        : aniGarantie(2)
    {
        this->tipMouse = tipMouse;
        this->valoareDPI = valoareDPI;
        this->esteWireless = esteWireless;

        this->culoareMouse = new char[strlen(culoare) + 1];
        strcpy(this->culoareMouse, culoare);

        numarMouseCreate++;
    }

    Mouse(const Mouse& obj) : aniGarantie(obj.aniGarantie)
    {
        this->tipMouse = obj.tipMouse;
        this->valoareDPI = obj.valoareDPI;
        this->esteWireless = obj.esteWireless;

        this->culoareMouse = new char[strlen(obj.culoareMouse) + 1];
        strcpy(this->culoareMouse, obj.culoareMouse);

        numarMouseCreate++;
    }

    ~Mouse()
    {
        delete[] this->culoareMouse;
    }

    string getTipMouse() { return this->tipMouse; }
    int getValoareDPI() { return this->valoareDPI; }
    bool getEsteWireless() { return this->esteWireless; }
    char* getCuloareMouse() { return this->culoareMouse; }
    int getAniGarantie() { return this->aniGarantie; }

    void setTipMouse(string tipNou) { this->tipMouse = tipNou; }
    void setValoareDPI(int dpiNou) { this->valoareDPI = dpiNou; }
    void setEsteWireless(bool e) { this->esteWireless = e; }

    void setCuloareMouse(const char* culoareNoua)
    {
        delete[] this->culoareMouse;
        this->culoareMouse = new char[strlen(culoareNoua) + 1];
        strcpy(this->culoareMouse, culoareNoua);
    }

    static int getNumarMouseCreate() { return numarMouseCreate; }

    void afisare()
    {
        cout << "Tip mouse: " << this->tipMouse << endl;
        cout << "DPI: " << this->valoareDPI << endl;
        cout << "Wireless: " << (this->esteWireless ? "DA" : "NU") << endl;
        cout << "Culoare: " << this->culoareMouse << endl;
        cout << "Ani garantie: " << this->aniGarantie << endl;
    }

    Mouse& operator=(const Mouse& obj)
    {
        if (this != &obj)
        {
            this->tipMouse = obj.tipMouse;
            this->valoareDPI = obj.valoareDPI;
            this->esteWireless = obj.esteWireless;

            delete[] this->culoareMouse;
            this->culoareMouse = new char[strlen(obj.culoareMouse) + 1];
            strcpy(this->culoareMouse, obj.culoareMouse);
        }
        return *this;
    }

    bool operator!() const
    {
        return !this->esteWireless;
    }

    Mouse& operator++()
    {
        this->valoareDPI += 200;
        return *this;
    }

    bool operator==(const Mouse& obj) const
    {
        return this->valoareDPI == obj.valoareDPI &&
            strcmp(this->culoareMouse, obj.culoareMouse) == 0;
    }

    friend bool esteMaiPuternic(const Calculator&, const Mouse&);
};

int Mouse::numarMouseCreate = 0;



//
// ----------------------------- FUNCTII FRIEND ------------------------------
//

bool auAcelasiBrand(const Dispozitiv& d1, const Dispozitiv& d2)
{
    return strcmp(d1.brandDispozitiv, d2.brandDispozitiv) == 0;
}

float pretTotalCalculatoare(const Calculator& c1, const Calculator& c2)
{
    return c1.pretCalculator + c2.pretCalculator;
}

bool esteMaiPuternic(const Calculator& c, const Mouse& m)
{
    return c.pretCalculator > m.valoareDPI;
}





class ServiceIT
{
private:
    char* numeService;
    Calculator calculator; // HAS-A 
    int nrAngajati;

public:

    // Constructor fără parametri
    ServiceIT() : calculator()
    {
        this->numeService = new char[strlen("ServiceIT") + 1];
        strcpy(this->numeService, "ServiceIT");

        this->nrAngajati = 0;
    }

    // Constructor cu parametri
    ServiceIT(const char* nume, const Calculator& c, int nrAngajati)
        : calculator(c)
    {
        this->numeService = new char[strlen(nume) + 1];
        strcpy(this->numeService, nume);

        this->nrAngajati = nrAngajati;
    }

    // Constructor de copiere
    ServiceIT(const ServiceIT& obj) : calculator(obj.calculator)
    {
        this->numeService = new char[strlen(obj.numeService) + 1];
        strcpy(this->numeService, obj.numeService);

        this->nrAngajati = obj.nrAngajati;
    }

    // Destructor
    ~ServiceIT()
    {
        delete[] this->numeService;
    }

    // GETTERI
    char* getNumeService() { return this->numeService; }
    Calculator getCalculator() { return this->calculator; }
    int getNrAngajati() { return this->nrAngajati; }

    // SETTERI
    void setNumeService(const char* numeNou)
    {
        delete[] this->numeService;
        this->numeService = new char[strlen(numeNou) + 1];
        strcpy(this->numeService, numeNou);
    }

    void setCalculator(const Calculator& c)
    {
        this->calculator = c;
    }

    void setNrAngajati(int nr)
    {
        this->nrAngajati = nr;
    }

    // Afișare
    void afisare()
    {
        cout << "\n===== SERVICE IT =====\n";
        cout << "Nume service: " << this->numeService << endl;
        cout << "Nr angajati: " << this->nrAngajati << endl;
        cout << "--- Calculator folosit in service ---\n";
        this->calculator.afisare();
    }

    
    bool operator==(const ServiceIT& obj) const
    {
        return strcmp(this->numeService, obj.numeService) == 0 &&
            this->nrAngajati == obj.nrAngajati;
    }

    bool operator<(const ServiceIT& obj) const
    {
        return this->nrAngajati < obj.nrAngajati;
    }

    ServiceIT& operator++()
    {
        this->nrAngajati++;
        return *this;
    }
};



void main()
{
    cout << "------ DISPOZITIVE -----\n";

    Dispozitiv dispozitiv1;
    Dispozitiv dispozitiv2("Telefon", 1);
    Dispozitiv dispozitiv3("Tableta", 1, 'T', "Samsung");
    Dispozitiv dispozitiv4 = dispozitiv3;

    ++dispozitiv4;
    cout << "dispozitiv3 == dispozitiv4 ? " << (dispozitiv3 == dispozitiv4 ? "DA" : "NU") << endl;
    cout << "dispozitiv4 > dispozitiv2 ? " << (dispozitiv4 > dispozitiv2 ? "DA" : "NU") << endl;

    dispozitiv1 = dispozitiv3;

    cout << "\n===== CALCULATOARE =====\n";

    Calculator calculator1;
    Calculator calculator2("ASUS");
    Calculator calculator3("PC Gaming", 32, 5500, "Ryzen 7");
    Calculator calculator4 = calculator3;

    cout << "calculator3 + calculator4 = " << (calculator3 + calculator4) << endl;
    cout << "calculator3 > calculator2 ? " << (calculator3 > calculator2 ? "DA" : "NU") << endl;
    cout << "Pret calculator3 ca float: " << float(calculator3) << endl;

    calculator1 = calculator3;

    cout << "\n===== MOUSE =====\n";

    Mouse mouse1;
    Mouse mouse2("Office", 1200);
    Mouse mouse3("Gaming", 6400, true, "RGB");
    Mouse mouse4 = mouse3;

    ++mouse4;
    cout << "mouse3 == mouse4 ? " << (mouse3 == mouse4 ? "DA" : "NU") << endl;
    cout << "!mouse1 ? " << (!mouse1 ? "NU este wireless" : "ESTE wireless") << endl;

    mouse2 = mouse4;

    cout << "\n===== FUNCTII PRIETENE =====\n";

    cout << "esteMaiPuternic(calculator3, mouse3) → "
        << (esteMaiPuternic(calculator3, mouse3) ? "Calculator > Mouse" : "Mouse > Calculator")
        << endl;

    cout << "Pret total calculator2 + calculator3 = "
        << pretTotalCalculatoare(calculator2, calculator3) << endl;

    cout << "\n===== END =====\n";


  

    cout << "\n\n===== VECTOR DISPOZITIVE =====\n";

    int n;
    cout << "Introduceti numarul de dispozitive: ";
    cin >> n;

    Dispozitiv* vecD = new Dispozitiv[n];

    for (int i = 0; i < n; i++)
    {
        string nume;
        int baterii;
        char initiala;
        char brand[50];

        cout << "\nDispozitiv " << i + 1 << ":\n";
        cout << "Denumire: "; cin >> nume;
        cout << "Baterii: "; cin >> baterii;
        cout << "Initiala: "; cin >> initiala;
        cout << "Brand: "; cin >> brand;

        vecD[i] = Dispozitiv(nume, baterii, initiala, brand);
    }

    cout << "\n--- AFISARE VECTOR DISPOZITIVE ---\n";
    for (int i = 0; i < n; i++)
        vecD[i].afisare();


    cout << "\n\n===== VECTOR CALCULATOARE =====\n";

    int m;
    cout << "Introduceti numarul de calculatoare: ";
    cin >> m;

    Calculator* vecC = new Calculator[m];

    for (int i = 0; i < m; i++)
    {
        string model;
        int ram;
        float pret;
        char procesor[50];

        cout << "\nCalculator " << i + 1 << ":\n";
        cout << "Model: "; cin >> model;
        cout << "RAM: "; cin >> ram;
        cout << "Pret: "; cin >> pret;
        cout << "Procesor: "; cin >> procesor;

        vecC[i] = Calculator(model, ram, pret, procesor);
    }

    cout << "\n--- AFISARE VECTOR CALCULATOARE ---\n";
    for (int i = 0; i < m; i++)
        vecC[i].afisare();


    cout << "\n\n===== VECTOR MOUSE =====\n";

    int k;
    cout << "Introduceti numarul de mouse-uri: ";
    cin >> k;

    Mouse* vecM = new Mouse[k];

    for (int i = 0; i < k; i++)
    {
        string tip;
        int dpi;
        bool wireless;
        char culoare[50];

        cout << "\nMouse " << i + 1 << ":\n";
        cout << "Tip: "; cin >> tip;
        cout << "DPI: "; cin >> dpi;
        cout << "Wireless (0/1): "; cin >> wireless;
        cout << "Culoare: "; cin >> culoare;

        vecM[i] = Mouse(tip, dpi, wireless, culoare);
    }

    cout << "\n--- AFISARE VECTOR MOUSE ---\n";
    for (int i = 0; i < k; i++)
        vecM[i].afisare();



    cout << "\n\n===== MATRICE CALCULATOARE =====\n";

    int R, Cc;
    cout << "Introduceti numarul de linii: ";
    cin >> R;
    cout << "Introduceti numarul de coloane: ";
    cin >> Cc;

    Calculator** matrice = new Calculator * [R];

    for (int i = 0; i < R; i++)
        matrice[i] = new Calculator[Cc];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < Cc; j++)
        {
            string model;
            int ram;
            float pret;
            char proc[50];

            cout << "\nElement [" << i << "][" << j << "]:\n";
            cout << "Model: "; cin >> model;
            cout << "RAM: "; cin >> ram;
            cout << "Pret: "; cin >> pret;
            cout << "Procesor: "; cin >> proc;

            matrice[i][j] = Calculator(model, ram, pret, proc);
        }
    }

    cout << "\n--- AFISARE MATRICE ---\n";

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < Cc; j++)
        {
            matrice[i][j].afisare();
            cout << endl;
        }
        cout << endl;
    }




    cout << "\n\n===== TESTARE CLASA SERVICEIT =====\n";

    ServiceIT s1; // default
    ServiceIT s2("TechRepair", calculator3, 5); // parametri
    ServiceIT s3 = s2; // copiere

    cout << "\n--- ServiceIT s1 ---\n";
    s1.afisare();

    cout << "\n--- ServiceIT s2 ---\n";
    s2.afisare();

    cout << "\n--- ServiceIT s3 (copie) ---\n";
    s3.afisare();

    cout << "\n--- Test operatori ---\n";
    cout << "s2 == s3 ? " << (s2 == s3 ? "DA" : "NU") << endl;
    cout << "s1 < s2 ? " << (s1 < s2 ? "DA" : "NU") << endl;

    ++s1;
    cout << "Dupa ++s1, nr angajati = " << s1.getNrAngajati() << endl;


    // Curățarea memoriei
    delete[] vecD;
    delete[] vecC;
    delete[] vecM;

    for (int i = 0; i < R; i++)
        delete[] matrice[i];

    delete[] matrice;
}
