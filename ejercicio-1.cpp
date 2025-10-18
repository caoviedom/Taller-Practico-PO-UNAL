/*
    Escriba un programa en C/C++ que solicite al usuario ingresar dos 
    n´umeros enteros y luego imprima
    la suma, resta, multiplicaci´on y divisi´on de esos n´umeros. 
    Aseg´urese de manejar la divisi´on por ceroadecuadamente. (10 %).
*/
#include <iostream>
using namespace std;
int num1, num2;
double float1, float2;

int main() {
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "Suma de " << num1 << " mas " << num2 << ": " << num1 + num2 << endl;
    cout << "Resta de " << num1 << " menos " << num2 << ": " << num1 - num2 << endl;
    cout << "Multiplicacion de " << num1 << " por " << num2 << ": " << num1 * num2 << endl;
    float1 = num1;
    float2 = num2;
    if (float2 != 0) {
        cout << "Division de " << num1 << " entre " << num2 << ": " << float1 / float2 << endl;
    } else {
        cout << "No hay resultado, no se puede dividir por cero." << endl;
    }

    return 0;
}
