// Parte A — pruebas de las funciones básicas

#include <iostream>
#include <string>
#include <cctype>     // para usar toupper
#include <iomanip>    // para usar setprecision
using namespace std;

//Devuelve una copia de s con todas sus letras en mayúscula
string aMayusculas(string s){               
    for (int i=0; i<s.length(); i++){
        s[i] = toupper (s[i]);
    }
    return s;
}

//Devuelve true si s solo contiene A, C, G o T. Recibe la secuencia ya en mayúsculas.
bool esValida(const string &s){
    for (int i=0; i<s.length();  i++){
        // una condición, si llega a encontrar un caracter diferete de ACGT, pone false
        if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T'){
            return false;
        }       
    }
    return true;
}


//Cuenta las posiciones en que difieren a y b. Se llama solo cuando ambas tienen la misma longitud.
int distanciaHamming(const string &a, const string &b){
    int d = 0;
    for (int i = 0; i < a.length(); i++){
        if (a[i] != b[i]){
            d++;
        }
    }
    return d;
}

// Devuelve (L − d) / L × 100, donde d es la distancia y L la longitud.
double porcentajeIdentidad(int d, int L){
    
    double L_double = static_cast<double>(L);             // Convertir L a double para la división (Ldebe ser != 0)
    return ((L_double - d) / L_double) * 100.0;

}



//!!!!!!!!este esl main de prueba NO se pega en el hamming.cpp

int main() {
    cout << boolalpha;               // muestra true/false en vez de 1/0
    cout << fixed << setprecision(1);

    cout << aMayusculas("atgc") << "   (esperado: ATGC)" << endl;
    cout << esValida("ATCG") << "   (esperado: true)" << endl;
    cout << esValida("AATXGG") << "   (esperado: false)" << endl;
    cout << distanciaHamming("ATCGAT", "ATGGCT") << "   (esperado: 2)" << endl;
    cout << porcentajeIdentidad(2, 6) << "   (esperado: 66.7)" << endl;
    cout << porcentajeIdentidad(0, 4) << "   (esperado: 100.0)" << endl;
    cout << porcentajeIdentidad(6, 6) << "   (esperado: 0.0)" << endl;
    return 0;
}