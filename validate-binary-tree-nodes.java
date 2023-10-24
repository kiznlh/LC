class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] inDegree = new int[n];
        for (int i =0; i < n; i++){
            if(leftChild[i] != -1 && inDegree[leftChild[i]]++ == 1) return false;
            if (rightChild[i] != -1 && inDegree[rightChild[i]]++ == 1) return false;
        }
        int root = -1;
        for (int i = 0; i < n; i++){
            if (inDegree[i] == 0){
                if (root != -1) return false;
                root = i;
            }
        }
        return false; //this has to be deleted
    }
    public int countNodes(int root, int[] leftChild, int[] rightChild){
        if (root == -1){
            return 0;
        }
        return 1 + countNodes(leftChild[root], leftChild, rightChild) + countNodes(rightChild[root], leftChild, rightChild);
    }
}