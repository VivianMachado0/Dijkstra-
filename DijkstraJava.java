//Código em Java
// Inicializar o grafo
Graph graph = new Graph();

// Define o ponto de partida e o ponto de destino
Node startNode = graph.getNode(start);
Node endNode = graph.getNode(end);

// Inicializar aheap binária
PriorityQueue<Node> heap = new PriorityQueue<Node>();

// Inicializar a distância do nó de partida para cada nó no grafo
for(Node node : graph.getNodes()) {
	node.setDistance(Integer.MAX_VALUE);
}

// Defina a distância do nó de partida como zero
startNode.setDistance(0);

// Adicione o nó de partida à heap binária
heap.add(startNode);

// Enquanto houver nós no heap
while(!heap.isEmpty()) {
	
	// Extraia o nó com menor distância
	Node current = heap.poll();
	
	// Para cada vizinho do nó atual
	for(Edge edge : current.getEdges()) {
		Node neighbour = edge.getNeighbour();
		
		// Calcular a distância do vizinho
		int distance = current.getDistance() + edge.getWeight();
		
		// Atualiza a distância do vizinho se a nova distância for menor
		if(distance < neighbour.getDistance()) {
			neighbour.setDistance(distance);
			neighbour.setPrevious(current);
			heap.add(neighbour);
		}
	}
}

// Crie a lista de caminhos
List<Node> path = new LinkedList<Node>();

// Adicione os nós na lista, começando do nó de destino
Node current = endNode;
while(current != null) {
	path.add(current);
	current = current.getPrevious();
}

// Inverter a lista para obter o caminho correto
Collections.reverse(path);

// Retorna o caminho
return path;
