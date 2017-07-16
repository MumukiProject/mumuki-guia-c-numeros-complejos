#import <string>

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
  
  Salida& esperar(double valor) {
    esperados[n++] = new EsperadoDouble(valor);
    return *this;
  }
  Salida& esperar(string valor) {
    esperados[n++] = new EsperadoString(valor);
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
