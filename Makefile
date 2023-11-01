EXECUTABLE:= avlTree
CXX:= g++
SRC_FILES:= $(wildcard *.cpp)
HEADER_FILES:= $(wildcard *.h)
OBJ_FILES:= $(patsubst %.cpp,%.o,$(SRC_FILES))
LDFLAGS:= -g -ggdb -static-libstdc++ -std=gnu++17 -Wall -Wextra -pedantic
CPPFLAGS:= -g -ggdb -static-libstdc++ -std=gnu++17 -Wall -Wextra -pedantic
${EXECUTABLE}: $(OBJ_FILES)
	@${CXX} $(LDFLAGS) -o $@ $^
%o: %.cpp $(HEADER_FILES)
	@${CXX} $(CPPFLAGS) -c -$@ $<