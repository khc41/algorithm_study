/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        Map<Node, Node> oldToNew = new HashMap<>();
        Node newHead = new Node(head.val);
        oldToNew.put(head, newHead);

        Node cur = head;
        while (cur != null) {
            oldToNew.put(cur, new Node(cur.val));
            cur = cur.next;
        }

        cur = head;
        while (cur != null) {
            oldToNew.get(cur).next = oldToNew.get(cur.next);
            oldToNew.get(cur).random = oldToNew.get(cur.random);
            cur = cur.next;
        }

        return oldToNew.get(head);
    }
}