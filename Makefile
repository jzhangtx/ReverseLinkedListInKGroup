ReverseListInKGroup: ReverseListInKGroup.o
	g++ -g -o ReverseListInKGroup.exe ReverseListInKGroup.o -pthread    

ReverseListInKGroup.o: ReverseListInKGroup/ReverseListInKGroup.cpp
	g++ -g  -c -pthread ReverseListInKGroup/ReverseListInKGroup.cpp
