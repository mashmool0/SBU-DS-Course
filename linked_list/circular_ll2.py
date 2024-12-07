class Node:
    def __init__(self, next: "Node" = None, data=None):
        self.next = next
        self.data = data


class CircularLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insertLast(self, value):
        new_node = Node(data=value)
        if self.head == None:
            self.head = new_node
            self.tail = new_node
            new_node.next = new_node  # اشاره به خودش در حالت تک گره‌ای
            return

        new_node.next = self.head
        self.tail.next = new_node
        self.tail = new_node

    def display(self):
        if self.head == None:
            return []

        result = []
        current = self.head
        while True:
            result.append(current.data)
            current = current.next
            if current == self.head:
                break
        return result


def test_circular_linked_list():
    # ایجاد لیست
    cll = CircularLinkedList()

    # تست لیست خالی
    assert cll.display() == []

    # تست تک عنصری
    cll.insertLast(5)
    assert cll.display() == [5]
    assert cll.head.next == cll.head  # تست دایره‌ای بودن

    # تست چند عنصری
    cll.insertLast(10)
    cll.insertLast(15)
    assert cll.display() == [5, 10, 15]

    # تست دایره‌ای بودن
    current = cll.head
    count = 0
    elements = set()

    while count < 10:  # محدودیت برای جلوگیری از حلقه بی‌نهایت
        elements.add(current.data)
        current = current.next
        count += 1
        if current == cll.head:
            break

    assert count == 3  # تعداد عناصر درست است
    assert elements == {5, 10, 15}  # همه عناصر موجودند

    print("All tests passed!")


# اجرای تست‌ها
test_circular_linked_list()
