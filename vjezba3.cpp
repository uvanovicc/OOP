#include <iostream>
#include <cstddef>

using namespace std;
/*
//1.
inline bool ascending(int a, int b) {
	return a < b;
}
inline bool descending(int a, int b) {
	return a > b;
}

void sortt(int arr[], size_t n, bool(*cmp)(int, int)) {
	for (size_t i = 0; i < n - 1; ++i) {
		for (size_t j = i + 1; j < n; ++j) {
			if (!cmp(arr[i], arr[j])) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	int niz[] = { 5, 1, 9, 3, 7 };
	size_t n = sizeof(niz) / sizeof(niz[0]);

	cout << "pocetni niz: ";
	for (int x : niz) cout << x << " ";
	cout << endl;

	sortt(niz, n, ascending);
	cout << "uzlazno: ";
	for (int x : niz) cout << x << " ";
	cout << endl;

	sortt(niz, n, descending);
	cout << "silazno: ";
	for (int x : niz) cout << x << " ";
	cout << endl;
	system("pause");
	return 0;
}
*/
//2.
template<typename T> inline bool ascending(T a, T b) {
	return a < b;
}
template<typename T> inline bool descending(T a, T b) {
	return a > b;
}
template<typename T>
void sortt(T arr[], size_t n, bool(*cmp)(T, T)) {
	for (size_t i = 0; i < n - 1; ++i) {
		for (size_t j = i + 1; j < n; ++j) {
			if (!cmp(arr[i], arr[j])) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	int niz[] = { 5, 1, 9, 3, 7 };
	size_t n = sizeof(niz) / sizeof(niz[0]);

	cout << "pocetni niz: ";
	for (int x : niz) cout << x << " ";
	cout << endl;

	sortt(niz, n, ascending<int>);
	cout << "uzlazno: ";
	for (int x : niz) cout << x << " ";
	cout << endl;

	sortt(niz, n, descending<int>);
	cout << "silazno: ";
	for (int x : niz) cout << x << " ";
	cout << endl;
	system("pause");
	return 0;
}

//3.
int main() {
    auto parnost = [](int x) { return x % 2 == 0; };
    auto neparnost = [](int x) { return x % 2 != 0; };
    auto udvostruci = [](int x) { return x * 2; };
    auto prepolovi = [](int x) { return x / 2; };

    vector<int> niz = {2, 3, 4, 5, 6, 7, 8};
    int suma = 0, produkt = 1;

    auto dodaj_sumu = [&](int x) { suma += x; };
    auto dodaj_produkt = [&](int x) { produkt *= x; };
    int prag = 5;
    auto dodaj_ako_veciprag = [prag, &suma](int x) { if (x > prag) suma += x; };

    for (int& x : niz) {
        if (parnost(x)) x = prepolovi(x);
        else x = udvostruci(x);
    }

    for (int x : niz) {
        dodaj_sumu(x);
        dodaj_produkt(x);
        dodaj_ako_veciprag(x);
    }

    cout << "Niz: ";
    for (int x : niz) cout << x << " ";
    cout << "\nSuma: " << suma << "\nProdukt: " << produkt << endl;
    return 0;
}

//4.
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string ime;
    string jmbag;
    int godina;
    int ects;
    double prosjek;
};

void filter_students(Student s[], size_t n,
    void (*akcija)(Student&),
    bool (*filter)(Student&)) {
    for (size_t i = 0; i < n; i++)
        if (filter(s[i])) akcija(s[i]);
}

void ispisi(Student& s) {
    cout << s.ime << " (" << s.godina << " god, " << s.ects << " ECTS, " << s.prosjek << ")" << endl;
}

void povecaj_godinu(Student& s) { s.godina++; }

int main() {
    Student studenti[] = {
        {"Marko", "001", 1, 30, 3.2},
        {"Ana", "002", 1, 10, 4.1},
        {"Luka", "003", 2, 50, 3.9},
        {"Iva", "004", 3, 45, 3.4}
    };
    size_t n = 4;

    auto uvjet1 = [](Student& s) { return s.godina == 1 && s.ects > 0; };
    cout << "Studenti 1. godine s barem jednim ispitom:\n";
    filter_students(studenti, n, ispisi, uvjet1);

    auto uvjet2 = [](Student& s) { return s.prosjek > 3.5; };
    cout << "\nStudenti s prosjekom > 3.5:\n";
    filter_students(studenti, n, ispisi, uvjet2);

    auto uvjet3 = [](Student& s) { return s.ects >= 45; };
    filter_students(studenti, n, povecaj_godinu, uvjet3);

    cout << "\nNakon povecanja godine:\n";
    for (auto& s : studenti) ispisi(s);

    return 0;
}
