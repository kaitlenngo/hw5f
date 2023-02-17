# include <iostream>
using namespace std;
#include "String.h"

void String::error(const char * msg) const
{
    cout << "ERROR: " << msg << endl;
}

bool String::in_bounds(int i) const
{
    return i >= 0 && i < ListNode::list_length(head);
}

String::String(List L){
    head = L;
}

String::String(const char * s){
    head = ListNode::list_from_string(s);
}

String::String(const String & s){
    head = ListNode::list_copy(s.head);
}

String::String(String && s){
    if (head != s.head){
        head = s.head;
        s.head = nullptr;
    }
}

String & String::operator = (String && s){
    if (head != s.head){
        ListNode::list_delete(head);
        head = s.head;
        s.head = nullptr;
    }
    return * this;
}

String & String::operator = (const String & s) {
    if (head != s.head){
        ListNode::list_delete(head);
        head = ListNode::list_copy(s.head);
    }
    return * this;
}

char & String::operator [] (int index){
    if (!in_bounds(index)){
        return head->data;
    }
    return ListNode::list_nth(head, index)->data;
}

int String::size() const{
    return ListNode::list_length(head);
}

String String::reverse() const {
    return String(ListNode::list_reverse(head));
}

int String::indexOf(const char c) const{
    List current = head;
    while (current->data != c && current != nullptr) {
        current = current->next;
    }
    if (current == nullptr) return -1;
    return ListNode::list_difference(head, current);
}

int String::indexOf(const String s) const {
    List tmp = ListNode::list_str(head, s.head);
    return ListNode::list_difference(head, tmp);
}

bool String::operator == (const String s){
    if (ListNode::list_cmp(head, s.head) == 0){
        return true;
    }
    else{
        return false;
    }
}

bool String::operator != (const String s){
    if (ListNode::list_cmp(head, s.head) != 0){
        return true;
    }
    else{
        return false;
    }
}

bool String::operator > (const String s) {
    if (ListNode::list_cmp(head, s.head) > 0) {
        return true;
    }
    return false;
}

bool String::operator < (const String s){
    if (ListNode::list_cmp(head, s.head) < 0){
        return true;
    }
    else{
        return false;
    }
}

bool String::operator <= (const String s) {
    if (ListNode::list_cmp(head, s.head) <= 0) {
        return true;
    }
    return false;
}

bool String::operator >= (const String s) {
    if (ListNode::list_cmp(head, s.head) >= 0) {
        return true;
    }
    return false;
}

String String::operator + (const String s) const{
    return String(ListNode::list_append(head, s.head));
}

String & String::operator += (const String s) {
    List tmp = ListNode::list_append(head, s.head);
    ListNode::list_delete(head);
    head = tmp;
    return *this;
}

void String::print(ostream & out) const{
    for (List node = head; node != nullptr; node = node->next)
        out << node->data;
}

void String::read(istream & in) {
    char var;
    in >> var;
    List tmp = new ListNode(var, nullptr);
    List current = tmp;
    while (in >> var) {
        current->next = new ListNode(var, nullptr);
        current = current->next;
    }
    ListNode::list_delete(head);
    head = tmp;
}

String::~String(){
    ListNode::list_delete(head);
}

ostream & operator << (ostream & out, String s){
    s.print(out);
    return out;
}
istream & operator >> (istream & in, String & s){
    s.read(in);
    return in;
}
