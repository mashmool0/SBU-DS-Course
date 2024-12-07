class Queue:

    def __init__(self, max_size) -> None:
        self.max_size = max_size
        self.array = [None] * max_size
        self.rare = -1
        self.front = -1

    def is_empty(self):
        return self.front == -1 and self.rare == -1

    def is_full(self):
        return (self.rare + 1) % self.max_size == self.front

    def enqueue(self, data):

        if self.is_full():
            print("List is Full")
            return

        elif self.is_empty():
            self.rare = 0
            self.front = 0
        else:
            self.rare = (self.rare + 1) % self.max_size

        self.array[self.rare] = data

    def dequeue(self):
        # [0,1,3,4,5]

        if self.is_empty():
            print("List is Empty")
            return

        element = self.array[self.front]
        print("Dequed : ", element)

        if self.front == self.rare:
            self.front = -1
            self.rare = -1

        else:
            self.front = (self.front + 1) % self.max_size

        return element

    def peek(self):
        if self.is_empty():
            print("Queue is empty!")
            return None
        return self.array[self.front]

    def display(self):
        if self.is_empty():
            print("List is Empty")
            return

        print("Queue Content")
        i = self.front

        while True:
            print(self.array[i], end=' ')

            if i == self.rare:
                break
            i = (i+1) % self.max_size
        print()


def test_queue():
    # Create a queue of size 5
    q = Queue(5)

    # Test enqueue
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)
    q.enqueue(5)
    q.display()  # Queue is full now

    # Try to enqueue when full
    q.enqueue(6)  # Should print "Queue is full!"

    # Test dequeue
    q.dequeue()
    q.dequeue()
    q.display()

    # Test enqueue after dequeue
    q.enqueue(6)
    q.enqueue(7)
    q.display()

    # Test peek
    print(f"Front element: {q.peek()}")


if __name__ == "__main__":
    test_queue()
