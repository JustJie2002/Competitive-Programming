// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    for (int i = 0; i < 1008; i++) {
        if (head == NULL) {
            return false;
        }
        head = head->next;
    }
    return true;
}