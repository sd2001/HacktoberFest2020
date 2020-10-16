public class LinkedList 
{ 
    Node head; 
    
    class Node 
    { 
        int data; 
        Node next; 
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
  
    void printMiddle() 
    { 
        Node slow = head; 
        Node fast = head; 
       
            while (fast!= null && fast.next!= null) 
            { 
                fast=fast.next.next; 
                slow=slow.next; 
            } 
            System.out.println("The middle element is"+slow.data); 
        } 
    
    public void push(int new_data) 
    { 
        Node new_node = new Node(new_data); 
        new_node.next = head; 
        head = new_node; 
    } 
     public static void main(String[]args) 
    { 
        LinkedList list = new LinkedList(); 
        
        list.push(5);
        list.push(4);
        list.push(3);
        list.push(2);
        list.push(1);
        list.printMiddle(); 
        } 
    } 
