#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class fraction {
private:
	long long int a, b;

public:
	fraction(long long int x = 0, long long int y = 1)
	{
		this->a = x;
		this->b = y;
	}

	long long int operator[](long long int z) {
		if (z == 0) {
			return a;
		}
		return b;
	}

	fraction operator*(fraction other) {
		return fraction(a *  other.a, b * other.b);
	}

	fraction operator-(fraction other) {
		return fraction(a *  other.b - b * other.a, b * other.b);
	}

	fraction operator/(fraction other) {
		return fraction(a *  other.b, b * other.a);
	}

	fraction operator/(int x) {
		return fraction(a *  x, b);
	}

	friend ostream& operator << (ostream &out, const fraction &w);
};

ostream& operator << (ostream &out, const fraction &w) {
	out << w.a << "/" << w.b;
	return out;
}

int main() {
	long long int a1, a2, b1, b2, c1, c2, d1, d2;
	char f;
	cin >> a1 >> f >> a2 >> b1 >> f >> b2 >> c1 >> f >> c2 >> d1 >> f >> d2;
	fraction a(a1, a2);
	fraction b(b1, b2);
	fraction c(c1, c2);
	fraction d(d1, d2);
	fraction b51 = (d * d) - ((a * 3) / (b * c));
	cout << b51;
	system("pause");
	return 0;
}
