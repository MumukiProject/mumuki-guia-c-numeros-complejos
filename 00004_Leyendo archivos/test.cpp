#include <stdarg.h>  

bool operator==(Complejo a, Complejo b) {
  return a.real == b.real && a.imaginario == b.imaginario;
}

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testCargarArchivo );
  CPPUNIT_TEST_SUITE_END();

  Complejo c(double r, double i) {
    return {r, i};
  }
  FILE *probarCargarArchivo(char *nombreArchivo, int n, ...) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    Complejo esperado[n];
    va_list va;
    va_start(va, n);
    for (int i = 0; i < n; i++) {
      Complejo numero = va_arg(va, Complejo);
      esperado[i] = numero;
      fwrite(&numero, sizeof(numero), 1, archivo);
    }
    va_end(va);
    fclose(archivo);
    archivo = fopen(nombreArchivo, "rb");
    Complejo arreglo[n + 10];
    int cantidad = 0;
    CargarArchivo(archivo, arreglo, cantidad);
    CPPUNIT_ASSERT_MESSAGE("La cantidad de elementos retornados no corresponde con la cantidad en el archivo", n == cantidad);
    bool correcto = true;
    if (n == cantidad) for (int i = 0; i < n; i++) {
      correcto = correcto && esperado[i] == arreglo[i];
    }
    CPPUNIT_ASSERT_MESSAGE("El contenido del arreglo no es igual al del archivo", correcto);
    fclose(archivo);
  }
  

  void testCargarArchivo() {
    char *arch = "complejos.bin";
    probarCargarArchivo(arch, 3, c(1, 1), c(3, 4), c(-1, 0));
    probarCargarArchivo(arch, 0);
    probarCargarArchivo(arch, 1, c(0.5, -0.5));
  }
  
};