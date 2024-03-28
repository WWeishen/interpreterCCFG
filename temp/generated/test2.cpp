
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
	let Variable0_0_0_101376 = 1; //undefined
	
                sigma.set("Variable0_0_0_10currentValue", new Number(Variable0_0_0_101376))
}
void functioninit9Variable(){
	sigma.set("Variable1_0_1_10currentValue",new Number();//A1
}
void function11initializeVar(){
	let Variable1_0_1_101376 = 4; //undefined
	
                sigma.set("Variable1_0_1_10currentValue", new Number(Variable1_0_1_101376))
}
void functioninit13Variable(){
	sigma.set("Variable2_0_2_10currentValue",new Number();//A1
}
void function15initializeVar(){
	let Variable2_0_2_101376 = 0; //undefined
	
                sigma.set("Variable2_0_2_10currentValue", new Number(Variable2_0_2_101376))
}
void function17startsParallelBloc(){
	
}
void function22executeAssignment(){
	
}
void function25startPlus(){
	
}
Number function29accessVarRef(){
	let VarRef4_18_4_201579 = new Number(sigma.get("Variable0_0_0_10currentValue");//currentValue}
	VarRef4_18_4_20terminates =  VarRef4_18_4_201579;
	return VarRef4_18_4_20terminates;
}
Number function32accessVarRef(){
	let VarRef4_13_4_151579 = new Number(sigma.get("Variable0_0_0_10currentValue");//currentValue}
	VarRef4_13_4_15terminates =  VarRef4_13_4_151579;
	return VarRef4_13_4_15terminates;
}
Number function34finishPlus(Number n2, Number n1){
	Plus4_12_4_214267 = n2;
	Plus4_12_4_214292 = n1;
	let  Plus4_12_4_214411 = n1; // was Plus4_12_4_214292; but using the parameter name now
	let  Plus4_12_4_214416 = n2; // was Plus4_12_4_214267; but using the parameter name now
	Plus4_12_4_214410 = Plus4_12_4_214411 + Plus4_12_4_214416;
	Plus4_12_4_21terminates =  Plus4_12_4_214410;
	return Plus4_12_4_21terminates;
}
void function35executeAssignment2(Number resRight){
	let  Assignment4_7_4_212520 = resRight; // was Assignment4_7_4_212354; but using the parameter name now
	                                 
                sigma.set("Variable1_0_1_10currentValue", new Number(Assignment4_7_4_212520))
}
void function37executeAssignment(){
	
}
void function40startPlus(){
	
}
Number function44accessVarRef(){
	let VarRef5_18_5_201579 = new Number(sigma.get("Variable1_0_1_10currentValue");//currentValue}
	VarRef5_18_5_20terminates =  VarRef5_18_5_201579;
	return VarRef5_18_5_20terminates;
}
Number function47accessVarRef(){
	let VarRef5_13_5_151579 = new Number(sigma.get("Variable1_0_1_10currentValue");//currentValue}
	VarRef5_13_5_15terminates =  VarRef5_13_5_151579;
	return VarRef5_13_5_15terminates;
}
Number function49finishPlus(Number n2, Number n1){
	Plus5_12_5_214267 = n2;
	Plus5_12_5_214292 = n1;
	let  Plus5_12_5_214411 = n1; // was Plus5_12_5_214292; but using the parameter name now
	let  Plus5_12_5_214416 = n2; // was Plus5_12_5_214267; but using the parameter name now
	Plus5_12_5_214410 = Plus5_12_5_214411 + Plus5_12_5_214416;
	Plus5_12_5_21terminates =  Plus5_12_5_214410;
	return Plus5_12_5_21terminates;
}
void function50executeAssignment2(Number resRight){
	let  Assignment5_7_5_212520 = resRight; // was Assignment5_7_5_212354; but using the parameter name now
	                                 
                sigma.set("Variable1_0_1_10currentValue", new Number(Assignment5_7_5_212520))
}
void function20finishParallelBloc(){
	
}
void function53condStart(){
	
}
Number function56accessVarRef(){
	let VarRef7_4_7_61579 = new Number(sigma.get("Variable0_0_0_10currentValue");//currentValue}
	VarRef7_4_7_6terminates =  VarRef7_4_7_61579;
	return VarRef7_4_7_6terminates;
}
void function58condFalseStart(){
	
}
void function64executeAssignment(){
	
}
void function65startsBloc(){
	
}
void function67startPlus(){
	
}
Number function71accessVarRef(){
	let VarRef9_15_9_171579 = new Number(sigma.get("Variable0_0_0_10currentValue");//currentValue}
	VarRef9_15_9_17terminates =  VarRef9_15_9_171579;
	return VarRef9_15_9_17terminates;
}
Number function74accessVarRef(){
	let VarRef9_10_9_121579 = new Number(sigma.get("Variable1_0_1_10currentValue");//currentValue}
	VarRef9_10_9_12terminates =  VarRef9_10_9_121579;
	return VarRef9_10_9_12terminates;
}
Number function76finishPlus(Number n2, Number n1){
	Plus9_9_9_184267 = n2;
	Plus9_9_9_184292 = n1;
	let  Plus9_9_9_184411 = n1; // was Plus9_9_9_184292; but using the parameter name now
	let  Plus9_9_9_184416 = n2; // was Plus9_9_9_184267; but using the parameter name now
	Plus9_9_9_184410 = Plus9_9_9_184411 + Plus9_9_9_184416;
	Plus9_9_9_18terminates =  Plus9_9_9_184410;
	return Plus9_9_9_18terminates;
}
void function77executeAssignment2(Number resRight){
	let  Assignment9_4_9_182520 = resRight; // was Assignment9_4_9_182354; but using the parameter name now
	                                 
                sigma.set("Variable1_0_1_10currentValue", new Number(Assignment9_4_9_182520))
}
void function78finishBloc(){
	
}
void function84executeAssignment(){
	
}
void function85startsBloc(){
	
}
void function87startPlus(){
	
}
Number function91accessVarRef(){
	let VarRef12_15_12_171579 = new Number(sigma.get("Variable0_0_0_10currentValue");//currentValue}
	VarRef12_15_12_17terminates =  VarRef12_15_12_171579;
	return VarRef12_15_12_17terminates;
}
Number function94accessVarRef(){
	let VarRef12_10_12_121579 = new Number(sigma.get("Variable1_0_1_10currentValue");//currentValue}
	VarRef12_10_12_12terminates =  VarRef12_10_12_121579;
	return VarRef12_10_12_12terminates;
}
Number function96finishPlus(Number n2, Number n1){
	Plus12_9_12_184267 = n2;
	Plus12_9_12_184292 = n1;
	let  Plus12_9_12_184411 = n1; // was Plus12_9_12_184292; but using the parameter name now
	let  Plus12_9_12_184416 = n2; // was Plus12_9_12_184267; but using the parameter name now
	Plus12_9_12_184410 = Plus12_9_12_184411 + Plus12_9_12_184416;
	Plus12_9_12_18terminates =  Plus12_9_12_184410;
	return Plus12_9_12_18terminates;
}
void function97executeAssignment2(Number resRight){
	let  Assignment12_4_12_182520 = resRight; // was Assignment12_4_12_182354; but using the parameter name now
	                                 
                sigma.set("Variable0_0_0_10currentValue", new Number(Assignment12_4_12_182520))
}
void function98finishBloc(){
	
}
void function99condStop(){
	
}
void function101executeAssignment(){
	
}
void function102statementsInOrder1(){
	
}
void function104evaluateConjunction(){
	
}
Boolean function109evalBooleanConst(){
	sigma.set("BooleanConst16_6_16_10constantValue",new Boolean(true);//A1
	let BooleanConst16_6_16_104630 = new Boolean(sigma.get("BooleanConst16_6_16_10constantValue");//constantValue}
	BooleanConst16_6_16_10terminates =  BooleanConst16_6_16_104630;
	return BooleanConst16_6_16_10terminates;
}
Boolean function112evalBooleanConst(){
	sigma.set("BooleanConst16_14_16_19constantValue",new Boolean(false);//A1
	let BooleanConst16_14_16_194630 = new Boolean(sigma.get("BooleanConst16_14_16_19constantValue");//constantValue}
	BooleanConst16_14_16_19terminates =  BooleanConst16_14_16_194630;
	return BooleanConst16_14_16_19terminates;
}
Boolean function114evaluateConjunction2(){
	Conjunction16_5_16_20terminates =  false;
	return Conjunction16_5_16_20terminates;
}
Boolean function115evaluateConjunction3(){
	Conjunction16_5_16_20terminates =  false;
	return Conjunction16_5_16_20terminates;
}
Boolean function117evaluateConjunction4(){
	Conjunction16_5_16_20terminates =  true;
	return Conjunction16_5_16_20terminates;
}
void function118executeAssignment2(Number resRight){
	let  Assignment16_0_16_202520 = resRight; // was Assignment16_0_16_202354; but using the parameter name now
	                                 
                sigma.set("Variable2_0_2_10currentValue", new Number(Assignment16_0_16_202520))
}
void function119finishModel(){
	
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
        
        #if DEBUG
            std::cout<<"17 : Step" <<std::endl;
        #endif
        function17startsParallelBloc();
         
            LockingQueue<Void> queue20;
            std::thread thread22([&](){

        #if DEBUG
            std::cout<<"22 : Step" <<std::endl;
        #endif
        function22executeAssignment();

        #if DEBUG
            std::cout<<"25 : Step" <<std::endl;
        #endif
        function25startPlus();

            LockingQueue<Number> queue34;
            std::thread thread29([&](){

        #if DEBUG
            std::cout<<"29 : Step" <<std::endl;
        #endif
        Number result29accessVarRef = function29accessVarRef();
{

            queue34.push(result29accessVarRef);
                }

        #if DEBUG
            std::cout<<"30 : Step" <<std::endl;
        #endif
        
            });
            thread29.detach();
                
            std::thread thread32([&](){

        #if DEBUG
            std::cout<<"32 : Step" <<std::endl;
        #endif
        Number result32accessVarRef = function32accessVarRef();
{

            queue34.push(result32accessVarRef);
                }

        #if DEBUG
            std::cout<<"33 : Step" <<std::endl;
        #endif
        
            });
            thread32.detach();
                
        //start of and join node
        
        Number AndJoinPopped_34_0;
        queue34.waitAndPop(AndJoinPopped_34_0);
            
        Number AndJoinPopped_34_1;
        queue34.waitAndPop(AndJoinPopped_34_1);
            
        #if DEBUG
            std::cout<<"34 : AndJoin" <<std::endl;
        #endif
        Number result34finishPlus = function34finishPlus(AndJoinPopped_34_0, AndJoinPopped_34_1);

        //end of and join node
        
        #if DEBUG
            std::cout<<"26 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"35 : Step" <<std::endl;
        #endif
        function35executeAssignment2(result34finishPlus);
{

            Void fakeParam20;
            queue20.push(fakeParam20);
                }

        #if DEBUG
            std::cout<<"23 : Step" <<std::endl;
        #endif
        
            });
            thread22.detach();
                
            std::thread thread37([&](){

        #if DEBUG
            std::cout<<"37 : Step" <<std::endl;
        #endif
        function37executeAssignment();

        #if DEBUG
            std::cout<<"40 : Step" <<std::endl;
        #endif
        function40startPlus();

            LockingQueue<Number> queue49;
            std::thread thread44([&](){

        #if DEBUG
            std::cout<<"44 : Step" <<std::endl;
        #endif
        Number result44accessVarRef = function44accessVarRef();
{

            queue49.push(result44accessVarRef);
                }

        #if DEBUG
            std::cout<<"45 : Step" <<std::endl;
        #endif
        
            });
            thread44.detach();
                
            std::thread thread47([&](){

        #if DEBUG
            std::cout<<"47 : Step" <<std::endl;
        #endif
        Number result47accessVarRef = function47accessVarRef();
{

            queue49.push(result47accessVarRef);
                }

        #if DEBUG
            std::cout<<"48 : Step" <<std::endl;
        #endif
        
            });
            thread47.detach();
                
        //start of and join node
        
        Number AndJoinPopped_49_0;
        queue49.waitAndPop(AndJoinPopped_49_0);
            
        Number AndJoinPopped_49_1;
        queue49.waitAndPop(AndJoinPopped_49_1);
            
        #if DEBUG
            std::cout<<"49 : AndJoin" <<std::endl;
        #endif
        Number result49finishPlus = function49finishPlus(AndJoinPopped_49_0, AndJoinPopped_49_1);

        //end of and join node
        
        #if DEBUG
            std::cout<<"41 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"50 : Step" <<std::endl;
        #endif
        function50executeAssignment2(result49finishPlus);
{

            Void fakeParam20;
            queue20.push(fakeParam20);
                }

        #if DEBUG
            std::cout<<"38 : Step" <<std::endl;
        #endif
        
            });
            thread37.detach();
                
        //start of and join node
        
        Void AndJoinPopped_20_0;
        queue20.waitAndPop(AndJoinPopped_20_0);
            
        Void AndJoinPopped_20_1;
        queue20.waitAndPop(AndJoinPopped_20_1);
            
        #if DEBUG
            std::cout<<"20 : AndJoin" <<std::endl;
        #endif
        function20finishParallelBloc();

        //end of and join node
        
        #if DEBUG
            std::cout<<"18 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"53 : Step" <<std::endl;
        #endif
        function53condStart();

        #if DEBUG
            std::cout<<"56 : Step" <<std::endl;
        #endif
        Number result56accessVarRef = function56accessVarRef();

        #if DEBUG
            std::cout<<"57 : Step" <<std::endl;
        #endif
        
        LockingQueue<Void> queue99;
            
        Number VarRef7_4_7_6terminates = result56accessVarRef;//Choice node
        if((VarRef7_4_7_6terminates == true)){
        #if DEBUG
            std::cout<<"58 : Choice" <<std::endl;
        #endif
        function58condFalseStart();

        #if DEBUG
            std::cout<<"60 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"62 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"64 : Step" <<std::endl;
        #endif
        function64executeAssignment();

        #if DEBUG
            std::cout<<"67 : Step" <<std::endl;
        #endif
        function67startPlus();

            LockingQueue<Number> queue76;
            std::thread thread71([&](){

        #if DEBUG
            std::cout<<"71 : Step" <<std::endl;
        #endif
        Number result71accessVarRef = function71accessVarRef();
{

            queue76.push(result71accessVarRef);
                }

        #if DEBUG
            std::cout<<"72 : Step" <<std::endl;
        #endif
        
            });
            thread71.detach();
                
            std::thread thread74([&](){

        #if DEBUG
            std::cout<<"74 : Step" <<std::endl;
        #endif
        Number result74accessVarRef = function74accessVarRef();
{

            queue76.push(result74accessVarRef);
                }

        #if DEBUG
            std::cout<<"75 : Step" <<std::endl;
        #endif
        
            });
            thread74.detach();
                
        //start of and join node
        
        Number AndJoinPopped_76_0;
        queue76.waitAndPop(AndJoinPopped_76_0);
            
        Number AndJoinPopped_76_1;
        queue76.waitAndPop(AndJoinPopped_76_1);
            
        #if DEBUG
            std::cout<<"76 : AndJoin" <<std::endl;
        #endif
        Number result76finishPlus = function76finishPlus(AndJoinPopped_76_0, AndJoinPopped_76_1);

        //end of and join node
        
        #if DEBUG
            std::cout<<"68 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"77 : Step" <<std::endl;
        #endif
        function77executeAssignment2(result76finishPlus);
{

            Void fakeParam99;
            queue99.push(fakeParam99);
                }

        #if DEBUG
            std::cout<<"65 : Step" <<std::endl;
        #endif
        function65startsBloc();

        #if DEBUG
            std::cout<<"78 : Step" <<std::endl;
        #endif
        function78finishBloc();

        #if DEBUG
            std::cout<<"61 : Step" <<std::endl;
        #endif
        
            //END IF (VarRef7_4_7_6terminates == true)
        }
            //Choice node
        if((VarRef7_4_7_6terminates == false)){
        #if DEBUG
            std::cout<<"58 : Choice" <<std::endl;
        #endif
        function58condFalseStart();

        #if DEBUG
            std::cout<<"80 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"82 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"84 : Step" <<std::endl;
        #endif
        function84executeAssignment();

        #if DEBUG
            std::cout<<"87 : Step" <<std::endl;
        #endif
        function87startPlus();

            LockingQueue<Number> queue96;
            std::thread thread91([&](){

        #if DEBUG
            std::cout<<"91 : Step" <<std::endl;
        #endif
        Number result91accessVarRef = function91accessVarRef();
{

            queue96.push(result91accessVarRef);
                }

        #if DEBUG
            std::cout<<"92 : Step" <<std::endl;
        #endif
        
            });
            thread91.detach();
                
            std::thread thread94([&](){

        #if DEBUG
            std::cout<<"94 : Step" <<std::endl;
        #endif
        Number result94accessVarRef = function94accessVarRef();
{

            queue96.push(result94accessVarRef);
                }

        #if DEBUG
            std::cout<<"95 : Step" <<std::endl;
        #endif
        
            });
            thread94.detach();
                
        //start of and join node
        
        Number AndJoinPopped_96_0;
        queue96.waitAndPop(AndJoinPopped_96_0);
            
        Number AndJoinPopped_96_1;
        queue96.waitAndPop(AndJoinPopped_96_1);
            
        #if DEBUG
            std::cout<<"96 : AndJoin" <<std::endl;
        #endif
        Number result96finishPlus = function96finishPlus(AndJoinPopped_96_0, AndJoinPopped_96_1);

        //end of and join node
        
        #if DEBUG
            std::cout<<"88 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"97 : Step" <<std::endl;
        #endif
        function97executeAssignment2(result96finishPlus);
{

            Void fakeParam99;
            queue99.push(fakeParam99);
                }

        #if DEBUG
            std::cout<<"85 : Step" <<std::endl;
        #endif
        function85startsBloc();

        #if DEBUG
            std::cout<<"98 : Step" <<std::endl;
        #endif
        function98finishBloc();

        #if DEBUG
            std::cout<<"81 : Step" <<std::endl;
        #endif
        
            //END IF (VarRef7_4_7_6terminates == false)
        }
             //or join node
        Void OrJoinPopped_99;
        queue99.waitAndPop(OrJoinPopped_99);
        
        #if DEBUG
            std::cout<<"54 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"101 : Step" <<std::endl;
        #endif
        function101executeAssignment();

        #if DEBUG
            std::cout<<"104 : Step" <<std::endl;
        #endif
        function104evaluateConjunction();

            LockingQueue<Boolean> queue106;
            LockingQueue<Boolean> queue116;
            std::thread thread109([&](){

        #if DEBUG
            std::cout<<"109 : Step" <<std::endl;
        #endif
        Boolean result109evalBooleanConst = function109evalBooleanConst();
{

            queue116.push(result109evalBooleanConst);
                }

        #if DEBUG
            std::cout<<"110 : Step" <<std::endl;
        #endif
        
                {
        Boolean BooleanConst16_6_16_10terminates = result109evalBooleanConst;//Choice node
        if((BooleanConst16_6_16_10terminates == false)){
        #if DEBUG
            std::cout<<"114 : Choice" <<std::endl;
        #endif
        Boolean result114evaluateConjunction2 = function114evaluateConjunction2();
{

            queue106.push(result114evaluateConjunction2);
                }

            //END IF (BooleanConst16_6_16_10terminates == false)
        }
            
                }
                
                {
                }
                
            });
            thread109.detach();
                
            std::thread thread112([&](){

        #if DEBUG
            std::cout<<"112 : Step" <<std::endl;
        #endif
        Boolean result112evalBooleanConst = function112evalBooleanConst();
{

            queue116.push(result112evalBooleanConst);
                }

        #if DEBUG
            std::cout<<"113 : Step" <<std::endl;
        #endif
        
                {
        Boolean BooleanConst16_14_16_19terminates = result112evalBooleanConst;//Choice node
        if((BooleanConst16_14_16_19terminates == false)){
        #if DEBUG
            std::cout<<"115 : Choice" <<std::endl;
        #endif
        Boolean result115evaluateConjunction3 = function115evaluateConjunction3();
{

            queue106.push(result115evaluateConjunction3);
                }

            //END IF (BooleanConst16_14_16_19terminates == false)
        }
            
                }
                
                {
                }
                
            });
            thread112.detach();
                
        //start of and join node
        
        Boolean AndJoinPopped_116_0;
        queue116.waitAndPop(AndJoinPopped_116_0);
            
        Boolean AndJoinPopped_116_1;
        queue116.waitAndPop(AndJoinPopped_116_1);
            
        #if DEBUG
            std::cout<<"116 : AndJoin" <<std::endl;
        #endif
        
        //end of and join node
        
        Boolean BooleanConst16_6_16_10terminates = AndJoinPopped_116_0;
        Boolean BooleanConst16_14_16_19terminates = AndJoinPopped_116_1;//Choice node
        if((BooleanConst16_6_16_10terminates == true) && (BooleanConst16_14_16_19terminates == true)){
        #if DEBUG
            std::cout<<"117 : Choice" <<std::endl;
        #endif
        Boolean result117evaluateConjunction4 = function117evaluateConjunction4();
{

            queue106.push(result117evaluateConjunction4);
                }

            //END IF (BooleanConst16_6_16_10terminates == true) && (BooleanConst16_14_16_19terminates == true)
        }
             //or join node
        Boolean OrJoinPopped_106;
        queue106.waitAndPop(OrJoinPopped_106);
        
        #if DEBUG
            std::cout<<"105 : Step" <<std::endl;
        #endif
        
        #if DEBUG
            std::cout<<"118 : Step" <<std::endl;
        #endif
        function118executeAssignment2(OrJoinPopped_106);

        #if DEBUG
            std::cout<<"102 : Step" <<std::endl;
        #endif
        function102statementsInOrder1();

        #if DEBUG
            std::cout<<"119 : Step" <<std::endl;
        #endif
        function119finishModel();

    //WARNING !! temporary code to test
    for(auto entry : sigma){
        std::cout << entry.first << " : " << *((int*)entry.second) << std::endl;
    }
}
    