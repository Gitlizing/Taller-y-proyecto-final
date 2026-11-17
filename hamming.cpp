// ===================================================================
// Proyecto final: Distancia de Hamming en secuencias de ADN


//Integrantes: Marian Caicedo, Anyerith Sequeda, Michell Mejía, Angie Rodríguez
// ===================================================================

#include <iostream> // cout y cin: escribir en pantalla y leer del teclado
#include <fstream> // ifstream: leer archivos de texto
#include <string> // string: cadenas de caracteres
#include <cctype> // toupper: convertir una letra a mayúscula
#include <iomanip> // setprecision: controlar los decimales al imprimir
using namespace std;


//Separa la línea en dos secuencias con un  único separador (espacio)

bool separarPareja(const string &linea, string &seq1, string &seq2) {
    int pos = -1;

    for (int i = 0; i < linea.length(); i++) {
        if (linea[i] == ' ' || linea[i] == ',') {
            if (pos != -1) {
                return false;
            }
            pos = i;
        }
    }

    if (pos <= 0 || pos == linea.length() - 1) {
        return false;
    }

    seq1 = linea.substr(0, pos);
    seq2 = linea.substr(pos + 1);
    return true;
}

// -------------------------------------------------------------------
// Parte A - funciones básicas

//1. Devuelve una copia de s con todas sus letras en mayúscula
string aMayusculas(string s){               
    for (int i=0; i<s.length(); i++){
        s[i] = toupper (s[i]);
    }
    return s;
}

//2. Devuelve true si s solo contiene A, C, G o T. Recibe la secuencia ya en mayúsculas.
bool esValida(const string &s){
    for (int i=0; i<s.length();  i++){
        // una condición, si llega a encontrar un caracter diferete de ACGT, pone false
        if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T'){
            return false;
        }       
    }
    return true;
}


//3. Cuenta las posiciones en que difieren a y b. Se llama solo cuando ambas tienen la misma longitud.
int distanciaHamming(const string &a, const string &b){
    int d = 0;
    for (int i = 0; i < a.length(); i++){
        if (a[i] != b[i]){
            d++;
        }
    }
    return d;
}

//4. Devuelve (L − d) / L × 100, donde d es la distancia y L la longitud.
double porcentajeIdentidad(int d, int L){
    
    double longitud = static_cast<double>(L);             // Convertir L a double para la división (Ldebe ser != 0)
    return ((longitud - d) / longitud) * 100.0;

}

// PARTE B: conteo de nucleotidos con arreglos
//PASO 1: contarNucleotidos
void contarNucleotidos(const string &s, int conteo[4]) {
    // Primero, poner el arreglo en ceros, esto se hace porque sino los conteos de la secuencia anterior se acumulan
    for (int i = 0; i < 4; i++) {
        conteo[i] = 0;
    }
    // 2do. Recorrer la secuencia y sumar 1 al contador que corresponda
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') conteo[0]++;
        else if (s[i] == 'C') conteo[1]++;
        else if (s[i] == 'G') conteo[2]++;
        else if (s[i] == 'T') conteo[3]++;
    }
}
//PASO 2: contenidoGC
double contenidoGC(const int conteo[4], int L) {
    return (conteo[1] + conteo[2]) * 100.0 / L; // El 100 con decimal solo evita la ddivisión entera
}

//Cuenta los nucleótidos de s y mueestra en una línea los conteos 
void mostrarConteos(const string &s) {
    int conteo[4];
    contarNucleotidos(s, conteo);
    cout << "   " << s << " A=" << conteo[0] << " C=" << conteo[1]
         << " G=" << conteo[2] << " T=" << conteo[3]
         << " GC=" << contenidoGC(conteo, s.length()) << "%" << endl;
}
// PARTE C (Persona C)
//
// procesarPareja: valida una pareja (ya con formato correcto) y
// muestra su resultado o el primer error encontrado.
// Orden de revisión (sección 3.2):
//   1. convertir ambas secuencias a mayúsculas
//   2. caracteres inválidos
//   3. longitudes diferentes
//   4. si todo está bien, calcular y mostrar resultados
// -------------------------------------------------------------------
void procesarPareja(int numPareja, string seq1, string seq2) {
    seq1 = aMayusculas(seq1);
    seq2 = aMayusculas(seq2);

    cout << "Pareja " << numPareja << ": " << seq1 << " vs " << seq2
         << " -> ";

    if (!esValida(seq1) || !esValida(seq2)) {
        cout << "Error: caracteres inválidos" << endl;
        return;
    }

    if (seq1.length() != seq2.length()) {
        cout << "Error: longitudes diferentes" << endl;
        return;
    }

    int L = seq1.length();
    int d = distanciaHamming(seq1, seq2);
    cout << "Distancia: " << d
         << " | Identidad: " << porcentajeIdentidad(d, L) << "%" << endl;

    mostrarConteos(seq1);
    mostrarConteos(seq2);
}

// -------------------------------------------------------------------
// separarPareja (código base, sin cambios)
// -------------------------------------------------------------------
bool separarPareja(const string &linea, string &seq1, string &seq2) {
    int pos = -1;

    for (int i = 0; i < linea.length(); i++) {
        if (linea[i] == ' ' || linea[i] == ',') {
            if (pos != -1) {
                return false;
            }
            pos = i;
        }
    }

    if (pos <= 0 || pos == linea.length() - 1) {
        return false;
    }

    seq1 = linea.substr(0, pos);
    seq2 = linea.substr(pos + 1);
    return true;
}


int main() {
    //primero pide el nombre del archivo y lo abre
    string nombreArchivo;
    cout <<"Nombre del archivo: ";
    cin >> nombreArchivo;
    cout << endl;

    // ifstream es para que lea los datos que tiene el archivo q el user puso
    ifstream archivo(nombreArchivo);

    //Return 1 para que le diga al pograma que hubo un error
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return 1;
    }

    //fixed es para referirse a las cifras decimales
    //setprecision dice cuantas cifras decimales se quieren mostrar, en este caso 1.
    cout << fixed << setprecision(1);

    // ahora lee el archivo línea por línea
    string linea;
    int numPareja = 0; //contador de parejas correctas

    while (getline(archivo, linea)) {

        //Quita el '\r' de los archivos creados en Windows
        if (!linea.empty() && linea[linea.length() - 1] == '\r') {
            linea.erase(linea.length() - 1);
        }

        // si la linea esta vacia se salta sin mensaje y sin numerarla
        if (linea.empty()) {
            continue;
        }

        //se separan las dos secuencias y se mira si son correctas 
        string seq1, seq2;
        if (!separarPareja(linea, seq1, seq2)) {
            cout << "Aviso: línea ignorada por formato incorrecto: "
                 << linea << endl;
            continue;
        }

        //1si el formato esta bien entonces se cuenta como una pareja nueva
        numPareja++;
        procesarPareja(numPareja, seq1, seq2);
    }

    archivo.close();
    return 0;