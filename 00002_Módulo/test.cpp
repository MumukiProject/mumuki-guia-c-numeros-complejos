#include <typeinfo>    // for 'typeid'

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testModuloComplejo );
  CPPUNIT_TEST_SUITE_END();

  void testModuloComplejo() {
    CPPUNIT_ASSERT_MESSAGE("La parte real no acepta un número real.", Modulo({ 1, 0 }) == 1);
    CPPUNIT_ASSERT_MESSAGE("La parte imaginaria no acepta un número real.", aceptaNumeroReal(complejo.imaginario));
    CPPUNIT_ASSERT_MESSAGE("La parte real y la parte imaginaria son de distinto tipo.", typeid(complejo.imaginario) == typeid(complejo.real));
  }
  
};