#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

vector<int> alwaysTaken(vector<string> b){
	int sum = 0;
	int total = 0;
	for(int i = 0 ; i < b.size() ; i++){
		if(b[i]=="T"){
			sum++;
		}
		total++;
	}
	vector<int> ret;
	ret.push_back(sum);
	ret.push_back(total);
	return ret;	
};

vector<int> alwaysNotTaken(vector<string> b){
	int sum = 0;
	int total = 0;
	for(int i = 0 ; i < b.size() ; i++){
		if(b[i]=="NT"){
			sum++;
		}
		total++;
	}
	vector<int> ret;
	ret.push_back(sum);
	ret.push_back(total);
	return ret;	
};

vector<int> biModelSingle(vector<unsigned long long> a, vector<string> b){
	vector<int> ret;
	unsigned long long addr;
  	string behavior;
	unsigned long long target;
	vector<string> sixteenbit;
	sixteenbit.resize(16);
	vector<string> thirtytwobit;
	thirtytwobit.resize(32);
	vector<string> onetwoeightbit;
	onetwoeightbit.resize(128);
	vector<string> twofivesixbit;
	twofivesixbit.resize(256);
	vector<string> fivetwelvebit;
	fivetwelvebit.resize(512);
	vector<string> ten24bit;
	ten24bit.resize(1024);
	vector<string> twenty48bit;
	twenty48bit.resize(2048);
	for(int i = 0 ; i < 2048 ; i++){
		if(i < sixteenbit.size()){
			sixteenbit[i]="T";
		}
		if(i < thirtytwobit.size()){
			thirtytwobit[i]="T";
		}
		if(i < onetwoeightbit.size()){
			onetwoeightbit[i]="T";	
		}
		if(i < twofivesixbit.size()){
			twofivesixbit[i]="T";
		}
		if(i < fivetwelvebit.size()){
			fivetwelvebit[i]="T";
		}
		if(i < ten24bit.size()){
			ten24bit[i]="T";	
		}
		if(i < twenty48bit.size()){
			twenty48bit[i]="T";
		}
	}
	int sum16 = 0;
	int total16 = 0;
	for(int i = 0 ; i < a.size() ; i++){
		int index16bit = a[i]%16;
		if(sixteenbit[index16bit]==b[i]){
			sum16++;
		}
		else{
			if(b[i]=="T"){
				sixteenbit[index16bit]="T";
			}
			else{
				sixteenbit[index16bit]="NT";
			}
		}
		total16++;
	}
	ret.push_back(sum16);
	ret.push_back(a.size());
	long sum32 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index32bit = a[i]%32;
		if(thirtytwobit[index32bit]==b[i]){
			sum32++;
		}
		else{
			if(b[i]=="T"){
				thirtytwobit[index32bit]="T";
			}
			else{
				thirtytwobit[index32bit]="NT";
			}
		}
	}
	ret.push_back(sum32);
	ret.push_back(a.size());
	long sum128 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index128bit = a[i]%128;
		if(onetwoeightbit[index128bit]==b[i]){
			sum128++;
		}
		else{
			if(b[i]=="T"){
				onetwoeightbit[index128bit]="T";
			}
			else{
				onetwoeightbit[index128bit]="NT";
			}
		}
	}
	ret.push_back(sum128);
	ret.push_back(a.size());
	long sum256 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index256bit = a[i]%256;
		if(twofivesixbit[index256bit]==b[i]){
			sum256++;
		}
		else{
			if(b[i]=="T"){
				twofivesixbit[index256bit]="T";
			}
			else{
				twofivesixbit[index256bit]="NT";
			}
		}
	}
	ret.push_back(sum256);
	ret.push_back(a.size());
	long sum512 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index512bit = a[i]%512;
		if(fivetwelvebit[index512bit]==b[i]){
			sum512++;
		}
		else{
			if(b[i]=="T"){
				fivetwelvebit[index512bit]="T";
			}
			else{
				fivetwelvebit[index512bit]="NT";
			}
		}
	}
	ret.push_back(sum512);
	ret.push_back(a.size());
	long sum1024 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index1024bit = a[i]%1024;
		if(ten24bit[index1024bit]==b[i]){
			sum1024++;
		}
		else{
			if(b[i]=="T"){
				ten24bit[index1024bit]="T";
			}
			else{
				ten24bit[index1024bit]="NT";
			}
		}
	}
	ret.push_back(sum1024);
	ret.push_back(a.size());
	long sum2048 = 0;
	//cout << a.size() << endl;
	for(int i = 0 ; i < a.size() ; i++){
		int index2048bit = a[i]%2048;
		if(twenty48bit[index2048bit]==b[i]){
			sum2048++;
		}
		else{
			if(b[i]=="T"){
				twenty48bit[index2048bit]="T";
			}
			else{
				twenty48bit[index2048bit]="NT";
			}
		}
	}
	ret.push_back(sum2048);
	ret.push_back(a.size());
	return ret;
}

int main(int argc, char** argv){
	unsigned long long addr;
	string behavior;
	unsigned long long target;
	vector<unsigned long long> addresses;
	vector<string> behaviors;
	vector<unsigned long long> targets;

  	// Open file for reading
  	ifstream infile("short_trace1.txt");

  	// The following loop will read a hexadecimal number and
  	// a string each time and then output them
  	while(infile >> std::hex >> addr >> behavior >> std::hex >> target) {
    		addresses.push_back(addr);
		behaviors.push_back(behavior);
		targets.push_back(target);
  	}
	vector<int> retval;
	retval = alwaysTaken(behaviors);
	cout << retval[0] << " , " << retval[1] << endl;
	vector<int> retval2;
	retval2 = alwaysNotTaken(behaviors);
	cout << retval2[0] << " , " << retval2[1] << endl;
	vector<int> retval3;
	retval3 = biModelSingle(addresses, behaviors);
	for(int i= 0 ; i < retval3.size() ; i++){
		if(i!=retval3.size()-1){
			cout << retval3[i] << ",";
		}
		else{
			cout << retval3[i];
		}
		if(i%2==1){
			cout << "; ";
		}
	}
	cout << endl;
	infile.close();
}
