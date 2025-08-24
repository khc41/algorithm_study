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
        Node newHead = getCopyNodeList(head);
        Node copyCur = newHead;
        Node cur = head;
        while (cur != null) {
            copyCur.random = getRandomNode(head, newHead, cur.random);
            cur = cur.next;
            copyCur = copyCur.next;
        }
        return newHead;
    }

    public Node getCopyNodeList(Node head) {
        Node newHead = new Node(head.val);
        if (head.next != null) {
            newHead.next = getCopyNodeList(head.next);
        }
        return newHead;
    }

    public Node getRandomNode(Node head, Node newHead, Node random) {
        if (random == null) {
            return null;
        }
        Node cur = head;
        Node newCur = newHead;
        while (cur != null) {
            if (cur == random) {
                return newCur;
            }
            cur = cur.next;
            newCur = newCur.next;
        }
        return null;
    }
}