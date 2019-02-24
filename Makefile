CXX = g++-8
RM = rm -f
CPPFLAGS = -std=c++17 -pedantic -Wall -Wextra
OUTPUT_FILE = run-me
SOURCEDIR := sources
SOURCE_FILES := $(shell find $(SOURCEDIR) -name '*.cpp')
FILES += main.cpp
#FILES += board.cpp
FILES += $(SOURCE_FILES)
OBJS = *.o

all:
	$(CXX) $(CPPFLAGS) $(FILES) -o $(OUTPUT_FILE)

clean:
	$(RM) $(OBJS) $(OUTPUT_FILE)


