#include <iostream>

/*
int Mully(int a){
    return a<<1;//необходимо сдвинуть число а на 1 влево
}
uint8_t b = 1;
*/

int main() {
    uint16_t a = 1;
    //a = a << 10;
    std::cout << a << std::endl;
    uint8_t b = 0;
    b = static_cast<uint8_t>(a);
    std::cout << static_cast<uint32_t>(b) << std::endl;
    return 0;
}