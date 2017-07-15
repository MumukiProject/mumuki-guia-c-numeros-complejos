#include <typeinfo>    // for 'typeid'
#include <type_traits>

template<class T, class U = void>
struct type_exists { enum { value = 0 }; };

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