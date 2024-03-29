#include<iostream>
#include<string>
#include<filesystem>
#include<stdexcept>

namespace f = std::filesystem;
//navigating directories
void changedir(std::string &dirpath){
    try{
    f::current_path(dirpath);
    std::cout<<"Directory changed to: "<<f::current_path()<<std::endl;
    }
    catch(std::exception &err){
        std::cout<<"Error! "<<err.what()<<std::endl;
    }
}
//create dir or file
void makedir(std::string &dir){
    try{
       f::create_directory(dir);
       std::cout<<"Directory created successfully!"<<std::endl;
    }
    catch(std::exception &err){
        std::cout<<"Error! "<<err.what()<<std::endl;
    }
}
//view files
void viewfiles(std::string& dirpath){
    try{
    std::cout<<"Files in: "<<dirpath<<std::endl;
    for(auto file: f::directory_iterator(dirpath)){
        std::cout<<file.path().filename()<<std::endl;
    }
    }
    catch(std::exception &err){
        std::cout<<"Error! "<<err.what()<<std::endl;
    }
}
//delete file
void dlt(std::string &dltpath){
    try{
        f::remove(dltpath);
        std::cout<<"File deleted!"<<std::endl;
    }
    catch(std::exception &er){
        std::cout<<"Error! "<<er.what()<<std::endl;
    }
}
//copy file
void copy(std::string &src, std::string &dest){
    try{
    f::copy_file(src,dest);
    std::cout<<"File copied to "<<dest<<std::endl;
    }
    catch(std::exception &e){
        std::cout<<"Error! "<<e.what()<<std::endl;
    }
}
//move file
void move(std::string &oldp, std::string &newp){
    try{
        f::rename(oldp,newp);
        std::cout<<"File moved to: "<<newp<<std::endl;
    }
    catch(std::exception &ex){
        std::cout<<"Error! "<<ex.what()<<std::endl;
    }
}

int main(){
    std::string path;
    std::string cmd;
    std::string destination;

    while(true){
    std::cout<<"Enter command (list, cd, mkdir, cpy, move, create, dlt) or 0 to exit: "<<std::endl;
    std::cin>>cmd;
    if(cmd == "0"){
        break;
    }
    else if(cmd == "list"){
    std::cout<<"\nEnter path to view files for: ";
    std::cin>>path;
    viewfiles(path);
    }
    else if(cmd == "cd"){
        std::cout<<"Enter path of directory you want to change to: ";
        std::cin>>path;
        changedir(path);
    }
    else if(cmd == "mkdir" || cmd == "create"){
        std::cout<<"Enter path of file or directory you want to create: ";
        std::cin>>path;
        makedir(path);
    }
    else if(cmd == "cpy"){
        std::cout<<"Enter file path you want to copy: ";
        std::cin>>path;
        std::cout<<"Enter file path you want to paste in: ";
        std::cin>>destination;
        copy(path, destination);
    }
    else if(cmd == "move"){
        std::cout<<"Enter path of file you want to move: ";
        std::cin>>path;
        std::cout<<"Enter path you want to move to: ";
        std::cin>>destination;
        move(path,destination);
    }
    else if(cmd == "dlt"){
        std::cout<<"Enter path of file you want to delete: ";
        std::cin>>path;
        dlt(path);
    }
    else{
        std::cout<<"Invalid Command!"<<std::endl;
    }
    }

}   