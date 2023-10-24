
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        queue = []
        queue.append(root)
        ans = []
        while queue:
            maximum = -9999999999999
            tempQueue = []
            while queue:
                node = queue.pop(0)
                if maximum < node.val:
                    maximum = node.val
                if node.left: tempQueue.append(node.left)
                if node.right: tempQueue.append(node.right)
            
            queue += tempQueue
            ans.append(maximum)
        return ans
    
root = TreeNode()
root.val = 1
root.left = 3 
a = Solution()
print(a.largestValues(root))