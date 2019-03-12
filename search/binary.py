
def dynamic(l, n):
    start, end = 0, len(l) - 1
    while start <= end:
        middle = (start + end) // 2
        if l[middle] > n:
            end = middle - 1
        elif l[middle] < n:
            start = middle + 1
        else:
            return middle
    return -1


def recursive(l, n, start=0, end=0):
    if start > end:
        return -1

    end = end if end > 0 else len(l) - 1
    middle = (start + end) // 2

    if l[middle] > n:
        end = middle - 1
        return recursive(l, n, start=start, end=end)
    elif l[middle] < n:
        start = middle + 1
        return recursive(l, n, start=start, end=end)
    else:
        return middle


if __name__ == "__main__":
    l = [1, 2, 3, 4, 5, 6, 7, 8 , 9, 10]
    assert dynamic(l, 7) == 6
    assert dynamic(l, 50) == -1
    assert recursive([1, 2, 3, 4], 3) == 2
    assert recursive(l, 50) == -1
