#include "Vehiculo.h"
#include <string>
using namespace std;

class Moto : public Vehiculo {
private:
    int precio_pedales;
    int precio_espejos;

public:
    Moto(string marca);
    int getPrecioPedales();
    int getPrecioEspejos();
    void setPrecioPedales(int precio);
    void setPrecioEspejos(int precio);
};