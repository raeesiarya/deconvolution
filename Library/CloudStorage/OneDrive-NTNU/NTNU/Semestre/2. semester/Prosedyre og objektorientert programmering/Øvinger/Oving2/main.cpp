#include "std_lib_facilities.h"
#include "AnimationWindow.h"

//Oppgave 1b
void inputAndPrintInteger() {
    int tall;
    cout << "Skriv heltall: ";
    cin >> tall;
    cout << "Du skrev: " << tall << endl;
}

//Oppgave 1c
int inputInteger() {
    int tall;
    cout << "Skriv et tall: ";
    cin >> tall;
    return tall;
}

//Oppgave 1d
void inputIntegersAndPrintSum() {
    int summ = 0;
    cout << "Summerer to tall" << endl;
    for(int i = 0; i < 2; i++) {
        summ += inputInteger();
    }
    cout << "Summen av tallene er: " << summ << endl;;
}

//Oppgave 1e
//Brukte inputInteger for det returnerte en verdi som gjør det lettere å direkte legge til 
//"summ" i inputIntegersAndPrintSum i stedet for inputAndPrintInteger som printer ut en verdi.

//Oppgave 1f
void isOdd(int tall) {
    if(tall % 2 == 0) {
        cout << "True" << endl;
    }
    else if(tall % 2 != 0) {
        cout << "False" << endl;
    }
}

//Oppgave 1g
void printHumanReadableTime(int sek) {
    int timer = sek / 3600;
    int min = (sek / 60) % 60;
    int sekund = sek % 60;
    cout << timer << " timer, " << min << " minutter og " << sekund << " sekunder" << endl;;
}

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

//Oppgave 2a
void sumHeltall() {
    int iterasjoner;
    cout << "Hvor mange iterasjoner skal du ha (skriv tall)? ";
    cin >> iterasjoner;
    int summ = 0;
    for(int i = 0; i < iterasjoner; i++) {
        int tall;
        cout << "Skriv et tall: ";
        cin >> tall;
        summ += tall;
    }
    cout << "Summen er: " << summ << endl;
}

//Oppgave 2b
void summTilNull() {
    int summ = 0;
    int tallrunde;
    while(tallrunde != 0) {
        cout << "Skriv et tall: ";
        cin >> tallrunde;
        summ += tallrunde;
    }
    cout << "Summen er: " << summ << endl;
}

//Oppgave 2c
//a = for løkke fordi vi sjekker hvor lang tid det tar før "i" er lik antall iterasjoner som brukeren har valgt
//b = while løkke fordi koden venter til tallrunde = 0

//Oppgave 2d
double inputDouble() {
    double desimaltall;
    cout << "Skriv et desimaltall: ";
    cin >> desimaltall;
    return float(desimaltall); //Funker også for int - Skriver int som int ikke double?
}

//Oppgave 2e
void NOKtilEURO() {
    int antallkr;
    double euro;
    cout << "Hvor mange kr? ";
    cin >> antallkr;
    euro = antallkr * 10.71;
    cout << "Antall euro: " << euro << endl; //setpresicion() funket ikke?
}

//Oppgave 2f
//Fordi inputDouble gir desimaltall mens inputInteger gir heltall

//Oppgave 2g
void gangeTabell() {
    int bredde;
    int hoyde;
    cout << "Gi høyde: ";
    cin >> hoyde;
    cout << "Gi bredde: ";
    cin >> bredde;
    int tall = 1;
    for(int i = 1; i <= hoyde; i++) {
        cout << setw(0);
        for(int j = 1; j <= bredde; j++) {
            cout << j*tall << setw(8);
        }
        cout << endl;

        tall += 1;
    }
}

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

//Oppgave 3a
double discriminant(double a, double b, double c) {
    return pow(b,2) - 4*a*c;
}

//Oppgave 3b
void printRealRoots(double a, double b, double c) {
    double x1 = (-b+sqrt(discriminant(a,b,c)))/(2*a);
    double x2 = (-b-sqrt(discriminant(a,b,c)))/(2*a);

    cout << "x1: " << x1 << ", x2: " << x2 << endl;
}

//Oppgave 3c
void solveQuadraticEquation() {
    double a;
    double b;
    double c;
    cout << "Skriv et desimaltall (a): ";
    cin >> a;
    cout << "Skriv et desimaltall (b): ";
    cin >> b;
    cout << "Skriv et desimaltall (c): ";
    cin >> c;

    printRealRoots(a,b,c);
}

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

//Oppgave 4
void pytagoras() {
    AnimationWindow win{100,100, 1000, 1000, "Pythagoras"};
    Point point1{350, 500};
    Point point2{650, 500};
    Point point3{650, 350};
    //-----------------------------
    Point point_l_k_one{800,500};
    Point point_l_k_two{800,350};
    //-----------------------------
    Point point_s_k_one{350, 800};
    Point point_s_k_two{650, 800};
    //-----------------------------
    Point point_h_one{500,50};
    Point point_h_two{200,200};
    //-----------------------------
    win.draw_triangle(point1,point2,point3,Color::black);
    win.draw_quad(point2,point_l_k_one,point_l_k_two,point3,Color::red);
    win.draw_quad(point1,point2,point_s_k_two,point_s_k_one,Color::green);
    win.draw_quad(point1,point3,point_h_one,point_h_two,Color::orange);
    win.wait_for_close();
}

//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------

//Oppgave 5a
vector<int> calculateBalance(int years, double kr, int rente) {
    vector<int> intVector(years);
    for(int i = 0; i < years; i++) {
        double faktor = 1;
        double gangemed = 1 + static_cast<double>(rente)/100;
        for(int j = 1; j < i+1 ; j++) {
            faktor *= static_cast<double>(gangemed);
        }
        double mellom = kr * faktor;
        intVector.at(i) = static_cast<int>(mellom);

    }
    return intVector;
}
//Oppgave 5b
void printBalance(vector<int> vec) {
    double penger;
    cout << "Penger: ";
    cin >> penger;
    double rente;
    cout << "Rente: ";
    cin >> rente;
    
    cout << "År" << setw(16) << "Saldo" << endl;
    for(int i = 0; i < vec.size(); i++) {
        penger *= (1 + rente/100);
        cout << setw(0);
        cout << i+1 << setw(16) << penger << endl;
    }
}


//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------


int main() {

int opgnr;
cout << "Velg oppgave (1 = oppgave 1 og 2, 2 = oppgave 3, 3 = oppgave 4, 4 = oppgave 5) ";
cin >> opgnr;


if(opgnr == 1) {

    //Oppgave 1a  
    bool logikk = true;
    while(logikk == true) {
        int valg;
        cout << " " << endl;
        cout << "Velg et tall mellom 0 og 10" << endl;
        cout << "0 = avslutte" << endl;
        cout << "1 = summe to tall" << endl;
        cout << "2 = summe flere tall" << endl;
        cout << "3 = NOK til EURO" << endl;
        cout << "4 = printe tall" << endl;
        cout << "5 = returnere tall" << endl;
        cout << "6 = sjekke oddetall" << endl;
        cout << "7 = lesbar tid" << endl;
        cout << "8 = helt til null" << endl;
        cout << "9 = printe desimaltall" << endl;
        cout << "10 = gangetabell" << endl;


        //cin >> valg;
        cin >> valg;

        switch (valg) {
            case 0:
                cout << "Avslutter..." << endl;
                logikk = false;
                break;

            case 1:
                inputIntegersAndPrintSum();
                break;
                
            case 2:
                cout << "Summer flere tall" << endl;

                sumHeltall();

                break;

//Oppgave 2e
            case 3:
                cout << "NOK til EURO" << endl;
                NOKtilEURO();
                break;

//Oppgave 1b           
            case 4:
                inputAndPrintInteger();
                break;
        
//Oppgave 1c
            case 5:
                cout << inputInteger() << endl;;
                break;

//Oppgave 1f
            case 6:
                int tallinn;
                cout << "Velg tall: ";
                cin >> tallinn;
                isOdd(tallinn);
                break;

//Oppgave 1g
            case 7:
                int sekinn;
                cout << "Velg antall sekund: ";
                cin >> sekinn;
                printHumanReadableTime(sekinn);
                break;

//Oppgave 2b
            case 8:
                summTilNull();
                break;

//Oppgave 2d
            case 9:
                cout << inputDouble() << endl;
                break;

//Oppgave 2g           
            case 10:
                gangeTabell();
                break;
        }

}
}

else if(opgnr == 2) {
    int valg;
    cout << "Velg oppgave (1 = a, 2 = b, 3 = c): ";
    cin >> valg;

    switch (valg) {

//Oppgave 3a
    case 1:
        cout << discriminant(2,6.2,1) << endl;
        break;

//Oppgave 3b
    case 2:
        printRealRoots(2,6.2,1);
        break;

//Oppgave 3c, 3d og 3e
    case 3:
        solveQuadraticEquation();
        break;
    }

}

else if(opgnr == 3) {
    //cout << "Hello world";
    pytagoras();
}

else if(opgnr == 4) {
    //cout << "Hello world";
    //printBalance();
    printBalance(calculateBalance(5,5000,3));
}
return 0;

}