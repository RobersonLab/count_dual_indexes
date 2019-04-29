CXX := g++
CXXFLAGS = 

#-----------------------------
# edit below at your own risk
#-----------------------------
PROG := count_dual_indexes
BITS := 64
OPT_LEVEL := 3

CXXFLAGS += -std=c++11 -m$(BITS) -O$(OPT_LEVEL)

# requires g++ capable of c++11
all: $(PROG)

$(PROG):
	$(CXX) $(CXXFLAGS) -o $(PROG) *.cpp
