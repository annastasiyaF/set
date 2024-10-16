#include "BitField.h"
#include <vector>

class Set{
private:
    BitField _bitField; //структура хранения нашего множества
    size_t _maxPower; //макксимальный размер нашего множества

public:
    Set(size_t mp);
    Set(const Set& set);
    Set(const BitField& bf);//конструктор преобразования
    operator BitField();//оператор который может принимать что-то там хихихи
    size_t GetMaxPower();
    void InsertElem(uint64_t elem);//вставить элемент
    void DeleteElem(uint64_t elem);
    bool IsMemer(uint64_t elem);//функция проверяет явл ли элемент элементом множества

    bool operator==(const Set& tmp);
    Set& operator=(const Set& tmp);
    Set operator+(const Set& tmp);//объединение 2х множеств
    Set operator+(uint16_t elem);//оператор добавления элементов в множество 
    Set operator-(uint16_t elem);
    Set operator*(const Set& tmp);
    Set operator~();//оператор возвращения дополнения 

    
    friend std::istream& operator>>(std::istream& istr, Set& set){

    }

    friend std::ostream& operator<<(std::ostream& ostr, const Set& set){

    }

    std::vector<uint64_t>GetPrimary();
};
// uint64_t* GetPrimary() возвращает из данного множества простые числа
//сделать репозиторий, загрузить туда код битфилд сет и новый метод  сет, скинуть репозиторий в группу 