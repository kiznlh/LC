

class Solution:
    def isBipartite(self, graph: list[list[int]]) -> bool:
        n = len(graph)
        colors = [0] * n
        
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        for i in range(n):
            if colors[i] == 0:
                if not self.dfs(graph,colors, i, 1):
                    return False
        return True
    
    def dfs(self, graph,colors,node, color) -> bool:
        if colors[node] != 0:
            return colors[node] == color
        
        colors[node] = color
        
        for adj in graph[node]:
            if not self.dfs(graph, colors, adj,-color):
                return False
            
        return True
        
