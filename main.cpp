#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Wprowadz liczbe wezlow" << endl;
    int liczbaWezlow;
    cin>>liczbaWezlow;
    float wezly[liczbaWezlow];

    for(int i=0;i<liczbaWezlow;i++)
    {
        cout<< "Wprowadz wartosc dla wezla "<<i<<endl;
        cin>>wezly[i];
        float mniejszy= wezly[i];
        //Sprawdzenie warunkow interpolacji
        //Czy wezly interpolacji sa rozne miedzy soba
        if(wezly[i]==wezly[i-1])
        {
            cout<<"Wezly interpolacji nie sa rozne miedzy soba. Wprowadz prawidlowe wartosci"<<endl;
        }
        //Czy wezly interpolacji sa ulozone w porzadku rosnacym
        if(i!=0&& mniejszy < wezly[i-1])
        {
            cout<<"Wezly nie sa ulozone w porzadku rosnacym. Wprowadz poprawne dane"<<endl;
        }
    }
    float wartoscFunkcji[liczbaWezlow];
    for(int i=0;i<liczbaWezlow;i++)
    {
        cout<< "Wprowadz wartosc funkcji w wezle "<<i<<endl;
        cin>>wartoscFunkcji[i];
    }
    cout<<"Wprowadz wartosc punktu p: "<<endl;
    float punkt;
    cin>>punkt;
    double wielomianyFundamentalne[liczbaWezlow];
    for(int i=0;i<liczbaWezlow;i++){wielomianyFundamentalne[i]=1.0;}
    wielomianyFundamentalne[0]=1.0;
    float wielomianFundamentalny[liczbaWezlow];
    for(int i=0;i<liczbaWezlow;i++){wielomianFundamentalny[i]=1.0;}
    double iloczyn;
    double suma;
    int i,j;
    //Sprawdzenie czy punkt nalezy do przedzialu wyznaczonego przez wezly

    if(punkt >= wezly[0] &&  punkt <=wezly[liczbaWezlow-1]) {
        cout << "Punkt nalezy do przedzialu, przechodze do obliczania przyblizonej wartosci" << endl;
        for(j=0;j<liczbaWezlow-1;j++)
        {
            for(i=liczbaWezlow-1;i>j;i--)
            {
                wartoscFunkcji[i]=(wartoscFunkcji[i]-wartoscFunkcji[i-1])/(wezly[i]- wezly[i-j-1]);
            }
        }
        for(i=liczbaWezlow-1;i>=0;i--)
        {
            iloczyn=1;
            for(j=0;j<i;j++)
            {
                iloczyn*=(punkt-wezly[j]);

            }
            iloczyn*=wartoscFunkcji[j];
            suma+=iloczyn;

        }
        cout<<"Wynik: "<<suma<<endl;


    }
    else
    {
        cout<<"Punkt nie nalezy do przedzialu, prosze podac odpowiedni punkt i sprobowac ponownie"<<endl;
    }



    return 0;
}
