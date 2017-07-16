#include <typeinfo>    // for 'typeid'

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testMostrarComplejo );
  CPPUNIT_TEST_SUITE_END();

  void probarMostrarComplejo(Complejo complejo) {
    cout.limpiar();
    cout.esperar(complejo.real).esperar("+").esperar(complejo.imaginario).esperar("i");
    MostrarComplejo(complejo);
    cout.limpiar();
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