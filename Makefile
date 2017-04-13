CC = g++
CCFLAG = -Wall -g
EXEC = exec.out
OUT = output.txt

all: Animal.o Wolf.o Rabbit.o Land.o main.o main.C Animal.C Animal.h Item.h Wolf.C Wolf.h Rabbit.C Rabbit.h Land.C Land.h
	$(CC) $(CCFLAG) -o $(EXEC) main.o Animal.o Wolf.o Rabbit.o Land.o

main.o: main.C Item.h
	$(CC) $(CCFLAG) -c main.C Item.h

Animal.o: Animal.C Animal.h
	$(CC) $(CCFLAG) -c Animal.C

#Item.o: Item.h
#	$(CC) $(CCFLAG) -c Item.h

Wolf.o: Wolf.C Wolf.h
	$(CC) $(CCFLAG) -c Wolf.C

Rabbit.o: Rabbit.C Rabbit.h
	$(CC) $(CCFLAG) -c Rabbit.C

Land.o: Land.C Land.h
	$(CC) $(CCFLAG) -c Land.C



clean:
	rm -rf *.o $(EXEC) *.gch

exec:
	./$(EXEC)

out:
	./$(EXEC) > $(OUT)
