class Node:
    def __init__(self, data):
        self.data = data
        self.previous = None
        self.next = None


class DoubleList:
    def __init__(self):
        self.head_val = None

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head_val
        self.head_val = new_node
        new_node.previous = None

    def append(self, data):
        new_node = Node(data)
        if self.head_val is None:
            self.head_val = new_node
        else:
            last = self.head_val
            while last.next:
                last = last.next
            last.next = new_node
            new_node.previous = last

    def list_print(self):
        print_val = self.head_val
        idx = 1
        while print_val is not None:
            print("\nThe element %d in the Linked List is: %d" %
                  (idx, print_val.data))
            idx += 1
            print_val = print_val.next
        
    def list_print_reverse(self):
        print_val = self.head_val
        while print_val.next:
            print_val = print_val.next
        while print_val:
            print(print_val.data)
            print_val = print_val.previous

    def insert(self, data, index):
        new_node = Node(data)
        if self.head_val is None:
            print(
                "\nThe Linked List is empty so the inserted element will be the the first element")
            self.head_val = new_node
        else:
            idx = 1
            node = self.head_val
            while idx < index:
                node = node.next
                idx += 1
            node.next = new_node
            new_node.previous = node

    def remove(self, removeKey):
        headVal = self.head_val
        if headVal is not None and headVal.data == removeKey:
                self.head_val = headVal.next
                headVal.next.previous = self.head_val
                headVal = None
                return
        while headVal is not None:
            if headVal.data == removeKey:
                break
            prev = headVal
            headVal = headVal.next
        if headVal == None:
            return
        prev.next = headVal.next
        if headVal.next is not None:
            headVal.next.previous = prev
        headVal = None
    
    def reverse(self):
        if self.head_val is not None:
            node = self.head_val
            while node:
                temp = node.next
                node.next = node.previous
                node.previous = temp
                if node.previous is None:
                    break
                node = node.previous
            self.head_val = node

linkedList = DoubleList()
linkedList.head_val = Node(1)
e2 = Node(2)
e3 = Node(3)

# Link first Node to second Node
linkedList.head_val.next = e2
e2.previous = linkedList.head_val

# Link second Node to third Node
e2.next = e3
e3.previous = e2

linkedList.append(10)

linkedList.prepend(0)

linkedList.list_print

linkedList.reverse()

linkedList.list_print()
