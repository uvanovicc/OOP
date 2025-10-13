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
	*/
//3.

int main() {
	using namespace std;
	string s;
	cout << "unesi broj:" << endl;
	cin >> s;
	getline(cin, s);
	for (int i = 0; s[i] != '\0'; i++) {
		char a = s[i];
		if (isalpha(a)) {
			char[s[i]] = toupper(a);
		}
		if (a == ' ') {
			char[s[i]] = '_';
		}
	}
	return 0;
}