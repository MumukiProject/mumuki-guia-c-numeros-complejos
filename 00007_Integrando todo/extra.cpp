struct Complejo {
  double real;
  double imaginario;
};

void VerificarTamanioArreglo(size_t tamanioArreglo);

void _CargarArchivo(FILE *archivo, Complejo arreglo[], int &n);

double PromedioModulo(Complejo arreglo[], int n);

void MostrarMayores(Complejo arreglo[], int n, double mayoresQue);

FILE *_fopen(char *nombre, char *modo);
void _fclose(FILE *archivo);

#define CargarArchivo(a, b, c)  VerificarTamanioArreglo(sizeof(b));\
_CargarArchivo(a, b, c)

#define fopen(a, b) _fopen(a, b)

#define fclose(a) _fclose(a)
