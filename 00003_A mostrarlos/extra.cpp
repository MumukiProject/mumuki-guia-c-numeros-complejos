#import <string>

using std::string;

struct Complejo {
  double real;
  double imaginario;
};

class Esperado {
  
}

class Salida {
  private:
  Esperado *esperados[10];
  int n = 0;
  
  public:
  void limpiar() {
    for (int i = 0; i < n; i++) {
      delete(esperados[i]);
      esperados[i] = 0;
    }
    n = 0;
  }
  
  Salida& esperar(double valor) {
    return *this;
  }
  Salida& esperar(string valor) {
    return *this;
  }
  
  Salida& operator<<(double valor) {
    return *this;
  }
  Salida& operator<<(string valor) {
    return *this;
  }
};

Salida cout = Salida();
