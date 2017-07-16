#import <string>
#include <sstream>

using std::string;

struct Complejo {
  double real;
  double imaginario;
};

class Esperado {
  public:
  virtual bool esCorrecto(double valor) {
    return false;
  }
  virtual bool esCorrecto(string valor) {
    return false;
  }
};

class EsperadoDouble : public Esperado {
  double esperado;
  public:
  EsperadoDouble(double esperado) {
    this->esperado = esperado;
  }
  bool esCorrecto(double valor) {
    return valor == esperado;
  }
};

class EsperadoString : public Esperado {
  string esperado;
  public:
  EsperadoString(string esperado) {
    this->esperado = esperado;
  }
  bool esCorrecto(string valor) {
    return valor.find(esperado) != string::npos;
  }
};

class Salida {
  private:
  Esperado *esperados[10];
  int n = 0;
  int current = 0;
  bool correcto = true;
  std::ostringstream esperada;
  std::ostringstream salida;
  
  public:
  void limpiar() {
    for (int i = 0; i < n; i++) {
      delete(esperados[i]);
      esperados[i] = 0;
    }
    current = n = 0;
    correcto = true;
    esperada.clear();
    salida.clear();
  }
  bool terminoBien() {
    return correcto && current == n;
  }
  string mensajeError() {
    return "Se esperaba \"" + esperada.str() + "\" pero se obtuvo \"" + salida.str() + "\"";
  }
  
  Salida& esperar(double valor) {
    esperada << valor;
    esperados[n++] = new EsperadoDouble(valor);
    return *this;
  }
  Salida& esperar(string valor) {
    esperada << valor;
    esperados[n++] = new EsperadoString(valor);
    return *this;
  }
  
  template <typename T>
  Salida& operator<<(T valor) {
    salida << valor;
    std::cout << (current < n) << esperados[current]->esCorrecto(valor)<<std::endl;
    correcto = correcto && (current < n) && esperados[current++]->esCorrecto(valor);
    return *this;
  }
};

template<> Salida& Salida::operator<<(Complejo valor) {
  CPPUNIT_FAIL("No se puede mostrar directamente un registro.");
}

Salida cout;
