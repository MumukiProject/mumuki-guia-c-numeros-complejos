```
struct Complejo {
  double real;
  double imaginario;
};

void CargarArchivo(FILE *archivo, Complejo arreglo[], int &n);

double PromedioModulo(Complejo arreglo[], int n);

void MostrarMayores(Complejo arreglo[], int n, double mayoresQue);
```