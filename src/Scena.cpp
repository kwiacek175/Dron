#include "Scena.hh"

Scena::Scena()
{

  Lacze.ZmienTrybRys(PzG::TR_3D);
  nr_elem = 0;
  nr_drona = 0;
  Lacze.UstawZakresY(-300, 300);
  Lacze.UstawZakresX(-300, 300);
  Lacze.UstawZakresZ(-300, 300);

  double tab_wym[3] = {600, 600, 0};
  Wektor3D wym_dna(tab_wym);
  dno = new Plaszczyzna(wym_dna, 20);
  Wektor3D srod;
  bool kolizja = false;
  for (int i = 0; i < 4; i++)
  {
 kolizja = false;
    srod[0] = rand() % 400 - 200;
    srod[1] = rand() % 400 - 200;
    srod[2] = 50;
    int nr_p = rand() % 3;
    if (nr_p == 0)
      Lista_elementow.push_front(std::make_shared<Gora>(srod, 100, 50, 100, "dat/Element" + std::to_string(nr_elem) + ".dat"));
    else if (nr_p == 1)
      Lista_elementow.push_front(std::make_shared<Plaskowyz>(srod, 100, 50, 100, "dat/Element" + std::to_string(nr_elem) + ".dat"));
    else if (nr_p == 2)
      Lista_elementow.push_front(std::make_shared<Gran>(srod, 100, 50, 100, "dat/Element" + std::to_string(nr_elem) + ".dat"));
    nr_elem++;
    for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
      if ((*Lista_elementow.begin())->czy_kolizja(*a))
      {
        kolizja = true;
      }
    }
    if (kolizja)
    {
      i--;
      Lista_elementow.erase(Lista_elementow.begin());
    }
  }
  for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->get_nazwa().c_str());
    (*a)->zapisz();
    cout << (*a)->get_nazwa() << " " << (*a)->promien() << endl;
  }

  Lacze.DodajNazwePliku(dno->get_nazwa().c_str());
  dno->zapisz();
  kolizja = false;
  for (int i = 0; i < N; i++)
  {
    double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

    Lista_Dronow.push_front(std::make_shared<Dron>(i, Lacze, Wektor3D(pozycja)));

    for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
      if ((*Lista_Dronow.begin())->czy_kolizja(*a))
      {
        kolizja = true;
      }
    }
    if (kolizja)
    {
      i--;
      Lista_Dronow.erase(Lista_Dronow.begin());
    }
    else
    {
      Lista_elementow.push_front(*Lista_Dronow.begin());
      cout << (*Lista_Dronow.begin())->get_nazwa() << " " << (*Lista_Dronow.begin())->promien() << endl;
      (*Lista_Dronow.begin())->zapisz();
      nr_drona++;
    }
    kolizja = false;
  }

  Lacze.Rysuj();
}
void Scena::rysuj()
{

  Lacze.Rysuj();
}
bool Scena::interfejs()
{
  cout << "1.Drony, 2. dodaj element, 3 usun element,4 usun drona" << endl;
  int opcja;
  cin >> opcja;
  switch (opcja)
  {
  case 1:
  {
    cout << "podaj nr " << endl;
    for (int i = 0; i < (int)Lista_Dronow.size(); i++)
    {
      cout << i << " ";
    }
    cout << ":" << endl;
    int nr;
    cin >> nr;
    std::list<std::shared_ptr<Dron>>::const_iterator a;
    a = Lista_Dronow.begin();
    for (int i = 0; i < nr; i++)
    {
      a++;
    }

    (*a)->sterowanie(Lista_elementow);
  }
  break;
  case 2:
  {
    cout << "podaj 1-gora, 2-plaskowyz, 3 gran, 4 dron" << endl;

    int nr;
    cin >> nr;
    Wektor3D srod;

    if (nr != 4)
    {
      for (int i = 0; i < 50; i++)
      {
        srod[0] = rand() % 400 - 200;
        srod[1] = rand() % 400 - 200;
        srod[2] = 50;
        bool kolizja = false;
        if (nr == 1)
        {

          Lista_elementow.push_front(std::make_shared<Gora>(srod, 100, 50, 100, "dat/Element" + std::to_string(nr_elem) + ".dat"));
        }
        if (nr == 2)
        {

          Lista_elementow.push_front(std::make_shared<Plaskowyz>(srod, 100, 50, 100, "dat/Element" + std::to_string(nr_elem) + ".dat"));
        }
        if (nr == 3)
        {

          Lista_elementow.push_front(std::make_shared<Gran>(srod, 100, 50, 100, "dat/Element" + std::to_string(nr_elem) + ".dat"));
        }

        nr_elem++;
        for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
        {
          if ((*Lista_elementow.begin())->czy_kolizja(*a))
          {
            kolizja = true;
          }
        }
        if (kolizja)
        {
          i--;
          Lista_elementow.erase(Lista_elementow.begin());
        }
        else
        {
          break;
        }
      }
      (*Lista_elementow.begin())->zapisz();
      Lacze.DodajNazwePliku((*Lista_elementow.begin())->get_nazwa().c_str());
    }
    else
    {
      bool kolizja = false;
      for (int i = 0; i < 50; i++)
      {
        double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

        Lista_Dronow.push_front(std::make_shared<Dron>(nr_drona, Lacze, Wektor3D(pozycja)));

        for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
        {
          if ((*Lista_Dronow.begin())->czy_kolizja(*a))
          {
            kolizja = true;
          }
        }
        if (kolizja)
        {

          Lista_Dronow.erase(Lista_Dronow.begin());
        }
        else
        {
          Lista_elementow.push_front(*Lista_Dronow.begin());
          cout << (*Lista_Dronow.begin())->get_nazwa() << " " << (*Lista_Dronow.begin())->promien() << endl;
          (*Lista_Dronow.begin())->zapisz();
          nr_drona++;
          break;
        }
        kolizja = false;
      }
    }
  }

  break;
case 3:
{
    int i = 0;
    for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator a = Lista_elementow.begin(); a != Lista_elementow.end(); a++)
    {
        cout << i << ": " << (*a)->get_nazwa() << endl;
        i++;
    }

    cout << "Podaj numer" << endl;

    int nr;
    cin >> nr;

    std::list<std::shared_ptr<Obiekt_Sceny>>::iterator a = Lista_elementow.begin();

    for (int j = 0; j < nr; j++) {
        a++;
    }

    if (a != Lista_elementow.end()) {
      
        auto next_a = std::next(a);

        Lacze.UsunNazwePliku((*a)->get_nazwa());

        Lista_elementow.erase(a);

        a = next_a;
    } else {
        cout << "Nieprawidłowy numer!" << endl;
    }
    break;
}

    ////faza 3 dla niektórych///
  case 4:
  {
    int i = 0;
    for (std::list<std::shared_ptr<Dron>>::const_iterator a = Lista_Dronow.begin(); a != Lista_Dronow.end(); a++)
    {
      cout << i << ": " << (*a)->get_id() << endl;
      i++;
    }
    cout << "podaj numer" << endl;

    int nr;
    cin >> nr;
    std::list<std::shared_ptr<Dron>>::const_iterator a = Lista_Dronow.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }

    (*a)->usun();

    for (std::list<std::shared_ptr<Obiekt_Sceny>>::const_iterator b = Lista_elementow.begin(); b != Lista_elementow.end(); b++)
    {
      if (*a == *b)
      {
        Lista_elementow.erase(b);
      }
    }
    Lista_Dronow.erase(a);
    break;
  }

  default:
    break;
  }

  return true;
}

Scena::~Scena()
{
  free(dno);
}