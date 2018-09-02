# MiniSearchEngine
Implementación de motor de búsqueda.

Integrantes:
------------

1. Choqueluque Roman David
2. Ramos Cooper Solange
3. Soto Barrera Roxana

Este proyecto presenta los siguientes modulos.

- 1.Preprocessing: En esta modulo se procesa el dataset para su correcto indexamiento.
- 2.Indexing: En este modulo se indexan en la estructura de datos las palabras antes procesadas.
- 3.SearchConsole: Este modulo ejecuta la aplicacion para realizar las consultas.

Pasos para la instalacion/ejecucion de la aplicacion
----------------------------------------------------
Para ejecutar la aplicacion debe seguir los siguientes pasos:
- Paso 0: Cree una carpeta para la aplicacion
- Paso 1: Descargue el dataset de palabras a indexar.
- Paso 2: Ejecute el modulo de preprocesamiento.
- Paso 3: Descargue los archivos necesarios para el indexamiento.
- Paso 4: Ejecute la aplicacion.

Desarrollo de los pasos
-----------------------
## Paso 0: Cree una carpeta para la aplicacion
Cree una carpeta donde vea conveniente y dentro de la misma clone o descargue el repositorio del proyecto.

## Paso 1: Descargue el dataset de palabras a indexar.

Descargue el dataset del siguiente link:

- https://drive.google.com/file/d/1W0-ZMqYqAWzZt-vHHh7xg5exrZKOsVlS/view

A continuacion descomprima el archivo en la carpeta que creo en el paso 0. En esta misma carpeta cree una nueva carpeta con el nombre "Docs".

## Paso 2: Ejecute el modulo de preprocesamiento.
- Dirijase a la carpeta "MiniSearchEngine/SearchEngineCore/PreProcessing/" y cree en esta misma una carpeta con el nombre "build" (sin comillas).
- Abra una terminal y dirijase a la carpeta build que creo anteriormente. (Use el comando "cd ").
- En la terminal ejecute el comando: "cmake .." (Sin comillas. Es necesario que tenga instalado cmake).
- A continuacion ejecute el comando: "make .." (este comando generara un ejecutable con nombre: "preprocess")
- Ejecute el ejecutable antes creado con el comando: "./preprocess". Este comando creara documentos en la carpeta "Docs" que creo en el paso 1.

## Paso 3: Descargue los archivos necesarios para el indexamiento.
- Dirijase a la carpeta: MiniSearchEngine/SearchEngineCore/SearchConsole/ y cree en esta una carpeta con el nombre "build".
- Descargue los siguientes dos archivos .txt del siguiente link: https://drive.google.com/open?id=1r8PSI-kIWigYTcvldp7w1YSb17SRLNuE

- Guarde los archivos descargados en la carpeta build que creo anteriormente.
- Abra una terminal y dirijase (con el comando cd) a la carpeta build que creo anteriormente.
- En la terminal ejecute el comando: "cmake .." (Sin comillas. Es necesario que tenga instalado cmake).
- A continuacion ejecute el comando: "make .." (este comando generara un ejecutable con nombre: "engine")


## Paso 4: Ejecute la aplicacion
- Ejecute el ejecutable antes creado en la carpeta buid con el comando: "./engine". Este ejecutara la aplicacion y mostrara un menu en consola.


