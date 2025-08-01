class LRUCache {
    private int capacity;
    private Node head;
    private Node tail;
    private HashMap<Integer, Node> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        tail = new Node(0, 0);
        head = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        Node node = map.get(key);
        if (node == null) {
            return -1;
        }
        moveToHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)){
            Node existNode = map.get(key);
            existNode.value = value;
            moveToHead(existNode);
            return;
        }
        Node node = new Node(key, value);
        if (map.size() >= capacity){
            deleteTail();
        }
        addToHead(node);
    }

    public void addToHead(Node node){
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
        map.put(node.key, node);
    }

    public void moveToHead(Node node){
        deleteNode(node);
        addToHead(node);
    }

    public void deleteNode(Node node){
        Node prevNode = node.prev;
        Node nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
        map.remove(node.key);
    }

    public void deleteTail(){
        Node last = tail.prev;
        tail.prev = last.prev;
        last.prev.next = tail;
        map.remove(last.key);
    }

    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        Node(int key, int value){
            this.key = key;
            this.value = value;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */