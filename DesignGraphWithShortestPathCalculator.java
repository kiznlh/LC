import java.util.Arrays;
import java.util.PriorityQueue;

public class DesignGraphWithShortestPathCalculator {
    int n;
    int[][] edges;
    public DesignGraphWithShortestPathCalculator(int n, int[][] edges) {
        this.n = n;
        this.edges = new int[n][n];
        for (int i = 0 ; i < edges.length; i++){
            this.edges[edges[i][0]][edges[i][1]] = edges[i][2];
        }
    }

    public void addEdge(int[] edge) {
        edges[edge[0]][edge[1]] = edge[2];
    }
   
    public int shortestPath(int startNode, int endNode) {
        PriorityQueue<NodeDistance> priorityQueue = new PriorityQueue<>();
        int[] distances = new int[n];
        Arrays.fill(distances, Integer.MAX_VALUE);

        priorityQueue.add(new NodeDistance(startNode, 0));
        distances[startNode] = 0;

        while (!priorityQueue.isEmpty()) {
            NodeDistance currentNode = priorityQueue.poll();

            if (currentNode.node == endNode) {
                return currentNode.distance;
            }

            for (int neighbor = 0; neighbor < n; neighbor++) {
                int weight = edges[currentNode.node][neighbor];
                if (weight > 0) {
                    int newDistance = currentNode.distance + weight;

                    if (newDistance < distances[neighbor]) {
                        distances[neighbor] = newDistance;
                        priorityQueue.add(new NodeDistance(neighbor, newDistance));
                    }
                }
            }
        }

        // If the end node is not reachable from the start node
        return -1;
    }

    static class NodeDistance implements Comparable<NodeDistance> {
        int node;
        int distance;

        NodeDistance(int node, int distance) {
            this.node = node;
            this.distance = distance;
        }

        @Override
        public int compareTo(NodeDistance other) {
            return Integer.compare(this.distance, other.distance);
        }
    }
    void print(){
        for (int i = 0; i < edges.length; i++) {
            // Iterate through each column in the current row
            for (int j = 0; j < edges[i].length; j++) {
                // Print the element at the current row and column
                System.out.print(edges[i][j] + " ");
            }
            // Move to the next line after printing all columns in the current row
            System.out.println();
        }
    }
   
    public static void main(String[] args) {
        int n = 4;
        int[][] edges = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
        DesignGraphWithShortestPathCalculator graph = new DesignGraphWithShortestPathCalculator(n, edges);
        graph.print();
        System.out.println(graph.shortestPath(3, 2));

    }
}
