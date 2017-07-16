#import <string>

using std::string;

struct Complejo {
  double real;
  double imaginario;
};

template <typename T>
class Esperado {
  T esperado;
  
  public:
  Esperado(T valor) {
    this.esperado = valor;
  }
  virtual bool esCorrecto(T valor) {
    return esperado == valor;
  }
  template <typename T>
  bool esCorrecto(T valor) {
    return false;
  }
};

class Esperado<string> {
  bool esCorrecto(string valor) {
    return valor.find(esperado) != string::npos;
  }
};

class Salida {
  private:
  Esperado *esperados[10];
  int n = 0;
  int current = 0;
  
  public:
  void limpiar() {
    for (int i = 0; i < n; i++) {
      delete(esperados[i]);
      esperados[i] = 0;
    }
    current = n = 0;
  }
  void terminoBien() {
    CPPUNIT_ASSERT_MESSAGE("faltaron salidas", current == n);
  }
  
  template <typedef T>
  Salida& esperar(T valor) {
    esperados[n++] = new Esperado(valor);
    return *this;
  }
  
  template <typename T>
  Salida& operator<<(T valor) {
    CPPUNIT_ASSERT_MESSAGE("hubo mas salidas que las esperadas.", current < n);
    if (current < n) {
      CPPUNIT_ASSERT_MESSAGE("se esperaba un valor distinto", esperados[current++]->esCorrecto(valor));
    }
    return *this;
  }
};

Salida cout = Salida();
