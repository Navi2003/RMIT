#include <iostream>
#include <fstream>
#include <cstring>
int main(){
    std::fstream myfile;
    myfile.open("myfile.dat", std::ios::out | std::ios::binary);
    if (!myfile){
        std::cerr << "Failed to open file.";
        return -1;
    }
    char data[11] = {0x5A, 0x3F, 0x33, 0x3D, 0x40, 0x6B, 0x4C, 0x58, 0x72, 0x4E, 0x2F};
    for (int i = 0; i < 11; i++){
        myfile << data[i];
    }
    myfile << std::endl;
    for (int i = 0; i < 11; i++){
        myfile.put(data[i]); 
    }
    myfile << std::endl;
    myfile.write(data, 11);
    myfile.close();
    return 0;
}