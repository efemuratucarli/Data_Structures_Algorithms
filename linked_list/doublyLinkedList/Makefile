OBJS = main.o
PROG = main.exe

# All .o files depend on corresponding .cpp file
%.o: %.cpp DoublyLinkedList.h DoublyNode.h
	g++ -c -o $@ $<

$(PROG): $(OBJS)
	g++ -o $@ $^	