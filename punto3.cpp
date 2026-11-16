#include <iostream>  // Permite utilizar cout y cin para mostrar y recibir datos
#include <vector>    // Permite almacenar varios números en un vector
#include <cstdlib>   // Permite utilizar rand() y srand() para números aleatorios con ayudita de la hora 
#include <ctime>     // Permite utilizar time(0) como base para los números aleatorios
#include <algorithm> // Permite ordenar los elementos de un vector (Aquí empezamos a modifircar el código anterior) 

using namespace std; // Evita tener que escribir std:: antes de cout, cin y vector (aquí es lo q cambia al parcial pasado)


int main() { // Aquí comienza el programita

    srand(time(0)); // Utilizamos la hora del pc para no repetir la misma generación de num cuando lo ejecutemos (me costó entender)

    int N; // Variable que almacena la cantidad de números que vamos a generar

    cout << "Ingrese la cantidad de numeros: "; // Solicita un número random a la personita, obvi
    cin >> N; // Guarda el número que escribió la persona 

    // Comprueba que N sea positivo y que la persona no haya puesto un negativo
    while (N <= 0) {
        cout << "Ingrese un numero positivo: ";
        cin >> N;
    }

    vector<int> numeros; // Crea un vector vacío para guardar los números

    int suma = 0; // Acumula la suma de todos los números generados

    // Genera N números aleatorios entre 0 y 10
    for (int i = 0; i < N; i++) {

        int numero = rand() % 11; // Genera un número entre 0 y 10 con ayuda de los residuos

        numeros.push_back(numero); // Guarda el número en el vector

        suma = suma + numero; // Suma el número al acumulado que teníamos

    }

    // Calcula la media
    double media = (double)suma / N;

    cout << "\nNumeros generados: ";

    // Recorre el vector para mostrar los números
    for (int i = 0; i < N; i++) {
        cout << numeros[i] << " ";
    }

    cout << "\nLa media es: " << media << endl;

    vector<int> mayores; // Segundo vector para poder guardar los mayores que la media

    // Busca los números que superan la media que tenemos 
    for (int i = 0; i < N; i++) {

        if (numeros[i] > media) {
            mayores.push_back(numeros[i]);
        }

    }

    //Ordena los números de menor a mayor (he aquí la super wow diferencia con el 2, siempre ordenadito)
    sort(mayores.begin(), mayores.end());

    // Muestra los números ya ordenaditos
    cout << "Numeros mayores que la media ordenados: ";

    for (int i = 0; i < mayores.size(); i++) {
        cout << mayores[i] << " ";
    }
    
    cout << endl;

    return 0; // Aquí termina el programa, Mar feliz :3
    // Cómo estás?
}