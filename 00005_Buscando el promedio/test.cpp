#include <stdarg.h>  

bool operator==(Complejo a, Complejo b) {
  return a.real == b.real && a.imaginario == b.imaginario;
}

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testPromedio );
  CPPUNIT_TEST_SUITE_END();

  Complejo c(double r, double i) {
    return {r, i};
  }
  void probarPromedio(int n, ...) {
    Complejo arreglo[n];
    double promedio = 0;
    va_list va;
    va_start(va, n);
    for (int i = 0; i < n; i++) {
      Complejo numero = va_arg(va, Complejo);
      arreglo[i] = numero;
      promedio += Modulo(numero);
    }
    va_end(va);
    promedio /= n;
    CPPUNIT_ASSERT_MESSAGE("El promedio calculado no corresponde con el promedio del arreglo", promedio == PromedioModulo(arreglo, n));
  }
  

  void testPromedio() {
    probarPromedio(3, c(1, 1), c(3, 4), c(-1, 0));
    probarPromedio(1, c(0.5, -0.5));
  }
  
};