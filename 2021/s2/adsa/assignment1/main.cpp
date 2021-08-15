#include <string>
#include <vector>
using namespace std;
#include <iostream>
//this function is used to make two input same size
//for example 100 and 4 will become 100 and 004 so the for loop in other function can run successful
void samesize(string &s1,string &s2){
    int n;
    if(s1.size()>s2.size()){
        n =s1.size()-s2.size();
        for(int i=0;i<n;i++){
            s2="0"+s2;
        }
    }
    if(s1.size()<s2.size()){
        n =s2.size()-s1.size();
        for(int i=0;i<n;i++){
            s1="0"+s1;
        }
    }
}

//add
string add(string a, string b, int c){
    samesize(a,b);  //make input a b same size
    string out="";
    int carry=0;
    int size=a.size();
    
    for(int i=size-1;i>=0;i--){
        int n1;
        int n2;
        if(a[i]!='0'){
            n1=int(a[i]-'0');
        }else{
            n1=0;
        }
        
        if(b[i]!='0'){
            n2=int(b[i]-'0');
        }else{
            n2=0;
        }
        
        if(carry==1){
            carry=0;
            if(n1+n2+1>=c){
                carry=1;
                out=to_string(n1+n2+1-c)+out;
            }else{
                out=to_string(n1+n2+1)+out;
            }
        }else{
            if(n1+n2>=c){
                carry=1;

                out=to_string(n1+n2-c)+out;
            }else{

                out=to_string(n1+n2)+out;
            }
        }
    }
    if(carry==1){
        out="1"+out;
    }

    return out;
}

//subtraction
string sub(string a, string b, int c){
    samesize(a,b);  //make input a b same size
    string out="";
    int carry=0;
    int size=a.size();
    
    for(int i=size-1;i>=0;i--){
        int n1;
        int n2;
        if(a[i]!='0'){
            n1=int(a[i]-'0');
        }else{
            n1=0;
        }
        
        if(b[i]!='0'){
            n2=int(b[i]-'0');
        }else{
            n2=0;
        }
        
        if(carry==1){
            carry=0;
            if(n1-n2-1<0){
                carry=1;
 
                out=to_string(n1+c-n2-1)+out;
            }else{

                out=to_string(n1-n2-1)+out;
            }
        }else{
            if(n1-n2<0){
                carry=1;

                out=to_string(c+n1-n2)+out;
            }else{

                out=to_string(n1-n2)+out;
            }
        }
    }
    return out;
}

//make shifting
string shift(string str, int num)
{
    for (int i = 0 ; i < num ; i++)
        str = str + '0';
    return str;
}

//multiply
string mul(string a, string b,int c){
    samesize(a,b);
    int n=a.size();
    //1 digit mul
    if(n==1){
        int n1=stoi(a);
        int n2=stoi(b);
        int o = n1*n2;
        if(o>c){
            o= o%c+10*(o/c);
        }else if(o==c){
            o=10;
        }
        
        return to_string(o);
    }
    
    int fh = n/2;
    int sh = (n-fh);
    //first part
    string a0 = a.substr(0, fh);
    string a1 = a.substr(fh, sh);
    //second part
    string b0 = b.substr(0, fh);
    string b1 = b.substr(fh, sh);

    string P1 = mul(a0, b0,c);
    string P2 = mul(a1, b1,c);
    string P3 = mul(add(a0, a1,c), add(b0, b1,c),c);
    return add(add(shift(P1, 2*(n-n/2)),P2,c),shift(sub(P3,add(P1,P2,c),c), n-(n/2)),c);
}
//delete the front 0
string del0(string str){
    while(str[0]=='0'){
        if(str[0]=='0'){
            str=str.substr(1, str.size()-1);

            //cout<<str<<endl;
        }
    }

    return str;
}

int main(){
    string s1, s2;
    int b;
    cin>>s1>>s2>>b;
    
    string o1=add(s1,s2,b);
    string o3=mul(s1,s2,b);
    o3 = del0(o3);
    cout<<o1<<" "<<o3<<endl;
    
    return 0;
}
