#import <string>

using std::string;

struct Complejo {
  double real;
  double imaginario;
};

class Salida {
  public:
  virtual void limpiar();
  virtual const Salida& operator<<(double);
  virtual const Salida& operator<<(string);
};

extern Salida cout;
