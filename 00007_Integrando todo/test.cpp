#include <string.h>  

#define CANT  99
#define PROM  123

FILE *gArchivo = (FILE *)0x01;
Complejo *gArreglo;
int *gCantidad;
int orden = 0;
bool archivoCerrado = false;

FILE *_fopen(char *nombre, char *modo) {
  CPPUNIT_ASSERT_MESSAGE("No se abrió el archivo correcto.", strcmp("complejos.bin", nombre) == 0);
  CPPUNIT_ASSERT_MESSAGE("No se usó el modo de apertura correcto.", strcmp("rb", modo) == 0);
  orden++;
  CPPUNIT_ASSERT_MESSAGE("No se abrió el archivo en el orden correcto.", orden == 1);
  return gArchivo;
}

void VerificarTamanioArreglo(size_t tamanioArreglo) {
  CPPUNIT_ASSERT_MESSAGE("El arreglo no tiene el tamaño adecuado.", tamanioArreglo == 100 * sizeof(Complejo));
}
void _CargarArchivo(FILE *archivo, Complejo arreglo[], int &n) {
  orden++;
  CPPUNIT_ASSERT_MESSAGE("No se cargó el archivo en el orden correcto.", orden == 2);
  gArreglo = arreglo;
  n = CANT;
}

double PromedioModulo(Complejo arreglo[], int n) {
  orden++;
  CPPUNIT_ASSERT_MESSAGE("Debe calcularse el promedio antes de MostrarMayores.", orden == 3);
  CPPUNIT_ASSERT_MESSAGE("No se invocó PromedioModulo con los parámetros correctos.", arreglo == gArreglo && n == CANT);
  return PROM;
}

void MostrarMayores(Complejo arreglo[], int n, double mayoresQue) {
  orden++;
  CPPUNIT_ASSERT_MESSAGE("MostrarMayores se invocó en el orden incorrecto.", orden == 4);
  CPPUNIT_ASSERT_MESSAGE("No se invocó MostrarMayores con los parámetros correctos.", arreglo == gArreglo && n == CANT && mayoresQue == PROM);
}

void _fclose(FILE *archivo) {
  CPPUNIT_ASSERT_MESSAGE("fclose se invocó en el orden incorrecto.", orden >= 2);
  archivoCerrado = true;
}

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testPrincipal );
  CPPUNIT_TEST_SUITE_END();

  void testPrincipal() {
    principal();
    CPPUNIT_ASSERT_MESSAGE("No se invocaron los subprogramas correctamente.", orden == 4);
    CPPUNIT_ASSERT_MESSAGE("No se cerró el archivo.", archivoCerrado);
  }
  
};