Segunda Tarea Programada


Objetivos:

    • Definir, especificar, implementar y usar el  modelo Grafo No Dirigido, con pesos en las aristas, sin lazos y sin aristas paralelas.

    • Definir, especificar, implementar y usar el  modelo Grafo Dirigido, con pesos en las aristas, sin lazos y sin aristas paralelas.

    • Definir, especificar, implementar y usar el  modelo Diccionario.

    • Definir, especificar, implementar y usar el  modelo Relaciones 1:1.

    • Implementar el  algoritmo de recorrido en profundidad primero de un grafo dirigido.

    • Implementar  algoritmos para encontrar caminos de costo mínimo en un grafo dirigido.
      
    • Aplicar el método de Búsqueda Exhaustiva Pura para resolver un problema de optimización en grafos no dirigidos.

    • Implementar otros algoritmos de grafos



Especificaciones de la Tarea.

    • Definir formalmente el modelo Grafo Dirigido, con pesos en las aristas, sin lazos y sin aristas paralelas.

    • Especificar de manera lógica, formal y completa los operadores básicos del modelo Grafo Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas: Crear, Destruir, Vaciar,  Vacío, AgregarVértice (devuelve el vértice creado), EliminarVértice, ModificarEtiqueta, Etiqueta, AgregarArista, EliminarArista, ModificarPeso, Peso, PrimerVértice, SiguienteVértice, PrimerVérticeAdyacente, SiguienteVérticeAdyacente y NumVértices.  La especificación de cada operador  debe incluir: nombre, parámetros con sus tipos y  las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.

    • La etiqueta es de tipo hilera.

    • Implementar el modelo Grafo Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas utilizando la estructura de datos Matriz de Adyacencia.
    • Implementar el modelo Grafo Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas utilizando la estructura de datos Lista de Adyacencia (LSE-LSE).

    • Definir formalmente el modelo Grafo No Dirigido, con pesos en las aristas, sin lazos y sin aristas paralelas.

    • Especificar de manera lógica, formal y completa los operadores básicos del modelo Grafo No Dirigido con pesos en las aristas, sin lazos y sin aristas paralelas: Crear, Destruir, Vaciar,  Vacío, AgregarVértice (devuelve el vértice creado), EliminarVértice, ModificarEtiqueta, Etiqueta, AgregarArista, EliminarArista, ModificarPeso, Peso, PrimerVértice, SiguienteVértice, PrimerVérticeAdyacente, SiguienteVérticeAdyacente y NumVértices.  La especificación de cada operador  debe incluir: nombre, parámetros con sus tipos y  las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.

    • La etiqueta es de tipo hilera.
      
    • Implementar el modelo Grafo No Dirigido usando al  modelo Grafo Dirigido.
    • Definir formalmente el modelo Diccionario.
    • Especificar de manera lógica, formal y completa los operadores básicos del modelo Diccionario: Crear, Destruir, Vaciar,  Vacío, Agregar, Eliminar, Pertenece y NumElem.  La especificación de cada operador debe incluir: nombre, parámetros con sus tipos y  las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.
    • El elemento es de tipo vértice.
    • Implementar el  modelo Diccionario mediante la estructura de datos Lista No Ordenada por LSE.
    • Definir formalmente el modelo Relaciones 1:1.
    • Especificar de manera lógica, formal y completa los operadores básicos del modelo Relaciones 1:1 Crear, Destruir, Vaciar,  Vacío, AgregarRelación, EliminarRelación, ModificarImagen, ExisteRelación, Imagen, PreImagen, EstáEnDominio, EstáEnCodominio y NumRel.  La especificación de cada operador debe incluir: nombre, parámetros con sus tipos y  las cláusulas Efecto (claro, completo y conciso), Requiere y Modifica.
    • Los elementos tanto del Dominio como del Codominio dependerán del algoritmo para el cual se requiera una Relación 1:1 como modelo auxiliar.
    • Implementar el  modelo Relaciones 1:1  mediante la estructura de datos Lista No Ordenada por LSE.


    • Implementar los siguientes seis algoritmos para un Grafo Dirigido:
    1. Implementar el algoritmo de Dijkstra versión original para el modelo Grafo Dirigido.  Para implementar este algoritmo debe usar el Modelo  Relaciones 1:1.
    2. Implementar el algoritmo de Floyd para el modelo Grafo Dirigido.  Para  implementar este algoritmo debe usar arreglo de dos dimensiones como estructura de dato auxiliar.
    3. Implementar el algoritmo de Recorrido en Profundidad Primero para listar las etiquetas de un Grafo Dirigido.   Para implementar este algoritmo debe usar el Modelo Diccionario.
    4. Implementar un algoritmo para Eliminar un Vértice No Aislado de un Grafo Dirigido.
    5. Implementar un algoritmo para copiar un grafo Dirigido.   Para implementar este algoritmo debe usar el Modelo  Relaciones 1:1.
    6. Implementar un algoritmo para averiguar si dos grafos Dirigidos son iguales.  Para simplificar, puede suponer que no hay etiquetas repetidas.  Para implementar este algoritmo debe usar el Modelo  Relaciones 1:1.
    • Implementar los siguientes dos  algoritmos para un Grafo No Dirigido:
    1. Implementar el algoritmo de Prim (modelo Grafo No Dirigido).  Para implementar este algoritmo debe usar el Modelo  Relaciones 1:1.
    2. Implementar el algoritmo para resolver el problema del Vendedor (problema de optimización para Grafos No Dirigidos) usando Búsqueda Exhaustiva Pura, para un grafo no necesariamente completo. El algoritmo deberá desplegar el número de soluciones factibles del problema y la solución óptima. Para implementar este algoritmo debe usar el Modelo Diccionario.
       
    • Hacer un programa de prueba que permita:

    • Trabajar con el Grafo Dirigido mediante el uso de sus operadores básicos
    • Trabajar con el Grafo No Dirigido mediante el uso de sus operadores básicos
    • Aplicar cada uno de los seis algoritmos del Grafo Dirigido.
    • Aplicar cada uno de los dos  algoritmos del Grafo No Dirigido.
      
    • Calcular y analizar los tiempos reales de ejecución de las estructuras de datos, operadores básicos y algoritmos implementados.


Notas importantes:

-La fecha de entrega es el miércoles 4 de julio.  Tanto los fuentes como la documentación deben subirse a la plataforma antes de las 11:30 p.m.

-La tarea se puede realizar en grupos de 3 personas.  

-Cada grupo es responsable de mantener respaldos de todos los archivos  creados para el cumplimiento de esta tarea.
