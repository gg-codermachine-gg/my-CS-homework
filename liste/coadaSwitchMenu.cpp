#include<iostream>
#include<fstream>

using namespace std;

struct nod {
    int util;
    nod* urm;
};

void adaugPrim(nod* &prim, nod* &ultim, int x){
    prim = new nod;
    prim->util = x;
    prim->urm = NULL;
    ultim = prim;
}

void adaug_dupa_ultim(nod* &ultim, int x){
    nod *p = new nod;
    p->util = x;
    p->urm = NULL;
    ultim->urm = p;
    ultim = p;
}

void creare(nod* &prim, nod* &ultim){
    prim = ultim = NULL;
    int x;
    ifstream f("numere.txt");
    f >> x;
    adaugPrim(prim, ultim, x);
    while(f >> x)
        adaug_dupa_ultim(ultim, x);
    f.close();
}



void afisare(nod* prim){
    nod* p;
    for(p = prim; p != NULL; p = p->urm)
        cout << p->util << " ";
    cout << endl;
}

void stergere(nod* &prim){
    nod* p;
    if(prim){
       p = prim;
      prim = prim -> urm;
      delete prim;
    }else cout<<"coada vida";

}

int main() {
    nod* prim;
    nod* ultim;

    int x;
    char op;
    do{
        cout << "Introdu operatia dorita: ";
        cin >> op;
        switch(op)
        {
            case '1':{
                cout << "\nStiva dupa afisare: " << endl;
                afisare(prim);
                break;
            }
            case '2':
                cout << "\nSterg din varf" << endl;
                stergere(prim);
                break;
            case '3':
                cout << "Care valoare adaugi: ";
                cin >> x;
                creare(prim,ultim);
                break;
            default: cout << "Introdu o valoare intre 1 - 3 " << endl;
        }
    } while(op != '0');

    return 0;
}
