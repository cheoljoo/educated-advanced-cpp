casting1:
	g++ -std=c++11 casting1.cpp -o a
casting2:
	g++ -std=c++17 casting2.cpp -o a
casting3:
	g++ -std=c++17 casting3.cpp -o a
casting4:
	g++ -std=c++17 casting4.cpp -o a
1addr1:
	g++ -std=c++17 1_addressof1.cpp -o a
	./a
1addr2:
	g++ -std=c++17 1_addressof2.cpp -o a
	./a
1addr3:
	g++ -std=c++17 1_addressof3.cpp -o a
	./a
2const1:
	g++ -std=c++17 2_const1.cpp -o a
	./a
3ref1:
	g++ -std=c++17 3_reference1.cpp -o a
	./a
3ref2:
	g++ -std=c++17 3_reference2.cpp -o a
	./a
3ref3:
	g++ -std=c++17 3_reference3.cpp -o a
	./a
3ref4:
	g++ -std=c++17 3_reference4.cpp -o a
	./a
3ref5:
	g++ -std=c++17 3_reference5.cpp -o a
	./a
3ref6:
	g++ -std=c++11 3_reference6.cpp -o a
	./a
3ref7:
	g++ -std=c++11 3_reference7.cpp -o a
	./a
3ref8:
	g++ -std=c++11 3_reference8.cpp -o a
	./a
3ref9:
	g++ -std=c++11 3_reference9.cpp -o a
	./a
3ref10:
	g++ -std=c++11 3_reference10.cpp -o a
	./a
4thin1:
	g++ -std=c++11 4_thinTemplate1.cpp -o a
	./a
4thin2:
	g++ -std=c++11 4_thinTemplate2.cpp -o a
	./a
4thin3:
	g++ -std=c++11 4_thinTemplate3.cpp -o a
	./a
5this1:
	g++ -std=c++11 5_this1.cpp -o a
	./a
6CTRP1:
	g++ -std=c++11 6_CRTP1.cpp -o a
	./a
7safe1:
	g++ -std=c++11 7_safe1.cpp -o a
	./a
7_safe2:
	g++ -std=c++11 7_safe2.cpp -o a
	./a
7_safe3:
	g++ -std=c++11 7_safe3.cpp -o a
	./a
all: 7_safe3
