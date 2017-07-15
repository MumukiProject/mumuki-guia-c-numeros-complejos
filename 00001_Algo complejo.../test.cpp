#include <typeinfo>    // for 'typeid'

#ifndef Complejo
using namespace Test;
#endif

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testComplejoTieneComponenteReal );
    CPPUNIT_TEST( testComplejoTieneComponenteImaginaria );
  CPPUNIT_TEST_SUITE_END();
  
  template <typename T>
  bool aceptaNumeroReal(T numero) {
    return typeid(numero) == typeid(float) || typeid(numero) == typeid(double);
  }
  
  bool tipoComplejoDefinido() {
    return typeid(Complejo) != typeid(Test::Complejo);
  }
  
  void testComplejoExiste() {
    CPPUNIT_ASSERT_MESSAGE("No se definió el tipo Complejo.", tipoComplejoDefinido());
  }
/*
  */
};