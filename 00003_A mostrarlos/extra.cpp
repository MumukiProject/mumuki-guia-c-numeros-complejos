#import <string>

using std::string;

struct Complejo {
  double real;
  double imaginario;
};

virtual class Salida {
  public:
  virtual void limpiar();
  virtual Salida& operator<<(double);
  virtual Salida& operator<<(string);
};

extern Salida cout;
