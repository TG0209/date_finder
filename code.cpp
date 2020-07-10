#include<iostream>
#include<iterator>
#include<map>
#include<vector>
#include<bits/stdc++.h> 

using namespace std;

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 

bool check(int year)  
{  
  
    if (year % 400 == 0)  
        return true;  
  
    
    if (year % 100 == 0)  
        return false;  
  
  
    if (year % 4 == 0)  
        return true;  
    return false;  
}  
  

int countLeapYears(int y, int m) 
{ 
    int years = y; 

    if (m <= 2) 
        years--; 
  
 
    return years / 4 - years / 100 + years / 400; 
} 
  
 
int getDifference(int d1,int d2, int m1, int m2, int y1, int y2) 
{ 
   
    long int n1 = y1*365 + d1; 
  
    for (int i=0; i<m1 - 1; i++) 
        n1 += monthDays[i]; 
  
    n1 += countLeapYears(y1,m1); 
  
   
  
    long int n2 = y2*365 + d2; 
    for (int i=0; i<m2 - 1; i++) 
        n2 += monthDays[i]; 
    n2 += countLeapYears(y2,m2); 
  
    
    return (n2 - n1); 
} 
  

bool sort_sec(const pair<string,int> &a,const pair<string,int> &b) 
{ 
    return (a.second < b.second); 
} 
  

void missing_dates(vector< pair <string,int> > &v){


	int n = v.size();
	
	for(int i=0;i<n-1;i++){ 

  			int d1 = ((int)v[i].first[8]-'0')*10 + (int)v[i].first[9]-'0';
  			int d2 = ((int)v[i+1].first[8]-'0')*10 + (int)v[i+1].first[9]-'0';
  			int m1 = ((int)v[i].first[5]-'0')*10 + (int)v[i].first[6]-'0';
  			int m2 = ((int)v[i+1].first[5]-'0')*10 + (int)v[i+1].first[6]-'0';
  			int y1 = ((int)v[i].first[0]-'0')*1000 + ((int)v[i].first[1]-'0')*100 + ((int)v[i].first[2]-'0')*10 + ((int)v[i].first[3]-'0') ;
  			int y2 = ((int)v[i+1].first[0]-'0')*1000 + ((int)v[i+1].first[1]-'0')*100 + ((int)v[i+1].first[2]-'0')*10 + ((int)v[i+1].first[3]-'0') ;
  			
  			int days = getDifference(d1,d2,m1,m2,y1,y2);
  			int vl=v[i].second;
  			
 			if(days>1){

				int d = (v[i+1].second - v[i].second )/days;

 				d1++;
 			
 				while(y1!=y2 || m1!=m2 || d1!=d2){
 					cout<<d1<<" "<<m1<<" "<<y1<<endl;
 					
 					if(y1!=y2){

 						if(m1==12 && d1==31){
 							string r;
		 					r += to_string(y1);
		 					r +="-";
		 					r += to_string(m1);
		 					r +="-";
		 					if(d1/10==0)
		 						r+="0";
		 					r += to_string(d1);
		 					vl = vl+d ;
		 					v.push_back( make_pair(r,vl));
 							y1++;
 							m1=1;
 							d1=1;

 				
 						}
 					}
 					if(m1!=m2 || y1!=y2){
 						if(m1>7 && m1%2==0 && d1==31){
 							
 							string r;
		 					r += to_string(y1);
		 					r +="-";
		 					r += to_string(m1);
		 					r +="-";
		 					if(d1/10==0)
		 						r+="0";
		 					r += to_string(d1);
		 					vl = vl+d ;
		 					v.push_back(make_pair(r,vl));
 							d1=1;
 							if(m1>=12)
 								m1=1;
 							else
 								m1++;

 						}
 						else if(m1>7 && m1%2!=0 && d1==30){
 							string r;
		 					r += to_string(y1);
		 					r +="-";
		 					r += to_string(m1);
		 					r +="-";
		 					if(d1/10==0)
		 						r+="0";
		 					r += to_string(d1);
		 					vl = vl+d ;
		 					v.push_back(make_pair(r,vl));
 							d1=1;
 							if(m1>=12)
 								m1=1;
 							else
 								m1++;
 						}
 						else if(m1%2!=0 && m1<=7 && d1==31){
 							
 							string r;
		 					r += to_string(y1);
		 					r +="-";
		 					r += to_string(m1);
		 					r +="-";
		 					if(d1/10==0)
		 						r+="0";
		 					r += to_string(d1);
		 					vl = vl+d ;
		 					v.push_back(make_pair(r,vl));
 							d1=1;
 							if(m1>=12)
 								m1=1;
 							else
 								m1++;
 						}
 						else if(m1%2==0 && m1<=7 && d1==30){
 							string r;
		 					r += to_string(y1);
		 					r +="-";
		 					r += to_string(m1);
		 					r +="-";
		 					if(d1/10==0)
		 						r+="0";
		 					r += to_string(d1);
		 					vl = vl+d ;
		 					v.push_back( make_pair(r,vl));
 							d1=1;
 							m1++;
 						}
 						else if(m1==2 && check(y1) && d1==29){
 							string r;
		 					r += to_string(y1);
		 					r +="-";
		 					r += to_string(m1);
		 					r +="-";
		 					if(d1/10==0)
		 						r+="0";
		 					r += to_string(d1);
		 					vl = vl+d ;
		 					v.push_back( make_pair(r,vl));
 							d1=1;
 							m1++;
 						}
 						else if(m1==2  && d1==28){
 							string r;
		 					r += to_string(y1);
		 					r +="-";
		 					r += to_string(m1);
		 					r +="-";
		 					if(d1/10==0)
		 						r+="0";
		 					r += to_string(d1);
		 					vl = vl+d ;
		 					v.push_back( make_pair(r,vl));
 							d1=1;
 							m1++;
 						}
 					}

 					if(y1==y2 && m1==m2 && d1==d2)
 						break;
 					string r;
 					r += to_string(y1);
 					r +="-";
 					r += to_string(m1);
 					r +="-";
 					if(d1/10==0)
		 				r+="0";
 					r += to_string(d1);
 					vl = vl+d ;
 					v.push_back( make_pair(r,vl));
 					d1++;
 					
 					
 			}

  			
	    } 

	}
}


int main(){

	 vector< pair <string,int> > vect;

	while(1){

		cout<<"enter the dictionary"<<endl;
		cout<<"To add key value pair press 1"<<endl;
		cout<<"to quit press -1"<<endl;
		int x;
		cin>>x;
		if(x==-1)
			break;
		else{
			string key;
			int val;
			cout<<"enter key"<<endl;
			cin>>key;
			cout<<"enter key value"<<endl;
			cin>>val;
			vect.push_back( make_pair(key,val));
			
		}

	}
	
	missing_dates(vect);
	sort(vect.begin(),vect.end(),sort_sec);
	for(int i=0;i<vect.size();i++){
		cout<<vect[i].first<<" : "<<vect[i].second<<endl;
	}
	

}