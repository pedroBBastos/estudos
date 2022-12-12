#include <iostream>
#include <limits.h>
#include <cstring>

#pragma pack(2)
struct MyStruct
{
    short brabas;
    int frubas;
    // short brabas;
};

struct OtherStruct {
    MyStruct array[10];
};

OtherStruct giveMeAStruct() {
    OtherStruct bla;
    for (int i=0; i<10; i++) {
        // bla.array[i] = {i, (short)(i+1)};
        bla.array[i] = {(short)(i+1), i};
    }
    return bla;
}

void printDeserializedStruct(OtherStruct& otherThing) {
    std::cout << "Printing deserialized!!!" << std::endl;
    for (int i=0; i<10; i++) {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << otherThing.array[i].frubas << std::endl;
        std::cout << otherThing.array[i].brabas << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }
}

void printSerializedStruct(char* byteArray) {
    std::cout << "Printing serialized!!!" << std::endl;
    int offset = 6; // de 6 em 6 bytes terei um MyStruct
    for(int i=0; i<6*10; i+=offset) {

        std::cout << "Current i value -> " << i << std::endl;

        MyStruct bla;
        std::memcpy(&bla, &byteArray[i], sizeof(MyStruct));

        std::cout << "-------------------------------------" << std::endl;
        std::cout << bla.frubas << std::endl;
        std::cout << bla.brabas << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }
}

int main() {

    std::cout << "__WORDSIZE -> " << __WORDSIZE << std::endl;

    std::cout << "sizeof(MyStruct) --> " << sizeof(MyStruct) << std::endl;

    OtherStruct otherThing = giveMeAStruct();
    std::cout << "sizeof(OtherStruct) --> " << sizeof(otherThing) << std::endl;

    char* byteArray = (char*) &otherThing;

    printDeserializedStruct(otherThing);
    printSerializedStruct(byteArray);
}