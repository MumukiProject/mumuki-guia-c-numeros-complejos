#include <typeinfo>    // for 'typeid'

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testMostrarComplejo );
  CPPUNIT_TEST_SUITE_END();

  void probarMostrarComplejo(Complejo complejo) {
    cout.limpiar();
    cout.esperar(complejo.real).esperar("+").esperar(complejo.imaginario).esperar("i");
    MostrarComplejo(complejo);
    if (!cout.terminoBien()) {
      CPPUNIT_FAIL(cout.mensajeError());
    }
  }

  void testMostrarComplejo() {
    probarMostrarComplejo({3, 4});
    probarMostrarComplejo({2, 2});
  }
  
};