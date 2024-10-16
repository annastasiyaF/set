#include <iostream>

/*
class BitField{
private:
    size_t _sizeMem; //sizeMem то, сколько элементов в массиве, определяет размер массива
    uint16_t* _mem; //массив
    size_t _sizeBit;//сколько хранится бит
    size_t GetMemIndex(size_t n) const{;//позволяет вернуть индекс который лежит в массиве ...
    size_t index = n/(8*sizeof(uint16_t));
    if (n >= _sizeBit){
        throw "Bit out of range";
    }
    return index;
    }
    uint16_t GetMask (size_t n) const{
        return 1 << (n % 16);
    }
public:
    BitField(size_t sizeBit);//конструктор
    BitField(const BitField& tmp){;//константная ссылка
        _sizeBit = tmp._sizeBit;
        _sizeMem = tmp._sizeMem;
        _mem = new uint16_t(_sizeMem);
        for (int i; i < _sizeMem; i++){
            _mem[i]= 0;
        }
    }

    BitField operator=(const BitField& tmp){
        
    }

    BitField(size_t len){
        _sizeBit = len;
        _sizeMem = (len / (8*sizeof(uint16_t))+(len%sizeof(uint16_t) != 0));

    }
    ~BitField();//деструктор, чистим память
    size_t GetSize() const;
    uint8_t GetBit(size_t n);//возвращает значение бита
    void SetBit(size_t n);//просваиваем какое-то значение
    void ClBit(size_t n);//устанавливает в массиве бит значение нуля
    void SetBit(size_t n){
    _mem[GetMemIndex(n)]|= GetMask(n);//реализация установки какой-то блять там
}

    //реализовать перегрузку операторов вывода в консоль
};  


//сдвигать единицу влево для составления маски на остаток от деления ...
*/
#include <iostream>

class BitField {
private:
    size_t _sizeBit;
    uint16_t* _mem;
    size_t _memSize;

    size_t GetMemIndex(size_t n) const;
    uint16_t GetMask(size_t n) const;
public:
    BitField(size_t len);
    BitField(const BitField& tmp);
    BitField& operator=(const BitField& tmp);
    
    size_t GetLength() const; // Получить количество бит
    void SetBit(size_t n);
    void ClrBit(size_t n); // Настя
    uint8_t GetBit(size_t n) const; // Саша


    BitField operator|(const BitField& tmp); // Карина
    BitField operator&(const BitField& tmp); // Алина
    BitField operator^(const BitField& tmp); // Арина
    bool operator==(const BitField& tmp); // Даша
    BitField operator~(); // Все

    ~BitField(); // Все
};