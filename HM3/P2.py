class Node:

    def __init__(self, next: 'Node' = None, data: int = 0) -> None:
        self.next = next
        self.data = data


class LinkedList:
    def __init__(self, head: Node = None) -> None:
        self.head = head

    def add(self, node):
        if not self.head:
            self.head = node
            return

        new_node = node
        current = self.head

        while (current.next != None):
            current = current.next

        current.next = new_node

    def printList(self):
        current = self.head
        current = current.next

        while (current != None):
            print(current.data)
            current = current.next


def mergeTwoSortedList(lst1: LinkedList, lst2: LinkedList):
    lst = LinkedList()
    lst.head = Node()
    current_ans = lst.head

    current1 = lst1.head
    current2 = lst2.head
    size1 = 0
    size2 = 0

    # lets calculate size of them
    while (current1 != None):
        current1 = current1.next
        size1 += 1

    while (current2 != None):
        current2 = current2.next
        size2 += 1

    # reset all current to head

    current1 = lst1.head
    current2 = lst2.head
    count = 0
    # 0 2 4
    # 1 2 3
    if size1 > size2:
        while (current2 != None and current1 != None):

            if current1.data >= current2.data:
                current_ans.next = Node(data=current2.data)
                current2 = current2.next
            else:
                current_ans.next = Node(data=current1.data)
                current1 = current1.next

            count += 1
            current_ans = current_ans.next

        if current1 != None:
            while (current1 != None):
                current_ans = Node(data=current1.data)
                current1 = current1.next
        elif current2 != None:
            while (current2 != None):
                current_ans.next = Node(data=current2.data)
                current2 = current2.next

    else:
        while (current1 != None and current2 != None):

            if current1.data >= current2.data:
                current_ans.next = Node(data=current2.data)
                current2 = current2.next

            else:
                current_ans.next = Node(data=current1.data)
                current1 = current1.next

            count += 1
            current_ans = current_ans.next

        if current1 != None:
            while (current1 != None):
                current_ans = Node(data=current1.data)
                current1 = current1.next
        elif current2 != None:
            while (current2 != None):
                current_ans.next = Node(data=current2.data)
                current2 = current2.next
    lst.printList()


def test_merge_two_sorted_lists():
    # Test Case 1: Both lists are empty
    lst1 = LinkedList()
    lst2 = LinkedList()
    print("Test Case 1: Both lists are empty")
    mergeTwoSortedList(lst1, lst2)

    # Test Case 2: One list is empty, and the other contains sorted elements
    lst1 = LinkedList()
    lst2 = LinkedList()
    lst2.add(Node(data=1))
    lst2.add(Node(data=2))
    lst2.add(Node(data=3))
    print("Test Case 2: One list is empty")
    mergeTwoSortedList(lst1, lst2)

    # Test Case 3: Both lists have sorted elements with no overlap
    lst1 = LinkedList()
    lst1.add(Node(data=0))
    lst1.add(Node(data=1))
    lst1.add(Node(data=2))

    lst2 = LinkedList()
    lst2.add(Node(data=3))
    lst2.add(Node(data=4))
    lst2.add(Node(data=5))

    print("Test Case 3: Both lists have sorted elements with no overlap")
    mergeTwoSortedList(lst1, lst2)

    # Test Case 4: Both lists have sorted elements with some common elements
    lst1 = LinkedList()
    lst1.add(Node(data=0))
    lst1.add(Node(data=2))
    lst1.add(Node(data=4))

    lst2 = LinkedList()
    lst2.add(Node(data=1))
    lst2.add(Node(data=2))
    lst2.add(Node(data=3))

    print("Test Case 4: Both lists have sorted elements with some common elements")
    mergeTwoSortedList(lst1, lst2)

    # Test Case 5: One list has more elements than the other
    lst1 = LinkedList()
    lst1.add(Node(data=1))
    lst1.add(Node(data=3))

    lst2 = LinkedList()
    lst2.add(Node(data=0))
    lst2.add(Node(data=2))
    lst2.add(Node(data=4))
    lst2.add(Node(data=5))

    print("Test Case 5: One list has more elements than the other")
    mergeTwoSortedList(lst1, lst2)

    # Test Case 6: Both lists have identical sorted elements
    lst1 = LinkedList()
    lst1.add(Node(data=1))
    lst1.add(Node(data=2))
    lst1.add(Node(data=3))

    lst2 = LinkedList()
    lst2.add(Node(data=1))
    lst2.add(Node(data=2))
    lst2.add(Node(data=3))

    print("Test Case 6: Both lists have identical sorted elements")
    mergeTwoSortedList(lst1, lst2)


test_merge_two_sorted_lists()
