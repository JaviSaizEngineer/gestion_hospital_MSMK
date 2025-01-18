#include <string>
#include <iostream>
#include "fecha.h"

class RegistroClinico { //representa un registro del historial clinico
private:
    Fecha fecha;  // Fecha del registro
    std::string diagnostico;
    std::string tratamiento;
    std::string observaciones;

public:
    RegistroClinico(const Fecha &fecha, std::string diagnostico, std::string tratamiento, std::string observaciones);
    
    void mostrarRegistro() const;

    Fecha getFecha() const;
    void setFecha(const Fecha &fecha);
    std::string getDiagnostico() const;
    void setDiagnostico(const std::string &diagnostico);
    std::string getTratamiento() const;
    void setTratamiento(const std::string &tratamiento);
    std::string getObservaciones() const;
    void setObservaciones(const std::string observaciones);
};