#include <iostream>
using namespace std;

const int MAX = 50;

struct Matriz {
    int datos[MAX][MAX];
    int filas;
    int columnas;
};

int main() {
    Matriz A;

    cout << "Número de filas (m): ";
    cin >> A.filas;
    cout << "Número de columnas (n): ";
    cin >> A.columnas;

    // Hasta aquí es parecido al anterior, solo que ya no es cuadrada, sino rectangular.


// PARTE A: Encontrar el máximo y mínimo de la matriz y sus posiciones


//Aquí se lee la matriz, que ahora tiene filas y columnas distintas, solo en eso cambia.
for (int i = 0; i < A.filas; i++) {
    for (int j = 0; j < A.columnas; j++) {
        cout << "Ingrese el elemento A[" << i + 1 << "][" << j + 1 << "]: ";
        cin >> A.datos[i][j];
    }
}

// Se inicializa edpués de leer la matriz, si se hace antes lee pura basura.
int maximo = A.datos[0][0];
int minimo = A.datos[0][0];
int filaMaximo = 0, columnaMaximo = 0;
int filaMinimo = 0, columnaMinimo = 0;

// Aquí se hace un bucle para recorrer la matriz y encontrar el máximo y mínimo, y sus posiciones. Se hace un bucle anidado, uno para las filas y otro para las columnas.
for (int i = 0; i < A.filas; i++) {
    for (int j = 0; j < A.columnas; j++) {
        if (A.datos[i][j] > maximo) {
            maximo = A.datos[i][j];
            filaMaximo = i;
            columnaMaximo = j;
        }
        if (A.datos[i][j] < minimo) {
            minimo = A.datos[i][j];
            filaMinimo = i;
            columnaMinimo = j;
        }
    }
}
// Y ya, facilisimo (no), se imprime y breve (no)
cout << "El máximo es: " << maximo << " en la posición ["
     << filaMaximo + 1 << "][" << columnaMaximo + 1 << "]" << endl;
cout << "El mínimo es: " << minimo << " en la posición ["
     << filaMinimo + 1 << "][" << columnaMinimo + 1 << "]" << endl;

// PARTE B: Intercambiar las filas del máximo y mínimo

// Aquí se hace un bucle para recorrer las columnas de la fila del máximo y mínimo, Solo con j poruqe pues las i están fijas, una es la fila del máximo y la otra es la fila del mínimo. Se hace un intercambio de valores usando una variable temporal.
for (int j = 0; j < A.columnas; j++) {
    int temp = A.datos[filaMaximo][j];
    A.datos[filaMaximo][j] = A.datos[filaMinimo][j];
    A.datos[filaMinimo][j] = temp;
}

// Y TADA
cout << "\nMatriz con las filas intercambiadas:" << endl;
for (int i = 0; i < A.filas; i++) {
    for (int j = 0; j < A.columnas; j++) {
        cout << A.datos[i][j] << "\t";
    }
    cout << endl;
}



// PARTE C: Transponer la matriz

Matriz T;
T.filas = A.columnas;     // las dimensiones se voltean porque ya no va a ser m x n sino n x m y pue esto ayuda a decir cuanto espacio va a usar T
T.columnas = A.filas;

for (int i = 0; i < A.filas; i++) { // aquí el bucle es para lo mismo recorrer las filar y columnas pero esta vez se le da los valores de A a T, pero se intercambian las posiciones, o sea, la fila de A se convierte en columna de T y la columna de A se convierte en fila de T.
    for (int j = 0; j < A.columnas; j++) {
        T.datos[j][i] = A.datos[i][j];
    }
}

// Se imprime la matriz original (con filas intercambiadas)
cout << "\nMatriz original (con filas intercambiadas):" << endl;
for (int i = 0; i < A.filas; i++) { 
    for (int j = 0; j < A.columnas; j++) {
        cout << A.datos[i][j] << "\t";
    }
    cout << endl;
}

//Se imprime la matriz transpuesta y ya ¿facilisimo verdad? = no
cout << "\nMatriz transpuesta:" << endl;
for (int i = 0; i < T.filas; i++) {
    for (int j = 0; j < T.columnas; j++) {
        cout << T.datos[i][j] << "\t";
    }
    cout << endl;
}

    return 0;
}