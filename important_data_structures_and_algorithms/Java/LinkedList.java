
public class LinkedList(){
    public static class Node<int>{
        private int data;
        private Node<int> next;

        public Node(int data, Node<int> next){
            this.data = data;
            this.next = next;
        }
    }

    public LinkedList(){
        head = null;
    }

    //adding a node to the head of the linked list
    public void addFirst(int item){
        head = new Node<int> (item, head);
    }

    //traveresing the linked list
    

    //adding a node to the last part of the LinkedList
    public void addLast(int item){
        //check if head node is null
        if(head == null) addFirst(item);
        else{
            Node <int> tmp = head;
            //traverse till it reaches end
            while(tmp.next!=null) temp = temp.next;

            tmp.next = new Node<int> (item, null);
        }

    }

    //insert after
    public void insertAfter(int key,int item){
        Node <int> tmp = head;
        while(tmp!=null && !tmp.data.equals(key)) tmp = tmp.next;

        if(tmp!=null){
            tmp.next = new Node<int> (item, tmp.next);
        }
    }

    //insert before

    //deletion of a node
    public void remove(int key){
        if(head == null) throw new RuntimeException("cannot delete");
        if(head.data.equals(key)){
            head =  head.next;
            return;
        }

        Node<int> cur = head;
        Node<int> prev = null;

        while(cur!=null && !cur.data.equals(key)){
            prev = cur;
            cur = cur.next;
        }

        if(cur==null) throw new RuntimeException("cannot delete");

        //delete cur node
        prev.next = cur.next;
    }

    //size()
    public int size(){
        if(head==null) return 0;
        int counter=0;
        while(head!=null){
            counter++;
            head = head.next;
        }

        return counter;
    }

    //isEmpty()
    public boolean isEmpty(){
        return head==null;
    }

    //value_at(index)
    public int value_at(int index){
        int ite = 0;
        if(head == null) throw new RuntimeException("error");
        if(index > size()) throw new RuntimeException("Error: index is larger then size of linked list");

        Node <int> tmp = head;
        while(tmp!=null && ite!=index){
            tmp = tmp.next;
            ite++;
        }

        return tmp.data;
    }

    //clear the whole linked list
    public void clear(){
        head  = null;
    }

    
}