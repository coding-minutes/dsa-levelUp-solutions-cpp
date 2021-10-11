#include<vector>
#include<string>
#include<sstream>
using namespace std;


string simplifyPath(string path){
    istringstream iss(path);
	
	string token;
	vector<string> tokens;
	bool rootdir = path[0]=='/';
	
	while(getline(iss,token,'/')){
		if(token!="." and token!=""){
			tokens.push_back(token);
		}
	}

 
    //--------------------//
	vector<string> stack;
	
	if(path[0]=='/'){
			stack.push_back("");
	}
	
	for(string token:tokens){
		if(token==".."){
			//pop back prev
			if(stack.size()==0 or stack[stack.size()-1]==".."){
				stack.push_back(token);
			}
			// checkingthis condition, pop back previous except root '/' when current is '.'
			else if(stack[stack.size()-1]!=""){
				stack.pop_back();
			}
		}
		else{
			stack.push_back(token);
		}
	}
	
	//corner case
	if(stack.size()==1 and stack[0]==""){
		return "/";
	}
	
	//otherwise construct the string
	ostringstream oss;
	int i = 0;
	for(auto token : stack){
		
		if(i!=0){
			oss<<"/";
		}
		
		i++;
		oss << token;
	}
	
	return oss.str();
}