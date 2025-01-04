class AVLTree:
    class Node:
        def __init__(self, key, height=1):
            self.key = key
            self.height = height
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    def insert(self, root, key):
        # Implementation of AVL Tree insertion
        pass

    def display(self, root):
        # Inorder traversal for displaying the AVL tree
        pass


class Stack:
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
        print("Stack Contents:", self.stack)

# Demo AVL Tree and Stack
stack = Stack()
stack.push("Document 1")
stack.push("Document 2")
stack.push("Document 3")
stack.push("Document 4")
stack.display()
stack.pop()
stack.display()