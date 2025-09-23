#ifndef DIFFIEHELLMAN_HPP
#define DIFFIEHELLMAN_HPP

class DiffieHellman
{
private:
    int p;  
    int g;  
    int a;  
    int b;  

    int A;  
    int B;  

    int sharedAlice;
    int sharedBob;

    int modExp(int base, int exp, int mod);

public:
    DiffieHellman(int prime);

    void generateValues();     
    void computePublicKeys();  
    void computeSharedKeys();  
    void display();      
};

#endif 
