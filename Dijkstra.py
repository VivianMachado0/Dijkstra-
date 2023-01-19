
def dijkstra(grafo, origen):
  # Establecemos todos los nodos con infinito
  distancias = {nodo: float('inf') for nodo in grafo}
  # Establecemos la distancia del nodo origen como 0
  distancias[origen] = 0
  nodo_previo = {}

  nodos_no_visitados = grafo.keys()

  while nodos_no_visitados: 
      # Seleccionamos el nodo con la menor distancia
      nodo_actual = min(nodos_no_visitados, key=lambda nodo: distancias[nodo])
      # Marcamos el nodo como visitado
      nodos_no_visitados.remove(nodo_actual)
      # Calculamos las distancias para los nodos vecinos del nodo actual
      for vecino, distancia_vecino in grafo[nodo_actual].items():
          alternativa = distancias[nodo_actual] + distancia_vecino
          # Si hay una mejor distancia, actualizamos
          if alternativa < distancias[vecino]:
              distancias[vecino] = alternativa
              nodo_previo[vecino] = nodo_actual
  
  return distancias, nodo_previo
