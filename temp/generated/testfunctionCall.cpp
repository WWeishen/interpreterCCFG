
#include <string>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include "../utils/LockingQueue.hpp"

using namespace std::chrono_literals;

class Void{
};

std::unordered_map<std::string, void*> sigma;
std::mutex sigma_mutex;  // protects sigma

void functioninit3Variable(){
	sigma["Variable13_0_13_10currentValue"] = new int();
}
void function5initializeVar(){
	int Variable13_0_13_101377 = 0; //undefined
	//TODO: fix this and avoid memory leak by deleting, constructing appropriately
                const std::lock_guard<std::mutex> lock(sigma_mutex);
                (*((int*)sigma["Variable13_0_13_10currentValue"])) = Variable13_0_13_101377;
}
int function9accessVarRef(){
	const std::lock_guard<std::mutex> lock(sigma_mutex);
	int VarRef14_3_14_51583 = *(int *) sigma["Variable13_0_13_10currentValue"];//currentValue}
	int VarRef14_3_14_5terminates =  VarRef14_3_14_51583;
	return VarRef14_3_14_5terminates;
}
void functioninit17Variable(){
	sigma["Variable1_4_1_14currentValue"] = new int();
}
void function19initializeVar(){
	int Variable1_4_1_141377 = 0; //undefined
	//TODO: fix this and avoid memory leak by deleting, constructing appropriately
                const std::lock_guard<std::mutex> lock(sigma_mutex);
                (*((int*)sigma["Variable1_4_1_14currentValue"])) = Variable1_4_1_141377;
}
void functioninit20Variable(){
	sigma["Variable2_4_2_14currentValue"] = new int();
}
void function22initializeVar(){
	int Variable2_4_2_141377 = 0; //undefined
	//TODO: fix this and avoid memory leak by deleting, constructing appropriately
                const std::lock_guard<std::mutex> lock(sigma_mutex);
                (*((int*)sigma["Variable2_4_2_14currentValue"])) = Variable2_4_2_141377;
}
int function25accessVarRef(){
	const std::lock_guard<std::mutex> lock(sigma_mutex);
	int VarRef3_9_3_111583 = *(int *) sigma["Variable1_4_1_14currentValue"];//currentValue}
	int VarRef3_9_3_11terminates =  VarRef3_9_3_111583;
	return VarRef3_9_3_11terminates;
}
void function27executeAssignment2(int resRight){
	int Assignment3_4_3_112524 = resRight; // was Assignment3_4_3_112358; but using the parameter name now
	//TODO: fix this and avoid memory leak by deleting, constructing appropriately
                const std::lock_guard<std::mutex> lock(sigma_mutex);                                    
                (*((int*)sigma["Variable2_4_2_14currentValue"])) = Assignment3_4_3_112524;
}
int function30accessVarRef(){
	const std::lock_guard<std::mutex> lock(sigma_mutex);
	int VarRef4_7_4_91583 = *(int *) sigma["Variable1_4_1_14currentValue"];//currentValue}
	int VarRef4_7_4_9terminates =  VarRef4_7_4_91583;
	return VarRef4_7_4_9terminates;
}
int function39accessVarRef(){
	const std::lock_guard<std::mutex> lock(sigma_mutex);
	int VarRef5_11_5_131583 = *(int *) sigma["Variable1_4_1_14currentValue"];//currentValue}
	int VarRef5_11_5_13terminates =  VarRef5_11_5_131583;
	return VarRef5_11_5_13terminates;
}
int function51accessVarRef(){
	const std::lock_guard<std::mutex> lock(sigma_mutex);
	int VarRef7_19_7_211583 = *(int *) sigma["Variable1_4_1_14currentValue"];//currentValue}
	int VarRef7_19_7_21terminates =  VarRef7_19_7_211583;
	return VarRef7_19_7_21terminates;
}
int function53accessVarRef(){
	const std::lock_guard<std::mutex> lock(sigma_mutex);
	int VarRef7_14_7_161583 = *(int *) sigma["Variable1_4_1_14currentValue"];//currentValue}
	int VarRef7_14_7_16terminates =  VarRef7_14_7_161583;
	return VarRef7_14_7_16terminates;
}
int function55finishPlus(int n2, int n1){
	int Plus7_13_7_224243 = n2;
	int Plus7_13_7_224268 = n1;
	int Plus7_13_7_224387 = n1; // was Plus7_13_7_224268; but using the parameter name now
	int Plus7_13_7_224392 = n2; // was Plus7_13_7_224243; but using the parameter name now
	int Plus7_13_7_224386 = Plus7_13_7_224387 + Plus7_13_7_224392;
	int Plus7_13_7_22terminates =  Plus7_13_7_224386;
	return Plus7_13_7_22terminates;
}
void function56executeAssignment2(int resRight){
	int Assignment7_8_7_222524 = resRight; // was Assignment7_8_7_222358; but using the parameter name now
	//TODO: fix this and avoid memory leak by deleting, constructing appropriately
                const std::lock_guard<std::mutex> lock(sigma_mutex);                                    
                (*((int*)sigma["Variable2_4_2_14currentValue"])) = Assignment7_8_7_222524;
}

int main() {
    functioninit3Variable();
function5initializeVar();
int result9accessVarRef = function9accessVarRef();

        LockingQueue<int> queue60;
            {

            queue60.push(result9accessVarRef);
                
           goto queue60;
            }
queue60: //or join node
        int OrJoinPopped_60;
        queue60.waitAndPop(OrJoinPopped_60);
        functioninit17Variable();
function19initializeVar();
functioninit20Variable();
function22initializeVar();
int result25accessVarRef = function25accessVarRef();
function27executeAssignment2(result25accessVarRef);
int result30accessVarRef = function30accessVarRef();

        int VarRef4_7_4_9terminates = result30accessVarRef;//Choice node
        if((bool)VarRef4_7_4_9terminates == true){int result39accessVarRef = function39accessVarRef();
{

            queue60.push(result39accessVarRef);
                
           goto queue60;
            }

            //END IF (bool)VarRef4_7_4_9terminates == true
        }
            //Choice node
        if((bool)VarRef4_7_4_9terminates == false){
            LockingQueue<int> queue55;
            std::thread thread51([&](){
int result51accessVarRef = function51accessVarRef();
{

            queue55.push(result51accessVarRef);
                }

            });
            thread51.detach();
                
            std::thread thread53([&](){
int result53accessVarRef = function53accessVarRef();
{

            queue55.push(result53accessVarRef);
                }

            });
            thread53.detach();
                
        //start of and join node
        
        int AndJoinPopped_55_0;
        queue55.waitAndPop(AndJoinPopped_55_0);
            
        int AndJoinPopped_55_1;
        queue55.waitAndPop(AndJoinPopped_55_1);
            int result55finishPlus = function55finishPlus(AndJoinPopped_55_0, AndJoinPopped_55_1);

        //end of and join node
        function56executeAssignment2(result55finishPlus);

        LockingQueue<Void> queue58;
            {

            Void fakeParam58;
            queue58.push(fakeParam58);
                }

            //END IF (bool)VarRef4_7_4_9terminates == false
        }
            
    //WARNING !! temporary code to test
    for(auto entry : sigma){
        std::cout << entry.first << " : " << *((int*)entry.second) << std::endl;
    }
}
    