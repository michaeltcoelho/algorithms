from typing import Optional


class Element:

    def __init__(self, value: int) -> None:
        self.value = value
        self.next: Optional[Element] = None

    def __str__(self) -> str:
        return f'<Element(value={self.value})>'


class LinkedList:

    def __init__(self) -> None:
        self.head = None

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
            current_element = self.head
            while current_element.next:
                current_element = current_element.next
            current_element.next = new_element

    def get_element_at(self, position: int) -> Element:
        if position == 0:
            return self.head
        current_position, current_element = 0, self.head
        while current_element.next and current_position < position:
            current_element = current_element.next
            current_position += 1
        return current_element

    def insert(self, new_element: Element, position: int) -> None:
        if position == 0:
            new_element.next = self.head
            self.head = new_element
        else:
            current_element = self.head
            current_position = 0
            previous_element = None
            while current_element.next and current_position < position:
                previous_element = current_element
                current_element = current_element.next
                current_position += 1
            new_element.next = current_element
            if previous_element:
                previous_element.next = new_element

    def delete_by_value(self, value: int) -> None:
        current_element = self.head
        previous_element = None
        while current_element.next and value != current_element.value:
            previous_element = current_element
            current_element = current_element.next
        if value == current_element.value:
            if current_element is self.head:
                self.head = self.head.next
            else:
                previous_element.next = current_element.next


if __name__ == "__main__":
    linked_list = LinkedList()
    first_element = Element(1)
    linked_list.push(first_element)
    second_element = Element(2)
    linked_list.push(second_element)
    third_element = Element(3)
    linked_list.push(third_element)

    assert linked_list.head is first_element
    assert linked_list.get_element_at(0) is first_element
    assert linked_list.get_element_at(1) is second_element
    assert linked_list.get_element_at(2) is third_element

    fourth_element = Element(4)
    linked_list.insert(fourth_element, 1)
    assert linked_list.get_element_at(1) is fourth_element

    fifth_element = Element(5)
    linked_list.insert(fifth_element, 2)
    assert linked_list.get_element_at(2) is fifth_element

    linked_list.delete_by_value(5)
    assert linked_list.get_element_at(2) is second_element
