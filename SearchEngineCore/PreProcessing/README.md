# PreProcessing

La etapa de Preprocesamiento de Datos realiza la lectura de los documentos contenidos en "raw.es" y genera diferentes archivos para cada documento. luego esos archivos son leídos para realizar el tratamiento de caractéres y generar un nuevo archivo que contendrá una lista de palabras asociadas a un documento, con su respectiva frecuencia (cantidad de veces que una palabra se repite en el documento). El tratamiento de caracteres consiste en convertir las palabras a minúsculas y remover caracteres especiales y tildes. Una vez realizado este procedimiento las palabras estarán listas para ser insertadas en el árbol.

Para realizar el preprocesamiento de la data realice los siguientes pasos

1. Descargar el siguiente archivo y descomprimirlo en la misma carpeta que contiene el proyecto principal "MiniSearchEngine", es decir, debe haber una caprteta llamada "raw.es" en la misma carpeta que contiene el proyecto principal.
    https://drive.google.com/open?id=1W0-ZMqYqAWzZt-vHHh7xg5exrZKOsVlS

2. Crear una carpeta llamada "Docs" en la misma carpeta que contiene el proyecto principal

3. Crear una carpeta llamada "build" en la ruta "MiniSearchEngine/SearchEngineCore/PreProcessing/"

4. Ingresar a la carpeta "build" y ejecutar el siguiente comando 
    cmake .. && make 

5. Finalmente ejecutar el programa
    ./preprocess


