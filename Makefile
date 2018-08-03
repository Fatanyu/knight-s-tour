CXX = g++
RM = rm -f
CPPFLAGS = -std=c++11 -pedantic -Wall -Wextra
OUTPUT_FILE = run-me
FILES += main.cpp
FILES += board.cpp
OBJS = *.o

all:
	$(CXX) $(CPPFLAGS) $(FILES) -o $(OUTPUT_FILE)

clean:
	$(RM) $(OBJS) $(OUTPUT_FILE)


