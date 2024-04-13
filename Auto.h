#include "Vehiculo.h"
#include <string>

class Auto : public Vehiculo {
private:
    int precio_puertas;
    int precio_luces;
    std::string accesorio_n1 = "Puertas";
    std::string accesorio_n2 = "Luces";


public:
    Auto();
    Auto(std::string marca);
    int getPrecioPuertas();
    int getPrecioLuces();
    void setPrecioPuertas(int precio);
    void setPrecioLuces(int precio);
    std::string getAccesorioN1();
    std::string getAccesorioN2();
};