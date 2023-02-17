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

void test_indexOf()
{
    String ex = String("1K-NNwWqkx448T.zDjTO.?cx1QEwv-?oF91kpPAA#wo'!qwKz!iCgkZ78nwnquJ3ou'L9Fd?1s-8IrCayTCE-lw4G0jXeTKA'Q#!fh'7z8ZaruaP'Km83Q4tA?iMRT'OBbVGiSxQSpY9JYROA3OnDDG-BXHcAMY1NEz4gXM7eu0VkJtKE7X!Cv.3cC'KgWD2s-QGSmx4OqJYZ2so1hnoKijVShx6-9Sn4sTOMjCkz-ai5sEYHSec8o5SDmIyflTbLwPqFbA##Bf91JSBt4LlkA3NUEd8PW9klJAYS9VXC8QvJAW3pzgHZ.fMyqEf'FxqgYgZZ9Gt9oODXDye.ELUGYy#!.bezzuGpIxgC-zvrfY?QgkLTWxjEVgDPhHgO9U-Cbb#eIrwWiCwwN!!BEj5jxB6EaflcZgE9iAfYZJE7#1wR8vcxM!O9INGJSRLJXhK'PYWyrsyvdU#e!gBUghNWUdxE28gShYPWGDnYWLd7pidwoMiCUWjG7G-UHbwOZdDyPYgDtrCQzGeOcna4brv8YqUpzi-quGO9o2EHe6pLEujPPsDQJYIzgvOFDS4XiKYxxm#JlmePOwonO0-pIDPX6vuu'iboT0LiePRp1V5HblUX-X'MtUtj!VDf4NtPF#XJLyZFdW#n7Z.-G!PZTa91VE6JbjqGn'iYv7nHNkUM9OPHOwrzwskkWa1YrcwE!EvvDI2i0O31mCt87Ssn.CFYLrG2t-zsHUV-uPdnn6?IBzIsb0Ndvd2?uA8VDrf-d1?GIbTWaZwJj49sXGwkRqidQaYeA4hLXfbpo2doMH5VEYftxBD?ZTkI1aUt#15T6?bm1mJx2ykqhpJMZeKI52aY3UcZN7LL5UYQ6rf0Ppa4NRAE3d#05fJ07LSFCniz!6i'pnY'LY1qIuUvxYgu3Xn3s5A2kIlrHBoWP#Ts3NIv");
    String x = String("xgC-zvrfY?QgkLTWxjEVgDPhHgO9U-Cbb#eIrwWiCwwN!!BEj5jxB6EaflcZgE9iAfYZJE7#1wR8vcxM!O9INGJSRLJXhK'PYWyrsyvdU#e!gBUghNWUdxE28gShYPWGDnYWLd7pidwoMiCUWjG7G-UHbwOZdDyPYgDtrCQzGeOcna4brv8YqUpzi-quGO9o2EHe6pLEujPPsDQJYIzgvOFDS4XiKYxxm#JlmePOwonO0-pIDPX6vuu'iboT0LiePRp1V5HblUX-X'MtUtj!VDf4NtPF#XJLyZFdW#n7Z.-G!PZTa91VE6JbjqGn'iYv7nHNkUM9OPHOwrzwskkWa1YrcwE!EvvDI2i0O31mCt87Ssn.CFYLrG2t-zsHUV-uPdnn6?IBzIsb0Ndvd2?uA8VDrf-d1?GIbTWaZwJj49sXGwkRqidQaYeA4hLXfbpo2doMH5VEYftxBD?ZTkI1aUt#15T6?bm1mJx2ykqhpJMZeKI52aY3UcZN7LL5UYQ6rf0Ppa4NRAE3d#05fJ07LSFCniz!6i'pnY'LY1qIuUvxYgu3Xn3s5A2kIlrHBoWP#Ts3NIv");
    cout << "HERE" << endl;
    cout << ex.indexOf(x) << endl;
}

int main()
{
    test_list_from_string_and_print();
    test_list_append();
    test_list_reverse();
    test_indexOf();

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