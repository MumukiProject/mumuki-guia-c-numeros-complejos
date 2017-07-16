#import <string>

using std::string;

struct Complejo {
  double real;
  double imaginario;
};

class Salida {
  public:
  void limpiar();
  Salida& operator<<(double);
  Salida& operator<<(string);
};

extern Salida cout;
