#include <typeinfo>    // for 'typeid'

struct Complejo;

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testComplejoEstaBienDefinido );
  CPPUNIT_TEST_SUITE_END();
  
  template <typename T>
  bool aceptaNumeroReal(T &numero) {
    return typeid(numero) == typeid(float) || typeid(numero) == typeid(double) || typeid(numero) == typeid(long double);
  }

  void testComplejoEstaBienDefinido() {
    Complejo complejo;
    CPPUNIT_ASSERT_MESSAGE("La parte real no acepta un número real.", aceptaNumeroReal(complejo.real));
    CPPUNIT_ASSERT_MESSAGE("La parte imaginaria no acepta un número real.", aceptaNumeroReal(complejo.imaginario));
  }
  
};