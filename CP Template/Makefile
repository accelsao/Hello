CXX = g++

CXXFLAGS = -Wall -std=c++17

source = A

all: $(source)
$(source):
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY : clean

clean:
	$(RM) $(source)