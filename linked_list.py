class Node : 
    def __init__(self,data) -> None:
        self.data = data 
        self.next = None 


class LinkedList : 
    def __init__(self) -> None:
        self.head = None 
    
    def InsertionAtBegin(self,data):
        new_node = Node(data)  
        if self.head == None : 
            self.head = new_node  
            return 
        else : 
            new_node.next = self.head 
            self.head = new_node  
        

    def InsertAtIndex(self,data,index) : 
        if index == 0 : 
            self.InsertionAtBegin(self,data) 
        
        count = 0 
        current = self.head  
        while (current is not None and count+1 != index) : 
            current = current.next          
            count += 1 
            
        
        if current is not None : 
            new_node = Node(data) 
            new_node.next = current.next 
            current.next = new_node
        else : 
            print("Index not present")


    def InsertAtEnd(self,data) : 
        new_node = Node(data)
        
        if self.head is None : 
            self.head = new_node 
            return 
        
        
        current_node = self.head 
        
        while (current_node.next ) : 
            current_node = current_node.next 
            
        current_node.next = new_node 
        
        
    def UpdateNode(self,data,index) : 
        new_node = Node(data) 
        count = 0 
        if count == index  : 
            current_node.data = data 
        current_node = self.head 
        while (current_node != None and count != index)  : 
            current_node = current_node.next 
            count += 1 
        
        if current_node != None  : 
            current_node.data = new_node.data 
        
        else : 
            print("Index not present")
        
    
    
         
        
                    
    