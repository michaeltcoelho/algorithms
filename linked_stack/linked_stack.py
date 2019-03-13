from typing import Optional


class Element:

    def __init__(self, value: int) -> None:
        self.value = value
        self.next = None

    def __str__(self) -> str:
        return f'<Element(value={self.value})>'


class LinkedStack:

    def __init__(self, head: Optional[Element] = None) -> None:
        self.head = head

    def __str__(self) -> str:
        current_element = self.head
        elements = []
        while current_element.next:
            elements.append(str(current_element))
            current_element = current_element.next
        elements.append(str(current_element))
        return str(elements)

    def push(self, new_element: Element) -> None:
        if self.head is None:
            self.head = new_element
        else:
            new_element.next = self.head
            self.head = new_element

    def pop(self) -> Element:
        old_head = self.head
        if self.head is None:
            return None
        if self.head.next is None:
            self.head = None
        else:
            self.head = old_head.next
        return old_head


if __name__ == "__main__":
    first_el = Element(1)
    second_el = Element(2)
    third_el = Element(3)

    linked_stack = LinkedStack(first_el)
    linked_stack.push(second_el)
    linked_stack.push(third_el)

    assert linked_stack.pop() is third_el
    assert linked_stack.pop() is second_el
    assert linked_stack.pop() is first_el
    assert linked_stack.pop() is None
