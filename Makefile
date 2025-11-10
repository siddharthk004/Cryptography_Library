

CXX = g++
CXXFLAGS = -Wall -O2 -std=c++17

INCLUDE_DIRS = -I"C:/Users/Asus/Desktop/ntl/include"
LIB_DIRS = -L"C:/Users/Asus/Desktop/ntl/lib"

LIBS = -lntl -lgmp -lm -mconsole

OBJS = AppliedCrypto.o \
       Shift/Shift_Cipher.o \
       Vigenere-Cipher/Vigenere_Cipher.o \
       Hill-Cipher/Hill_Cipher.o \
       OTP/OneTimePad.o \
       Diffie-Hellman/Diffe_Hellman.o \
       El-Gamal/El_Gamal.o \
       Int_Fact/RSA.o \
       Eliptic-Curve/Eliptic_Curve.o

all: Myexe

Myexe: $(OBJS)
	@echo " Linking executable..."
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(LIB_DIRS) -o $@ $(OBJS) $(LIBS)
	@echo " Build successful!"

%.o: %.cpp
	@echo " Compiling $< ..."
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

clean:
	@echo " Cleaning object and executable files..."
	@find . -name "*.o" -type f -delete
	@rm -f Myexe
	@echo "Clean complete!"
