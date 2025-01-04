class FixedQueue:
    def __init__(self, size):
        self.queue = [None] * size
        self.size = size
        self.count = 0

    def enqueue(self, data):
        if self.count == self.size:
            print("Queue is full")
            return
        self.queue[self.count] = data
        self.count += 1

    def dequeue(self):
        if self.count == 0:
            print("Queue is empty")
            return None
        data = self.queue[0]
        for i in range(1, self.count):
            self.queue[i - 1] = self.queue[i]
        self.queue[self.count - 1] = None
        self.count -= 1
        return data

    def display(self):
        print("Fixed Queue Contents:", [x for x in self.queue if x is not None])

# Demo Fixed Queue
fq = FixedQueue(3)
fq.enqueue("Job 1")
fq.enqueue("Job 2")
fq.enqueue("Job 3")
fq.display()
fq.dequeue()
fq.display()