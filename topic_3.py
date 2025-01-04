class CircularQueue:
    def __init__(self, size):
        self.size = size
        self.queue = [None] * size
        self.front = self.rear = -1

    def enqueue(self, data):
        if (self.rear + 1) % self.size == self.front:
            print("Queue is full")
            return
        elif self.front == -1:
            self.front = 0
        self.rear = (self.rear + 1) % self.size
        self.queue[self.rear] = data

    def dequeue(self):
        if self.front == -1:
            print("Queue is empty")
            return None
        data = self.queue[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % self.size
        return data

    def display(self):
        if self.front == -1:
            print("Queue is empty")
            return
        index = self.front
        result = []
        while True:
            result.append(self.queue[index])
            if index == self.rear:
                break
            index = (index + 1) % self.size
        print("Circular Queue Contents:", result)

# Demo Circular Queue
cq = CircularQueue(5)
cq.enqueue("Request 1")
cq.enqueue("Request 2")
cq.enqueue("Request 3")
cq.enqueue("Request 4")
cq.display()
cq.dequeue()
cq.display()