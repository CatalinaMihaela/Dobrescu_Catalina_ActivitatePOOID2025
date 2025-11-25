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

    // Constructor fara parametri
    Dispozitiv() : anInfiintare(2024)
    {
        this->denumireDispozitiv = "Necunoscuta";
        this->numarBaterii = 0;
        this->initialaDispozitiv = '-';

        this->brandDispozitiv = new char[strlen("Anonim") + 1];
        strcpy(this->brandDispozitiv, "Anonim");

        numarDispozitiveCreate++;
    }

    // Constructor cu 2 parametri
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

    // Constructor cu toti parametrii
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

    // Constructor de copiere
    Dispozitiv(const Dispozitiv& obj) : anInfiintare(obj.anInfiintare)
    {
        this->denumireDispozitiv = obj.denumireDispozitiv;
        this->numarBaterii = obj.numarBaterii;
        this->initialaDispozitiv = obj.initialaDispozitiv;

        this->brandDispozitiv = new char[strlen(obj.brandDispozitiv) + 1];
        strcpy(this->brandDispozitiv, obj.brandDispozitiv);

        numarDispozitiveCreate++;
    }

    // Destructor
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
    void setDenumireDispozitiv(string denumireNoua) { this->denumireDispozitiv = denumireNoua; }
    void setNumarBaterii(int numarNou) { this->numarBaterii = numarNou; }
    void setInitialaDispozitiv(char initialaNoua) { this->initialaDispozitiv = initialaNoua; }

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

    // AFISARE
    void afisare()
    {
        cout << "Denumire: " << this->denumireDispozitiv << endl;
        cout << "Numar baterii: " << this->numarBaterii << endl;
        cout << "Initiala: " << this->initialaDispozitiv << endl;
        cout << "An infiintare: " << this->anInfiintare << endl;
        cout << "Brand: " << this->brandDispozitiv << endl;
    }

    // OPERATORI
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
// CLASA CALCULATOR 
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

    // Constructor de copiere
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
        if (this->tipProcesor != NULL)
            delete[] this->tipProcesor;
    }

    // GETTERI
    string getModelCalculator() { return this->modelCalculator; }
    int getMemorieRAM() { return this->memorieRAM; }
    float getPretCalculator() { return this->pretCalculator; }
    char* getTipProcesor() { return this->tipProcesor; }
    int getAnProductie() { return this->anProductie; }

    // SETTERI
    void setModelCalculator(string modelNou) { this->modelCalculator = modelNou; }
    void setMemorieRAM(int ramNou) { this->memorieRAM = ramNou; }
    void setPretCalculator(float pretNou) { this->pretCalculator = pretNou; }

    void setTipProcesor(const char* procesorNou)
    {
        delete[] this->tipProcesor;
        this->tipProcesor = new char[strlen(procesorNou) + 1];
        strcpy(this->tipProcesor, procesorNou);
    }

    // STATIC
    static int getNumarCalculatoareCreate() { return numarCalculatoareCreate; }

    // AFISARE
    void afisare()
    {
        cout << "Model calculator: " << this->modelCalculator << endl;
        cout << "RAM: " << this->memorieRAM << endl;
        cout << "Pret: " << this->pretCalculator << endl;
        cout << "Procesor: " << this->tipProcesor << endl;
        cout << "An productie: " << this->anProductie << endl;
    }

    // OPERATORI

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
// CLASA MOUSE 
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

    // Constructor de copiere
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

    // GETTERI
    string getTipMouse() { return this->tipMouse; }
    int getValoareDPI() { return this->valoareDPI; }
    bool getEsteWireless() { return this->esteWireless; }
    char* getCuloareMouse() { return this->culoareMouse; }
    int getAniGarantie() { return this->aniGarantie; }

    // SETTERI
    void setTipMouse(string tipNou) { this->tipMouse = tipNou; }
    void setValoareDPI(int dpiNou) { this->valoareDPI = dpiNou; }
    void setEsteWireless(bool esteWirelessNou) { this->esteWireless = esteWirelessNou; }

    void setCuloareMouse(const char* culoareNoua)
    {
        delete[] this->culoareMouse;
        this->culoareMouse = new char[strlen(culoareNoua) + 1];
        strcpy(this->culoareMouse, culoareNoua);
    }

    // STATIC
    static int getNumarMouseCreate() { return numarMouseCreate; }

    // AFISARE
    void afisare()
    {
        cout << "Tip mouse: " << this->tipMouse << endl;
        cout << "DPI: " << this->valoareDPI << endl;
        cout << "Wireless: " << (this->esteWireless ? "DA" : "NU") << endl;
        cout << "Culoare: " << this->culoareMouse << endl;
        cout << "Ani garantie: " << this->aniGarantie << endl;
    }

    // OPERATORI

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
// FUNCTII FRIEND 
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


//
// ------------------------- MAIN ------------------
//

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

    
}
