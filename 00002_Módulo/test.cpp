#include <typeinfo>    // for 'typeid'

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testModuloComplejo );
  CPPUNIT_TEST_SUITE_END();

  void testModuloComplejo() {
    CPPUNIT_ASSERT_MESSAGE("El módulo de (1) debería ser 1.", Modulo({ 1, 0 }) == 1);
    CPPUNIT_ASSERT_MESSAGE("El módulo de (3+4i) debería ser 5.", Modulo({ 3, 4 }) == 5);
    CPPUNIT_ASSERT_MESSAGE("El módulo de (3-4i) debería ser 5.", Modulo({ 3, -4 }) == 5);
  }
  
};