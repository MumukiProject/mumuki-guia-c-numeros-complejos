#include <typeinfo>    // for 'typeid'

struct Complejo;

class MumukiTest : public CppUnit::TestFixture  {
  CPPUNIT_TEST_SUITE( MumukiTest );
    CPPUNIT_TEST( testComplejoTieneComponenteReal );
    CPPUNIT_TEST( testComplejoTieneComponenteImaginaria );
  CPPUNIT_TEST_SUITE_END();
  
  template <typename T>
  bool aceptaNumeroReal(T numero) {
    return tstd::is_floating_point<numero)>::value;
  }
  
  bool tipoComplejoDefinido() {
    static_assert(type_exists<Complejo>::value, "expected compile-time error");
    return sizeof(Complejo) > 0;
  }
  
  void testComplejoExiste() {
    CPPUNIT_ASSERT_MESSAGE("No se definió el tipo Complejo.", tipoComplejoDefinido());
  }

  void testComplejoTieneComponenteReal() {
    Complejo complejo;
    CPPUNIT_ASSERT_MESSAGE("La parte real no acepta un número real.", aceptaNumeroReal(complejo.real));
  }
  
  void testComplejoTieneComponenteImaginaria() {
    Complejo complejo;
    CPPUNIT_ASSERT_MESSAGE("La parte imaginaria no acepta un número real.", aceptaNumeroReal(complejo.imaginario));
  }
  
};