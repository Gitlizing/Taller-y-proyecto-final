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

// Funciones para varios puntos



// Para Mostrar matriz alineada 
void imprimirMatriz(const vector<vector<int>> &M) {         //const para que no se modifique la matriz
   for (int i = 0; i < M.size(); i++) {                     //Para recorrer filas i
        for (int j = 0; j < M[i].size(); j++) {             //Para recorrer columnas j
            cout << setw(4) << M[i][j];                     // muestra la matriz alineada en columnas de 4 espacios
        }
        cout << endl;
    }
}

//Muestra los elementos de un vector separados por espacios.
void imprimirVector(const vector<int> &v) {                 
    for (int i = 0; i < v.size(); i++) {                    //Recorre el vector
        cout << v[i] << " ";                                //Muestra el elemento i del vector 
    }
}

// Primos true, false si no lo es, 0 y 1 No son primos
bool esPrimo(int x) {
    if (x < 2) {
        return false;
    }
    
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {                                    //se prueba con la operación de resuduo 
            return false;                                    //si encontró un divisor: no es primo
        }
    }
    return true;                                             //si no encontró ningún divisor es primo
}


// a) Leer n y generar matriz con número aleatorios entre 0 y 50

void llenarAleatoria(vector<vector<int>> &M) {               //vector dentro de vector de enteros
    for (int i =0; i<M.size(); i++) {                        //recorre filas i
        for (int j =0; j < M[i].size(); j++) {               //recorre columnas j
            M[i][j] = rand() % 51;                           //llena aleatoriamente números entre 0 y 50, el residui nunca pasa por 51
        }
    }
}


// b) Extraer las diagonales principal y secundaria de la matriz. Hallar la suma de sus elementos.


//Diagonales y sus sumas    
void diagonales(const vector<vector<int>> &M) {            //Función que recibe la matriz (2D)
    int n = M.size();                                      //tamaño de la matriz
    vector<int> principal(n);                              //definir diagonal principal (P)
    vector<int> secundaria(n);                             //definir diagonal secundaria (S)
    int sumaPrincipal = 0;                                 //Define suma de P        
    int sumaSecundaria = 0;                                //Define suma de S

    
    for (int i = 0; i < n; i++) {
        principal[i] = M[i][i];                             //Cuando fila==columna es de la diagonal principal 
        secundaria[i] = M[i][n - 1 - i];                    //Cuando fila+columna == n-1, es de la diagonal secundaria
        sumaPrincipal += principal[i];                      //Si es de la diagonal principal, se suma a la suma de la diagonal principal
        sumaSecundaria += secundaria[i];                    //Si es de la diagonal secundaria, se suma a la suma de la diagonal secundaria
    }

    cout << "\nb) Diagonal principal: ";                      //Mostrar la diagonal principal
    imprimirVector(principal);
    cout << "-> Suma: " << sumaPrincipal << endl;

    cout << "   Diagonal secundaria: ";                     //Mostrar la diagonal secundaria
    imprimirVector(secundaria);
    cout << "-> Suma: " << sumaSecundaria << endl;
}

// c) Primera fila y última columna en vectores; vector resultado con la suma de los cuadrados

void filaYColumna(const vector<vector<int>> &M) {
    int n = M.size();
    vector<int> primeraFila(n);
    vector<int> ultimaColumna(n);
    vector<int> resultado(n);

    for (int i = 0; i < n; i++) {
        primeraFila[i] = M[0][i];                          // la fila queda fija en la 0, avanza la columna
        ultimaColumna[i] = M[i][n - 1];                    // la columna queda fija en n-1, avanza la fila
        
        // cuadrado del primero + cuadrado del segundo, en la misma posición i
        resultado[i] = primeraFila[i] * primeraFila[i] + ultimaColumna[i] * ultimaColumna[i];    
                     
    }

    cout << "\nc) Primera fila:   "<< endl;                      //para imprimir la primera fila
    imprimirVector(primeraFila);
    cout << "\nUltima columna: " << endl;                        //para imprimir la última columna
    imprimirVector(ultimaColumna);
    cout << "\nSuma de cuadrados posicion a posicion: " << endl;         //para imprimir la suma
    imprimirVector(resultado);
}

// d) Contar los elementos primos de la matriz

void contarPrimos(const vector<vector<int>> &M) {                              ///definir función 
    int primos = 0;                                                            // contador: empieza en 0
    for (int i = 0; i < M.size(); i++) {                                       //recorrre filas
        for (int j = 0; j < M[i].size(); j++) {                                //recorre columnas
            if (esPrimo(M[i][j])) {                                            //llama la función de arriba esPrimo devuelve true o false
                primos++;                                                      // cuenta los primos
            }
        }
    }
    cout << "\nd) Cantidad de numeros primos: " << primos << endl;               // imprime en una línea abajo para que se vea ordenado
}

// e) Contar pares, impares y divisibles por 3

void contarParesImpares(const vector<vector<int>> &M) {                        //funcioncita
    int pares = 0;
    int impares = 0;
    int divisiblesPor3 = 0;

    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[i].size(); j++) {
            if (M[i][j] % 2 == 0) {                                            // Ya tu sabe, Si el residuo de dividir por 2 es 0, es par; si no, pues.....
                pares++;
            } else {
                impares++;
            }
            if (M[i][j] % 3 == 0) {                                           // mismo calculo con residuo de dividir en 3
                divisiblesPor3++;                                             // juuumm el 0 cuenta como par y como divisible por 3.
            }
        }
    }

    cout << "\ne) Pares: " << pares << endl;
    cout << "   Impares: " << impares << endl;
    cout << "   Divisibles por 3: " << divisiblesPor3 << endl;
}

// f) Suma por columnas, conversión a radianes y seno; tabla X  Y

void sumaColumnasSeno(const vector<vector<int>> &M) {
    int n = M.size();
    vector<int> sumaColumnas(n, 0);                                            // n posiciones, todas en 0
             
    for (int j = 0; j < n; j++) {                                             // Recorrido por columnas: el ciclo de afuera fija la columna j
        for (int i = 0; i < n; i++) {                                         // y el de adentro baja por sus filas i.
            sumaColumnas[j] += M[i][j];
        }
    }

    const double PI = acos(-1.0);

    cout << "\nf) Tabla: suma de cada columna (X) y seno en radianes (Y)" << endl;
    cout << setw(10) << "X" << setw(14) << "Y = sen(X)" << endl;

    for (int j = 0; j < n; j++) {
        double radianes = sumaColumnas[j] * PI / 180.0;                         //para pasar de grados a radianes
        double seno = sin(radianes);                                            // sin() de la ñlinrería  trabaja en radianes
        cout << setw(10) << sumaColumnas[j]
             << setw(14) << fixed << setprecision(4) << seno << endl;
    }
}

// g) Pasar la matriz a un vector, promedio y división por el promedio

void matrizAVector(const vector<vector<int>> &M) {
    vector<int> lineal;                                                        // empieza vacío y se llena con push_back

    for (int i = 0; i < M.size(); i++) {                                        //se van copiando los elementos fila por fila al final del vector.
        for (int j = 0; j < M[i].size(); j++) {
            lineal.push_back(M[i][j]);
        }
    }
// Promedio
    double suma = 0;                                                           //suma con double para que el promedio tenga decimales           
    for (int k = 0; k < lineal.size(); k++) {
        suma += lineal[k];
    }
    double promedio = suma / lineal.size();

    cout << "\ng) Matriz como vector: ";
    imprimirVector(lineal);
    cout << "   Promedio: " << fixed << setprecision(2) << promedio << endl;

    if (promedio == 0) {                                         
        cout << "   El promedio es 0: no se puede dividir." << endl;
        return;                                                                 // por si los elementos fueran 0sale de la función antes de dividir
    }

    vector<double> divididos(lineal.size());                                    // El resultado tiene decimales.
    cout << "   Cada elemento dividido por el promedio: ";
    for (int k = 0; k < lineal.size(); k++) {
        divididos[k] = lineal[k] / promedio;
        cout << divididos[k] << " ";
    }
    cout << endl;
}


//main = principal, ahora si lo entendí todo

int main() {
    int n;                                                  //Definir n, tamaño matriz
    do {                                                    //Do-While para que se repita hasta que n sea valido         
        cout << "Ingrese n (mayor que 0): ";                //Pide n
        cin >> n;                                           //Lee n
    } while (n <= 0);                                       //Hasta que el usurio ponga un n  positivo

    srand(time(0));                                         // Número aleatorio con semilla diferente cada vez
    vector<vector<int>> M(n, vector<int>(n));               // matriz de vectores n x n en ceros

    llenarAleatoria(M);                                     //LLena la matriz
    cout << "\nMatriz aleatoria generada:" << endl;         //Mensaje Matriz generada:
    imprimirMatriz(M);                                      //Imprime matriz generada en la sigioente línea
 
    diagonales(M);           // b
    filaYColumna(M);         // c
    contarPrimos(M);         // d
    contarParesImpares(M);   // e
    sumaColumnasSeno(M);     // f
    matrizAVector(M);        // g
    return 0;
}