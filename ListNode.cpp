#include <iostream>
#include "ListNode.h"
using namespace std;

int ListNode::total_allocations = 0;
int ListNode::net_allocations = 0;
int ListNode::total_bytes = 0;

//put other ListNode definitions here??
//oh so
//all the other declarations from ListNode.h will be defined here
//dunno how constructor destructor and report_allocations will be uuhhhh
//idk basically theyre defined in the .h file, not here

List ListNode::list_from_string(const char *s){
    if (s[0] == '\0') return nullptr;

    List start_Node = new ListNode(s[0], nullptr);
    List current = start_Node;
    int i;
    for (i=1; s[i] != '\0'; i++){
        current->next = new ListNode(s[i], nullptr);
        current = current->next;
    }
    return start_Node;
}

List ListNode::list_copy(List L){
    if (L == nullptr) return nullptr;

    List start_Node = new ListNode(L->data, nullptr);
    List current = L->next;
    List node = start_Node;
    while (current != nullptr)
    {
        node->next = new ListNode(current->data, nullptr);
        node = node->next;
        current = current->next;
    }
    return start_Node;
}

List ListNode::list_reverse(List L){
    if (L == nullptr) return nullptr;

    List reversed_list = nullptr;
    List current = L;
    while (current != nullptr)
    {
        reversed_list = new ListNode(current->data, reversed_list);
        current = current->next;
    }
    return reversed_list;
}

List ListNode::list_append(List L1, List L2){
    if (L1 == nullptr && L2 == nullptr) return nullptr;

    List L3 = nullptr;
    List current = nullptr;

    for (List node = L1; node != nullptr; node = node->next){
        if (L3 == nullptr){
            L3 = new ListNode(node->data, nullptr);
            current = L3;
        }
        else{
            current->next = new ListNode(node->data, nullptr);
            current = current->next;
        }
    }

    for (List node = L2; node != nullptr; node = node->next){
        if (L3 == nullptr){
            L3 = new ListNode(node->data, nullptr);
            current = L3;
        }
        else{
            current->next = new ListNode(node->data, nullptr);
            current = current->next;
        }
    }
    return L3;
}

List ListNode::list_str(List haystack, List needle){
    List current_haystack = haystack;
    List current_needle = needle;
    while (current_haystack != nullptr){
        if (current_haystack->data == current_needle->data){
            List tmp_haystack = current_haystack;
            List tmp_needle = current_needle;
            while (tmp_haystack != nullptr && tmp_needle != nullptr && current_haystack->data == current_needle->data){
                tmp_haystack = tmp_haystack->next;
                tmp_needle = tmp_needle->next;
            }
            if (tmp_needle == nullptr){
                return current_haystack;
            }
        }
        current_haystack = current_haystack->next;
    }
    return nullptr;
}

List ListNode::list_chr(List str, int c){
    List current = str;
    while (current != nullptr){
        if (current->data == c) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

List ListNode::list_nth(List str, int n){
    if (str == nullptr) return nullptr;

    int count = 0;
    List current = str;
    while (current != nullptr && count < n){
        current = current->next;
        count++;
    }

    if (count == n && current != nullptr){
        return current;
    }
    else{
        return nullptr;
    }
}

void ListNode::list_delete(List L){
    List current = L;
    List tmp;
    while (current != nullptr){
        tmp = current->next;
        current->~ListNode();
        current = tmp;
    }
}

void ListNode::print(ostream & out, List L){
    List current = L;
    while (current != nullptr) {
        out << current->data;
        current = current->next;
    }
    cout << endl;
}

int ListNode::list_difference(List L1, List L2){
    int count = 0;
    List current = L1;
    while (current != nullptr && current != L2){
        count++;
        current = current->next;
    }
    if (current == nullptr){
        return -1;
    }
    else{
        return count;
    }
}

List ListNode::list_last(List L){
    if (L == nullptr){
        return nullptr;
    }
    List current = L;
    while (current->next != nullptr){
        current = current->next;
    }
    return current;
}

int ListNode::list_cmp(List L1, List L2){
    List current1 = L1;
    List current2 = L2;

    while (current1 != nullptr && current2 != nullptr){
        if (current1->data < current2->data){
            return -1;
        }
        else if (current1->data > current2->data){
            return 1;
        }

        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 == nullptr && current2 == nullptr){
        return 0;
    }
    else if (current1 == nullptr){
        return -1;
    }
    else{
        return 1;
    }
}

int ListNode::list_ncmp(List L1, List L2, int n){
    List current1 = L1;
    List current2 = L2;
    int i = 0;

    while (i < n && current1 != nullptr && current2 != nullptr){
        if (current1->data < current2->data){
            return -1;
        }
        else if (current1->data > current2->data){
            return 1;
        }

        current1 = current1->next;
        current2 = current2->next;
        i++;
    }
    if (i==n){
        return 0;
    }
    else if (current1 == nullptr && current2 == nullptr){
        return 0;
    }
    else if (current1 == nullptr){
        return -1;
    }
    else{
        return 1;
    }
}

int ListNode::list_length(List L){
    if (L == nullptr) return 0;

    int count = 0;
    List current = L;
    while (current != nullptr){
        current = current->next;
        count++;
    }
    return count;
}
