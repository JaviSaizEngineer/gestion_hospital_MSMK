cmake_minimum_required(VERSION 3.6)

# Nombre del proyecto
project(practica)

# Archivos fuente .cpp que contiene el código
set(SOURCES
    main.cpp
    medico.cpp
    paciente.cpp
    persona.cpp
)

# Crear el ejecutable
add_executable(practica ${SOURCES})

# Establecer el tipo de construcción: Debug o Release
set(CMAKE_BUILD_TYPE Debug)

# Configuración de flags para Debug y Release
set(CMAKE_CXX_FLAGS_DEBUG "-pedantic -Wall -W -Wconversion -O0 -ggdb -std=gnu++17 -O0 -ggdb3 -DDEBUG ")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -std=gnu++17")

# Si tus archivos de cabecera están en una carpeta `include`, debes especificarlo
# Esto asegura que CMake sepa dónde buscar los archivos `.h`
include_directories(${CMAKE_SOURCE_DIR})

# Instalar el ejecutable en una carpeta `bin`
install(TARGETS practica RUNTIME DESTINATION bin)
