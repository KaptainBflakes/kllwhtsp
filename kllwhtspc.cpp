#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
//removes whitespace from a file. Be careful to not use this with paths that contain directories that have whitespace.
using namespace std;
using namespace std::filesystem;
int main(int argc,char**argv){
	fstream f;f.open(argv[1]);
	vector<string> worklist;
	if(f.good()){//loads worklist file to memory
		char c;string out="";
		while(f.get(c)){
			if(c=='\n'){worklist.push_back(out);out="";}
			else{out+=c;}
		}
	}
	for(int i=0;i<worklist.size();i++){
		string out;
		for(int c=0;c<worklist[i].size();c++){
			if(worklist[i][c]!=' '){
				out+=worklist[i][c];
			}
		}
		try{
			rename(worklist[i], out);
		}catch(...){
			cout<<"Path at line \""<<to_string(i)<<"failed to rename.\n";
		}
	}
}