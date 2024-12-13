
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class Stack:

    # Initializing a stack.
    # Use a dummy node, which is
    # easier for handling edge cases.
    def __init__(self):
        self.head = Node("head")
        self.size = 0

    # String representation of the stack
    def __str__(self):
        cur = self.head.next
        out = ""
        while cur:
            out += str(cur.value) + "->"
            cur = cur.next
        return out[:-2]

    # Get the current size of the stack
    def getSize(self):
        return self.size

    # Check if the stack is empty
    def isEmpty(self):
        return self.size == 0

    # Get the top item of the stack
    def peek(self):

        # Sanitary check to see if we
        # are peeking an empty stack.
        if self.isEmpty():
            return None

        return self.head.next.value

    # Push a value into the stack.
    def push(self, value):
        node = Node(value)
        node.next = self.head.next  # Make the new node point to the current head
        self.head.next = node  # !!! # Update the head to be the new node
        self.size += 1

    # Remove a value from the stack and return.

    def pop(self):
        if self.isEmpty():
            raise Exception("Popping from an empty stack")
        remove = self.head.next
        self.head.next = remove.next  # !!! changed
        self.size -= 1
        return remove.value

    def printStack(self):
        current = self.head.next
        while (current != None):
            print(current.value, end=' ')
            current = current.next
        print()


test = [-5, 2, -1, 0, 3]

main_stack = Stack()
for item in test:
    main_stack.push(item)


stack1 = Stack()
stack2 = Stack()


while main_stack.getSize() != 0:
    print("main stack :", end=" ")
    main_stack.printStack()
    print("First Stack :", end=" ")
    stack1.printStack()
    print("Second Stack :", end=" ")
    stack2.printStack()
    num = main_stack.peek()

    if stack1.getSize() == 0:
        stack1.push(num)
        main_stack.pop()
        continue

    elif num <= stack1.peek():
        stack1.push(num)
        main_stack.pop()

    else:
        stack2.push(stack1.pop())
        count = 1
        while num >= stack1.peek():
            print("stack1 item : ", stack2.peek())
            stack2.push(stack1.pop())
            count += 1

        stack1.push(num)

        for i in range(count):
            stack1.push(stack2.pop())

        main_stack.pop()

print("Stack Ans : ", end=" ")
while stack1.getSize() != 0:
    print(stack1.pop(), end=" ")

print()
