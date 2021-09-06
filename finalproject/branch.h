#ifndef branch_h
#define branch_h
#include "string"
#include "iostream"
#include "sstream"
#include "vector.h"
#include <stdio.h>
class branch{
    private:
    branch* parent;
    fileVector<branch*> folders;
    fileVector<branch*> files;
    
    public:
    std::string name;
    branch():name(),parent(),folders(),files(){}
    branch(std::string name):name(name),parent(),folders(),files(){}
    branch(std::string name,branch* parent):name(name),parent(parent),folders(),files(){}
    fileVector<branch*> getFolders(){
        return folders;
    }
    fileVector<branch*> getFiles(){
        return files;
    }
    fileVector<branch*> getContent(){
        fileVector<branch*> tmp=this->getFolders();
        if(files.length()==0 && folders.length()==0){std::cout<<"directory empty"; return tmp;}
        
        for(int i =0;i<files.length();i++){
            tmp.push(files[i]);
        }
        return tmp;
    }
    branch* getParent(){
        return parent;
    }
    bool isEmpty(){
        if(files.length()==0 && folders.length()==0)return true;
        return false;
    }
    void setParent(branch* parent){
        this->parent=parent;
    }
    int indexof(std::string filename){
        for(int i = 0; i < files.length();i++){
            if(files[i]->name==filename){
                return i;
            }
        }
        for(int i = 0; i < folders.length();i++){
            if(folders[i]->name==filename){
                return i;
            }
        }
        return -1; // if indexof return -1, then the vector does not contain the element searched
    }
    void addfile(std::string filename){
        int contain=indexof(filename);
        if(contain!=-1){
            std::cout<<"FILE NAME ALREADY EXIST YOU BANANA TRY LS FIRST!"<<std::endl;
            return;
        }
        branch* newfile=new branch(filename);
        newfile->setParent(this);
        
        files.push(newfile);
    }
    void addfolder(std::string filename){
        int contain=indexof(filename);
        if(contain!=-1){
            std::cout<<"FOLDER NAME ALREADY EXIST YOU BANANA TRY LS FIRST!"<<std::endl;
            return;
        }
        branch* newfile=new branch(filename);
        newfile->setParent(this);
        folders.push(newfile);
    }
    void addfile(branch* file){
        int contain=indexof(file->name);
        if(contain!=-1){
            std::cout<<"FILE NAME ALREADY EXIST YOU BANANA TRY LS FIRST!"<<std::endl;
            return;
        }
        files.push(file);
    }
    void addfolder(branch* folder){
        int contain=indexof(folder->name);
        if(contain!=-1){
            std::cout<<"FOLDER NAME ALREADY EXIST YOU BANANA TRY LS FIRST!"<<std::endl;
            return;
        }
        folders.push(folder);
    }
    std::string pwd(){
        std::string out;
        branch* tmp=this;
        while(tmp->getParent()!=NULL){
            out=tmp->name+"/"+out;
            tmp=tmp->getParent();
        }
        return "root/"+out;
    }
    void rm(std::string fn){
        for(int i = 0; i < files.length();i++){
            if(files[i]->name==fn){
                files.remove(i);
                return;
            }
        }
        for(int i = 0; i < folders.length();i++){
            if(folders[i]->name==fn){
                folders.remove(i);
                return;
            }
        }
    }
    void changefileName(std::string oldname,std::string newname){
        int contain=indexof(newname);
         if(contain==-1){
             std::cout<<"FILE IS NOT IN THIS, TRY LS FIRST"<<std::endl;
            return;
         }
         files[contain]->name=newname;
    }
    void changefolderName(std::string oldname,std::string newname){
        int contain=indexof(newname);
         if(contain==-1){
             std::cout<<"FOLDER IS NOT IN THIS, TRY LS FIRST"<<std::endl;
            return;
         }
         files[contain]->name=newname;
    }
    void ls(){
        
        fileVector<branch*> tmp=getContent();
        for(int i=0;i<tmp.length();i++){
            if(i<folders.length()){
                std::cout<<"\x1B[34m"<<tmp[i]->name<<"\033[0m"<< "  "; //ayy colors
            }else{
                 std::cout<<tmp[i]->name<<"  ";
            }  
        }
        std::cout<<std::endl;
    }





};
#endif