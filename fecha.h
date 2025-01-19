#ifndef FECHA_H
#define FECHA_H

#include <string>
#include <iostream>

class Fecha {
	private:
        int dia;
        int mes;
        int anio;
	public:
		Fecha(int dia, int mes, int anio);
        Fecha(int dia, int mes);
        Fecha();

        bool operator==(const Fecha& fecha);
        bool operator<(const Fecha& fecha);
		friend std::ostream& operator<<(std::ostream& out, const Fecha &libro);
        int getDia();
        void setDia(int dia);
        int getMes();
        void setMes(int mes);
        int getAnio();
        void setAnio(int anio);
};

#endif