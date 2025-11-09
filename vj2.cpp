#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>  
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
//3.
double** alociraj_matricu(int m, int n) {
    double** mat = new double*[m];
    for (int i = 0; i < m; i++)
        mat[i] = new double[n];
    return mat;
}

void dealociraj_matricu(double** mat, int m) {
    for (int i = 0; i < m; i++)
        delete[] mat[i];
    delete[] mat;
}

void unos_matrice(double** mat, int m, int n) {
    cout << "Unesi elemente matrice (" << m << "x" << n << "):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "mat[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
    }
}

void generiraj_matricu(double** mat, int m, int n, double a, double b) {
    srand((unsigned)time(nullptr));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double randomValue = a + static_cast<double>(rand()) / RAND_MAX * (b - a);
            mat[i][j] = randomValue;
        }
    }
}

void ispisi_matricu(double** mat, int m, int n) {
    cout << fixed << setprecision(4);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << mat[i][j];
        }
        cout << endl;
    }
}

double** zbroji_matrice(double** A, double** B, int m, int n) {
    double** C = alociraj_matricu(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double** oduzmi_matrice(double** A, double** B, int m, int n) {
    double** C = alociraj_matricu(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double** pomnozi_matrice(double** A, int m1, int n1, double** B, int m2, int n2) {
    if (n1 != m2) {
        cout << "Mnozenje nije moguce! Broj stupaca prve matrice mora biti jednak broju redaka druge." << endl;
        return nullptr;
    }

    double** C = alociraj_matricu(m1, n2);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

double** transponiraj_matricu(double** A, int m, int n) {
    double** T = alociraj_matricu(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}

int main() {
    int m, n;
    cout << "Unesi broj redaka i stupaca matrice: ";
    cin >> m >> n;

    double** A = alociraj_matricu(m, n);
    double** B = alociraj_matricu(m, n);

    cout << "\n--- Generiranje matrica A i B ---" << endl;
    generiraj_matricu(A, m, n, 1.0, 10.0);
    generiraj_matricu(B, m, n, 1.0, 10.0);

    cout << "\nMatrica A:" << endl;
    ispisi_matricu(A, m, n);
    cout << "\nMatrica B:" << endl;
    ispisi_matricu(B, m, n);

    cout << "\n--- Zbroj matrica (A + B) ---" << endl;
    double** C = zbroji_matrice(A, B, m, n);
    ispisi_matricu(C, m, n);

    cout << "\n--- Razlika matrica (A - B) ---" << endl;
    double** D = oduzmi_matrice(A, B, m, n);
    ispisi_matricu(D, m, n);

    cout << "\n--- Transponirana matrica A ---" << endl;
    double** T = transponiraj_matricu(A, m, n);
    ispisi_matricu(T, n, m);

    if (n == m) {
        cout << "\n--- Umnozak matrica (A * B) ---" << endl;
        double** M = pomnozi_matrice(A, m, n, B, m, n);
        if (M) ispisi_matricu(M, m, n);
        dealociraj_matricu(M, m);
    }

    dealociraj_matricu(A, m);
    dealociraj_matricu(B, m);
    dealociraj_matricu(C, m);
    dealociraj_matricu(D, m);
    dealociraj_matricu(T, n);

    system("pause");
    return 0;
}
