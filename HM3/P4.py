class Node:

    def __init__(self, prev=None, data=None, next=None):
        self.prev = prev
        self.data = data
        self.next = next


class SpeceficLinkedList:

    def __init__(self):
        self.head = None
        self.tail = None
        self.right_to_left = True

    def insertAtBegin(self, data):
        new_node = Node(data=data)
        current = self.head
        if current == None:
            self.head = new_node
            self.tail = new_node
            return

        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def insertAtLast(self, data):
        new_node = Node(data=data)
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    def reverse(self):
        self.right_to_left = not self.right_to_left

    def display(self):

        if self.right_to_left:
            if self.head == None:
                print("List is Empty")
                return

            current = self.head

            while (True):
                print(current.data, end=' -> ')
                current = current.next

                if current == None:
                    print(None)
                    break
        else:
            if self.tail == None:
                print("List is Empty")
                return

            current = self.tail

            while True:
                print(current.data, end=' -> ')
                current = current.prev
                if current == None:
                    print(None)
                    break

# out put example
# 12 -> 0 -> 3 -> 1 -> 10 -> None
# 10 -> 1 -> 3 -> 0 -> 12 -> None


lst = SpeceficLinkedList()
lst.insertAtBegin(1)
lst.insertAtBegin(3)
lst.insertAtBegin(0)
lst.insertAtLast(10)
lst.insertAtBegin(12)
lst.display()
lst.reverse()
lst.display()
