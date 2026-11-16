
#include <iostream>  // Permite utilizar cout y cin para mostrar y recibir datos
#include <vector>    // Permite almacenar varios números en un vector
#include <cstdlib>   // Permite utilizar rand() y srand() para números aleatorios con ayudita de la hora
#include <ctime>     // Permite utilizar time(0) como base para los números aleatorios

using namespace std; // Evita tener que escribir std:: antes de cout, cin y vector (aquí es lo q cambia al parcial pasado)

// Es la función que calcula el factorial de un número (se me díficulta hacerlo en hoja, ahora programarlo, nah)
int factorial(int numero) {

    int resultado = 1; // Empieza el resultado en 1 (el factorial de 0, es 1, cuando ingresan 0 el programa no se ejecuta como tal, así q te da el factorial correcto, el 1 q guardamos desde el principio)

    // Multiplica los números desde 1 hasta el número recibido
    for (int i = 1; i <= numero; i++) {
        resultado = resultado * i;
    }

    return resultado; // Devuelve el factorial calculado
}

int main() {

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

    // Genera N números aleatorios entre 0 y 10
    for (int i = 0; i < N; i++) {

        int numero = rand() % 11; // Genera un número entre 0 y 10 con ayuda de los residuos

        numeros.push_back(numero); // Guarda cada número en el vector
    }

    cout << "\nNumeros generados: ";

    // Muestra los números almacenados
    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << " ";
    }

    cout << "\n\nFactoriales de los numeros:\n";

    // Calcula y muestra el factorial de cada elemento
    for (int i = 0; i < numeros.size(); i++) {

        cout << numeros[i] << "! = "
             << factorial(numeros[i]) << endl;
    }

    return 0; // Aquí termina el programa, Mar feliz :3
    // Yo súper estresada, ojála ya acabe el semestre 
}
