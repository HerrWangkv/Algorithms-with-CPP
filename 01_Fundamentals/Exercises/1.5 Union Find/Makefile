1_5: 1_5.cpp Percolation.o QuickFindUF.o QuickUnionUF.o WeightedQuickUnionUF.o CompressedQuickUnionUF.o
	g++ -o 1_5 1_5.cpp Percolation.o QuickFindUF.o QuickUnionUF.o WeightedQuickUnionUF.o CompressedQuickUnionUF.o

QuickFindUF.o: QuickFindUF.cpp
	g++ -c -o QuickFindUF.o QuickFindUF.cpp

QuickUnionUF.o: QuickUnionUF.cpp
	g++ -c -o QuickUnionUF.o QuickUnionUF.cpp

WeightedQuickUnionUF.o: WeightedQuickUnionUF.cpp
	g++ -c -o WeightedQuickUnionUF.o WeightedQuickUnionUF.cpp

CompressedQuickUnionUF.o: CompressedQuickUnionUF.cpp
	g++ -c -o CompressedQuickUnionUF.o CompressedQuickUnionUF.cpp

Percolation.o: Percolation.cpp
	g++ -c -o Percolation.o Percolation.cpp

clean:
	rm -f *.o
