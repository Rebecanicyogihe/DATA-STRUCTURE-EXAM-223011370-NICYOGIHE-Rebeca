class DynamicStack:
    def __init__(self):
        self.stack = []

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        if not self.stack:
            print("Stack is empty")
            return None
        return self.stack.pop()

    def display(self):
        print("Dynamic Stack Contents:", self.stack)

# Demo Dynamic Stack
ds = DynamicStack()
ds.push("Operation A")
ds.push("Operation B")
ds.push("Operation C")
ds.push("Operation D")
ds.display()
ds.pop()
ds.display()