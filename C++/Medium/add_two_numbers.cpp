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
    ListNode* dummyHead = new ListNode(0); // Виртуальный узел для удобства
    ListNode* current = dummyHead; // Указатель для добавления новых узлов

    ListNode* current1 = l1;
    ListNode* current2 = l2;

    bool flag = 0;
    while (current1 != nullptr || current2 != nullptr || flag != 0) {
        uint8_t sum = flag;

        if (current1 != nullptr) {
            sum += current1->val; // Добавляем значение из первого списка
            current1 = current1->next; // Переходим к следующему узлу
        }

        if (current2 != nullptr) {
            sum += current2->val; // Добавляем значение из второго списка
            current2 = current2->next; // Переходим к следующему узлу
        }

        flag = sum > 9;
        current->next = new ListNode((sum) % 10); // Создаем новый узел с последней цифрой суммы
        current = current->next; // Переходим к новому узлу
    }

    return dummyHead->next; // Возвращаем следующий узел после виртуального
}

// Функция для вывода списка
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