#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

/**
 * Calcula la norma L2 (euclidiana) de un arreglo de numeros decimales
 * La norma L2 es la raiz cuadrada de la suma de los cuadrados de todos los elementos
 * Formula: ||x||2 = raiz(x1^2 + x2^2 + ... + xn^2)
 */
double calcularNormaL2(const vector<double>& arreglo) {
    double sumaDeCuadrados = 0.0;
    
    // Sumar el cuadrado de cada elemento
    for (double elemento : arreglo) {
        sumaDeCuadrados += elemento * elemento;
    }
    
    // Retornar la raíz cuadrada de la suma
    return sqrt(sumaDeCuadrados);
}

/**
 * Calcula la norma Linfinito (maxima) de un arreglo de numeros decimales
 * La norma Linfinito es el valor absoluto del elemento con mayor magnitud
 * Formula: ||x||infinito = max(|x1|, |x2|, ..., |xn|)
 */
double calcularNormaLinfinito(const vector<double>& arreglo) {
    if (arreglo.empty()) {
        return 0.0;
    }
    
    double maximoValorAbsoluto = abs(arreglo[0]);
    
    // Buscar el elemento con mayor valor absoluto
    for (double elemento : arreglo) {
        double valorAbsoluto = abs(elemento);
        if (valorAbsoluto > maximoValorAbsoluto) {
            maximoValorAbsoluto = valorAbsoluto;
        }
    }
    
    return maximoValorAbsoluto;
}

/**
 * Función principal que solicita datos al usuario y calcula ambas normas
 */
void procesarArregloYCalcularNormas() {
    int tamaño;
    
    cout << "=== CALCULO DE NORMAS L2 Y Linfinito ===" << endl;
    cout << "\nIngrese el tamanio del arreglo: ";
    cin >> tamaño;
    
    // Validar que el tamanio sea positivo
    if (tamaño <= 0) {
        cout << "Error: El tamanio debe ser un numero positivo." << endl;
        return;
    }
    
    // Crear el vector con el tamanio especificado
    vector<double> arreglo(tamaño);
    
    // Solicitar los elementos del arreglo
    cout << "\nIngrese los " << tamaño << " elementos del arreglo:" << endl;
    for (int i = 0; i < tamaño; i++) {
        cout << "Elemento " << (i + 1) << ": ";
        cin >> arreglo[i];
    }
    
    // Calcular ambas normas
    double normaL2 = calcularNormaL2(arreglo);
    double normaLinfinito = calcularNormaLinfinito(arreglo);
    
    // Mostrar resultados con formato
    cout << fixed << setprecision(6);
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Norma L2 (Euclidiana): " << normaL2 << endl;
    cout << "Norma Linfinito (Maxima): " << normaLinfinito << endl;
    
    // Mostrar interpretacion
    cout << "\n=== INTERPRETACION ===" << endl;
    cout << "* La norma L2 representa la 'longitud' del vector en el espacio euclidiano." << endl;
    cout << "* La norma Linfinito representa la mayor desviacion en cualquier dimension." << endl;
}

int main() {
    // Configurar la consola para caracteres en español (Windows)
    system("chcp 65001 > nul");
    
    procesarArregloYCalcularNormas();
    return 0;
}