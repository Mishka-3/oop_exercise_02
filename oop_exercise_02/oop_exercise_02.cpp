// oop_exercise_02.cpp
//
// Гаврилин Михаил Юрьевич 80-201
// 
// Реализовать класс FazzyNumber для работы с нечеткими числами, которые представляются тройками чисел (x – el, x, x + er). Для чисел A = (A – al, A, A + ar) и B = (B – bl, B, B + br) арифметические операции выполняются по следующим формулам:
//-сложение A + B = (A + B – al – bl, A + B, A + B + ar + br);
//-вычитание A – B = (A – B – al – bl, A – B, A – B + ar + br);
//-умножение A · B = (A ´ B – B ´ al – A ´ bl + al ´ bl, A ´ B, A ´ B + B ´ al + A ´ bl + al ´ bl);
//-обратное число A = (1 / (A + ar), 1 / A, 1 / (A – al)), A > 0;
//-деление A / B = ((A – al) / (B + br), A / B, (A + ar) / (B – bl)), B > 0;
//Считать el = er, то есть число представлено парой <x, e>.
//Реализовать операции сравнения по х.


#include "oop_exercise_02.h"
using namespace std;

class fazzy { // класс fazzy
public:
    double x, e, q, t, k;
    void printfazzy() { // вывод fazzy
        cout << "(" << q << "," << t << "," << k << ")" << "\n";
    }
    fazzy(double a, double b);
    fazzy(double a, double b, double c);
    fazzy operator+(fazzy b);
    fazzy operator-(fazzy b);
    fazzy operator*(fazzy b);
    fazzy operator! () const;
    fazzy operator/(fazzy b);
    int operator^(fazzy b);

};
fazzy::fazzy(double a, double b) { // конструктор 
    x = a;
    e = b;
    q = x - e;
    t = x;
    k = x + e;
}
fazzy::fazzy(double a, double b, double c) { //конструктор 2
    q = a;
    t = b;
    k = c;
}
fazzy  fazzy::operator + (fazzy b) { // перегрузка сложения 
    double a, d, c;
    a = x + b.x - e - b.e;
    d = x + b.x;
    c = x + b.x + e + b.e;
    fazzy f(a, d, c);
    return f;
}
fazzy  fazzy::operator - (fazzy b) { // перегрузка вычитания
    double a, d, c;
    a = x - b.x - e - b.e;
    d = x - b.x;
    c = x - b.x + e + b.e;
    fazzy f(a, d, c);
    return f;
}
fazzy  fazzy::operator * (fazzy b) { // перегрузка умножения
    double a, d, c;
    a = x * b.x - b.x * e - x * b.e + e * b.e;
    d = x * b.x;
    c = x * b.x + b.x * e + x * b.e + e * b.e;
    fazzy f(a, d, c);
    return f;
}
fazzy  fazzy:: operator!() const { // перегрузка ! (! - обратное fazzy)
    double a, d, c;
    a = 1/(x + e);
    d = 1/x;
    c = 1/(x - e);
    fazzy f(a, d, c);
    return f;
}
fazzy  fazzy::operator / (fazzy b) { // перегрузка деления 
    double a, d, c;
    a = (x - e)/(b.x + b.e);
    d = x / b.x;
    c = (x + e) / (b.x - b.e);
    fazzy f(a, d, c);
    return f;
} 
int  fazzy::operator ^ (fazzy b) { // перегрузка ^ (^ - сравнение)
    int t;
    if (x > b.x) {
        t = 1;
        return t;
    }
    else if (x < b.x) {
        t = 0;
        return t;
    }
    else {
        t = -1;
        return t;
    }
}
int main() {
    int k = 0;
    fazzy first(0.0, 0.0);
    while (1) {
        cout << "1. Input fazzy" << "\t" << "2. Print fazzy" << "\t" << "3. Sum" << "\t" << "4.  Substract" << "\t" << "5. Multiply " << "\t" << "6. Reverse" << "\t" << "7. Divide" << "\t" << "8. Compare" << "\t" << "9. Exit" << "\n";
        scanf_s("%d", &k);
        if (k == 1) {
            double a, b;
            cout << "Enter x and e" << '\n';
            cin >> a >> b;
            fazzy p(a, b);
            first = p;
        }
        if (k == 2) {
            first.printfazzy();
        }
        if (k == 3) {
            cout << "Enter x and e of second fazzy" << "\n";
            double c, d;
            fazzy sum(0, 0);
            cin >> c >> d;
            fazzy second(c, d);
            sum = first + second;
            cout << "first+second = ";
            sum.printfazzy();
        }
        if (k == 4) {
            cout << "Enter x and e of second fazzy" << "\n";
            double c, d;
            fazzy subt(0, 0);
            cin >> c >> d;
            fazzy second(c, d);
            subt = first - second;
            cout << "first-second = ";
            subt.printfazzy();
        }
        if (k == 5) {
            cout << "Enter x and e of second fazzy" << "\n";
            double c, d;
            fazzy mult(0, 0);
            cin >> c >> d;
            fazzy second(c, d);
            mult = first * second;
            cout << "first*second = ";
            mult.printfazzy();
        }
        if (k == 6) {
            double c, d;
            fazzy rev(0, 0);
            rev = !first;
            cout << "Revfirst = ";
            rev.printfazzy();
        }
        if (k == 7) {
            cout << "Enter x and e of second fazzy" << "\n";
            double c, d;
            fazzy div(0, 0);
            cin >> c >> d;
            fazzy second(c, d);
            div = first / second;
            cout << "first/second = ";
            div.printfazzy();
        }
        if (k == 8) {
            cout << "Enter x and e of second fazzy" << "\n";
            double c, d;
            int t;
            cin >> c >> d;
            fazzy second(c, d);
            t = first ^ second;
            if (t == 1) { cout << "first fazzy is larger\n"; }
            if (t == 0) { cout << "second fazzy is larger\n"; }
            if (t == -1) { cout << "they are equal\n"; }
        }
        if (k == 9) {
            break;
        }
    }
    return 0;
}
