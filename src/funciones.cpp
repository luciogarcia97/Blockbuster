#include "funciones.h"

//TODO: Corregir la validacion, me tira error "Multiple definition of 'nombre de la funcion'"
int validarCinInt(){
   int error;
   int value;
   do
   {
       error = 0;
       std::cin >> value;
       if (std::cin.fail())
       {
           std::cout << "Dato invalido, reingrese nuevamente" << std::endl;
           error = 1;
           std::cin.clear();
           std::cin.ignore(80, '\n');
       }
   }while(error == 1);
   return value;
}

float validarCinFloat(){
    int error;
    float value;
    do
    {
        error = 0;
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cout << "Dato invalido, reingrese nuevamente" << std::endl;
            error = 1;
            std::cin.clear();
            std::cin.ignore(80, '\n');
        }
    }while(error == 1);
    return value;
}

bool validarCinBool() {
  bool valor;
  int entrada;
  int error;

  do {
        error = 0;
        std::cin >> entrada;

        if (std::cin.fail() || (entrada != 0 && entrada != 1)) {
            std::cout << "Dato invalido, reingrese nuevamente. " << std::endl;
            std::cout << "Ingrese un valor (0 o 1): ";
            error = 1;
            std::cin.clear();
            std::cin.ignore(80, '\n');
        } else {
            valor = entrada;
            break;
        }
  } while(error == 1);

  return valor;
}

void headerVentas(){
    //TO DO, esto se puede mejorar con algunos repos de github donde crean una clase que te hace toda esta configuracion. (https://stackoverflow.com/questions/6755250/format-output-in-a-table-c)
    //Tiene formato de tabla
    std::cout << "Venta" << "\t\tCliente" << "\t\tFecha" << "\t\tVendedor" << "\tForma de pago" << std::endl;
}

void headerAlquiler(){
    std::cout << "Alquiler" << "\tCliente" << "\t\tFecha Alquiler" << "\tVendedor" << "\tForma de pago" << "\tFecha de Devolucion" << "\t\tFecha de Entrega" << "\t\tEstado" << std::endl;
}

void headerAlquilerDetalle(){
    std::cout << "Alquiler" << "\tArticulo" << "\tTipo Articulo" << "\tCantidad" << "\tValor total" << std::endl;
}

void headerVentaDetalle(){
    std::cout << "Venta" << "\tArticulo" << "\tTipo Articulo" << "\tCantidad" << "\tValor total" << std::endl;
}

const char* stringToConstChar(std::string nombre, int caracteres){
    if (nombre.size() <= caracteres)
    {
        return nombre.c_str();
    }
    return "ErrorEnNombrar";
}

bool validarPositivoInt(int value){
    if (value > 0) return true;
    return false;
}

bool validarPositivoFloat(float value){
    if (value > 0) return true;
    return false;
}

void setCaracteres(char cad[]){
	int i=1;
	if(cad[0]>='a' && cad[0]<='z'){
		cad[0] = cad[0] - ('a' - 'A');
	}
	while(cad[i]!= '\0'){
		if(cad[i]>='A' && cad[i]<='Z'){
			cad[i] = cad[i] + ('a' - 'A');
		}
		if(cad[i] == ' '){
            if(cad[i+1]>='a' && cad[i+1]<='z'){
                cad[i+1] = cad[i+1] - ('a' - 'A');
                i++;
            }
		}
		i++;
	}
}