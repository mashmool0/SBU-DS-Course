class Node:

    def __init__(self, node: "Node" = None, data: int = None) -> None:
        self.next = node
        self.data = data


class LinkedList:
    size = 0

    def __init__(self, head: Node = None):
        self.head = head

    def add(self, node):
        if self.head == None:
            self.head = node
            self.size += 1
            return

        current = self.head

        while (current.next != None):
            current = current.next

        current.next = node
        self.size += 1

    def calcSize(self):
        current = self.head
        if current == None:
            print("List is Empty")
            return

        count = 0
        while current != None:
            current = current.next
            count += 1

        self.size = count
        return count

    def printFromHere(self, current: Node):
        while (current != None):
            print(current.data)
            current = current.next

    def last_n(self, n):
        if self.head == None:
            print("List is Empty")
            return
        elif n == 0:
            return

        current = self.head
        count = self.size
        while True:
            if count == n:
                break

            elif current.next == None:
                print("n is bigger than size of linked list ")
                return

            count -= 1
            current = current.next

        return current


def test_linked_list():
    print("Test Case 1: Add nodes to the list.")
    lst1 = LinkedList()
    lst1.add(Node(data=1))
    lst1.add(Node(data=2))
    lst1.add(Node(data=3))
    lst1.calcSize()
    node = lst1.last_n(2)
    lst1.printFromHere(node)  # Should print 2 and 3
    print("---")

    print("Test Case 2: Request last n of a non-empty list.")
    lst2 = LinkedList()
    lst2.add(Node(data=10))
    lst2.add(Node(data=20))
    lst2.add(Node(data=30))
    lst2.calcSize()
    node = lst2.last_n(1)
    lst2.printFromHere(node)  # Should print 30
    print("---")

    print("Test Case 3: Request last n where n > size of list.")
    lst3 = LinkedList()
    lst3.add(Node(data=5))
    lst3.add(Node(data=15))
    lst3.calcSize()
    # Should print "n is bigger than size of linked list"
    node = lst3.last_n(5)
    if node is not None:
        lst3.printFromHere(node)
    print("---")

    print("Test Case 4: Request last n when the list is empty.")
    lst4 = LinkedList()
    node = lst4.last_n(2)  # Should print "List is Empty"
    print("---")

    print("Test Case 5: Request last n with n = 0.")
    lst5 = LinkedList()
    lst5.add(Node(data=7))
    lst5.calcSize()
    node = lst5.last_n(0)  # Should return nothing
    if node is not None:
        lst5.printFromHere(node)
    print("---")

    print("Test Case 6: Request last n from a single-node list.")
    lst6 = LinkedList()
    lst6.add(Node(data=100))
    lst6.calcSize()
    node = lst6.last_n(1)  # Should print 100
    lst6.printFromHere(node)
    print("---")

    print("Test Case 7: Request last n where n equals size of the list.")
    lst7 = LinkedList()
    lst7.add(Node(data=1))
    lst7.add(Node(data=2))
    lst7.add(Node(data=3))
    lst7.calcSize()
    node = lst7.last_n(3)  # Should print 1, 2, and 3
    lst7.printFromHere(node)
    print("---")


# Run the tests
test_linked_list()
