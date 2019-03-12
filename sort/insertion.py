import copy
import random
import unittest

import matplotlib.pyplot as plt
import matplotlib.animation as animation


def sort(l):
    timeline = []
    timeline.append(copy.copy(l))
    for j in range(1, len(l)):
        key = l[j]
        e = j - 1
        while e >= 0 and l[e] > key:
            l[e + 1] = l[e]
            e -= 1
            timeline.append(copy.copy(l))
        l[e + 1] = key
        timeline.append(copy.copy(l))
    return l, timeline


class TestCase(unittest.TestCase):

    def test_should_sort_list(self):
        l = [2, 3, 5, 6, 1, 4]
        result, timeline = sort(l)
        self.assertEqual(result, [1, 2, 3, 4, 5, 6])


if __name__ == "__main__":
    l = list(range(50))

    random.shuffle(l)

    sorted_list, timeline = sort(l)

    fig = plt.figure()

    barcollection = plt.bar(sorted_list, sorted_list, color='b')

    def animate(i, timeline):
        for react, y in zip(barcollection, timeline[i]):
            react.set_height(y)

    line_ani = animation.FuncAnimation(
        fig, animate,
        frames=len(timeline),
        fargs=(timeline,),
        interval=50,
        blit=False,
        repeat=False)
    FFwriter = animation.FFMpegWriter(fps=30, extra_args=['-vcodec', 'libx264'])
    line_ani.save('insertion_sort.mp4', writer=FFwriter)
