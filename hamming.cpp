// ===================================================================
2 // Proyecto final: Distancia de Hamming en secuencias de ADN
3 // Código base
4 // ===================================================================
5
6 #include <iostream> // cout y cin: escribir en pantalla y leer del teclado
7 #include <fstream> // ifstream: leer archivos de texto
8 #include <string> // string: cadenas de caracteres
9 #include <cctype> // toupper: convertir una letra a mayúscula
10 #include <iomanip> // setprecision: controlar los decimales al imprimir
11 using namespace std;
12
13 // -------------------------------------------------------------------
14 // Incluir aquí el código que ejecute lo solicitado en el enunciado
15 // (funciones de las Partes A y B).
16 // -------------------------------------------------------------------
// -------------------------------------------------------------------
20 // separarPareja
21 //
22 // Recibe una línea del archivo, por ejemplo "ATCGAT ATGGCT", y la
23 // divide en dos secuencias: seq1 = "ATCGAT" y seq2 = "ATGGCT".
24 //
25 // Parámetros:
26 // linea la línea leída del archivo. Se pasa como 'const string &'
27 // para no copiarla y para garantizar que no se modifica.
28 // seq1 aquí se guarda la primera secuencia.
29 // seq2 aquí se guarda la segunda secuencia.
30 // seq1 y seq2 se pasan por referencia ('string &') porque la
31 // función debe "devolver" dos valores: los cambios que se les
32 // hagan aquí dentro se ven en la variable original del main.
33 //
34 // Valor de retorno:
35 // true si la línea tiene exactamente un separador (un espacio o
36 // una coma) con texto a ambos lados.
37 // false en cualquier otro caso; entonces seq1 y seq2 no se tocan.
38 // -------------------------------------------------------------------
39 bool separarPareja(const string &linea, string &seq1, string &seq2) {
40 // 'pos' guardará la posición (el índice) del separador.
41 // Empieza en -1, un valor imposible como índice, que aquí
42 // significa "todavía no he encontrado ningún separador".
43 int pos = -1;
44
45 // Recorremos la línea carácter por carácter.
46 // linea.length() es el número de caracteres de la línea, y
47 // linea[i] es el carácter que está en la posición i (desde 0).
48 for (int i = 0; i < linea.length(); i++) {
49 if (linea[i] == ' ' || linea[i] == ',') {
50 // Encontramos un separador. Si 'pos' ya no vale -1,
51 // significa que este es el SEGUNDO separador de la línea,
52 // por ejemplo en "AAA CCC GGG". Esa línea no es válida.
53 if (pos != -1) {
54 return false;
55 }
56 // Es el primer separador: recordamos dónde está.
57 pos = i;
58 }
59 }
60
61 // Al salir del ciclo hay tres situaciones inválidas:
62 // pos == -1 no había separador ("ATCG")
63 // pos == 0 el separador es el primer carácter
64 // (" ATCG"): no hay primera secuencia
65 // pos == linea.length() - 1 el separador es el último carácter
66 // ("ATCG,"): no hay segunda secuencia
67 // La condición 'pos <= 0' cubre a la vez los casos -1 y 0.
68 if (pos <= 0 || pos == linea.length() - 1) {
69 return false;
70 }
71
72 // substr(inicio, cantidad) extrae 'cantidad' caracteres desde
73 // 'inicio'. Con la línea "ATCGAT ATGGCT", pos vale 6:
// linea.substr(0, 6) -> "ATCGAT" (posiciones 0 a 5)
75 // linea.substr(7) -> "ATGGCT" (desde la posición 7 hasta
76 // el final de la línea)
77 seq1 = linea.substr(0, pos);
78 seq2 = linea.substr(pos + 1);
79 return true;
80 }
81
82
83 int main() {
84 // ---------------------------------------------------------------
85 // 1. Pedir el nombre del archivo y abrirlo
86 // ---------------------------------------------------------------
87 string nombreArchivo;
88 cout << "Nombre del archivo: ";
89 cin >> nombreArchivo; // lee una palabra (el nombre no debe
90 // tener espacios, p. ej. secuencias.txt)
91 cout << endl;
92
93 // 'ifstream' (input file stream) es un flujo de entrada asociado
94 // a un archivo. Se usa igual que 'cin', pero los datos vienen del
95 // archivo en lugar del teclado. Al crearlo con el nombre, intenta
96 // abrir el archivo. El archivo debe estar en la misma carpeta
97 // desde donde se ejecuta el programa (o escribir la ruta completa).
98 ifstream archivo(nombreArchivo);
99
100 // is_open() devuelve false si el archivo no se pudo abrir: no
101 // existe, el nombre está mal escrito o no hay permisos.
102 // En ese caso no tiene sentido continuar: terminamos el programa.
103 // 'return 1' le indica al sistema operativo que hubo un error
104 // ('return 0', al final, indica que todo salió bien).
105 if (!archivo.is_open()) {
106 cout << "Error: no se pudo abrir el archivo." << endl;
107 return 1;
108 }
109
110 // 'fixed' y 'setprecision(1)' hacen que todos los números con
111 // decimales (double) que se impriman de aquí en adelante muestren
112 // exactamente un decimal: 66.7 en lugar de 66.6667.
113 cout << fixed << setprecision(1);
114
115 // ---------------------------------------------------------------
116 // 2. Leer el archivo línea por línea
117 // ---------------------------------------------------------------
118 string linea; // aquí se guarda cada línea leída
119 int numPareja = 0; // cuántas parejas con formato correcto van
120
121 // getline(archivo, linea) lee la línea completa siguiente del
122 // archivo (hasta el salto de línea, sin incluirlo) y la guarda en
123 // 'linea'. Devuelve un valor que se evalúa como verdadero si logró
124 // leer algo, y como falso cuando ya no quedan líneas. Por eso el
125 // ciclo 'while' se repite una vez por cada línea y se detiene
126 // solo al llegar al final del archivo.
127 //
128 // Se usa getline y no 'archivo >> linea' porque >> se detiene en
// el primer espacio, y aquí necesitamos la línea entera.
130 while (getline(archivo, linea)) {
131
132 // Los archivos creados en Windows terminan cada línea con dos
133 // caracteres: '\r' y '\n'. getline quita el '\n' pero deja el
134 // '\r' al final, invisible en pantalla, y haría que "ATGGCT\r"
135 // tuviera un carácter inválido. Si el último carácter es '\r',
136 // lo borramos con erase(posición).
137 if (!linea.empty() && linea[linea.length() - 1] == '\r') {
138 linea.erase(linea.length() - 1);
139 }
140
141 // Una línea vacía no tiene datos: 'continue' salta el resto
142 // del cuerpo del ciclo y pasa directamente a leer la siguiente.
143 if (linea.empty()) {
144 continue;
145 }
146
147 // Intentamos dividir la línea en dos secuencias. Si el formato
148 // es incorrecto, avisamos y pasamos a la siguiente línea sin
149 // contarla como pareja.
150 string seq1, seq2;
151 if (!separarPareja(linea, seq1, seq2)) {
152 cout << "Aviso: línea ignorada por formato incorrecto: "
153 << linea << endl;
154 continue;
155 }
156
157 // Si llegamos aquí, la línea tiene formato correcto: es una
158 // pareja nueva y le asignamos su número.
159 numPareja++;
160
161 // -----------------------------------------------------------
162 // Incluir aquí el código que ejecute lo solicitado en el
163 // enunciado para cada pareja.
164 // -----------------------------------------------------------
165 }
166
167 // Cerramos el archivo: ya no lo necesitamos. (Se cerraría solo al
168 // terminar el programa, pero cerrarlo explícitamente es buena
169 // costumbre.)
170 archivo.close();
171 return 0;
172 }