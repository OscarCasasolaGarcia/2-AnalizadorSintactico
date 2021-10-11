CXX=clang++
EXE=compiler
CXXDEBUG= -g -Wall
CXXSTD=-std=c++17
CXXFLAGS= -Wno-deprecated-register -O0 $(CXXDEBUG) $(CXXSTD)

CPPOBJ= main ParserGrammar Grammar Production Symbol Body Nullable First Follow Compiler 

FILES= $(addsuffix .cpp, $(CPPOBJ))
OBJS = $(addsuffix .o, $(CPPOBJ))
SOBJ = lexer

CLEANLIST = $(addsuffix .o, $(OBJS))

.PHONY: all
all: wc

wc: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) lexer.o

lexer: lexer.ll
	flex $<
	$(CXX) $(CXXFLAGS) -c LexerGrammar.cpp -o lexer.o

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)