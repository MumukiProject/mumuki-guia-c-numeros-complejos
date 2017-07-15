class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testComplejoTieneComponenteReal );
    CPPUNIT_TEST( testComplejoTieneComponenteImaginaria );
  CPPUNIT_TEST_SUITE_END();

  void testComplejoTieneComponenteReal() {
    Complejo complejo;
    complejo.real = 1.5;
    CPPUNIT_ASSERT_MESSAGE("La parte real no acepta un número real.", complejo.real == 1.5);
  }
  
  void testComplejoTieneComponenteImaginaria() {
    Complejo complejo;
    complejo.imaginario = 1.5;
    CPPUNIT_ASSERT_MESSAGE("La parte imaginaria no acepta un número real.", complejo.imaginario == 1.5);
  }
  
};