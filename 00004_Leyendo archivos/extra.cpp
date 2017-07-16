struct Complejo {
  double real;
  double imaginario;
};

template <typename T>
void Leer(FILE *archivo, T &registro) {
  fread(&registro, sizeof(registro), 1, archivo);
}
