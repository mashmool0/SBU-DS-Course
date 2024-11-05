from linked_list import Node ,LinkedList



# create a new linked list
llist = LinkedList()

# add nodes to the linked list
llist.InsertAtEnd('a')
llist.InsertAtEnd('b')
llist.InsertAtBegin('c')
llist.InsertAtEnd('d')
llist.InsertAtIndex('g', 2)

# print the linked list
print("Node Data")
llist.printLL()

# remove a nodes from the linked list
print("\nRemove First Node")
llist.remove_first_node()
print("Remove Last Node")
llist.remove_last_node()
print("Remove Node at Index 1")
llist.remove_at_index(1)

# print the linked list again
print("\nLinked list after removing a node:")
llist.printLL()

print("\nUpdate node Value")
llist.UpdateNode('z', 0)
llist.printLL()

print("\nSize of linked list :", end=" ")
print(llist.sizeOfLL())# create a new linked list
llist = LinkedList()

# add nodes to the linked list
llist.InsertAtEnd('a')
llist.InsertAtEnd('b')
llist.InsertAtBegin('c')
llist.InsertAtEnd('d')
llist.InsertAtIndex('g', 2)

# print the linked list
print("Node Data")
llist.printLL()

# remove a nodes from the linked list
print("\nRemove First Node")
llist.remove_first_node()
print("Remove Last Node")
llist.remove_last_node()
print("Remove Node at Index 1")
llist.remove_at_index(1)

# print the linked list again
print("\nLinked list after removing a node:")
llist.printLL()

print("\nUpdate node Value")
llist.UpdateNode('z', 0)
llist.printLL()

print("\nSize of linked list :", end=" ")
print(llist.sizeOfLL())