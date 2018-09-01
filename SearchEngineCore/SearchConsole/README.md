# Search

El programa final permite realizar consultas de una o varias palabras por consola, al ingresar una consulta desde el buscador, el programa mostrará todos los documentos donde se encontraron coincidencias con la(s) palabra)s) ingresadas. Además muestra la cantidad de documentos y el tiempo que tomó el programa en realizar la consulta. Además muestra un pequeño "Menú de opciones" para poder navegar entre los resultados o mostrar el contenido de un docuemnto.

Para realizar la ejecución del programa realice los siguientes pasos 

1. Crear una carpeta llamada "build" en la ruta "MiniSearchEngine/SearchEngineCore/SearchConsole/"
    Esta carpeta debe contener los documentos persistence_cloud.txt persistence_tree.txt
    Estos archivos pueden ser descargados desde el siguiente link https://drive.google.com/open?id=1r8PSI-kIWigYTcvldp7w1YSb17SRLNuE

2. Ingresar a la carpeta "build" y ejecutar el siguiente comando 
    cmake .. && make 

3. Finalmente ejecutar el programa
    ./engine

NOTA IMPORTANTE:
Debe existir una carpeta llamada "Docs" en la misma carpeta que contiene el proyecto principal "MiniSearchEngine", esta carpeta debe contener todos los documentos en los cuales se hará la búsqueda. Estos archivos son generados por el programa de pre-procesamiento.
