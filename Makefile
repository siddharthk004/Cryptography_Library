
CXX = g++
CXXFLAGS = -Wall -O2
LIBS = -lntl -lgmp -lm -mconsole

OBJS = AppliedCrypto.o \
       Shift/Shift_Cipher.o \
       Vigenere-Cipher/Vigenere_Cipher.o \
       Hill-Cipher/Hill_Cipher.o \
       OTP/OneTimePad.o \
       Diffie-Hellman/Diffe_Hellman.o \
       El-Gamal/El_Gamal.o \
       Eliptic-Curve/Eliptic_Curve.o

all: Myexe

Myexe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning object and executable files..."
	@find . -name "*.o" -type f -delete
	@rm -f Myexe
	@echo "✅ Clean complete!"
