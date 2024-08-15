#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Number words arrays
string unidades[] = {"uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
string decenas[] = {"veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
string centenas[] = {"cien", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

// Funtions to cats the entire part
string formatoCorrecto(int numero) {
    if(numero <=0)return "";
    else if(numero == 1)return " millon ";
    else return " millones ";
}
// funcion para llevar numero a palabras
string convertirEnteroAString(int num) {
    /*
     Esta funcion busca traducir un numero ingresado
     por parametros a su forma de letras por ejemplo:
     100 -> cien.
     */
    if(num == 0) return "0";
    else if(num < 20)return unidades[num - 1];
    else if(num <100) return decenas[(num/10)-2] + (num % 10!=0 ? " y "  + convertirEnteroAString(num % 10): "");
    // Comentar condicion ya que se puede hacer de una manera mas corta.
    // else if(num < 1000) return (num == 100 ? "cien" : centenas[(num / 100) -1]+ (num % 100 != 0 ? " "+convertirEnteroAString(num %100): ""));
    // condicino mas corta para el mismo resultado
    else if(num < 1000) return centenas[(num /100)-1] + (num % 100 != 0 ? " " +convertirEnteroAString(num % 100): "") ;
    else if(num < 100000) return convertirEnteroAString(num / 1000) + " mil " + (num % 1000 != 0 ? convertirEnteroAString(num %1000) :"");
    else if(num < 1000000000) return convertirEnteroAString(num / 1000000) + formatoCorrecto(num / 1000000) +(num % 1000000 !=0? convertirEnteroAString(num % 1000000):"");
    else return convertirEnteroAString(num / 1000000000) + " mil millones " + (num % 1000000000 != 0 ? convertirEnteroAString(num % 1000000000): "");
}

string convertirDecimal(int decimal) {
    return " con " + to_string(decimal) + "/100";
}

double eliminarMascara(string num) {
    num.erase(remove(num.begin(), num.end(), ','), num.end());
    return stod(num);
}
int main() {
    string numeroConMascara;
    cout << "Ingrese un numero: ";
    cin >> numeroConMascara;
    //Eliminar la mascara del numero.
    double num = eliminarMascara(numeroConMascara);
    // split int and decimal part
    int intPart = static_cast<int>(num);
    int decimalPart = static_cast<int>((num - intPart)*100);
    cout << convertirEnteroAString(intPart) + convertirDecimal(decimalPart);
    return 0;
}