#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    int n;
    int posicionMax = -1, posicionMin = -1;
    cout << "Ingrese la cantidad de numeros decimales: ";
    cin >> n;
    double numeros[n];
    cout << "Ingrese los numeros decimales:" << endl;
    for (int i = 0; i < n; ++i) {
        string entrada;
        cin >> entrada;
        // Reemplaza la coma por punto si existe
        for (char &c : entrada) {
            if (c == ',') c = '.';
        }
        numeros[i] = stod(entrada);
    }

    double maximo = numeric_limits<double>::lowest();
    double minimo = numeric_limits<double>::max();

    for (int i = 0; i < n; ++i) {
        if (numeros[i] > maximo) {
            maximo = numeros[i];
            posicionMax = i;
        }
        if (numeros[i] < minimo) {
            minimo = numeros[i];
            posicionMin = i;
        }
    }

    cout << "Valor maximo: " << maximo << " en la posicion: " << posicionMax << endl;
    cout << "Valor minimo: " << minimo << " en la posicion: " << posicionMin << endl;

    return 0;
}