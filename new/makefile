ar.out:client.o implimentation.o
	gcc -o ar.out client.o implimentation.o
client.o:client.c structure.h
	gcc -c client.c
implimentation.o:implimentation.c structure.h
	gcc -c implimentation.c
clean:
	find . -type f | xargs touch
	rm -rf $(OBJS)
