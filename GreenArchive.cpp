//PROIECT 2 (MOSTENIRE) - TEMA: PLANTE

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


//functionalitati
//componenta: FUNCTIA VIRTUALA (in fct de cantitatea de apa primita -cat creste/dezvolta)
//radacina: in fct de tipul radacinii (si cant de apa), calculeaza adancimea maxima (si dc supravietuieste)
//tulpina: in fct de cant de apa, calc inaltimea tulpinii maxima (si dc supravietuieste)
//floare: in fc de cant de apa, calculeaza dc supravietuieste
//planta: in fct de cantitatea de apa pe care o primeste, calc daca supravietuiteste planta

class IOinterface
{
  public:
      virtual ostream& afisare(ostream& out) const = 0;
      virtual istream& citire(istream& in) = 0;
};

class componenta:public IOinterface
{
protected:
    string functie;
    // fotosinteza, stocarea substr nutritive(flori)
    int apa; //cantitatea de apa pe care o absoarbe

public:
    componenta();
    componenta(const string functie, const int apa);
    componenta(const componenta& c);
    componenta& operator=(const componenta& c);

    virtual void crestere(int apa) = 0;
    void cant(int apa);

    friend ostream &operator<<(ostream &out, const componenta &c);
    virtual ostream &afisare(ostream &out) const
    {
    out<<endl<<"Functie: "<<this->functie;
    out<<endl<<"Cant. apa: "<<this->apa<<endl;
    return out;
    }

    friend istream &operator>>(istream &in, componenta &c);
    virtual istream &citire(istream &in)
    {
    cout<<endl<<"Citeste functia indeplinita: ";
    in>>this->functie;
    cout<<"Citeste cant. de apa: ";
    in>>this->apa;
    return in;
    }

};

componenta::componenta(){this->functie="fotosinteza"; this->apa=100;}
componenta::componenta(const string functie, const int apa){this->functie=functie; this->apa=apa;}
componenta::componenta(const componenta& c){this->functie=c.functie; this->apa=c.apa;}
componenta& componenta::operator=(const componenta& c)
{
    if (this != &c)
    {this->functie=c.functie;
    this->apa=c.apa;}

    return *this;
}

ostream &operator<<(ostream &out, const componenta &c)
{
    return c.afisare(out);
}
istream &operator>>(istream &in, componenta &c)
{
    return c.citire(in);
}

int ok=1;

class radacina:public virtual componenta
{
protected:
    string tip;
    int adancime;
public:
    radacina();
    radacina(string tip,int adancime);
    radacina(const radacina& r);
    radacina& operator=(const radacina& r);

    void crestere(int apa);
    void cant(int apa);

    void getRadacina()const;

    radacina operator+(int x);
    friend radacina operator+(int x, radacina r);

    friend ostream &operator<<(ostream &out, const radacina &r);
    ostream &afisare(ostream &out) const
    {
//    this->componenta::afisare(out);

    out<<endl<<"Tip radacina: "<<this->tip<<endl;
    out<<"Adancime: "<<this->adancime<<endl;
    return out;
    }

    friend istream &operator>>(istream &in, radacina &r);
    istream &citire(istream &in)
    {
    cout<<endl<<"//Info radacina";

    this->componenta::citire(in);

    cout<<endl<<"Citeste tipul(pivotanta, fibroasa): ";
    in>>this->tip;
    cout<<"Citeste adancimea: ";
    in>>this->adancime;
    return in;
    }
};
radacina::radacina():componenta()
{this->tip="pivotanta"; this->adancime=12;}
radacina::radacina(const string tip, const int adancime):componenta(functie, apa)
{this->tip=tip; this->adancime=adancime;}
radacina::radacina(const radacina& r):componenta(r)
{this->tip=r.tip; this->adancime=r.adancime;}
radacina& radacina::operator=(const radacina& r)
{
    if (this!=&r)
    {
        componenta::operator=(r);
        this->tip=r.tip; this->adancime=r.adancime;
    }
    return *this;
}

void radacina::crestere(int apa)
{
    if (this->tip == "fibroasa")
        if (apa >= 200 && apa <= 500)
            {this->adancime=25;
            cout<< endl << "Cant. de apa e suficienta pt. a sustine viata.";}
        else
            {cout <<"Cant. de apa nu este suficienta pt. a sustine viata."; ok=0;}
    else
    if (this->tip == "pivotanta")
        if (apa >= 500 && apa <= 1000)
            {this->adancime=20;
            cout<< endl << "Cant. de apa e suficienta pt. a sustine viata.";}
        else
            {cout <<"Cant. de apa nu este suficienta pt. a sustine viata."; ok=0;}
    else
        cout<<"Tipul radacinii nu exista. ";
}

void radacina::cant(int apa)
{
    if (this->tip == "fibroasa")
        if (apa < 200 && apa > 500)
        {ok=0;}

    if (this->tip == "pivotanta")
        if (apa < 500 && apa > 1000)
        {ok=0;}
}

void radacina::getRadacina() const
{
    cout<<endl<<"Tip radacina: "<<this->tip<<endl;
    cout<<"Adancime: "<<this->adancime<<endl;
    cout<<endl;
}

radacina radacina::operator+(int x)
{
    radacina r=*this;
    r.adancime+=x;
    return r;
}
radacina operator+(int x, radacina r)
{
    r.adancime+=x;
    return r;
}

ostream &operator<<(ostream &out, const radacina &r)
{
    return r.afisare(out);
}
istream &operator>>(istream &in, radacina &r)
{
    return r.citire(in);
}

class tulpina: public virtual componenta
{
protected:
    int h;
public:
    tulpina();
    tulpina(int h);
    tulpina(const tulpina &t);
    tulpina& operator=(const tulpina &t);

    void crestere(int apa);
    void cant(int apa);

    void getTulpina() const;

    tulpina operator+(int x);
    friend tulpina operator+(int x, tulpina t);

    friend ostream &operator<<(ostream &out, const tulpina &t);
    ostream &afisare(ostream &out) const
    {
//    this->componenta::afisare(out);

    out<<endl<<"Inaltime: "<<this->h<<endl;
    return out;
    }

    friend istream &operator>>(istream &in, tulpina &t);
    istream &citire(istream &in)
    {
    cout<<endl<<"//Info tulpina";

    this->componenta::citire(in);

    cout<<endl<<"Citeste inaltimea: ";
    in>>this->h;
    return in;
    }
};

tulpina::tulpina():componenta(){this->h=30;}
tulpina::tulpina(int h):componenta(functie, apa){this->h=h;}
tulpina::tulpina(const tulpina &t):componenta(t)
{this->h=t.h;}
tulpina& tulpina::operator=(const tulpina &t)
{
    if (this != &t)
    {componenta::operator=(t);
    this->h=t.h;}
    return *this;
}

void tulpina::crestere(int apa)
{
    if (apa >= 100 && apa <= 500)
        {this->h=40;
        cout<< endl << "Cant. de apa e suficienta pt. a sustine viata.";}
    else
        {cout <<"Cant. de apa nu este suficienta pt. a sustine viata."; ok=0;}
}

void tulpina::cant(int apa)
{
    if (apa < 100 && apa > 500)
        ok=0;
}

void tulpina::getTulpina() const
{
    cout<<endl<<"Inaltime: "<<this->h<<endl;
    cout<<endl;
}

tulpina tulpina::operator+(int x)
{
    tulpina t=*this;
    t.h+=x;
    return t;
}
tulpina operator+(int x, tulpina t)
{
    t.h+=x;
    return t;
}

ostream &operator<<(ostream &out, const tulpina &t)
{
    return t.afisare(out);
}
istream &operator>>(istream &in, tulpina &t)
{
    return t.citire(in);
}

class frunza:public virtual componenta
{
protected:
    int s;
public:
    frunza();
    frunza(int s);
    frunza(const frunza& f);
    frunza& operator=(const frunza& f);

    int getS() const;

    void crestere(int apa);

    friend ostream &operator<<(ostream &out, const frunza &f);
    ostream &afisare(ostream &out) const
    {
//    this->componenta::afisare(out);

    out<<endl<<"Suprafata: "<<this->s<<endl;
    return out;
    }

    friend istream &operator>>(istream &in, frunza &f);
    istream &citire(istream &in)
    {
//    cout<<endl<<"//Info frunze";

    this->componenta::citire(in);

    cout<<endl<<"Citeste suprafata: ";
    in>>this->s;
    return in;
    }

};

frunza::frunza():componenta(){this->s=20;}
frunza::frunza(int s):componenta(functie, apa){this->s=s;}
frunza::frunza(const frunza& f):componenta(f)
{this->s=f.s;}
frunza& frunza::operator=(const frunza& f)
{
    if (this != &f)
    {componenta::operator=(f);
    this->s=f.s;}

    return *this;
}

int frunza::getS() const {return this->s;}

void frunza::crestere(int apa)
{
    if (apa >= 50 && apa <= 100)
        cout<< endl << "Cant. de apa e suficienta pt. a sustine viata.";
    else
        cout <<"Cant. de apa nu este suficienta pt. a sustine viata."; ok=0;
}

ostream &operator<<(ostream &out, const frunza &f)
{
    return f.afisare(out);
}
istream &operator>>(istream &in, frunza &f)
{
    return f.citire(in);
}

class floare: public virtual componenta
{
protected:
    string culoare;
    string forma;
public:
    floare();
    floare(string culoare, string forma);
    floare(const floare &f);
    floare& operator=(const floare &f);

    void crestere(int apa);
    void cant(int apa);

    void getFloare() const;

    friend ostream &operator<<(ostream &out, const floare &f);
    ostream &afisare(ostream &out) const
    {
//    this->componenta::afisare(out);

    out<<endl<<"Culoare: "<<this->culoare<<endl;
    out<<"Forma florii: "<<this->forma<<endl;
    return out;
    }

    friend istream &operator>>(istream &in, floare &f);
    istream &citire(istream &in)
    {
    cout<<endl<<"//Info floare";

    this->componenta::citire(in);

    cout<<endl<<"Citeste culoarea: ";
    in>>this->culoare;
    cout<<"Citeste forma(tubulara, stea): ";
    in>>this->forma;
    return in;
    }
};

floare::floare():componenta()
{this->culoare="albastru"; this->forma="tubulara";}

floare::floare(string culoare, string forma):componenta(functie, apa)
{
 this->culoare=culoare; this->forma=forma;
}

floare::floare(const floare &f):componenta(f)
{
 this->culoare=f.culoare; this->forma=f.forma;
}

floare& floare::operator=(const floare &f)
{
    if (this != &f)
    {
        componenta::operator=(f);
        this->culoare=f.culoare; this->forma=f.forma;
    }

    return *this;
}

void floare::crestere(int apa)
{
    if (this->forma == "tubulara")
        if (apa >= 250 && apa <= 500)
            cout<< endl << "Cant. de apa e suficienta pt. a sustine viata.";
        else
            {cout <<"Cant. de apa nu este suficienta pt. a sustine viata."; ok=0;}

    if (this->forma == "stea")
        if (apa >= 300 && apa <= 450)
            cout<< endl << "Cant. de apa e suficienta pt. a sustine viata.";
        else
            {cout <<"Cant. de apa nu este suficienta pt. a sustine viata."; ok=0;}
}

void floare::cant(int apa)
{
    if (this->forma == "tubulara")
        if (apa < 250 && apa > 500) ok=0;

    if (this->forma == "stea")
        if (apa < 300 && apa > 450){ok=0;}
}

void floare::getFloare() const
{
    cout<<endl<<"Culoare: "<<this->culoare<<endl;
    cout<<"Forma florii: "<<this->forma<<endl;
    cout<<endl;
}

ostream &operator<<(ostream &out, const floare &f)
{
    return f.afisare(out);
}
istream &operator>>(istream &in, floare &f)
{
    return f.citire(in);
}

class planta: public radacina, public tulpina, public floare
{
protected:
    string nume;
    int h_max;
    int* perioada; //perioada de inflorire (anotimpurile in care are flori)
    vector<frunza *> frunze;
public:
    planta();
    planta(string nume, int h_max, int* perioada, vector<frunza *> frunze);
    planta(const planta &p);
    planta& operator=(const planta &p);

    void crestere(int apa);

    void getFrunze() const;
    string getNume() const;

    operator string();

    operator string() const;

    friend ostream &operator<<(ostream &out, const planta &p);
    ostream &afisare(ostream &out) const
    {
    cout<<endl<<"//Info planta";

    this->componenta::afisare(out);
    this->radacina::afisare(out);
    this->tulpina::afisare(out);
    this->floare::afisare(out);

    out<<endl<<"Nume: "<<this->nume<<endl;
    out<<"Inaltime maxima: "<<this->h_max<<endl;
    out<<"Perioada de inflorire(1-are flori, 0-nu): "<<endl;
    out<<"Primavara "<<this->perioada[0]<<endl;
    out<<"Vara "<<this->perioada[1]<<endl;
    out<<"Toamna "<<this->perioada[2]<<endl;
    out<<"Iarna "<<this->perioada[3]<<endl;

    if (this->frunze.size() != 0)
    {out<<"Info despre frunze(suprafata): \n";
    for(int i=0; i<this->frunze.size(); i++)
        out<<this->frunze[i]->getS()<<" ";}

    out<<endl;
    return out;
    }

    friend istream &operator>>(istream &in, planta &p);
    istream &citire(istream &in)
    {
    if (this->perioada != NULL)
        delete[] this->perioada;

//    this->componenta::citire(in);
    this->radacina::citire(in);
    this->tulpina::citire(in);
    this->floare::citire(in);

    cout<<endl<<"//Info planta";

    cout<<endl<<"Citeste numele: ";
    in>>this->nume;
    cout<<"Citeste inaltimea maxima: ";
    in>>this->h_max;
    this->perioada=new int[4];
    cout<<endl<<"Citeste perioada de inflorire - 1(are flori), 0(nu): "<<endl;
    cout<<"Primavara "; in>>this->perioada[0];
    cout<<"Vara "; in>>this->perioada[1];
    cout<<"Toamna "; in>>this->perioada[2];
    cout<<"Iarna "; in>>this->perioada[3];

    cout <<endl<<"Apasa f daca planta are frunze, 0 altfel."<<endl;
    char comm;
    in>>comm;
    if (comm=='f')
        {int nr;
        cout<<"Introdu nr. de frunze: ";
        in>>nr;
        cout<<endl<<"//Info frunze";
        for (int i=0; i<nr; i++)
            {
                frunze.push_back(new frunza);
                in>>*frunze.back();
            }
        }

    return in;
    }

    ~planta();
};

planta::planta():componenta(),radacina(),tulpina(),floare()
{
    this->nume="trandafir";
    this->h_max=40;
    this->perioada=new int[4];
    this->perioada[0]=0;
    this->perioada[1]=1;
    this->perioada[2]=1;
    this->perioada[3]=0;
    this->frunze={};
}

planta::planta(string nume, int h_max, int* perioada, vector<frunza *> frunze):componenta(functie, apa),radacina(tip, adancime), tulpina(h), floare(culoare, forma)
{
    this->nume=nume;
    this->h_max=h_max;
    this->perioada=new int[4];
    this->perioada[0]=perioada[0];
    this->perioada[1]=perioada[1];
    this->perioada[2]=perioada[2];
    this->perioada[3]=perioada[3];
    this->frunze=frunze;
}

planta::planta(const planta &p):componenta(p),radacina(p),tulpina(p),floare(p)
{
    this->nume=p.nume;
    this->h_max=p.h_max;
    this->perioada=new int[4];
    for (int i=0; i<4; i++)
        this->perioada[i]=p.perioada[i];
    this->frunze=p.frunze;
}

planta& planta::operator=(const planta &p)
{
    if (this != &p)
    {
    if (this->perioada != NULL)
        delete[] this->perioada;

    componenta::operator=(p);
    radacina::operator=(p);
    tulpina::operator=(p);
    floare::operator=(p);
    this->nume=p.nume;
    this->h_max=p.h_max;
    this->perioada=new int[4];
    for (int i=0; i<4; i++)
        this->perioada[i]=p.perioada[i];
    this->frunze=p.frunze;
    }

    return *this;
}

void planta::crestere(int apa)
{
    this->radacina::cant(apa/3);
    if (ok == 1) {
        this->tulpina::cant(apa/3);
        if (ok == 1) {
            this->floare::cant(apa/3);
        }
    }

    if (ok == 1)
        cout << "Cant. de apa este suficienta pt. a sustine viata";
    else
        cout << "Cant. de apa nu este suficienta pt. a sustine viata.";
}

void planta::getFrunze() const
{
    if (this->frunze.size() > 0)
    for(int i=0; i<this->frunze.size(); i++)
        cout<<this->frunze[i]->getS()<<" ";
    else cout<<"Planta nu are frunze. \n";
    cout<<endl;
}

string planta::getNume() const
{
    return this->nume;
}

planta::operator string()
{
    return this->nume;
}

planta::operator string() const
{
    return this->nume;
}

ostream &operator<<(ostream &out, const planta &p)
{
    return p.afisare(out);
}
istream &operator>>(istream &in, planta &p)
{
    return p.citire(in);
}

planta::~planta(){
    if (this->perioada != NULL)
        delete[] this->perioada;
}

int main()
{
    vector<planta> lista;
    int t=1;
    while (t==1)
    {
        cout<<endl;
        cout<<"---------------------------------------------------------------------";
        cout<<endl<<"Apasa 1 daca vrei sa introduci informatii despre o planta.";
        cout<<endl<<"Apasa 2 daca vrei sa vezi informatiile stocate despre o planta anume.";
        cout<<endl<<"Apasa 3 daca vrei sa vezi informatiile deja stocate.";
        cout<<endl<<"Apasa 4 pentru a iesi."<<endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        int ok;
        cin>>ok;

        switch(ok)
        {
        case 1:
            {
                planta p;
                cin>>p;
                lista.push_back(p);

                cout <<endl<<"Scrie * pentru a verifica daca cant. de apa e suficienta, 0 daca vrei sa continui."<<endl;
                char a;
                cin>>a;
                if (a=='*')
                    {cout <<endl<<"Introdu cantitatea: "<<endl;
                    int nr;
                    cin>>nr; cout<<endl;
//                    p.radacina::crestere(nr);
                    p.crestere(nr);
                    cout<<endl;
                    }

                break;
            }
        case 2:
            {
                if (lista.size() == 0 )
                    cout<<endl<<"Inca nu ai inregistrat plante."<<endl;
                else{
                cout<<endl<<"Introdu indicele plantei: ";
                int x;
                cin>>x;

                if (x<0 || x>lista.size()-1) cout<<"\nNu exista nicio planta cu acest indice. \n";
                else{
                int k=1;

                while(k)
                {
                cout <<"Apasa a daca vrei sa vizualizezi toate informatiile."<<endl;
                cout <<"Apasa b daca vrei sa accesezi o anumita informatie."<<endl;
                cout <<"Apasa x daca vrei sa iesi."<<endl;

                char ch;
                cin>>ch;
                switch(ch)
                {
                case 'a':
                    {
                        cout<<lista[x]<<endl; //afiseaza toate inf
                        break;
                    }
                case 'b':
                    {
                        cout<<endl<<"Scrie ce componenta te intereseaza(radacina, tulpina, floare, frunze): ";
                        char comp[100];
                        cin.get(); cin.get(comp, 100);
                        if (strcmp(comp, "radacina")==0)
                            lista[x].radacina::getRadacina();
                        if (strcmp(comp, "tulpina")==0)
                            lista[x].tulpina::getTulpina();
                        if (strcmp(comp, "floare")==0)
                            lista[x].floare::getFloare();
                        if (strcmp(comp, "frunze")==0)
                            {cout<<"suprafata fiecarei frunze: "; lista[x].getFrunze(); cout<<endl;}
                        break;
                    }
                default:
                    {
                        k=0; break;
                    }
                }

                }

                }
                }

                break; //de la case 2

            }
        case 3:
            {   cout<<endl;
                for (int i=0; i<lista.size(); i++)
                    cout<<" << "<<i<<" >> "<<endl<<lista[i]<<endl;
                break;
            }
        case 4:
            {
                t=2; break;
            }
        }
    }


    return 0;
}
