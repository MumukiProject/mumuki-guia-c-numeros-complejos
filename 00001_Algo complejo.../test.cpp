#include <typeinfo>    // for 'typeid'

struct Complejo;

/*
  Se define la variable acá para tirar error
  una sola vez.
*/
Complejo complejo;

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testComplejoTieneParteReal);
    CPPUNIT_TEST( testComplejoTieneParteImaginaria);
    CPPUNIT_TEST( testRealEImaginarioSonDelMismoTipo);
  CPPUNIT_TEST_SUITE_END();
  
  template <typename T>
  bool aceptaNumeroReal(T &numero) {
    return typeid(numero) == typeid(float) || typeid(numero) == typeid(double) || typeid(numero) == typeid(long double);
  }

  void testComplejoTieneParteReal() {
    CPPUNIT_ASSERT_MESSAGE("La parte real no acepta un número real.", aceptaNumeroReal(complejo.real));
  }
  
  void testComplejoTieneParteImaginaria() {
    CPPUNIT_ASSERT_MESSAGE("La parte imaginaria no acepta un número real.", aceptaNumeroReal(complejo.imaginario));
  }
  
  void testRealEImaginarioSonDelMismoTipo() {
    complejo.imaginario;
    CPPUNIT_ASSERT_MESSAGE("La parte real y la parte imaginaria son de distinto tipo.", typeid(complejo.imaginario) == typeid(complejo.real));
  }
  
};