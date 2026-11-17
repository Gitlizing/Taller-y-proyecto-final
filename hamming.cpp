// ===================================================================
// Proyecto final: Distancia de Hamming en secuencias de ADN
// Código base

//Integrantes: Marian Caicedo, Anyeriyh Sequeda, Michelle Mejía, Y Angie Rodríguez
// ===================================================================

#include <iostream> // cout y cin: escribir en pantalla y leer del teclado
#include <fstream> // ifstream: leer archivos de texto
#include <string> // string: cadenas de caracteres
#include <cctype> // toupper: convertir una letra a mayúscula
#include <iomanip> // setprecision: controlar los decimales al imprimir
using namespace std;

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
// Parte A — pruebas de las funciones básicas

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
    
    double L_double = static_cast<double>(L);             // Convertir L a double para la división (Ldebe ser != 0)
    return ((L_double - d) / L_double) * 100.0;

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

void mostrarConteos(const string &s) {
    int conteo[4];
    contarNucleotidos(s, conteo);
    cout << s << " A=" << conteo[0] << " C=" << conteo[1]
         << " G=" << conteo[2] << " T=" << conteo[3]
         << " GC=" << contenidoGC(conteo, s.length()) << "%" << endl;
}


 int main() {
 // ---------------------------------------------------------------
 // Pedir el nombre del archivo y abrirlo
 // ---------------------------------------------------------------
 string nombreArchivo;
  cout << "Nombre del archivo: ";
 cin >> nombreArchivo; // lee una palabra (el nombre no debe
 // tener espacios, p. ej. secuencias.txt)
 cout << endl;

 // 'ifstream' (input file stream) es un flujo de entrada asociado
 // a un archivo. Se usa igual que 'cin', pero los datos vienen del
 // archivo en lugar del teclado. Al crearlo con el nombre, intenta
 // abrir el archivo. El archivo debe estar en la misma carpeta
 // desde donde se ejecuta el programa (o escribir la ruta completa).
 ifstream archivo(nombreArchivo);

 // is_open() devuelve false si el archivo no se pudo abrir: no
 // existe, el nombre está mal escrito o no hay permisos.
 // En ese caso no tiene sentido continuar: terminamos el programa.
 // 'return 1' le indica al sistema operativo que hubo un error
 // ('return 0', al final, indica que todo salió bien).
 if (!archivo.is_open()) {
 cout << "Error: no se pudo abrir el archivo." << endl;
 return 1;
 }

 // 'fixed' y 'setprecision(1)' hacen que todos los números con
 // decimales (double) que se impriman de aquí en adelante muestren
 // exactamente un decimal: 66.7 en lugar de 66.6667.
 cout << fixed << setprecision(1);

 // ---------------------------------------------------------------
 // 2. Leer el archivo línea por línea
 // ---------------------------------------------------------------
 string linea; // aquí se guarda cada línea leída
 int numPareja = 0; // cuántas parejas con formato correcto van


 // getline(archivo, linea) lee la línea completa siguiente del
 // archivo (hasta el salto de línea, sin incluirlo) y la guarda en
 // 'linea'. Devuelve un valor que se evalúa como verdadero si logró
 // leer algo, y como falso cuando ya no quedan líneas. Por eso el
 // ciclo 'while' se repite una vez por cada línea y se detiene
 // solo al llegar al final del archivo.
 //
 // Se usa getline y no 'archivo >> linea' porque >> se detiene en
// el primer espacio, y aquí necesitamos la línea entera.
 while (getline(archivo, linea)) {

 // Los archivos creados en Windows terminan cada línea con dos
 // caracteres: '\r' y '\n'. getline quita el '\n' pero deja el
 // '\r' al final, invisible en pantalla, y haría que "ATGGCT\r"
 // tuviera un carácter inválido. Si el último carácter es '\r',
 // lo borramos con erase(posición).
 if (!linea.empty() && linea[linea.length() - 1] == '\r') {
 linea.erase(linea.length() - 1);
 }

 // Una línea vacía no tiene datos: 'continue' salta el resto
 // del cuerpo del ciclo y pasa directamente a leer la siguiente.
 if (linea.empty()) {
 continue;
 }

 // Intentamos dividir la línea en dos secuencias. Si el formato
 // es incorrecto, avisamos y pasamos a la siguiente línea sin
 // contarla como pareja.
 string seq1, seq2;
 if (!separarPareja(linea, seq1, seq2)) {
 cout << "Aviso: línea ignorada por formato incorrecto: "
 << linea << endl;
 continue;
 }

 // Si llegamos aquí, la línea tiene formato correcto: es una
 // pareja nueva y le asignamos su número.
 numPareja++;
 // -----------------------------------------------------------
 // Incluir aquí el código que ejecute lo solicitado en el
 // enunciado para cada pareja.
// -----------------------------------------------------------
 seq1 = aMayusculas(seq1);
seq2 = aMayusculas(seq2);

cout << "Pareja " << numPareja << ": " << seq1 << " vs " << seq2 << " -> ";

if (!esValida(seq1) || !esValida(seq2)) {
    cout << "Error: caracteres inválidos" << endl;
} else if (seq1.length() != seq2.length()) {
    cout << "Error: longitudes diferentes" << endl;
} else {
    int d = distanciaHamming(seq1, seq2);
    cout << "Distancia: " << d << " | Identidad: "
         << porcentajeIdentidad(d, seq1.length()) << "%" << endl;
    mostrarConteos(seq1);
    mostrarConteos(seq2);
}
}
// Cerramos el archivo: ya no lo necesitamos. (Se cerraría solo al
// terminar el programa, pero cerrarlo explícitamente es buena// costumbre.)
 archivo.close(); 
 return 0;
 }