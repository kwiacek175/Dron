#include "Bryla.hh"

Wektor3D &Bryla::operator[](int index)
{
    return wierz[index];
}
Wektor3D Bryla::operator[](int index) const
{
    return wierz[index];
}

void Bryla::set_nazwa(std::string nazwa)
{
    this->nazwa = nazwa;
}

void Bryla::set_srodek(Wektor3D srodek)
{
    this->srodek = srodek;
}

Wektor3D Bryla::get_srodek() const
{
    return srodek;
}

std::string Bryla::get_nazwa() const
{
    return nazwa;
}

void Bryla::przesun(Wektor3D przes)
{
    for (int i = 0; i < (int)wierz.size(); i++)
    {
        wierz[i] = wierz[i] + przes;
    }
    srodek = srodek + przes;
}

void Bryla::translacja(Macierz3x3 obr)
{
    for (int i = 0; i < (int)wierz.size(); i++)
    {
        wierz[i] = (obr * wierz[i]);
    }
    srodek=obr*srodek;
}

void Bryla::zapisz()
{
    std::fstream plik;
    double tab[] = {0, 0, (*wymiary)[2] / 2};
    Wektor3D przesun_sr(tab);

    plik.open(nazwa, std::ios::out);

    for (int i = 0; i < (int)wierz.size(); i += 2)
    {
        plik << srodek + przesun_sr << std::endl;
        for (int j = 0; j < 2; j++)
        {
            plik << wierz[j + i] << std::endl;
        }
        plik << srodek - przesun_sr << std::endl
             << std::endl;
    }

    plik << srodek + przesun_sr << std::endl;
    for (int j = 0; j < 2; j++)
    {
        plik << wierz[j] << std::endl;
    }
    plik << srodek - przesun_sr << std::endl
         << std::endl;
    plik.close();
}
bool Bryla::czy_kolizja(shared_ptr<Obiekt_Sceny> ob)
{
    std::shared_ptr<Bryla> self = shared_from_this();

    if (ob != self)
    {

        Wektor3D srodek_Bryla= get_srodek();
        Wektor3D srodek_Obiektu = ob->get_srodek();
        double l = sqrt(pow(srodek_Bryla[0] - srodek_Obiektu[0], 2) + pow(srodek_Bryla[1] - srodek_Obiektu[1], 2) + pow(srodek_Bryla[2] - srodek_Obiektu[2], 2));
        if (promien() + ob->promien() >= l)
        {
            return true;
        }
    }
    return false;
}