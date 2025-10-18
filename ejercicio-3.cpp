/*  
    Escriba un programa en C/C++ que lea una cadena de caracteres y cuente el n´umero de vocales
    presentes en la cadena.
*/
#include <iostream>
#include <string>
using namespace std;
string cadena;

int main() {
    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, cadena);

    int contadorVocales = 0;
    for (char c : cadena) {
        c = tolower(c);  // Convertir a minúscula para simplificar la comparación
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contadorVocales++;
        }
    }

    cout << "El numero de vocales en la cadena es: " << contadorVocales << endl;

    return 0;
}