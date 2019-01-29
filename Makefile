CXX=g++
CPPFLAGS=-Iinclude
CXXFLAGS=-Wall -O3
LDFLAGS=
LDLIBS=
SRC=main.cpp consoleinput.cpp fileoutput.cpp disease.cpp person.cpp population.cpp simulation.cpp
OBJS=consoleinput.o fileoutput.o disease.o person.o population.o simulation.o main.o
BIN=disease

#$(BIN): $(OBJS)
#	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $(BIN) $(LDLIBS)

%.o: source/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

#consoleinput.o: consoleinput.cpp
#	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $(BIN) $(LDLIBS)
