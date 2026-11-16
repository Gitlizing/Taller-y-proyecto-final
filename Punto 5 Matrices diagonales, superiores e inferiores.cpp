#include <iostream>
using namespace std;

// Las posiciones las tomo en cuenta desde la diagonal, o sea, una cuadricula con una diagonal hacia arriba
// a la izquierda y de la derecha hacia abajo.

const int MAX = 50; // Se define el tamaño máximo de la matriz

struct Matriz {                  // Usé struct para definir la estructura de la matriz, y porque está más chevere que usar vector.
    int filas;
    int columnas;
    int datos[MAX][MAX];
};

int main () { 
    Matriz A;
    int n; // Variable para el tamaño de la matriz cuadrada
    cout << "¿Tamaño de la matriz? = n (nxn): ";   
    cin >> n; // Entra el número dado por el usuario y se lee el tamaño de la matriz cuadrada
    A.filas = n; // Se asigna el tamaño de la matriz a la variable filas
    A.columnas = n; // Lo mismo de la filas pero para columnas

    for (int i = 0; i < A.filas; i++) { // Se hace un bucle para recorrer las filas, el for otro da una vuelta por cada i "fila"
        for (int j = 0; j < A.columnas; j++) { // Se hace otro bucle para recorrer las columnas. Entonces la lógica es i == j para la diagonal, i < j para la parte superior y i > j para la parte inferior.
            cout << "Ingrese el valor de la posición [" << i + 1 << "][" << j + 1 << "]: "; // Se pide al usuario que ingrese el valor de la posición, el 1 es solo para mostrarlo porque el programa empieza en 0 pero el usuario ingresará desde 1.
            cin >> A.datos[i][j];
        }
    }

    bool TriangularSuperior = true, TriangularInferior = true; 
    {for (int i = 0; i < A.filas; i++)
     { 
        for (int j = 0; j < A.columnas; j++) { 
            if (i > j && A.datos[i][j] != 0) { // Si la fila es mayor que la columna y el valor de la posición es diferente de 0, entonces... FALSE
                (TriangularSuperior = false); 
            }
            if (i < j && A.datos[i][j] != 0) { // Lo mismo pero triangular inferior, y que si la fila es menor que la columna, entonces se cambia el booleano
                (TriangularInferior = false);
            }
        } //fun fact, se colocan dos if porque son independientes, si se colocara un else if, entonces no se podría cumplir la condición de que sea triangular superior e inferior al mismo tiempo.
    }
    }
    if (TriangularSuperior && TriangularInferior) { // Si ambos booleanos son verdaderos, entonces es una matriz diagonal
        cout << "La matriz es diagonal." << endl;
    } else if (TriangularSuperior) { 
        cout << "La matriz es triangular superior." << endl;
    } else if (TriangularInferior) { 
        cout << "La matriz es triangular inferior." << endl;
    }else { // Si ninguno de los booleanos es verdadero
        cout << "La matriz no es ni diagonal ni triangular." << endl;
    }
}

