class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class SingleList:
    def __init__(self):
        self.head_val = None

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head_val
        self.head_val = new_node
    
    def append(self, data):
        new_node = Node(data)
        if self.head_val is None:
            self.head_val = new_node
        else:
            last = self.head_val
            while last.next:
                last = last.next
            last.next = new_node

    def list_print(self):
        print_val = self.head_val
        idx = 1
        while print_val is not None:
            print("The element %d in the Linked List is: %d" % (idx, print_val.data))
            idx += 1
            print_val = print_val.next

    def insert(self, data, index):
        new_node = Node(data)
        if self.head_val is None:
            print("The Linked List is empty so the inserted element will be the the first element")
            self.head_val = new_node
        else:
            idx = 1
            node = self.head_val
            while idx < index:
                node = node.next
                idx += 1
            node.next = new_node

    def remove(self, removeKey):
        if self.head_val is not None:
            if self.head_val.data == removeKey:
                headVal = self.head_val
                self.head_val = self.head_val.next
                headVal = None
            else:
                node = self.head_val
                while node:
                    if node.data == removeKey:
                        break
                    prevElement = node
                    removeElement = node.next
                    node = node.next

            
            prevElement.next = removeElement.next
            removeElement = None

linkedList = SingleList()
linkedList.head_val = Node(1)
e2 = Node(2)
e3 = Node(3)

# Link first Node to second Node
linkedList.head_val.next = e2

# Link second Node to third Node
e2.next = e3

linkedList.append(10)

linkedList.prepend(0)

linkedList.remove(3)

linkedList.list_print()