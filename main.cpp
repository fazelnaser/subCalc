#include <iostream>
using namespace std;

// Deklarationer av funktionerna
void skrivInfo();
int lasEttTal(int ettTal);
int lasOp(char berTyp);
void ordna(int var1, int var2, int &min, int &max);
int berakna(int min, int max, char berTyp);
void skrivResultat(int resultat);

int main()
{
    int tal1, tal2, ettTal, min, max, svar;
    char op, opTyp;

    skrivInfo();

    tal1 = lasEttTal(ettTal);
    tal2 = lasEttTal(ettTal);

    op = lasOp(opTyp);

    ordna(tal1, tal2, min, max);

    svar = berakna(min, max,op);

    skrivResultat(svar);

    return 0;
}

// Definitioner av funktionerna
void skrivInfo()
{
    cout << endl;
    cout << "Detta program utföra tre enkla typer av beräkningar baserat på" << endl;
    cout << "inmatningarna och vald beräkningstyp.\n\n";

    cout << "Programmet tar emot två heltal och frågar därefter vilken typ av som ska utföras." << endl;
    cout << "Därefter kommer alla tal mellan det minsta och störta att antigen summeras," << endl;
    cout << "multipliceras eller kvadratsummeras. Alla heltal är giltiga.\n\n";

    cout << "- Tillgängliga beräkningstyper -" << endl;
    cout << "a - för att addera talen" << endl;
    cout << "m - för att multiplicera talen" << endl;
    cout << "k - för att beräkna kvadratsumman av talen\n\n" << endl;
}

int lasEttTal(int ettTal)
{
    int value;
    cout << "Anget ett valfritt heltal: ";
    cin >> value;

    return value;
}

int lasOp(char berTyp)
{
    char Op;
    bool fortsatt = true;

    while (fortsatt)
    {
        cout << "\n\n";
        cout << "Ange beräkningstypen som ska utföras: " ;
        cin >> Op;
        if ((Op == 'a' || Op == 'm' || Op == 'k'))
        {
            fortsatt = false;
        }
        else
        {
            cout << endl << "FEL! Ange ett giltigt beräkningstyp." << endl;     // Om fel char anges frågan den igen
        }
    }
    return Op;
}

void ordna(int var1, int var2, int &min, int &max)
{
    if (var1 > var2)
    {
        max = var1;
        min = var2;
    }
    else
    {
        max = var2;
        min = var1;
    }
}

int berakna(int min, int max, char berTyp)
{
    int svaret = 0;

    // "reverse and add" metod av Gauss för att summera alla artimetiska progressioner
    // mellan max och min finns det (max - min + 1) antal tal.
    if (berTyp == 'a')
    {
        svaret = ((max-min+1)*(min+max))/2;
    }
    else if (berTyp == 'm')                 // Som factorial
    {
        svaret = 1;                         // svaret=1 för att det inte ska bli gånger 0
        for (int i = min; i <= max; i++)
        {
            svaret *= i;
        }
    }
    else if (berTyp == 'k')
    {
        for (int i = min; i <= max; i++)
        {
            svaret += (i*i);
        }
    }
    return svaret;
}

void skrivResultat(int resultat)
{
    cout << endl << "Resultatet av beräkningen: " << resultat << endl;
}