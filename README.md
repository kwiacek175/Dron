# Projekt Dron

Projekt "Dron" to aplikacja symulacyjna, która modeluje interakcje dronów w przestrzeni 3D, w której znajdują się różne elementy terenowe. Celem projektu jest stworzenie środowiska, w którym użytkownik może dodawać i zarządzać dronami oraz obiektami w scenie, kontrolować ruchy dronów i sprawdzać kolizje między nimi a obiektami terenowymi.

## Opis projektu

### Główne funkcjonalności

1. **Symulacja 3D**  
   Aplikacja tworzy wirtualną przestrzeń 3D, w której znajdują się drony i różne elementy terenowe. Interakcje między obiektami w przestrzeni są dynamiczne, a każde wprowadzenie nowego obiektu sprawdza, czy nie dojdzie do kolizji z już istniejącymi obiektami.

2. **Obiekty w scenie**  
   W przestrzeni 3D znajdują się różne obiekty terenowe:
   - **Góra**  
   - **Płaskowyż**  
   - **Graniastosłup**  
   Użytkownik może dodawać te obiekty do sceny, a aplikacja automatycznie sprawdza, czy nie kolidują one z innymi elementami.

3. **Drony**  
   Użytkownik może dodawać drony do sceny. Każdy dron ma unikalną pozycję startową, a po jego dodaniu sprawdzana jest możliwość kolizji z innymi obiektami (w tym z innymi dronami). Drony mają możliwość sterowania, a użytkownik może wybrać, którym dronem chce sterować.

4. **Kolizje**  
   Aplikacja automatycznie sprawdza kolizje między obiektami. Jeśli dodany obiekt (np. dron lub element terenowy) koliduje z innym obiektem, zostaje on usunięty z listy, a użytkownik zostaje poproszony o ponowne dodanie elementu w innym miejscu.

5. **Interfejs użytkownika**  
   Użytkownik może interaktywnie zarządzać dronami i obiektami w scenie za pomocą prostego interfejsu tekstowego:
   - **1** – kontrolowanie dronów
   - **2** – dodawanie nowych elementów do sceny (góra, płaskowyż, granit, dron)
   - **3** – usuwanie elementów z sceny
   - **4** – usuwanie dronów z listy

6. **Rysowanie sceny**  
   Aplikacja korzysta z biblioteki graficznej (prawdopodobnie PzG) do rysowania 3D i wizualizacji elementów. Wszystkie obiekty i drony są dodawane do wizualizacji po ich utworzeniu.

### Struktura projektu

Projekt oparty jest na klasach, które modelują różne aspekty sceny:

- **Scena** – główna klasa, która odpowiada za zarządzanie wszystkimi elementami i dronami, dodawanie nowych obiektów do przestrzeni, sprawdzanie kolizji i interakcję z użytkownikiem.
- **Obiekt_Sceny** – bazowa klasa dla wszystkich elementów sceny, takich jak góry, płaskowyże, granit oraz drony. Odpowiada za podstawowe operacje na obiektach, jak np. zapis danych, kolizje itp.
- **Gora, Plaskowyz, Graniastosłup** – klasy dziedziczące po `Obiekt_Sceny`, reprezentujące różne typy obiektów terenowych, które można dodawać do sceny.
- **Dron** – klasa reprezentująca dron, który porusza się w przestrzeni 3D i może wchodzić w interakcje z innymi obiektami.

### Implementacja

1. **Inicjalizacja sceny**:  
   Scena jest tworzona w konstruktorze klasy `Scena`, gdzie ustawiane są zakresy dla osi X, Y, Z oraz tworzony jest obiekt "dno", które stanowi podstawę sceny. Następnie losowo generowane są różne elementy terenowe i dodawane do listy, przy czym każdorazowo sprawdzana jest możliwość kolizji z innymi obiektami.

2. **Dodawanie dronów**:  
   Drony są również dodawane do sceny w sposób losowy, a następnie sprawdzana jest możliwość ich kolizji z istniejącymi obiektami. Każdy dron posiada swoją unikalną pozycję początkową oraz jest zapisany do odpowiednich plików.

3. **Sterowanie dronami**:  
   Użytkownik może wybrać, który dron ma być sterowany, po czym może wprowadzać komendy sterujące dla wybranego drona. Każdy dron może poruszać się w przestrzeni 3D, a interakcje są kontrolowane przez odpowiednie metody w klasie `Dron`.

4. **Zarządzanie obiektami**:  
   Użytkownik może dodawać nowe obiekty do sceny, usuwając je w razie potrzeby, a także usuwać drony, które już nie są potrzebne.

5. **Rysowanie i aktualizacja**:  
   Scena jest aktualizowana i rysowana na bieżąco za pomocą funkcji `Lacze.Rysuj()`, która wykorzystuje graficzną bibliotekę do wyświetlania 3D w przestrzeni.

### Wymagania

- **C++** – projekt napisany w języku C++, wykorzystujący klasy i mechanizmy dziedziczenia.
- **Biblioteka PzG** – używana do rysowania 3D i wizualizacji obiektów w przestrzeni.
- **Kompilacja** – projekt wymaga kompilatora C++ obsługującego standard C++11 lub wyższy.

### Przykładowe polecenia interfejsu

1. **Dodanie elementu**:
   ```text
   2
   Podaj 1-gora, 2-plaskowyz, 3-granit, 4-dron
   1
