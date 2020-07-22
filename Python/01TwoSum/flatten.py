"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        i = 0
        arr = []
        cur = head
        while(cur != None):

            print(cur.val)

            if cur.child != None:
                print("IN1")
                if cur.next != None:
                    arr.append(cur.next)
                    i = i + 1

                cur.next = cur.child
                cur.child.prev = cur
                cur.child = None
                
            elif cur.next == None:
                print("IN2 {}".format(i))
                i = i - 1
                if i >= 0 :
                    tmp = arr[i]
                    cur.next = tmp
                    tmp.prev = cur;
            
            print("IN3")
            cur = cur.next
        
        cur = head
        while(cur != None):
            print(cur.val)
            cur = cur.next

        return head

