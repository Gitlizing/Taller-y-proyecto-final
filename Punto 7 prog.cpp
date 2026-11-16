
//hay q multiplicar dos matrices: A (m x p) por B (p x q) y debe dar: C (m x q)
//los resultados de la matriz C se obtiene multiplicando la
//fila i de A por la columna j de B y se va sumando cada una
//     C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j]... etc

#include <iostream>
#include <vector>     // vector
#include <iomanip>    // setw
using namespace std;

//muestra la matriz alineada en columnas con 6 espacios (para eso es el setw)
void imprimirMatriz(const vector<vector<int>> &M) {
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[i].size(); j++) {
            cout << setw(6) << M[i][j];
        }
        cout << endl;
    }
}

// aqui se le pide al usuario cada numero q va a ir en la matriz

void leerMatriz(vector<vector<int>> &M, char nombre) {
    cout << "Ingrese los elementos de la matriz " << nombre << ":" << endl;
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[i].size(); j++) {
            cout << nombre << "[" << i << "][" << j << "] = ";
            cin >> M[i][j];
        }
    }
}

// Aca se suman los elementos de la matriz C
int sumarFila(const vector<int> &fila) {
    int suma = 0;
    for (int j = 0; j < fila.size(); j++) {
        suma += fila[j];
    }
    return suma;
}

int main() {
    int m, p, filasB, q;

    
    // lee dimensiones y verifica que se puedan multiplicar
    // el do-while repite el ciclo hasta que sea correcto
    bool valido;
    do {
        cout << "Filas de A (m): ";      cin >> m;
        cout << "Columnas de A (p): ";   cin >> p;
        cout << "Filas de B: ";          cin >> filasB;
        cout << "Columnas de B (q): ";   cin >> q;

        valido = (m > 0 && p > 0 && filasB > 0 && q > 0 && p == filasB);
        if (!valido) {
            cout << "las columnas de A deben ser iguales a las filas de B"
                 << " y todas las dimensiones deben ser positivas."
                 << " Intentelo de nuevo" << endl;
        }
    } while (!valido);

    
    // Ahora se va a ir formando la matriz con los datos q de el usuario
    
    vector<vector<int>> A(m, vector<int>(p));
    vector<vector<int>> B(p, vector<int>(q));
    leerMatriz(A, 'A');
    leerMatriz(B, 'B');

    // mltiplicacion de las matrices A x B= C
    //i recorre las filas de A (y de C)
    // j recorre las columnas de B (y de C)
    //k recorre a la vez la fila i de A y la columna j de B
    vector<vector<int>> C(m, vector<int>(q, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatriz A (" << m << " x " << p << "):" << endl;
    imprimirMatriz(A);
    cout << "\nMatriz B (" << p << " x " << q << "):" << endl;
    imprimirMatriz(B);
    cout << "\nMatriz C = A x B (" << m << " x " << q << "):" << endl;
    imprimirMatriz(C);


    //suma de cada fila de C usando la funcion sumarFila

    cout << "Suma de cada fila de C:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "  Fila " << i << ": " << sumarFila(C[i]) << endl;
    }

    return 0;
}
