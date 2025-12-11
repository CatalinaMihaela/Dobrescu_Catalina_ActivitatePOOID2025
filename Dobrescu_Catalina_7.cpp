#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class CursaCiclism
{
    string numeCursa;
    int dificultate;
    int nrEtape;
    int* timpiEtape; 

public:

    // Constructor fara parametrii
    CursaCiclism()
    {
        this->numeCursa = "Necunoscuta";
        this->dificultate = 0;
        this->nrEtape = 0;
        this->timpiEtape = NULL;
    }

    // Constructor cu toti parametri
    CursaCiclism(string nume, int dific, int nrEtape, int* timpi)
    {
        this->numeCursa = nume;
        this->dificultate = (dific >= 0 && dific <= 10 ? dific : 0);
        this->nrEtape = nrEtape;

        this->timpiEtape = new int[nrEtape];
        for (int i = 0; i < nrEtape; i++)
            this->timpiEtape[i] = timpi[i];
    }

    // Constructor de copiere
    CursaCiclism(const CursaCiclism& c)
    {
        this->numeCursa = c.numeCursa;
        this->dificultate = c.dificultate;
        this->nrEtape = c.nrEtape;

        this->timpiEtape = new int[this->nrEtape];
        for (int i = 0; i < this->nrEtape; i++)
            this->timpiEtape[i] = c.timpiEtape[i];
    }

    // Operator =
    CursaCiclism& operator=(const CursaCiclism& c)
    {
        if (this != &c)
        {
            if (this->timpiEtape != NULL)
                delete[] this->timpiEtape;

            this->numeCursa = c.numeCursa;
            this->dificultate = c.dificultate;
            this->nrEtape = c.nrEtape;

            this->timpiEtape = new int[this->nrEtape];
            for (int i = 0; i < this->nrEtape; i++)
                this->timpiEtape[i] = c.timpiEtape[i];
        }
        return *this;
    }

    
    void adaugaEtapa(int timpNou)
    {
        int* copie = new int[this->nrEtape];
        for (int i = 0; i < this->nrEtape; i++)
            copie[i] = this->timpiEtape[i];

        delete[] this->timpiEtape;

        this->nrEtape++;
        this->timpiEtape = new int[this->nrEtape];

        for (int i = 0; i < this->nrEtape - 1; i++)
            this->timpiEtape[i] = copie[i];

        this->timpiEtape[this->nrEtape - 1] = timpNou;

        delete[] copie;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const CursaCiclism& c)
    {
        out << "Cursa: " << c.numeCursa
            << " | Dificultate: " << c.dificultate
            << " | Nr Etape: " << c.nrEtape
            << " | Timpi: ";

        for (int i = 0; i < c.nrEtape; i++)
            out << c.timpiEtape[i] << " min | ";

        return out;
    }

    // Operator >>
    friend istream& operator>>(istream& in, CursaCiclism& c)
    {
        cout << "Nume cursa: ";
        in >> c.numeCursa;

        cout << "Dificultate (0-10): ";
        in >> c.dificultate;
        if (c.dificultate < 0 || c.dificultate > 10) c.dificultate = 0;

        cout << "Numar etape: ";
        in >> c.nrEtape;

        if (c.timpiEtape != NULL) delete[] c.timpiEtape;
        c.timpiEtape = new int[c.nrEtape];

        cout << "Introdu timp pentru fiecare etapa:\n";
        for (int i = 0; i < c.nrEtape; i++)
        {
            cout << "Etapa " << i + 1 << ": ";
            in >> c.timpiEtape[i];
        }
        return in;
    }

    // Operator <
    bool operator<(const CursaCiclism& c)
    {
        return this->dificultate < c.dificultate;
    }

    // Operator cast la int (total timp)
    explicit operator int()
    {
        int total = 0;
        for (int i = 0; i < this->nrEtape; i++)
            total += this->timpiEtape[i];
        return total;
    }

    // Operator index
    int operator[](int index)
    {
        if (index >= 0 && index < this->nrEtape)
            return this->timpiEtape[index];
        return -1;
    }

    // Destructor
    ~CursaCiclism()
    {
        if (this->timpiEtape != NULL)
            delete[] this->timpiEtape;
    }
};

void main()
{
    CursaCiclism c1;
    cout << c1 << endl << endl;

    int timpi[] = { 30, 45, 50 };
    CursaCiclism c2("Turul Romaniei", 7, 3, timpi);
    cout << c2 << endl << endl;

    cout << "Adaug etapa:\n";
    c2.adaugaEtapa(40);
    cout << c2 << endl;

    cout << "Cast la int (total timp): " << (int)c2 << " minute\n";

    cout << "Operator index c2[1] = " << c2[1] << " minute\n";
}
