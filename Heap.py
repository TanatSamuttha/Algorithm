class Node():
    def __init__(self, value: int): 
        self.value = value
        self.full = False
        self.leftNode = None
        self.rightNode = None

class Heap():
    def __init__(self):
        self.top = None
        self.empty = True

    def __newNode(self, value: int) -> Node:
        return Node(value)

    def push(self, value: int):
        if self.empty:
            self.top = self.__newNode(value)
            self.empty = False
        else:
            self.__insert(self.top, value)
            
    def __insert(self, node: Node, value: int):
        if node.leftNode == None:
            node.leftNode = self.__newNode(value)
            if node.leftNode.value > node.value:
                handle = node.value
                node.value = node.leftNode.value
                node.leftNode.value = handle
            return
        elif node.rightNode == None:
            node.rightNode = self.__newNode(value)
            node.full = True
            if node.rightNode.value > node.value:
                handle = node.value
                node.value = node.rightNode.value
                node.rightNode.value = handle
            return

        if node.leftNode.full == False or node.rightNode.full == True:
            node.rightNode.full = False
            self.__insert(node.leftNode, value)
            if node.leftNode.value > node.value:
                handle = node.value
                node.value = node.leftNode.value
                node.leftNode.value = handle
        elif node.leftNode.full == True:
            self.__insert(node.rightNode, value)
            if node.rightNode.value > node.value:
                handle = node.value
                node.value = node.rightNode.value
                node.rightNode.value = handle

        if node.leftNode.full == True and node.rightNode.full == True:
            node.full = True
        else:
            node.full = False

    def stucture(self):
        return self.__traversal(self.top)

    def __traversal(self, node: Node) -> list:
        resultList = [node.value]
        if node.leftNode != None:
            resultList.append(self.__traversal(node.leftNode))
        if node.rightNode != None:
            resultList.append(self.__traversal(node.rightNode))
        return resultList

heap = Heap()

numList = [3, 1, 4, 2, 5, 6]
for i in numList:
    heap.push(i)
    print(heap.stucture())