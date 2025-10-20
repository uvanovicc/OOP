#include <iostream>
using namespace std;
/*
// 1.
int* fibonacci(int n) {
	int* niz = new int[n];
	niz[0] = 1;
	niz[1] = 1;
	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 2] + niz[i - 1];
	}
	return niz;
}

int main() {
	int n;
	cout << "unesi velicinu: ";
	cin >> n;
	int * niz = fibonacci(n);
	for (int i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	delete niz;
	niz = nullptr;
	system("pause");
	return 0;
}

// 2.
struct Vector{
	int* element;
	int logicka;
	int fizicka;
};

Vector vector_new(int pocetni_kapacitet){
	Vector v;
	v.element = new int[pocetni_kapacitet];
	v.logicka = 0;
	v.fizicka = pocetni_kapacitet;
	return v;
};

void vector_delete(Vector& v){
	delete[] v.element;
	v.element = nullptr;
	v.logicka = 0;
	v.fizicka = 0;
};

void vector_push_back(Vector& v, int nelement) {
	if (v.logicka >= v.fizicka) {
		int novi_kapacitet = v.fizicka * 2;
		int* novi_niz = new int[novi_kapacitet];
		for (int i = 0; i < v.logicka; i++) {
			novi_niz[i] = v.element[i];
		}
		delete[] v.element;
		v.element = novi_niz;
		v.fizicka = novi_kapacitet;
	}
	v.element[v.logicka] = nelement;
	v.logicka++;
};

void vector_pop_back(Vector& v) {
	if (v.logicka > 0) {
		v.logicka--;
	}
};

int vector_front(Vector& v) {
	return v.element[0];
};

int vector_back(Vector& v) {
	return v.element[v.logicka - 1];
};

int vector_size(Vector& v) {
	return v.logicka;
};

int main() {
	Vector v = vector_new(2);
	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30);
	vector_push_back(v, 40);

	cout << "prvi element: " << vector_front(v) << endl;
	cout << "zadnji element: " << vector_back(v) << endl;
	cout << "velicina vektora: " << vector_size(v) << endl;

	vector_pop_back(v);
	cout << "nakon pop back, velicina je: " << vector_size(v) << endl;

	cout << "sadrzaj: ";
	for (int i = 0; i < vector_size(v); i++) {
		cout << v.element[i] << " ";
	}
	cout << endl;
	vector_delete(v);
	system("pause");
	return 0;
}
*/