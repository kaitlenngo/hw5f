F = -std=c++11
P = string_test
O = ListNode.o String.o string_test.o
Z = hw5.zip

def: $P

string_test.o: string_test.cpp String.h ListNode.h
	g++ $F -c string_test.cpp
String.o: String.cpp String.h ListNode.h
	g++ $F -c String.cpp
ListNode.o: ListNode.cpp ListNode.h
	g++ $F -c ListNode.cpp
string_test: $O
	g++ $F $O -o string_test
clean:
	/bin/rm -f $P $O $Z
zip:
	zip $Z *.h *.cpp Makefile

# F = -std=c++11
# P = string_test

# all: $P

# string_test: ListNode.cpp ListNode.h String.h String.cpp string_test.cpp
# 	g++ $F ListNode.cpp String.cpp string_test.cpp -o string_test

# clean:
# 	/bin/rm -f $P