#include <math.h>

struct Complejo {
  double real;
  double imaginario;
};

double Modulo(Complejo complejo) {
  return sqrt(complejo.real * complejo.real + complejo.imaginario * complejo.imaginario);
}
