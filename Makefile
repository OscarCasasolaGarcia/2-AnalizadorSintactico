CXX?=clang++
EXE=compiler
CXXDEBUG= -g -Wall
CXXSTD=-std=c++14
CXXFLAGS= -Wno-deprecated-register -O0 $(CXXDEBUG) $(CXXSTD)

CPPOBJ= main Parser

FILES= $(addsuffix .cpp, $(CPPOBJ))
OBJS = $(addsuffix .o, $(CPPOBJ))

CLEANLIST = $(addsuffix .o, $(OBJS))


.PHONY: all
all: wc

wc: $(FILES)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS)

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)
