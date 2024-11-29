class Node:

    def __init__(self, prev, data, next) -> None:
        self.prev = prev
        self.data = data
        self.next = next


class DoublyLinkedList:

    def __init__(self, head) -> None:
        self.head = None

    def insertAtLast(self, data):
        new_node = Node(data=data)
        current = self.head
        if current == None:
            current = new_node
            return

        while (current.next != None):
            current = current.next

        current.next = new_node
        new_node.prev = current

    def
