#include "Set.h"
#include <vector>

Set::Set(size_t mp):_bitField(mp){
}
Set::Set(const Set& set):_maxPower(set._maxPower), _bitField(set._bitField){
}
Set::Set(const BitField& bf):_maxPower(bf.GetLength()), _bitField(bf){
}//конструктор преобразования

Set::operator BitField(){
    return _bitField;
}//оператор который может принимать что-то там хихихи
size_t Set::GetMaxPower(){
    return _maxPower;
}

void Set::InsertElem(uint64_t elem){
    if(elem < _maxPower){
        _bitField.SetBit(elem);
    }
}//вставить элемент
void Set::DeleteElem(uint64_t elem){
    if(elem < _maxPower){
        _bitField.ClrBit(elem);
    }
}
bool Set::IsMemer(uint64_t elem){
    return elem < _maxPower && _bitField.GetBit(elem);
}//функция проверяет явл ли элемент элементом множества
bool Set::operator==(const Set& tmp){
    if(_maxPower != tmp._maxPower){
        return false;
    }
    return _bitField == tmp._bitField;
}
Set& Set::operator=(const Set& tmp){
    _maxPower = tmp._maxPower;
    _bitField = tmp._bitField;
    return *this;
}
Set Set::operator+(const Set& tmp){
    Set result(_maxPower);
    result._bitField = _bitField | tmp._bitField;
    return result;
}//объединение 2х множеств
Set Set::operator+(uint16_t elem){
    Set result(*this);
    result.InsertElem(elem);
    return result;
}//оператор добавления элементов в множество 
Set Set::operator-(uint16_t elem){
    Set result(*this);
    result.DeleteElem(elem);
    return result;
}
Set Set::operator*(const Set& tmp){
    Set result(_maxPower);
    result._bitField = _bitField & tmp._bitField;
    return result;
}
Set Set::operator~(){
    Set result(_maxPower);
    result._bitField = ~_bitField;
    return result;
}//оператор возвращения дополнения 

std::vector<uint64_t>Set::GetPrimary(){
    BitField b = _bitField;
    std::vector<uint64_t>array;
    for (size_t i = 2; i < _maxPower; i++){
        if (b.GetBit(i)(i)){
            array.push_back(i);
        }
    }
    return array;
}

