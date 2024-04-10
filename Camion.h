#include "Vehiculo.h"
#include <string>
using namespace std;

class Camion : public Vehiculo {
private:
    int precio_caja;
    int precio_ejes;

public:
    Camion(string marca);
    int getPrecioCaja();
    int getPrecioEjes();
    void setPrecioCaja(int precio);
    void setPrecioEjes(int precio);
};