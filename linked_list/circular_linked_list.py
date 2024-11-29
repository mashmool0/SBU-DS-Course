class Node:

    def __init__(self, next: "Node" = None, data=None):
        self.next = next
        self.data = data


class CircularLinkedList:

    def __init__(self):
        self.head = None

    def insertLast(self, data):
        new_node = Node(data=data)

        if self.head == None:
            new_node.next = new_node
            self.head = new_node
            return

        current = self.head
        while (current.next != self.head):
            current = current.next

        new_node.next = self.head
        current.next = new_node

    def insertAtBegin(self, data):
        new_node = Node(data=data)
        current = self.head

        if current == None:
            new_node.next = new_node
            self.head = new_node
            return

        current = self.head
        new_node.next = self.head
        while (current.next != self.head):
            current = current.next

        current.next = new_node
        self.head = new_node

    def insertAtPosition(self, pos, data):
        new_node = Node(data=data)
        current = self.head
        count = 0

        if pos < 0:
            print("Invalid postitino ")
            return

        elif pos == 0:
            self.insertAtBegin(data)
            return
        else:
            while True:
                if count == pos - 1:
                    last = current
                    after = current.next
                    break
                elif current == None:
                    print("Out of the range")
                    return

                count += 1
                current = current.next

            new_node.next = after
            last.next = new_node

    def printAllElements(self):
        current = self.head
        if current == None:
            print("List is Empty")
            return

        while True:
            print(current.data, end=" -> ")
            current = current.next
            if current == self.head:
                break

        print()


lst = CircularLinkedList()
lst.insertLast(1)
lst.insertLast(2)
lst.insertLast(3)
lst.insertLast(4)
lst.insertLast(5)
lst.insertLast(6)
lst.insertAtBegin(0)
lst.insertAtPosition(2, 9)
lst.insertAtPosition(0, 7)
lst.printAllElements()
