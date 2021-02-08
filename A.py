import random
class tree:
    def __init__(self, val=None,left=None,right=None):
        self.value = val
        self.left = left
        self.right = right
    def compareTo(self, TreeNode):
        return self.value < TreeNode.value
    def find(self, val):
        if self.value == val:
            return True
        elif val < self.value:
            if self.left == None:
                return False
            return self.left.find(val)
        elif val > self.value:
            if self.right == None:
                return False
            return self.right.find(val)
    def add(self, val):
        if val == self.value:
            return
        if val < self.value and self.left != None:
            self.left.add(val)
            return
        if val < self.value:
            self.left = tree(val)
            return
        if val > self.value and self.right != None:
            self.right.add(val)
            return
        if val > self.value:
            self.right = tree(val)
            return
    def printValues(self):
        lst = [self.value]
        if self.left != None:
            lst.extend(self.left.printValues())
        if self.right != None:
            lst.extend(self.right.printValues())
        return lst

Set = tree(8888888)
lst = [i for i in range(1, 2000)]
random.shuffle(lst)
for i in lst:
    Set.add(i)
print(Set.find(10))
        