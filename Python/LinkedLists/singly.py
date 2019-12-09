class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def display(self):
        temp = self.head
        while temp!= None:
            print(temp.data)
            temp = temp.next
    
    def insertNode(self , value):
        headNode = self.head
        nextNode = Node(value)
        nextNode.next = headNode
        self.head = nextNode
    
    def isValueFound(self, key):
        headNode = self.head
        flag = 0
        
        while headNode!= None:
            if headNode.data == key:
                flag = 1
                break
            headNode = headNode.next
        
        if flag == 1:
            return True
        else:
            return False
    
def main():
    list = LinkedList()
    print("1.INSERT \n2.DISPLAY \n3.Search \n4.EXIT")
    while(1):
        choice = int(input("Enter Choice:"))
        if choice == 1:
            list.insertNode(int(input("Enter Value:")))
        elif choice == 2:
            list.display()
        elif choice == 3:
            found = list.isValueFound(int(input("Enter Key Value:")))
            print(found)
        else:
            break

if __name__=='__main__': 
    main()