#pragma once
#include <iostream>

// from https://stackoverflow.com/questions/11747439/c-object-class
class object {
protected:
    void * Value;
    
public:

    template <class Type>
    void operator = (Type Value){
        this->Value = (void*)Value;
    }

    template <>
    void operator = <std::string>(std::string Value) {
        this->Value = (void*)Value.c_str();
    }

    template <class Type>
    bool operator ==  (Type Value2) {
        return (int)(void*)Value2==(int)this->Value;
    }

    template<>
    bool operator == <Object> (Object Value2) {
        return Value2.Value==this->Value;
    }

    template <class ReturnType>
    ReturnType Get() {
        return (ReturnType)this->Value;
    }

    template <>
    std::string Get() {
        std::string str = (const char*)this->Value;
        return str;
    }

    template <>
    void* Get() {
        return this->Value;
    }

    void Print() {
        std::cout << (signed)this->Value << "\n";
    }


};
