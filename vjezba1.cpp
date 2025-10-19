#include <iostream>
#include <iomanip>
#include <cctype>
/*
//1.
int main()
{
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::boolalpha << flag << std::endl;
	int a = 255;
	std::cout << "hex " << std::hex << a << std::endl;
	std::cout << "dec " << std::dec << a << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;
	double pi = 3.141592;
	std::cout << "pi = " << std::scientific << std::uppercase;
	std::cout << std::setprecision(7) << std::setw(20);
	std::cout << std::setfill('0');
	std::cout << pi << std::endl;
	system("pause");
}

//2.
	int limit(int vrijednost, int low = 0, int high = 100) {
		if (vrijednost < low) return low;
		if (vrijednost >= high) return high;
		return vrijednost;
	}
	double limit(double vrijednost, double low = 0.0, double high = 100.0) {
		if (vrijednost < low) return low;
		if (vrijednost >= high) return high;
		return vrijednost;
	}
	int main() {
		int vrijednost;
		std::cout << "unesi broj:" << std::endl;
		std::cin >> vrijednost;
		int rezultat = limit(vrijednost);
		std::cout << "vrijednost: " << rezultat << std::endl;
		system("pause");
		return 0;
	}
	
//3.

int main() {
    std::string s;
    std::cout << "Unesi red: ";
    std::getline(std::cin, s);

    for (char &c : s) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            c = std::toupper(static_cast<unsigned char>(c));
        } else if (std::isdigit(static_cast<unsigned char>(c))) {
            c = '*';
        } else if (c == ' ' || c == '\t') {
            c = '_';
        }
    }

    std::cout << "Rezultat: " << s << std::endl;
    return 0;
}
*/
//4

char& at(char niz[], int i) {
    return niz[i];
}

int main() {
    char niz[] = "Split";
    int i;

    std::cout << "Niz: " << niz << std::endl;
    std::cout << "Unesi indeks koji zelis povecati: ";
    std::cin >> i;

    at(niz, i)++;
    std::cout << "Nakon povecanja: " << niz << std::endl;

    return 0;
}
