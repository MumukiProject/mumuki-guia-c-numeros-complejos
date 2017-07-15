#include <typeinfo>    // for 'typeid'

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testModuloComplejo );
  CPPUNIT_TEST_SUITE_END();

  void testModuloComplejo() {
    CPPUNIT_ASSERT_MESSAGE("La parte real no acepta un número real.", Modulo({ 1, 0 }) == 1);
  }
  
};