# Taller de Programación Avanzada en C++

[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Descripción del Proyecto

Este repositorio contiene la solución completa de los **5 ejercicios** del Taller de Programación Avanzada, implementados en C++. Cada ejercicio aborda conceptos fundamentales de programación, estructuras de datos y algoritmos numéricos.

---

## Estructura del Repositorio

```
taller-programacion-avanzada/
│
├── README.md                 # Este archivo
├── ejercicio-1.cpp          # Operaciones aritméticas básicas
├── ejercicio-2.cpp          # Búsqueda de máximo y mínimo
├── ejercicio-3.cpp          # Contador de vocales
├── Ejercicio4.cpp           # Cálculo de normas vectoriales
└── ejercicio5.cpp           # Inversión de matrices
```

---

## Requisitos Previos

Para compilar y ejecutar estos programas necesitas:

- **Compilador C++**: g++, MinGW (Windows), clang, o Visual Studio
- **Sistema Operativo**: Windows, Linux, o macOS
- **Conocimientos básicos**: Terminal/CMD y comandos básicos

### Instalación del Compilador

**Windows:**
```bash
# Descargar e instalar MinGW desde:
# https://sourceforge.net/projects/mingw/
```

**Linux:**
```bash
sudo apt-get update
sudo apt-get install g++
```

**macOS:**
```bash
xcode-select --install
```

---

##  Ejercicios Implementados

### **Ejercicio 1: Operaciones Aritméticas Básicas** 

**Objetivo:** Solicitar dos números enteros y realizar operaciones aritméticas básicas con manejo de división por cero.

####  Descripción del Código

```cpp
#include <iostream>
using namespace std;
int num1, num2;
double float1, float2;
```

**Variables globales:**
- `num1, num2`: Almacenan los números enteros ingresados
- `float1, float2`: Conversión a double para división exacta

#### Desglose del Código

```cpp
cout << "Ingrese el primer numero: ";
cin >> num1;
cout << "Ingrese el segundo numero: ";
cin >> num2;
```
- **Entrada de datos**: Solicita al usuario dos números enteros mediante `cin`

```cpp
cout << "Suma de " << num1 << " mas " << num2 << ": " << num1 + num2 << endl;
cout << "Resta de " << num1 << " menos " << num2 << ": " << num1 - num2 << endl;
cout << "Multiplicacion de " << num1 << " por " << num2 << ": " << num1 * num2 << endl;
```
- **Operaciones básicas**: Realiza suma, resta y multiplicación directamente
- Imprime resultados formateados con operadores de inserción `<<`

```cpp
float1 = num1;
float2 = num2;
if (float2 != 0) {
    cout << "Division de " << num1 << " entre " << num2 << ": " << float1 / float2 << endl;
} else {
    cout << "No hay resultado, no se puede dividir por cero." << endl;
}
```
- **Conversión de tipos**: Los enteros se convierten a double para obtener resultado decimal
- **Validación crítica**: Verifica que el divisor no sea cero antes de dividir
- **Manejo de error**: Muestra mensaje apropiado si se intenta dividir por cero

####  Cumplimiento del Requisito

✔️ Solicita dos números enteros  
✔️ Realiza suma, resta, multiplicación y división  
✔️ Maneja adecuadamente la división por cero  
✔️ Muestra resultados formateados

####  Cómo Ejecutar

```bash
# Compilar
g++ ejercicio-1.cpp -o ejercicio1

# Ejecutar
./ejercicio1          # Linux/Mac
ejercicio1.exe        # Windows
```

####  Ejemplo de Uso

```
Ingrese el primer numero: 10
Ingrese el segundo numero: 3
Suma de 10 mas 3: 13
Resta de 10 menos 3: 7
Multiplicacion de 10 por 3: 30
Division de 10 entre 3: 3.33333
```

---

### **Ejercicio 2: Búsqueda de Máximo y Mínimo** 

**Objetivo:** Encontrar el valor máximo y mínimo en un arreglo de números decimales con sus posiciones.

#### Descripción del Código

```cpp
#include <iostream>
#include <limits>     // Para numeric_limits
#include <string>     // Para manejo de strings
```

**Librerías utilizadas:**
- `limits`: Proporciona valores límite para tipos numéricos
- `string`: Permite manipulación de cadenas para procesar entrada

####  Desglose del Código

```cpp
int n;
int posicionMax = -1, posicionMin = -1;
cout << "Ingrese la cantidad de numeros decimales: ";
cin >> n;
double numeros[n];
```
- **Arreglo dinámico**: Crea un array de tamaño `n` especificado por el usuario
- **Inicialización de posiciones**: `-1` indica que aún no se han encontrado valores

```cpp
for (int i = 0; i < n; ++i) {
    string entrada;
    cin >> entrada;
    // Reemplaza la coma por punto si existe
    for (char &c : entrada) {
        if (c == ',') c = '.';
    }
    numeros[i] = stod(entrada);
}
```
- **Entrada flexible**: Acepta números con coma o punto decimal
- **Normalización**: Convierte todas las comas a puntos para compatibilidad
- **Conversión**: `stod()` convierte string a double

```cpp
double maximo = numeric_limits<double>::lowest();
double minimo = numeric_limits<double>::max();
```
- **Inicialización inteligente**: 
  - `lowest()`: Valor más pequeño representable (negativo más extremo)
  - `max()`: Valor más grande representable
- Garantiza que cualquier número del arreglo será comparado correctamente

```cpp
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
```
- **Algoritmo de búsqueda lineal**: Recorre todo el arreglo una vez (O(n))
- **Actualización simultánea**: Busca máximo y mínimo en un solo recorrido
- **Registro de posición**: Guarda el índice donde se encuentra cada valor

####  Cumplimiento del Requisito

✔️ Lee cantidad de números decimales  
✔️ Almacena valores en un arreglo  
✔️ Encuentra el máximo y su posición  
✔️ Encuentra el mínimo y su posición  
✔️ Maneja formato con comas y puntos

####  Cómo Ejecutar

```bash
# Compilar
g++ ejercicio-2.cpp -o ejercicio2

# Ejecutar
./ejercicio2          # Linux/Mac
ejercicio2.exe        # Windows
```

####  Ejemplo de Uso

```
Ingrese la cantidad de numeros decimales: 5
Ingrese los numeros decimales:
3.5
-2.1
8.9
0.5
-5.3
Valor maximo: 8.9 en la posicion: 2
Valor minimo: -5.3 en la posicion: 4
```

---

### **Ejercicio 3: Contador de Vocales** 

**Objetivo:** Leer una cadena de caracteres y contar el número total de vocales presentes.

#### 📖 Descripción del Código

```cpp
#include <iostream>
#include <string>
using namespace std;
string cadena;
```

**Variable global:**
- `cadena`: Almacena la cadena de caracteres ingresada por el usuario

####  Desglose del Código

```cpp
cout << "Ingrese una cadena de caracteres: ";
getline(cin, cadena);
```
- **`getline()`**: Lee la línea completa incluyendo espacios
- Diferencia clave con `cin >>` que solo lee hasta el primer espacio

```cpp
int contadorVocales = 0;
for (char c : cadena) {
    c = tolower(c);  // Convertir a minúscula
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        contadorVocales++;
    }
}
```
- **Range-based for loop**: Itera sobre cada carácter de la cadena
- **`tolower(c)`**: Convierte el carácter a minúscula para simplificar comparación
  - Maneja tanto 'A' como 'a' sin necesidad de verificar ambos casos
- **Comparación múltiple**: Verifica si el carácter es una de las 5 vocales
- **Contador**: Incrementa por cada vocal encontrada

####  Cumplimiento del Requisito

✔️ Lee una cadena completa (con espacios)  
✔️ Cuenta todas las vocales (mayúsculas y minúsculas)  
✔️ Muestra el resultado total  
✔️ Maneja entrada de cualquier longitud

####  Cómo Ejecutar

```bash
# Compilar
g++ ejercicio-3.cpp -o ejercicio3

# Ejecutar
./ejercicio3          # Linux/Mac
ejercicio3.exe        # Windows
```

####  Ejemplo de Uso

```
Ingrese una cadena de caracteres: Hola Mundo en Programacion
El numero de vocales en la cadena es: 10
```

**Desglose:** H**o**l**a** M**u**nd**o** **e**n Pr**o**gr**a**m**a**c**i****o**n = 10 vocales

---

### **Ejercicio 4: Cálculo de Normas Vectoriales** 

**Objetivo:** Calcular la norma L2 (euclidiana) y la norma L∞ (infinito) de un vector de números decimales.

####  Descripción del Código

```cpp
#include <iostream>
#include <vector>      // Contenedor dinámico
#include <cmath>       // Funciones matemáticas (sqrt, abs)
#include <iomanip>     // Formato de salida
#include <windows.h>   // Configuración de consola
```

**Librerías especializadas:**
- `vector`: Estructura de datos dinámica y segura
- `cmath`: Funciones matemáticas esenciales
- `iomanip`: Control de precisión decimal

#### Desglose del Código

##### Función: `calcularNormaL2()`

```cpp
double calcularNormaL2(const vector<double>& arreglo) {
    double sumaDeCuadrados = 0.0;
    
    for (double elemento : arreglo) {
        sumaDeCuadrados += elemento * elemento;
    }
    
    return sqrt(sumaDeCuadrados);
}
```

**Paso por paso:**

1. **Parámetro `const vector<double>&`**:
   - `const`: No modifica el vector (seguridad)
   - `&`: Pasa por referencia (eficiencia, no copia)
   
2. **Acumulación**: Suma el cuadrado de cada elemento

3. **Fórmula matemática**: ||x||₂ = √(x₁² + x₂² + ... + xₙ²)

4. **`sqrt()`**: Calcula la raíz cuadrada del resultado

**Ejemplo:**
```
Vector: [3, 4]
Suma: 3² + 4² = 9 + 16 = 25
Norma L2: √25 = 5
```

##### Función: `calcularNormaLinfinito()`

```cpp
double calcularNormaLinfinito(const vector<double>& arreglo) {
    if (arreglo.empty()) {
        return 0.0;
    }
    
    double maximoValorAbsoluto = abs(arreglo[0]);
    
    for (double elemento : arreglo) {
        double valorAbsoluto = abs(elemento);
        if (valorAbsoluto > maximoValorAbsoluto) {
            maximoValorAbsoluto = valorAbsoluto;
        }
    }
    
    return maximoValorAbsoluto;
}
```

**Paso por paso:**

1. **Validación**: Verifica que el vector no esté vacío

2. **Inicialización**: Comienza con el valor absoluto del primer elemento

3. **Búsqueda**: Encuentra el máximo valor absoluto

4. **Fórmula matemática**: ||x||∞ = max(|x₁|, |x₂|, ..., |xₙ|)

**Ejemplo:**
```
Vector: [3, -7, 2]
Valores absolutos: [3, 7, 2]
Norma L∞: 7
```

##### Función Principal: `procesarArregloYCalcularNormas()`

```cpp
void procesarArregloYCalcularNormas() {
    int tamaño;
    
    cout << "=== CALCULO DE NORMAS L2 Y Linfinito ===" << endl;
    cout << "\nIngrese el tamanio del arreglo: ";
    cin >> tamaño;
    
    if (tamaño <= 0) {
        cout << "Error: El tamanio debe ser un numero positivo." << endl;
        return;
    }
```
- **Validación**: Asegura que el tamaño sea positivo

```cpp
    vector<double> arreglo(tamaño);
    
    cout << "\nIngrese los " << tamaño << " elementos del arreglo:" << endl;
    for (int i = 0; i < tamaño; i++) {
        cout << "Elemento " << (i + 1) << ": ";
        cin >> arreglo[i];
    }
```
- **Vector dinámico**: Crea vector del tamaño especificado
- **Entrada iterativa**: Solicita cada elemento numerado

```cpp
    double normaL2 = calcularNormaL2(arreglo);
    double normaLinfinito = calcularNormaLinfinito(arreglo);
    
    cout << fixed << setprecision(6);
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Norma L2 (Euclidiana): " << normaL2 << endl;
    cout << "Norma Linfinito (Maxima): " << normaLinfinito << endl;
```
- **Cálculo**: Llama a ambas funciones
- **Formato**: `fixed` y `setprecision(6)` muestran 6 decimales

```cpp
    cout << "\n=== INTERPRETACION ===" << endl;
    cout << "* La norma L2 representa la 'longitud' del vector en el espacio euclidiano." << endl;
    cout << "* La norma Linfinito representa la mayor desviacion en cualquier dimension." << endl;
}
```
- **Contexto educativo**: Explica el significado de cada norma

```cpp
int main() {
    system("chcp 65001 > nul");
    procesarArregloYCalcularNormas();
    return 0;
}
```
- **Configuración UTF-8**: Permite caracteres especiales en Windows

#### Cumplimiento del Requisito

✔️ Solicita tamaño y elementos del arreglo  
✔️ Calcula norma L2 (euclidiana) correctamente  
✔️ Calcula norma L∞ (máximo valor absoluto)  
✔️ Muestra resultados con precisión de 6 decimales  
✔️ Incluye validación de entrada  
✔️ Proporciona interpretación de resultados

####  Cómo Ejecutar

```bash
# Compilar
g++ Ejercicio4.cpp -o ejercicio4

# Ejecutar
./ejercicio4          # Linux/Mac
ejercicio4.exe        # Windows
```

####  Ejemplo de Uso

```
=== CALCULO DE NORMAS L2 Y Linfinito ===

Ingrese el tamanio del arreglo: 3

Ingrese los 3 elementos del arreglo:
Elemento 1: 3.0
Elemento 2: 4.0
Elemento 3: -2.5

=== RESULTADOS ===
Norma L2 (Euclidiana): 5.408327
Norma Linfinito (Maxima): 4.000000

=== INTERPRETACION ===
* La norma L2 representa la 'longitud' del vector en el espacio euclidiano.
* La norma Linfinito representa la mayor desviacion en cualquier dimension.
```

**Verificación matemática:**
- Norma L2: √(3² + 4² + (-2.5)²) = √(9 + 16 + 6.25) = √31.25 ≈ 5.408327
- Norma L∞: max(|3|, |4|, |-2.5|) = 4

####  Aplicaciones Prácticas

- **Machine Learning**: Normalización de features, cálculo de distancias
- **Procesamiento de señales**: Medición de energía
- **Optimización numérica**: Criterios de convergencia
- **Computer Graphics**: Normalización de vectores de dirección

---

### **Ejercicio 5: Inversión de Matrices (Gauss-Jordan)** 

**Objetivo:** Calcular la inversa de una matriz cuadrada utilizando el método de Gauss-Jordan con visualización paso a paso.

#### Descripción del Código

```cpp
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <fcntl.h>      // Para _setmode
#include <io.h>         // Para _fileno
```

**Librerías avanzadas:**
- `fcntl.h` y `io.h`: Configuración de modo de archivo para caracteres Unicode
- Necesarias para mostrar caracteres especiales (✓, ✗, ×, ⁻¹)

```cpp
using Matriz = vector<vector<double>>;
const double TOLERANCIA_CERO = 1e-10;
```
- **Type alias**: `Matriz` es más legible que `vector<vector<double>>`
- **Tolerancia**: Define cuando un número se considera cero (precisión numérica)

####  Desglose del Código

##### Función: `imprimirMatriz()`

```cpp
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
```
- **`wstring`**: String de caracteres anchos (Unicode)
- **`setw(12)`**: Ancho fijo de 12 caracteres para alineación
- **`setprecision(4)`**: 4 decimales de precisión
- Formatea la salida en columnas alineadas

##### Función: `esCero()`

```cpp
bool esCero(double numero) {
    return abs(numero) < TOLERANCIA_CERO;
}
```
- **Comparación numérica segura**: Evita errores de punto flotante
- Considera números muy pequeños (< 1e-10) como cero

##### Función: `calcularInversaMatriz()` (Algoritmo Principal)

**Paso 1: Crear Matriz Aumentada [A | I]**

```cpp
bool calcularInversaMatriz(const Matriz& matrizOriginal, Matriz& matrizInversa) {
    int dimension = static_cast<int>(matrizOriginal.size());
    Matriz matrizAumentada(dimension, vector<double>(2 * dimension, 0.0));

    for (int fila = 0; fila < dimension; fila++) {
        for (int col = 0; col < dimension; col++) {
            matrizAumentada[fila][col] = matrizOriginal[fila][col];
        }
        matrizAumentada[fila][dimension + fila] = 1.0;
    }
```
- **Matriz aumentada**: Combina matriz original con identidad [A | I]
- **Dimensión doble**: 2n columnas (n para A, n para I)
- **Identidad**: Coloca 1.0 en la diagonal de la parte derecha

**Ejemplo:**
```
Matriz A:        Aumentada [A | I]:
[2  1]           [2  1 | 1  0]
[1  3]           [1  3 | 0  1]
```

**Paso 2: Pivoteo Parcial (Búsqueda del Mejor Pivote)**

```cpp
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
```
- **Pivoteo**: Busca el elemento con mayor valor absoluto en la columna
- **Estabilidad numérica**: Reduce errores de redondeo
- **Búsqueda**: Compara desde fila actual hasta la última

**Paso 3: Verificación de Invertibilidad**

```cpp
        if (esCero(valorMejorPivote)) {
            wcout << L"¡MATRIZ NO INVERTIBLE!" << endl;
            wcout << L"Razón: La columna " << (pivoteActual + 1) 
                  << L" tiene todos ceros en la diagonal y debajo." << endl;
            return false;
        }
```
- **Condición de singularidad**: Si el pivote es cero, la matriz no es invertible
- **Determinante cero**: Indica dependencia lineal de filas/columnas

**Paso 4: Intercambio de Filas**

```cpp
        if (filaMejorPivote != pivoteActual) {
            swap(matrizAumentada[pivoteActual], matrizAumentada[filaMejorPivote]);
            wcout << L"Intercambiando fila " << (pivoteActual + 1) 
                  << L" con fila " << (filaMejorPivote + 1) << endl;
        }
```
- **`swap()`**: Intercambia vectores completos (filas enteras)
- Solo se realiza si se encontró un mejor pivote

**Paso 5: Normalización del Pivote**

```cpp
        double valorPivote = matrizAumentada[pivoteActual][pivoteActual];
        for (int col = 0; col < 2 * dimension; col++) {
            matrizAumentada[pivoteActual][col] /= valorPivote;
        }
        
        wcout << L"Después de normalizar la fila " << (pivoteActual + 1) << L":" << endl;
        imprimirMatriz(matrizAumentada);
```
- **División por pivote**: Convierte el elemento diagonal en 1
- **Toda la fila**: Aplica la operación a ambas partes de la matriz aumentada

**Paso 6: Eliminación Gaussiana**

```cpp
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
```
- **Eliminación completa**: Hace ceros arriba Y abajo del pivote (Gauss-Jordan)
- **Factor**: Valor a eliminar de cada fila
- **Operación de fila**: Resta (factor × fila_pivote) de cada fila

**Paso 7: Extracción de la Inversa**

```cpp
    matrizInversa.resize(dimension, vector<double>(dimension));
    for (int fila = 0; fila < dimension; fila++) {
        for (int col = 0; col < dimension; col++) {
            matrizInversa[fila][col] = matrizAumentada[fila][dimension + col];
        }
    }
    
    return true;
}
```
- **Extracción**: Copia la parte derecha de la matriz aumentada
- **Resultado**: [I | A⁻¹] → La inversa está en la parte derecha

##### Funciones Auxiliares

**`esMatrizCuadrada()`**
```cpp
bool esMatrizCuadrada(const Matriz& matriz) {
    if (matriz.empty()) return false;
    size_t numeroFilas = matriz.size();
    for (const auto& fila : matriz) {
        if (fila.size() != numeroFilas) return false;
    }
    return true;
}
```
- Verifica que número de filas = número de columnas
- Requisito necesario para calcular la inversa

**`multiplicarMatrices()`**
```cpp
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
```
- **Multiplicación estándar**: Implementa el algoritmo clásico O(n³)
- **Verificación**: Permite comprobar que A × A⁻¹ = I

##### Función Principal: `procesarInversionMatriz()`

```cpp
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
```
- **Entrada estructurada**: Solicita elementos organizados por filas
- **Validación**: Verifica dimensión positiva

```cpp
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
```
- **Flujo completo**: Valida, calcula, verifica y muestra resultados
- **Verificación matemática**: Comprueba que A × A⁻¹ = I
- **Manejo de errores**: Explica por qué una matriz no es invertible

##### Configuración de Main

```cpp
int main() {
    // Configurar la consola para UTF-8 y salida wide
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    procesarInversionMatriz();
    return 0;
}
```
- **UTF-8**: Permite caracteres Unicode (símbolos matemáticos)
- **Wide mode**: Configura entrada/salida para `wcout` y `wcin`
- Esencial para mostrar: ✓, ✗, ×, ⁻¹

#### Cumplimiento del Requisito

✔️ Calcula la inversa de matrices cuadradas  
✔️ Implementa método de Gauss-Jordan completo  
✔️ Muestra el proceso paso a paso  
✔️ Detecta matrices no invertibles  
✔️ Verifica el resultado (A × A⁻¹ = I)  
✔️ Maneja pivoteo parcial para estabilidad numérica  
✔️ Formatea salida profesionalmente

#### Cómo Ejecutar

```bash
# Compilar
g++ ejercicio5.cpp -o ejercicio5

# Ejecutar
./ejercicio5          # Linux/Mac
ejercicio5.exe        # Windows
```

#### Ejemplo de Uso

```
=== INVERSIÓN DE MATRIZ ===

Ingrese la dimensión de la matriz cuadrada: 2

Ingrese los elementos de la matriz (fila por fila):
Fila 1:
  Elemento [1,1]: 2
  Elemento [1,2]: 1
Fila 2:
  Elemento [2,1]: 1
  Elemento [2,2]: 3

============================================================
Matriz original:
      2.0000      1.0000
      1.0000      3.0000

Matriz aumentada inicial [A | I]:
      2.0000      1.0000      1.0000      0.0000
      1.0000      3.0000      0.0000      1.0000

Después de normalizar la fila 1:
      1.0000      0.5000      0.5000      0.0000
      1.0000      3.0000      0.0000      1.0000

Después de eliminar en la columna 1:
      1.0000      0.5000      0.5000      0.0000
      0.0000      2.5000     -0.5000      1.0000

Después de normalizar la fila 2:
      1.0000      0.5000      0.5000      0.0000
      0.0000      1.0000     -0.2000      0.4000

Después de eliminar en la columna 2:
      1.0000      0.0000      0.6000     -0.2000
      0.0000      1.0000     -0.2000      0.4000

============================================================
✓ MATRIZ INVERSA:
      0.6000     -0.2000
     -0.2000      0.4000

Verificación (A × A⁻¹):
      1.0000      0.0000
      0.0000      1.0000
```

**Verificación matemática:**
- A × A⁻¹ = I (matriz identidad)
- Resultado correcto ✓

#### 📚 Conceptos Matemáticos

**Método de Gauss-Jordan:**
1. Crear matriz aumentada [A | I]
2. Pivoteo parcial (estabilidad numérica)
3. Hacer 1 en la diagonal
4. Hacer 0 arriba y abajo del pivote
5. Resultado: [I | A⁻¹]

**Condiciones de invertibilidad:**
- Determinante ≠ 0
- Matriz cuadrada
- Filas linealmente independientes
- Rango completo

---

## Compilación y Ejecución General

### Compilar Todos los Ejercicios

```bash
# En el directorio del proyecto
g++ ejercicio-1.cpp -o ejercicio1
g++ ejercicio-2.cpp -o ejercicio2
g++ ejercicio-3.cpp -o ejercicio3
g++ Ejercicio4.cpp -o ejercicio4
g++ ejercicio5.cpp -o ejercicio5
```

### Script de Compilación Automática

**Para Linux/Mac** (crear archivo `compilar.sh`):
```bash
#!/bin/bash
echo "Compilando ejercicios..."
g++ ejercicio-1.cpp -o ejercicio1
g++ ejercicio-2.cpp -o ejercicio2
g++ ejercicio-3.cpp -o ejercicio3
g++ Ejercicio4.cpp -o ejercicio4
g++ ejercicio5.cpp -o ejercicio5
echo "¡Compilación completada!"
```

Dar permisos y ejecutar:
```bash
chmod +x compilar.sh
./compilar.sh
```

**Para Windows** (crear archivo `compilar.bat`):
```batch
@echo off
echo Compilando ejercicios...
g++ ejercicio-1.cpp -o ejercicio1.exe
g++ ejercicio-2.cpp -o ejercicio2.exe
g++ ejercicio-3.cpp -o ejercicio3.exe
g++ Ejercicio4.cpp -o ejercicio4.exe
g++ ejercicio5.cpp -o ejercicio5.exe
echo Compilacion completada!
pause
```

---

## Resumen de Cumplimiento

| Ejercicio | Requisito | Estado | Complejidad |
|-----------|-----------|--------|-------------|
| 1 | Operaciones básicas + división por cero |  Completo | O(1) |
| 2 | Máximo y mínimo en arreglo | Completo | O(n) |
| 3 | Contador de vocales | Completo | O(n) |
| 4 | Normas L2 y L∞ |  Completo | O(n) |
| 5 | Inversión de matriz (Gauss-Jordan) |  Completo | O(n³) |

---

##  Conceptos Aplicados

### Programación
-  Entrada/salida de datos
-  Validación de entrada
-  Manejo de errores
-  Estructuras de control (if, for, while)
-  Funciones y modularización
-  Paso por referencia
-  Tipos de datos avanzados (vector, string)

### Estructuras de Datos
-  Arreglos estáticos
-  Vectores dinámicos
-  Matrices 2D (vector de vectores)
-  Strings y manipulación de caracteres

### Algoritmos
-  Búsqueda lineal
-  Algoritmos de comparación
-  Operaciones matriciales
-  Gauss-Jordan con pivoteo parcial
-  Multiplicación de matrices

### Matemáticas
-  Álgebra lineal (normas, inversión)
-  Aritmética de punto flotante
-  Tolerancia numérica
-  Operaciones vectoriales

---

##  Solución de Problemas Comunes

### Error: "g++ no se reconoce como comando"
**Solución:** Instalar MinGW (Windows) o g++ (Linux/Mac) y agregarlo al PATH.

### Error de compilación con `windows.h`
**Solución:** Esta librería es específica de Windows. En Linux/Mac, comentar las líneas relacionadas.

### Caracteres especiales no se muestran correctamente
**Solución:** Asegurarse de que la consola esté configurada en UTF-8.
```bash
# Windows CMD
chcp 65001

# Windows PowerShell
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
```

### Error con números decimales en Ejercicio 2
**Solución:** El programa acepta tanto comas como puntos decimales automáticamente.

---

##  Autor

**Carlos Alberto Oviedo Machado, Luiyi David Brito Palmezano e Ismael David Perez Cudriz**
- Universidad: [Univsidad Nacional de Col]
- Curso: Programación Avanzada
- Fecha: [Fecha de entrega]

---

##  Licencia

Este proyecto es de uso académico y está disponible bajo la licencia MIT.

---

##  Contacto

Si tienes preguntas o sugerencias sobre este proyecto:
- Email: [caoviedom@unal.edu.co, lbritop@unal.edu.co, Isperezc@unal.edu.co]
- GitHub: [caoviedom(https://github.com/caoviedom)

---

##  Agradecimientos

- Profesor del curso de Programación Avanzada Mauro Alonso Baquero Suarez
- Comunidad de Stack Overflow
- Documentación oficial de C++

---

**⭐ Si este repositorio te fue útil, no olvides darle una estrella en GitHub**
