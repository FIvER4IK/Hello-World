include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>


using namespace std;

template <typename T>
class m_vector{
private:
    T *_array;
    int _arraySize;
public:
    void push_back(T data){
        T *_result = new T[++this->_arraySize];
        for (int index = 0; index < this->_arraySize; index++){
            if (index != this->_arraySize - 1){
                _result[index] = this->_array[index];
            }
            else{
                _result[index] = data;
                break;
            }
        }
        delete[] this->_array;
        this->_array = _result;
    }

    T pop(){
        return this->popIndex(this->_arraySize - 1);
    }

    T operator [](int index){
        return this->_array[index];
    }

    int size(){
        return this->_arraySize;
    }

    void pushIndex(T data, int index)
    {
        int oldSize = this->_arraySize;
        this->_arraySize = (this->_arraySize >= index) ? (++this->_arraySize) : (this->_arraySize + (index - this->_arraySize));
        T *_result = new T[this->_arraySize];
        int arrIndex = 0;
        for (int index2 = 0; index2 < this->_arraySize; index2++){
            if (index2 == index){
                _result[index2] = data;
                continue;
            }

            if (arrIndex != oldSize){
                _result[index2] = this->_array[arrIndex++];
            }
        }
        delete[] this->_array;
        this->_array = _result;
    }

    T popIndex(int index)
    {
        T *_result = new T[--this->_arraySize];

        T resItem;

        int resIndex = 0;

        for (int index2 = 0; index2 < this->_arraySize + 1; index2++)
        {
            T item = this->_array[index2];

            if (index == index2)
            {
                resItem = item;
                continue;
            }
            _result[resIndex++] = this->_array[index2];

        }


        delete[] this->_array;
        this->_array = _result;
        return resItem;

    }

    void reverse() {
        for (int i = 0; i < this->_arraySize / 2 + this->_arraySize % 2; i++) {
            swap(this->_array[i], this->_array[this->_arraySize - 1 - i]);
        }
    }


    m_vector()
    {
        this->_arraySize = 0;
        this->_array = new T[this->_arraySize];
    }

};



class Fraction {
private:
    long long num, denum;
public:
    Fraction(long long num = 0, long long denum = 1) {
        this->num = num;
        this->denum = denum;
    }



    long long gcd(long long a, long long b) {
        while (a != 0 && b != 0) {
            if (a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        }
        return a + b;
    }



    void normalize() {
        if (this->denum < 0 && this->num) {
            this->num *= -1;
            this->denum *= -1;
        }
        else if (this->num > 0 && this->denum < 0) {
            this->num *= -1;
            this->denum *= -1;
        }
        int sign = 1;
        long long tmp = gcd(abs(this->num), this->denum);
        if (this->num < 0) {
            sign = -1;
        }
        this->num = abs(this->num) / tmp * sign;
        this->denum = this->denum / tmp;
    }



    friend bool operator<(double &b, Fraction &a) {
        return b < (double)a.num / (double)a.denum;
    }
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
        Fraction tmp(lhs.num*rhs.denum
                     + rhs.num*lhs.denum,
                     lhs.denum*rhs.denum);
        tmp.normalize();
        return tmp;
    }
    friend Fraction operator+=(Fraction& lhs, const Fraction& rhs) {
        Fraction tmp(lhs.num*rhs.denum
                     + rhs.num*lhs.denum,
                     lhs.denum*rhs.denum);
        tmp.normalize();
        lhs = tmp;
        return lhs;
    }
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
        Fraction tmp(lhs.num*rhs.denum
                     - rhs.num*lhs.denum,
                     lhs.denum*rhs.denum);
        return tmp;
    }
    friend Fraction operator-=(Fraction& lhs, const Fraction& rhs) {
        Fraction tmp(lhs.num*rhs.denum
                     - rhs.num*lhs.denum,
                     lhs.denum*rhs.denum);
        tmp.normalize();
        lhs = tmp;
        return lhs;
    }
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
        Fraction tmp(lhs.num*rhs.num,
                     lhs.denum*rhs.denum);
        tmp.normalize();
        return tmp;
    }
    friend Fraction operator*=(Fraction& lhs, const Fraction& rhs) {
        Fraction tmp(lhs.num*rhs.num,
                     lhs.denum*rhs.denum);
        tmp.normalize();
        lhs = tmp;
        return lhs;
    }
    friend Fraction operator*(int lhs, const Fraction& rhs) {
        Fraction tmp(lhs*rhs.num, rhs.denum);
        tmp.normalize();
        return tmp;
    }
    friend Fraction operator*(const Fraction& rhs, int lhs) {
        Fraction tmp(lhs*rhs.num, rhs.denum);
        tmp.normalize();
        return tmp;
    }
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
        Fraction tmp(lhs.num*rhs.denum,
                     lhs.denum*rhs.num);
        tmp.normalize();
        return tmp;
    }
    friend bool operator==(const Fraction &a, const Fraction &b) {
        double c, d;
        c = (double)a.num / a.denum;
        d = (double)b.num / b.denum;
        return c == d;
    }
    friend bool operator>(const Fraction &b, const Fraction &c) {
        if (((b.num*c.denum - c.num*b.denum) > 0 && b.denum * c.denum > 0) || (((b.num*c.denum - c.num*b.denum) < 0 && b.denum * c.denum < 0))) {
            return true;
        }
        else {
            return false;
        }
    }
    friend bool operator<(const Fraction &a, const Fraction &b) {
        if (!(a > b) && !(a == b)) {
            return true;
        }
        else {
            return false;
        }
    }
    friend Fraction operator%(const Fraction &a, int n) {
        n *= a.denum;
        return Fraction(a.num % n, a.denum);
    }
    friend Fraction operator%(Fraction &a, Fraction &b) {
        if (a.denum != a.num) {
            a.num *= b.denum;
            b.num *= a.denum;
        }
        return Fraction(a.num%b.num, a.denum*b.denum);
    }
    friend ostream &operator<<(ostream &output, const Fraction &d) {
        output << d.num << "/" << d.denum;
        return output;
    }

    friend istream &operator >> (istream  &input, Fraction &D) {
        char c;
        input >> D.num >> c >> D.denum;
        return input;
    }
};
template <typename T>
void printVector(m_vector<T> vector)
{
    int size = vector.size();
    for (int index = 0; index < vector.size(); index++)
    {
        cout << vector[index] << ' ';
    }
    cout << endl;
}

int main() {
    int a;
    cin >> a;
    cout << a << endl;
    m_vector<int> v;
    while (a--) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    v.reverse();
    printVector(v);

    cin >> a;
    cout << a << endl;
    m_vector<char> vv;
    while (a--) {
        char tmp;
        cin >> tmp;
        vv.push_back(tmp);
    }
    vv.reverse();
    printVector(vv);

    cin >> a;
    cout << a << endl;
    m_vector<Fraction> vvv;
    while (a--) {
        Fraction tmp;
        cin >> tmp;
        tmp.normalize();
        vvv.push_back(tmp);
    }
    vvv.reverse();
    printVector(vvv);

    system("pause");
    return 0;
}