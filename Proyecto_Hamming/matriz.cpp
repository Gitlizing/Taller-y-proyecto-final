//lee un archivo muestras.txt con hasta 10 secuencias
//Guarda las secuencias en arreglo string seq[10], 
//calcula la distancia de Hamming entre cada par y lass almacéna en una matriz int D[10][10]. 

//Integrantes: Marian Caicedo, Anyerith Sequeda, Michell Mejía, Angie Rodríguez


#include <iostream>  // Permite mostrar información en pantalla
#include <fstream>   // Permite abrir y leer archivos de texto
#include <string>    // Permite trabajar con cadenas de carácteres
#include <iomanip>   // Permite organizar los resultados en columnas
#include <cctype>    // Permite convertir letras a mayúsculas
// Profe tengo demasiado sueño, me duermo

using namespace std;

// Convierte todas las letras de una secuencia a mayúsculas
string aMayusculas(string s) {

    // Recorre cada cáracter de la secuencia
    for (int i = 0; i < s.length(); i++) {

        // Convierte el carácter actual a mayúscula
        s[i] = toupper(static_cast<unsigned char>(s[i]));
    }

    // Devuelve la secuencia convertida
    return s;
}

// Verifica que una secuencia solo contenga A, C, G o T
bool esValida(const string &s) {

    // Recorre todos los carácteres de la secuencia
    for (int i = 0; i < s.length(); i++) {

        // Comprueba si el carácter no es ninguna de las bases permitidas
        if (s[i] != 'A' && s[i] != 'C' &&
            s[i] != 'G' && s[i] != 'T') {

            // Si encuentra un carácter incorrecto, devuelve false
            return false;
        }
    }

    // Si todos los carácteres son correctos, devuelve true
    return true;
}

// Calcula la distancia de Hamming entre dos secuencias
int distanciaHamming(const string &a, const string &b) {

    // Guarda la cantidad de posiciones diferentes
    int distancia = 0;

    // Recorre las posiciones de ambas secuencias
    for (int i = 0; i < a.length(); i++) {

        // Compara los carácteres que están en la misma posición
        if (a[i] != b[i]) {

            // Aumenta el contador cuando encuentra una diferencia
            distancia++;
        }
    }

    // Devuelve la cantidad total de diferencias
    return distancia;
}

int main() { //Empieza lo chido, ya no veo

    // Abre el archivo que contiene las muestras de ADN
    ifstream archivo("muestras.txt");

    // Comprueba si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir muestras.txt" << endl;
        return 1;
    }

    // Arreglo que puede guardar hasta 10 secuencias
    string seq[10];

    // Cuenta cuántas secuencias válidas se han guardado
    int n = 0;

    // Guarda temporalmente cada línea leída
    string linea;

    // Guarda la longitud que deben tener todas las secuencias
    // Se inicia en -1 porque todavia no se ha leido ninguna
    int longitud = -1;

    // Lee el archivo mientras existan líneas y haya espacio en el arreglo
    while (getline(archivo, linea) && n < 10) {

        // Elimina el carácter de retorno que puede quedar en archivos de Windows
        if (!linea.empty() && linea[linea.length() - 1] == '\r') {
            linea.pop_back();
        }

        // Ignora las líneas vacías
        if (linea.empty()) {
            continue;
        }

        // Convierte la secuencia a mayúsculas
        linea = aMayusculas(linea);

        // Verifica que solo tenga nucleótidos permitidos
        if (!esValida(linea)) {
            cout << "Secuencia invalida: " << linea << endl;
            continue;
        }

        // Si es la primera secuencia válida, guarda su longitud
        if (longitud == -1) {
            longitud = linea.length();
        }

        // Si no es la primera, comprueba que tenga la misma longitud
        else if (linea.length() != longitud) {
            cout << "Longitud diferente: " << linea << endl;
            continue;
        }

        // Guarda la secuencia válida en el arreglo
        seq[n] = linea;

        // Aumenta la cantidad de secuencias guardadas
        n++;
    }

    // Cierra el archivo después de terminar la lectura
    archivo.close();

    // Comprueba que exista al menos una secuencia válida
    if (n == 0) {
        cout << "No hay secuencias validas." << endl;
        return 1;
    }

    // Crea una matriz de 10 filas y 10 columnas para guardar las distancias
    int D[10][10];

    // Recorre las filas de la matriz
    for (int i = 0; i < n; i++) {

        // Recorre las columnas de la matriz
        for (int j = 0; j < n; j++) {

            // Compara las secuencias ubicadas en las posiciones i y j
            D[i][j] = distanciaHamming(seq[i], seq[j]);
        }
    }

    // Muestra el título de la matriz
    cout << "Matriz de distancias de Hamming:" << endl;

    // Deja un espacio antes de los encabezados
    cout << setw(6) << " ";

    // Imprime los nombres de las columnas
    for (int i = 0; i < n; i++) {
        cout << setw(6) << "S" + to_string(i + 1);
    }

    cout << endl;

    // Recorre las filas para imprimir los resultados
    for (int i = 0; i < n; i++) {

        // Imprime el nombre de la secuencia de esa fila
        cout << setw(6) << "S" + to_string(i + 1);

        // Recorre las columnas de esa fila
        for (int j = 0; j < n; j++) {

            // Muestra la distancia guardada en la matriz
            cout << setw(6) << D[i][j];
        }

        // Termina la fila y pasa a la siguiente
        cout << endl;
    } // Perdón los comentarios sin sazón, le juro que se me cierran los ojos

    // El programita termina, Mar feliz :3
    return 0;
}
