#include <string>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0); // ����������� ���� ��� ��������
    ListNode* current = dummyHead; // ��������� ��� ���������� ����� �����

    ListNode* current1 = l1;
    ListNode* current2 = l2;

    bool flag = 0;
    while (current1 != nullptr || current2 != nullptr || flag != 0) {
        uint8_t sum = flag;

        if (current1 != nullptr) {
            sum += current1->val; // ��������� �������� �� ������� ������
            current1 = current1->next; // ��������� � ���������� ����
        }

        if (current2 != nullptr) {
            sum += current2->val; // ��������� �������� �� ������� ������
            current2 = current2->next; // ��������� � ���������� ����
        }

        flag = sum > 9;
        current->next = new ListNode((sum) % 10); // ������� ����� ���� � ��������� ������ �����
        current = current->next; // ��������� � ������ ����
    }

    return dummyHead->next; // ���������� ��������� ���� ����� ������������
}

// ������� ��� ������ ������
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    ListNode* one = new ListNode(5, new ListNode(8, new ListNode(7)));
    ListNode* two = new ListNode(7, new ListNode(6, new ListNode(9)));

    auto res = addTwoNumbers(one, two);
    printList(res);
}