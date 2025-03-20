#include <fstream>
#include <iostream>
using namespace std;

const int N = 1000;

int main() {
  int tab[N];
  ifstream in("liczby.txt");
  ofstream out("wyniki.txt");
  for (int i = 0; i < N; i++) {
    in >> tab[i];
  }

  int parzysta = 0;
  out << "ZADANIE 1" << endl;

  for (int i = 0; i < N; i++) {
    if (tab[i] % 2 == 0 && tab[i] > parzysta) {
      parzysta = tab[i];
    }
  }

  out << parzysta << endl;

  out << "ZADANIE 2" << endl;

  for (int i = 0; i < N; i++) {

    int liczba = tab[i];
    int oryginal = liczba;
    int odwrocona = 0;
    int ostatnia = 0;

    while (liczba > 0) {
      ostatnia = liczba % 10;
      odwrocona = odwrocona * 10 + ostatnia;
      liczba = liczba / 10;
    }
    if (oryginal == odwrocona) {
      out << oryginal << endl;
    }
  }

  out << "ZADANIE 3" << endl;
  int suma_wszystkich_cyfr = 0;
  for (int i = 0; i < N; i++) {

    int liczba = tab[i];
    int oryginal = liczba;
    int suma_cyfr = 0;
    int ostatnia = 0;
    while (liczba > 0) {
      ostatnia = liczba % 10;
      suma_cyfr += ostatnia;
      liczba /= 10;
    }
    suma_wszystkich_cyfr += suma_cyfr;
    if (suma_cyfr >= 30) {
      out << oryginal << endl;
    }
  }
  out << "SUMA WSZYSTKICH CYFR = " << suma_wszystkich_cyfr;
  in.close();
  out.close();
}
