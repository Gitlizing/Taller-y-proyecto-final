#include <iostream>
#include <vector>     // vector
#include <iomanip>    // setw, fixed, setprecision
using namespace std;

int main() {
    int n, m;

  
    //Primero se le pide al usuario los datos

    do {
        cout << "Numero de estudiantes (n): ";
        cin >> n;
        cout << "Numero de asignaturas (m): ";
        cin >> m;
    } while (n <= 0 || m <= 0);

    //como las notas tienen decimales la matriz es de double
    vector<vector<double>> notas(n, vector<double>(m));

    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        for (int j = 0; j < m; j++) {
            //se repite el ciclo hasta que la nota esté en el rango (0 a 5)
            do {
                cout << "Nota asignatura " << j + 1 << " (0.0 a 5.0): ";
                cin >> notas[i][j];
                if (notas[i][j] < 0.0 || notas[i][j] > 5.0) {
                    cout << " Nota invalida, intente de nuevo" << endl;
                }
            } while (notas[i][j] < 0.0 || notas[i][j] > 5.0);
        }
    }

    //los números se muestran con 2 decimales
    cout << fixed << setprecision(2);

    cout << "Matriz de calificaciones (filas = estudiantes, columnas = asignaturas):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(7) << notas[i][j];
        }
        cout << endl;
    }

    
    //promedio por filas (cada estudiante)
    // El ciclo de afuera fija el estudiante i y el de adentro recorre sus m notas.
    vector<double> promEstudiante(n);
    for (int i = 0; i < n; i++) {
        double suma = 0;
        for (int j = 0; j < m; j++) {
            suma += notas[i][j];
        }
        promEstudiante[i] = suma / m;   // se divide por el número de asignaturas
    }

    cout << "Promedio de cada estudiante:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i + 1 << ": " << promEstudiante[i] << endl;
    }

    
    //promedio por columnas (cada asignatura)
    //ahora se invierten los ciclos: el de afuera fija la asignatura j y el
    // de adentro baja por los n estudiantes.
    vector<double> promAsignatura(m);
    for (int j = 0; j < m; j++) {
        double suma = 0;
        for (int i = 0; i < n; i++) {
            suma += notas[i][j];
        }
        promAsignatura[j] = suma / n;   //se divide por el número de estudiantes
    }

    cout << "Promedio de cada asignatura:" << endl;
    for (int j = 0; j < m; j++) {
        cout << "   Asignatura " << j + 1 << ": " << promAsignatura[j] << endl;
    }

    
    //para el mayor promedio de estudiante y menor promedio de asignatura
    //se empieza suponiendo que el primero es el mejor (o el peor) y se compara con los demás y se va guardando cada vez q aparece uno mejor
    int mejorEst = 0;
    for (int i = 1; i < n; i++) {
        if (promEstudiante[i] > promEstudiante[mejorEst]) {
            mejorEst = i;
        }
    }

    int peorAsig = 0;
    for (int j = 1; j < m; j++) {
        if (promAsignatura[j] < promAsignatura[peorAsig]) {
            peorAsig = j;
        }
    }

    cout << "Estudiante con el promedio mas alto: estudiante " << mejorEst + 1
         << " (indice " << mejorEst << "), promedio " << promEstudiante[mejorEst] << endl;
    cout << "Asignatura con el promedio mas bajo: asignatura " << peorAsig + 1
         << " (indice " << peorAsig << "), promedio " << promAsignatura[peorAsig] << endl;
         // y ya

    return 0;
}
