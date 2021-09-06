#ifndef UC_H
#define UC_H
#include "tree.h"
#include "branch.h"
using namespace std;


const string commandlist[6]={"ls","cd","mkdir","touch","rm","quit"};


void display(tree& shell);
bool include(string str);
void printdefault(tree& shell);
void parseargument(tree& shell,string com,string arg);
void startprogram(){
    branch* root = new branch("root",NULL);
    tree shell(root);
display(shell);
}

void display(tree& shell){
        printdefault(shell);
        string command;
        cin>>command;
         if(!include(command)){
             cout<< "INVALID COMMAND"<<endl;
            display(shell);
         }
        if(command=="ls"){shell.ls(); display(shell);}
        if(command=="quit"){exit(0);}
        else{
            string argument;
            cin>>argument;
            parseargument(shell,command,argument);
        }
        display(shell);
}
bool include(string str){
    for(int i=0;i<6;i++){
        if(commandlist[i]==str)return true;
    }
    return false;
}
void parseargument(tree& shell,string com,string arg){
    if(com=="touch"){shell.touch(arg);}
    if(com=="mkdir"){shell.mkdir(arg);}
    if(com=="rm"){shell.rm(arg);}
    if(com=="cd"){shell.cd(arg);}

}
void printdefault(tree& shell){
    cout<<shell.current->pwd();
    cout<<": ";
}
#endif
