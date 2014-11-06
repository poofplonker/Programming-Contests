//
//  interpreter.cpp
//  PC
//
//  Created by Cinnamon Scudworth on 4/07/14.
//  Copyright (c) 2014 Cinnamon Scudworth. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(void){
    int cases;
    cin >> cases;
    getchar();
    string dummy;
    getline(cin, dummy);
    for (int i =0; i < cases; i++) {
        string sinput;
        //cout << "Start new case" << endl;
        int registers[10];
        int ram[1000];
        for (int j = 0; j < 1000; j++) {
            if(j < 10){
                registers[j]= 0;
            }
            ram[j] = 0;
        }
        int counter = 0;
        int pc = 0;
        int instruction;
        string instructionx;
        getline(cin, sinput);
        //cout << sinput << endl;
        while (!sinput.empty()) {
            ram[counter++] = stoi(sinput);
            //cout << "Inputting " << stoi(sinput) << " at ram " << counter -1 << endl;
            getline(cin, sinput);
            //cout << sinput << endl;
        }
        counter = 0;
        bool halt = false;
        while (!halt) {
            instruction = ram[pc++];
            counter++;
            stringstream o;
            o << instruction;
            instructionx = o.str();
            while (instructionx.length() != 3) {
                instructionx = "0" + instructionx;
            }
            switch (instructionx[0]) {
                case '1':
                    //cout << "halt" << endl;
                    cout << counter << endl;
                    halt = true;
                    break;
                case '2':
                    registers[instructionx[1] - '0'] = instructionx[2] - '0';
                    //cout << "Code 2: Register " << instructionx[1] << " now " << instructionx[2] << endl;
                    break;
                case '3':
                    registers[instructionx[1] - '0'] += instructionx[2] - '0';
                    registers[instructionx[1] - '0'] %= 1000;
                    //cout << "Code 3: Register " << instructionx[1] << " now " << registers[instructionx[1]- '0'] << endl;
                    break;
                case '4':
                    registers[instructionx[1] - '0'] *= (instructionx[2] - '0');
                    registers[instructionx[1] - '0'] %= 1000;
                    //cout << "Code 4: Register " << instructionx[1] << " now " << registers[instructionx[1]- '0'] << endl;
                    break;
                case '5':
                    registers[instructionx[1] - '0'] = registers[instructionx[2] - '0'];
                    //cout << "Code 5: Register " << instructionx[1] << " now " << registers[instructionx[1]- '0'] << endl;
                    break;
                case '6':
                    registers[instructionx[1] - '0'] += registers[instructionx[2] - '0'];
                    registers[instructionx[1] - '0'] %= 1000;
                    //cout << "Code 6: Register " << instructionx[1] << " now " << registers[instructionx[1]- '0'] << endl;
                    break;
                case '7':
                    registers[instructionx[1] - '0'] *= registers[instructionx[2] - '0'];
                    registers[instructionx[1] - '0'] %= 1000;
                    //cout << "Code 7: Register " << instructionx[1] << " now " << registers[instructionx[1]- '0'] << endl;
                    break;
                case '8':
                    registers[instructionx[1] - '0'] = ram[registers[instructionx[2] - '0']];
                    break;
                case '9':
                    ram[instructionx[2] - '0'] = registers[instructionx[1] - '0'];
                    break;
                case '0':
                    //cout << "Code 0: Register " << instructionx[2] << " contains " << registers[instructionx[2] - '0'] << endl;
                    if(registers[instructionx[2] - '0']){
                        pc = registers[instructionx[1] - '0'];
                        //cout << "PC now: " << pc << endl;
                    }
                    break;
                default:
                    break;
            
            }
        }
    }
}
