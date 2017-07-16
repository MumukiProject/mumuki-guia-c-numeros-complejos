#include <typeinfo>    // for 'typeid'

class TestSalida : Salida {
  void limpiar() {
    
  }
  
  Salida &<<(double valor) {
    return this;
  }
  Salida &<<(string valor) {
    return this;
  }
}

Salida cout = new TestSalida();

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testMostrarComplejo );
  CPPUNIT_TEST_SUITE_END();

  void probarMostrarComplejo(Complejo complejo) {
    cout.limpiar();
    MostrarComplejo(complejo);
  }

  void testMostrarComplejo() {
    probarMostrarComplejo({3, 4});
    probarMostrarComplejo({2, 2});
    /*
    CPPUNIT_ASSERT_MESSAGE("El módulo de (1) debería ser 1.", Modulo({ 1, 0 }) == 1);
    CPPUNIT_ASSERT_MESSAGE("El módulo de (-i) debería ser 1.", Modulo({ 0, -1 }) == 1);
    CPPUNIT_ASSERT_MESSAGE("El módulo de (3+4i) debería ser 5.", Modulo({ 3, 4 }) == 5);
    CPPUNIT_ASSERT_MESSAGE("El módulo de (3-4i) debería ser 5.", Modulo({ 3, -4 }) == 5);
    */
  }
  
};