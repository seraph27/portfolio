%.o: %.cpp
	g++ -g -O0 -std=c++20 -Wall -Wextra -pedantic -Wshadow -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -fstack-protector-all -D_GLIBCXX_DEBUG -o $*.o $*.cpp
.PRECIOUS: %.o

%.out: %.o
	./$*.o

%.dbg: %.o
	gdb $*.o
