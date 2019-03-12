import random

def sort(A):
    size = len(A)
    if size <= 1:
        return A
    middle = size // 2
    start = sort(A[:middle])
    end = sort(A[middle:])
    return merge(start, end)


def merge(start, end):
    arr = []
    i, j = 0, 0
    while i < len(start) and j < len(end):
        if start[i] < end[j]:
            arr.append(start[i])
            i += 1
        else:
            arr.append(end[j])
            j += 1
    if start[i:]: arr.extend(start[i:])
    if end[j:]: arr.extend(end[j:])
    return arr

if __name__ == "__main__":
    l = list(range(4))
    random.shuffle(l)
    print(sort(l))
