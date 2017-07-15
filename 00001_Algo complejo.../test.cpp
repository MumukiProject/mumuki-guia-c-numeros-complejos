class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testComplejoTieneComponenteReal );
    CPPUNIT_TEST( testComplejoTieneComponenteImaginaria );
  CPPUNIT_TEST_SUITE_END();

  void testComplejoTieneComponenteReal() {
    Complejo * complejo = new Complejo();
    complejo->real = 1;
    CPPUNIT_ASSERT( complejo->real == 1 );
  }
  
  void testComplejoTieneComponenteImaginaria() {
    Complejo * complejo = new Complejo();
    complejo->imaginario = 1;
    CPPUNIT_ASSERT( complejo->imaginario == 1 );
  }
  
};