#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

using namespace std;

// Tipo alias para hacer el código más legible
using Matriz = vector<vector<double>>;

const double TOLERANCIA_CERO = 1e-10; // Precisión para considerar un número como cero

/**
 * Imprime una matriz en formato legible
 */
void imprimirMatriz(const Matriz& matriz, const wstring& titulo = L"") {
    if (!titulo.empty()) {
        wcout << titulo << endl;
    }
    
    for (const auto& fila : matriz) {
        for (double elemento : fila) {
            wcout << setw(12) << fixed << setprecision(4) << elemento;
        }
        wcout << endl;
    }
    wcout << endl;
}

/**
 * Verifica si un número es prácticamente cero
 */
bool esCero(double numero) {
    return abs(numero) < TOLERANCIA_CERO;
}

/**
 * Calcula la inversa de una matriz usando el método de Gauss-Jordan
 */
bool calcularInversaMatriz(const Matriz& matrizOriginal, Matriz& matrizInversa) {
    int dimension = static_cast<int>(matrizOriginal.size());
    Matriz matrizAumentada(dimension, vector<double>(2 * dimension, 0.0));

    for (int fila = 0; fila < dimension; fila++) {
        for (int col = 0; col < dimension; col++) {
            matrizAumentada[fila][col] = matrizOriginal[fila][col];
        }
        matrizAumentada[fila][dimension + fila] = 1.0;
    }

    wcout << L"Matriz aumentada inicial [A | I]:" << endl;
    imprimirMatriz(matrizAumentada);
    
    for (int pivoteActual = 0; pivoteActual < dimension; pivoteActual++) {
        int filaMejorPivote = pivoteActual;
        double valorMejorPivote = abs(matrizAumentada[pivoteActual][pivoteActual]);
        
        for (int fila = pivoteActual + 1; fila < dimension; fila++) {
            double valorCandidato = abs(matrizAumentada[fila][pivoteActual]);
            if (valorCandidato > valorMejorPivote) {
                valorMejorPivote = valorCandidato;
                filaMejorPivote = fila;
            }
        }
        
        if (esCero(valorMejorPivote)) {
            wcout << L"¡MATRIZ NO INVERTIBLE!" << endl;
            wcout << L"Razón: La columna " << (pivoteActual + 1) 
                  << L" tiene todos ceros en la diagonal y debajo." << endl;
            return false;
        }
        
        if (filaMejorPivote != pivoteActual) {
            swap(matrizAumentada[pivoteActual], matrizAumentada[filaMejorPivote]);
            wcout << L"Intercambiando fila " << (pivoteActual + 1) 
                  << L" con fila " << (filaMejorPivote + 1) << endl;
        }
        
        double valorPivote = matrizAumentada[pivoteActual][pivoteActual];
        for (int col = 0; col < 2 * dimension; col++) {
            matrizAumentada[pivoteActual][col] /= valorPivote;
        }
        
        wcout << L"Después de normalizar la fila " << (pivoteActual + 1) << L":" << endl;
        imprimirMatriz(matrizAumentada);
        
        for (int fila = 0; fila < dimension; fila++) {
            if (fila != pivoteActual) {
                double factor = matrizAumentada[fila][pivoteActual];
                for (int col = 0; col < 2 * dimension; col++) {
                    matrizAumentada[fila][col] -= factor * matrizAumentada[pivoteActual][col];
                }
            }
        }
        
        wcout << L"Después de eliminar en la columna " << (pivoteActual + 1) << L":" << endl;
        imprimirMatriz(matrizAumentada);
    }
    
    matrizInversa.resize(dimension, vector<double>(dimension));
    for (int fila = 0; fila < dimension; fila++) {
        for (int col = 0; col < dimension; col++) {
            matrizInversa[fila][col] = matrizAumentada[fila][dimension + col];
        }
    }
    
    return true;
}

bool esMatrizCuadrada(const Matriz& matriz) {
    if (matriz.empty()) return false;
    size_t numeroFilas = matriz.size();
    for (const auto& fila : matriz) {
        if (fila.size() != numeroFilas) return false;
    }
    return true;
}

Matriz multiplicarMatrices(const Matriz& A, const Matriz& B) {
    int filasA = static_cast<int>(A.size());
    int columnasA = static_cast<int>(A[0].size());
    int columnasB = static_cast<int>(B[0].size());
    Matriz resultado(filasA, vector<double>(columnasB, 0.0));
    for (int i = 0; i < filasA; i++)
        for (int j = 0; j < columnasB; j++)
            for (int k = 0; k < columnasA; k++)
                resultado[i][j] += A[i][k] * B[k][j];
    return resultado;
}

void procesarInversionMatriz() {
    int dimension;
    wcout << L"=== INVERSIÓN DE MATRIZ ===" << endl;
    wcout << L"\nIngrese la dimensión de la matriz cuadrada: ";
    wcin >> dimension;

    if (dimension <= 0) {
        wcout << L"Error: La dimensión debe ser positiva." << endl;
        return;
    }

    Matriz matriz(dimension, vector<double>(dimension));
    wcout << L"\nIngrese los elementos de la matriz (fila por fila):" << endl;
    for (int fila = 0; fila < dimension; fila++) {
        wcout << L"Fila " << (fila + 1) << L":" << endl;
        for (int col = 0; col < dimension; col++) {
            wcout << L"  Elemento [" << (fila + 1) << L"," << (col + 1) << L"]: ";
            wcin >> matriz[fila][col];
        }
    }

    if (!esMatrizCuadrada(matriz)) {
        wcout << L"Error: La matriz no es cuadrada." << endl;
        return;
    }

    wcout << L"\n" << wstring(60, L'=') << endl;
    imprimirMatriz(matriz, L"Matriz original:");

    Matriz matrizInversa;
    bool esInvertible = calcularInversaMatriz(matriz, matrizInversa);

    if (esInvertible) {
        wcout << wstring(60, L'=') << endl;
        imprimirMatriz(matrizInversa, L"✓ MATRIZ INVERSA:");
        wcout << L"Verificación (A × A⁻¹):" << endl;
        Matriz verificacion = multiplicarMatrices(matriz, matrizInversa);
        imprimirMatriz(verificacion);
    } else {
        wcout << L"\n✗ LA MATRIZ NO TIENE INVERSA" << endl;
        wcout << L"Una matriz no tiene inversa cuando:" << endl;
        wcout << L"  • Su determinante es cero" << endl;
        wcout << L"  • Sus filas o columnas son dependientes" << endl;
        wcout << L"  • Es singular" << endl;
    }
}

int main() {
    // Configurar la consola para UTF-8 y salida wide
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    procesarInversionMatriz();
    return 0;
}
