// Archivo Programa.cpp

#include "Programa.h"
#include "Auto.h"

Programa::Programa() {
}

Programa::~Programa() {
    for (Venta* v : ventas) {
        delete v;
    }
}

void Programa::ejecutar() {
    int opcion;
    bool ventaEnCurso = false;
    
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Realizar venta\n";
        std::cout << "2. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                if (ventaEnCurso) {
                    std::cout << "Ya hay una venta en curso.\n";
                    break;
                }

                std::string nombre_cliente;
                std::cout << "Ingrese nombre del cliente:\n ";
                std::cin >> nombre_cliente;

                std::string rut_cliente;
                std::cout << "Ingrese Rut del cliente:\n ";
                std::cin >> rut_cliente;

                Venta* nuevaVenta = new Venta(nombre_cliente, rut_cliente);
                ventaEnCurso = true;
                
                int opcionVenta;
                do {
                    std::cout << "\nSubmenu Venta:\n";
                    std::cout << "1. Terminar venta\n";
                    std::cout << "2. Cancelar venta\n";
                    std::cout << "3. Comprar vehiculo o accesorios\n";
                    std::cout << "Ingrese una opcion: ";
                    std::cin >> opcionVenta;
                    
                    switch (opcionVenta) {
                        case 1:
                            std::cout << "Venta finalizada.\n";
                            ventaEnCurso = false;
                            ventas.push_back(nuevaVenta);
                            break;
                        case 2:
                            std::cout << "Venta cancelada.\n";
                            ventaEnCurso = false;
                            delete nuevaVenta; 
                            break;
                        case 3:
                            int tipo_vehiculo;;
                            do {
                                std::cout << "Elige el tipo de vehículo.\n";
                                std::cout << "1. Auto\n";
                                std::cout << "2. Moto\n";
                                std::cout << "3. Camión\n";
                                std::cout << "4. Volver\n";
                                std::cout << "Ingrese una opcion: ";
                                std::cin >> tipo_vehiculo;

                                Auto auto_elegido;

                                std::string marca_auto;
                                switch (tipo_vehiculo) {
                                    case 1:
                                    case 2:
                                    case 3:
                                        int cantidad_autos;
                                        int cantidad_puertas;
                                        int cantidad_luces;
                                        std::cout << "Ingrese la marca del auto:\n ";
                                        std::cin >> marca_auto;
                                        auto_elegido = Auto(marca_auto);
                                        if (auto_elegido.getMarca() == "") {
                                            std::cout << "Marca ingresada no existe, volviendo a submenú.\n";
                                            break;
                                        } else {
                                            int opcion_venta;
                                            do {
                                                std::cout << "Submenú venta autos y accesorios para marca " << auto_elegido.getMarca() << std::endl;
                                                std::cout << "1. Comprar Autos " << auto_elegido.getMarca() << "\n"  << std::endl;
                                                std::cout << "2. Comprar Accesorios " << auto_elegido.getMarca() << "\n"  << std::endl;
                                                std::cout << "3. Volver\n";
                                                std::cout << "Ingrese una opcion: ";
                                                std::cin >> opcion_venta;

                                                switch (opcion_venta)
                                                {
                                                case 1:
                                                    std::cout << "Elige cantidad de Autos " << auto_elegido.getMarca() << "a comprar:\n"  << std::endl;
                                                    std::cin >> cantidad_autos;
                                                    break;
                                                case 2:
                                                    std::cout << "Elige accesorios para Autos " << auto_elegido.getMarca() << "a comprar:\n"  << std::endl;
                                                    std::cout << "1." << auto_elegido.getAccesorioN1() << "\n"  << std::endl;
                                                    std::cout << "2." << auto_elegido.getAccesorioN2() << "\n"  << std::endl;
                                                    std::cout << "3. Volver\n";
                                                    std::cin >> cantidad_autos;
                                                    break;
                                                default:
                                                    break;
                                                }

                                            }while (opcion_venta != 3);
                                            break;
                                        }
                                        break;
                                    case 4:
                                        break;
                                    default:
                                        std::cout << "Opcion invalida. Intente de nuevo.\n";
                                }
                            } while (tipo_vehiculo != 4);
                            break;
                        default:
                            std::cout << "Opcion invalida. Intente de nuevo.\n";
                    }
                } while (opcionVenta != 1 && opcionVenta != 2);
                break;
            }
            case 2:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 2);
}
