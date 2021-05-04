//Simplistic word counting app;

#include <bits/stdc++.h>
using namespace std;

map<string,int> words;
bool comp(pair<int,string> p1, pair<int,string> p2){
	if(p1.first != p2.first) return p1.first > p2.first;
	return p1.second < p2.second;
}

int main() {
	char buffer[200]; int i,j,k,l;
	
	FILE *from = fopen("in.txt","r"), *to = fopen("out.txt","w");
	while(fscanf(from,"%[^\n]\n",buffer)!=EOF){
		i=0; string s;
		while(buffer[i]!='\0'){
			if(buffer[i] >= 'A' && buffer[i] <= 'Z') s.push_back(buffer[i]);
			else if(buffer[i] >= 'a' && buffer[i] <= 'z') s.push_back(buffer[i] - 'a' + 'A'); //convert into uppercase
			else {
				if(s.size() > 0){
					words[s]++;
					s.clear();
				}
			}
			i++;
		}
		
		if(s.size() > 0){
			words[s]++;
			s.clear();
		}
	}
	
	vector<pair<int,string>> freq_words;
	for(auto it = words.begin(); it != words.end(); it++)
		freq_words.push_back(make_pair(it->second,it->first));
	
	sort(freq_words.begin(), freq_words.end(), comp);
	for(i=0;i<freq_words.size();i++){
		string w1 = freq_words[i].second; int cnt = freq_words[i].first;
		j=0;
		while(j < w1.size()){ //Just converting string into char[] to use printf
			buffer[j] = w1[j];
			j++;
		}
		buffer[j] = '\0';
		
		fprintf(to,"%s: Numero de ocorrencias: %d\n",buffer,cnt);
	}
	
	return 0;
}