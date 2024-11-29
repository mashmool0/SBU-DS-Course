# Python Program for Insertion at a Particular Position
class Node:
    def __init__(self, data):
        # Initialize a node with data and next pointer
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        # Initialize an empty linked list with head pointer pointing to None
        self.head = None

    def insertAtPosition(self, position, data):
        # Insert a new node with data at the specified position in the linked list
        new_node = Node(data)
        if position < 0:
            # Check if the position is valid
            print("Invalid position")
            return
        if position == 0:
            # If the position is 0, insert the new node at the beginning of the linked list
            new_node.next = self.head
            self.head = new_node
            return
        current = self.head
        count = 0
        while count < position - 1 and current:
            # Traverse the linked list until the node before the specified position
            current = current.next
            count += 1
        if not current:
            # If the position is out of range, print an error message
            print("Position out of range")
            return
        # Insert the new node at the specified position
        new_node.next = current.next
        current.next = new_node

    def display(self):
        # Display the elements of the linked list
        current = self.head
        while current:
            # Traverse through each node and print its data
            print(current.data, end=" -> ")
            current = current.next
        # Print None to indicate the end of the linked list
        print("None")


# Driver Code
linked_list = LinkedList()
linked_list.insert_at_position(0, 1)
# Insertion at the end
linked_list.insert_at_position(1, 3)
# Insertion at position 1
linked_list.insert_at_position(0, 2)

print("Linked List after insertion at position:")
linked_list.display()
