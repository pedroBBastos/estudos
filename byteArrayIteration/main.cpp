#include <iostream>
#include <limits.h>
#include <cstring>

struct MyStruct
{
    short qualityPlusAngle;
    short x;
    short yPlusType;
};

struct OtherStruct {
    MyStruct array[10];
};

OtherStruct giveMeAStruct() {
    OtherStruct bla;
    for (int i=0; i<10; i++) {
        bla.array[i] = {(short)i, (short)(i+1), (short)(i+2)};
    }
    return bla;
}

void printDeserializedStruct(OtherStruct& otherThing) {
    std::cout << "Printing deserialized!!!" << std::endl;
    for (int i=0; i<10; i++) {
        std::cout << "-------------------------------------" << std::endl;
        std::cout << otherThing.array[i].qualityPlusAngle << std::endl;
        std::cout << otherThing.array[i].x << std::endl;
        std::cout << otherThing.array[i].yPlusType << std::endl;
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
        std::cout << bla.qualityPlusAngle << std::endl;
        std::cout << bla.x << std::endl;
        std::cout << bla.yPlusType << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }
}

int main() {

    std::cout << "__WORDSIZE -> " << __WORDSIZE << std::endl;

    OtherStruct otherThing = giveMeAStruct();

    std::cout << "sizeof(OtherStruct) --> " << sizeof(otherThing) << std::endl;

    char* byteArray = (char*) &otherThing;

    printDeserializedStruct(otherThing);
    printSerializedStruct(byteArray);
}