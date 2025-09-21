CXX = g++
CXXFLAGS = -Wall -O2
LIBS = -lntl -lgmp -lm -mconsole

OBJS = AppliedCrypto.o Hill_Cipher.o Shift_Cipher.o Vigenere_Cipher.o OneTimePad.o

all: Myexe

Myexe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o Myexe
