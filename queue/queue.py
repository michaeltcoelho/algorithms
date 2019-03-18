from typing import Optional, List


class Element:

    def __init__(self, value: int) -> None:
        self.value = value

    def __str__(self) -> str:
        return f'<Element(value={self.value})>'


class Queue:

    def __init__(self, head: Optional[Element] = None) -> None:
        self.storage: List[Element] = [head]

    def enqueue(self, new_element: Element) -> None:
        self.storage.append(new_element)

    def peek(self):
        return self.storage[0]

    def dequeue(self):
        return self.storage.pop(0)


if __name__ == "__main__":
    first_el = Element(1)
    second_el = Element(2)
    third_el = Element(3)

    queue = Queue(first_el)
    queue.enqueue(second_el)
    queue.enqueue(third_el)

    assert queue.peek() is first_el

    assert queue.dequeue() is first_el
    assert queue.dequeue() is second_el

    assert queue.peek() is third_el
