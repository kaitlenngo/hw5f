#include <iostream>
using namespace std;
#include "String.h"

void test_list_from_string_and_print()
{
    cout << "TESTS: list_from_string_and_print" << endl;
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");
    ListNode::print(cout, L1);
    ListNode::print(cout, L2);
    cout << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    //add more tests
}

void test_list_append()
{
    cout << "TESTS: list_append" << endl;
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");
    List C = ListNode::list_append(L1, L2);
    ListNode::print(cout, C);
    cout << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(C);
    //add more tests
}

void test_list_reverse()
{
    cout << "TESTS: list_reverse" << endl;
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");
    List C = ListNode::list_append(L1, L2);
    List R = ListNode::list_append(L1, L2);
    ListNode::print(cout, R);
    cout << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(C);
    ListNode::list_delete(R);
    //add more tests
}

int main()
{
    test_list_from_string_and_print();
    test_list_append();
    test_list_reverse();

    // test_constructors_and_print();
    // test_assignment();
    // test_relationals();
    // test_reverse();
    // test_concatenate();
    // test_indexOf();
    //these dont exist here, yet??

    ListNode::report_allocations();
    return 0;

    //there are more tests
}