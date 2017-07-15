#include <typeinfo>    // for 'typeid'

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testComplejoTieneComponenteReal );
    CPPUNIT_TEST( testComplejoTieneComponenteImaginaria );
  CPPUNIT_TEST_SUITE_END();
  
  template <typename T>
  bool probarNumeroReal(T numero) {
    return typeid(numero) == typeid(float) || typeid(numero) == typeid(double);
  }

  void testComplejoTieneComponenteReal() {
    Complejo complejo;
    CPPUNIT_ASSERT_MESSAGE("La parte real no acepta un número real.", probarNumeroReal(complejo.real));
  }
  
  void testComplejoTieneComponenteImaginaria() {
    Complejo complejo;
    complejo.imaginario = 1.5;
    CPPUNIT_ASSERT_MESSAGE("La parte imaginaria no acepta un número real.", complejo.imaginario == 1.5);
  }
  
};