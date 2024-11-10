#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if(towar==0) //Gdy towar=0, nie tworzymy statków
    {
        return 0;
    }
    unsigned int licznik=0;//Wskazuje ile już przetransportowaliśmy towaru
    int liczba_zaglowcow=0;//Liczy liczbę żaglowców
    Stocznia stocznia{};//Tworzy stocznię, fabrykę statków

    while(licznik<towar)//Tworzymy nowe statki, dopóki nie przetransportujemy całego towaru
    {
        Statek* s1 = stocznia();//Tworzymy nowy statek
        licznik+=s1->transportuj();//Liczymy ile towaru przewieźliśmy
        if(dynamic_cast<Zaglowiec*>(s1))//Sprawdzamy czy statek to żaglowiec. Jeśli tak to zwróci niezerowy wskaźnik i wykona się działanie liczb_zaglowcow++.
        {                               //Jeśli nie jest to żalogiec to zwróci wartość nullptr i nie wykona działania liczba_zaglowcow+++.
            liczba_zaglowcow++;
        }
        delete s1;//Usuwamy statek
    }
    return liczba_zaglowcow;
}