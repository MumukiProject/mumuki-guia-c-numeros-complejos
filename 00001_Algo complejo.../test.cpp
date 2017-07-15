class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testComplejoTieneComponenteReal );
    CPPUNIT_TEST( testComplejoTieneComponenteImaginaria );
  CPPUNIT_TEST_SUITE_END();

  void testComplejoTieneComponenteReal() {
    Complejo complejo;
    complejo.real = 1.5;
    CPPUNIT_ASSERT( complejo.real == 1.5, "La parte real no acepta un número real." );
  }
  
  void testComplejoTieneComponenteImaginaria() {
    Complejo complejo;
    complejo.imaginario = 1.5;
    CPPUNIT_ASSERT( complejo.imaginario == 1.5, "La parte imaginaria no acepta un número real." );
  }
  
};