
#include <string>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include "../utils/LockingQueue.hpp"

using namespace std::chrono_literals;

#define DEBUG 1
    
class Void{
};

std::unordered_map<std::string, void*> sigma;
std::mutex sigma_mutex;  // protects sigma

void functioninit5Variable(){
	sigma.set("Variable0_0_0_10currentValue",new Number();//A1
}
void function7initializeVar(){
	let Number Variable0_0_0_101376 = 1; //undefined
	
                sigma.set("Variable0_0_0_10currentValue", new Number(Variable0_0_0_101376))
}
void functioninit9Variable(){
	sigma.set("Variable1_0_1_10currentValue",new Number();//A1
}
void function11initializeVar(){
	let Number Variable1_0_1_101376 = 4; //undefined
	
                sigma.set("Variable1_0_1_10currentValue", new Number(Variable1_0_1_101376))
}
void functioninit13Variable(){
	sigma.set("Variable2_0_2_10currentValue",new Number();//A1
}
void function14statementsInOrder1(){
	
}
void function15initializeVar(){
	let Number Variable2_0_2_101376 = 0; //undefined
	
                sigma.set("Variable2_0_2_10currentValue", new Number(Variable2_0_2_101376))
}
void function16finishModel(){
	
}

int main() {
    
        #if DEBUG
            std::cout<<"1 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"3 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"5 : Step" <<std::endl;
        #endif
        functioninit5Variable();

        #if DEBUG
            std::cout<<"7 : Step" <<std::endl;
        #endif
        function7initializeVar();

        #if DEBUG
            std::cout<<"6 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"9 : Step" <<std::endl;
        #endif
        functioninit9Variable();

        #if DEBUG
            std::cout<<"11 : Step" <<std::endl;
        #endif
        function11initializeVar();

        #if DEBUG
            std::cout<<"10 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"13 : Step" <<std::endl;
        #endif
        functioninit13Variable();

        #if DEBUG
            std::cout<<"15 : Step" <<std::endl;
        #endif
        function15initializeVar();

        #if DEBUG
            std::cout<<"14 : Step" <<std::endl;
        #endif
        function14statementsInOrder1();

        #if DEBUG
            std::cout<<"16 : Step" <<std::endl;
        #endif
        function16finishModel();

    //WARNING !! temporary code to test
    for(auto entry : sigma){
        std::cout << entry.first << " : " << *((int*)entry.second) << std::endl;
    }
}
    