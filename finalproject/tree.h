#ifndef tree_h
#define tree_h
#include "branch.h"
using namespace std;
class tree{
    public:
    branch* root;
    branch* current;
    tree(branch* root):root(root),current(root){};
void cd( std::string filename){
    if(filename==".." && current!=root){
        current=current->getParent();
        return;
    }
    if(filename== "."){
        return;
    }

    if(current->indexof(filename)!=-1){
        current=current->getFolders()[current->indexof(filename)]; 
    }else{
        cout<<"destination not found"<<endl;
    }
}
void mkdir(std::string foldername){
    current->addfolder(foldername);
}
void ls(){
    current->ls();
}
void touch(std::string filename){
    current->addfile(filename);
}
void pwd(){
    current->pwd();
}
void rm(std::string filename){
    if(current->indexof(filename)!=-1){
        if(current->getFolders()[current->indexof(filename)]->isEmpty()) 
        {current->rm(filename);}
        else{
            cout<<"this folder is not empty or does not exist"<<endl;
        }
    }
    
}
};

#endif
