#include <stdarg.h>  

bool operator==(Complejo a, Complejo b) {
  return a.real == b.real && a.imaginario == b.imaginario;
}

Complejo *gMayores;
int gCurrent, gTotal;
bool gCorrecto;

void MostrarComplejo(Complejo complejo) {
  gCorrecto = gCorrecto && gCurrent < gTotal && gMayores[gCurrent++] == complejo;
}

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testCargarArchivo );
  CPPUNIT_TEST_SUITE_END();

  Complejo c(double r, double i) {
    return {r, i};
  }
  void probarMostrarMayores(double mayoresQue, int n, ...) {
    Complejo arreglo[n];
    Complejo mayores[n];
    gMayores = mayores;
    gCurrent = 0;
    gTotal = 0;
    gCorrecto = true;
    va_list va;
    va_start(va, n);
    for (int i = 0; i < n; i++) {
      Complejo numero = va_arg(va, Complejo);
      arreglo[i] = numero;
      if (Modulo(numero) > mayoresQue) {
        mayores[gTotal++] = numero;
      }
    }
    va_end(va);
    MostrarMayores(arreglo, n, mayoresQue);
    CPPUNIT_ASSERT_MESSAGE("La cantidad de elementos mostrados no corresponde con la cantidad en elementos cuyo módulo es mayor al parámetro.", gCurrent == gTotal);
    CPPUNIT_ASSERT_MESSAGE("Los elementos mostrados no son los correctos.", gCorrecto);
  }

  void testMostrarMayores() {
    probarMostrarMayores(1, 3, c(1, 1), c(3, 4), c(-1, 0));
    probarMostrarMayores(0, 1, c(0.5, -0.5));
  }
  
};