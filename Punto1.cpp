//Taller evaluación 1
// Integrantes: Angie rodríguez, Anyerith Sequeda, Marian Caicedo, Michelle Mejia
// Punto 1.
#include <iostream>
#include <vector>     // Librería para vectores    
#include <cstdlib>    // Libreria para rand y srand
#include <ctime>      // Librería para time 
#include <iomanip>    // Librería para set(w)
#include <cmath>      // Librería para sin, acos

using namespace std;

// a) Leer n y generar matriz con número aleatorios entre 0 y 50

void matrixaleatoria(vector<vector<int>> &M) {               //vector dentro de vector de enteros
    for (int i =0; i<M.size(); i++) {                         //recorre filas i
        for (int j =0; j < M[i].size(); j++) {               //recorre columnas j
            M[i][j] = rand() % 51;                           //llena aleatoriamente números entre 1 y 50, el residui nunca pasa por 51
        }
    }
}

// Para Mostrar matriz alineada todavía con ceros
void imprimirMatriz(const vector<vector<int>> &M) {         //const para que no se modifique la matriz
   for (int i = 0; i < M.size(); i++) {                     //Para recorrer filas i
        for (int j = 0; j < M[i].size(); j++) {             //Para recorrer columnas j
            cout << setw(4) << M[i][j];                     // muestra la matriz alineada en columnas de 4 espacios
        }
        cout << endl;
    }
}

int main() {
    int n;                                                  //Definir n, tamaño matriz
    do {                                                    //Do-While para que se repita hasta que n sea valido         
        cout << "Ingrese n (mayor que 0): ";                //Pide n
        cin >> n;                                           //Lee n
    } while (n <= 0);                                       //Hasta que el usurio ponga un n  positivo

    srand(time(0));                                         // Número aleatorio con semilla diferente cada vez
    vector<vector<int>> M(n, vector<int>(n));               // matriz de vectores n x n en ceros

    matrixaleatoria(M);                                     //LLena la matriz
    cout << "\n Matriz generada:" << endl;                  //Mensaje Matriz generada:
    imprimirMatriz(M);                                      //Imprime matriz generada en la sigioente línea

    // Aquí irán las llamadas de los incisos b) a g)

    return 0;
}