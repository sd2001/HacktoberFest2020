class Node
{
        
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
}


public class LinkedList
{

   
 Node head;
    public void removeDuplicates()
    {
        Node temp=head;
        Node curr=temp;
        while(temp!=null &&temp.next!=null)
        
        {
            curr=temp;
            temp=temp.next;
            while(temp!=null && curr.data==temp.data){
                temp=temp.next;
            }
            curr.next=temp;
        }
    }
     public void push(int new_data)
    {
       
        Node new_node = new Node(new_data);
  
         new_node.next = head;
  
         head = new_node;
    }
    public void printList()
     {
          System.out.println("the list after removing duplicate  ");
         Node temp = head;
         while (temp != null)
         {
            System.out.print(temp.data);
            temp = temp.next;
         }  
         
     }
    public static void main(String[]args)
    {
        LinkedList llist = new LinkedList();
        llist.push(20);
        llist.push(13);
        llist.push(13);
        llist.push(11);
        llist.push(11);
        llist.push(11);
         
        llist.removeDuplicates();
         llist.printList();     
       
    }
} 
 