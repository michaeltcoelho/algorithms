

def shift(i, array):
    n = array[i]
    array[i] = array[i + 1]
    array[i + 1] = n


def sort(array):
    is_sorted = False
    while not is_sorted:
        is_sorted = True
        for i in range(len(array) - 1):
            if array[i] > array[i + 1]:
                shift(i, array)
                is_sorted = False


if __name__ == "__main__":
    array = [5, 4, 20, 6, 21, 2, 0]
    sort(array)
    assert array == [0, 2, 4, 5, 6, 20, 21]
