#include <iostream>
#include <string>

using namespace std;

int main()
{
    string alphabet,secret_alphabet,selection;
    
    alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; 
    secret_alphabet="xusfbojcdkrywvqitgelhpmanzPKHMXZSDLNGBYTCIOQUWFAVERJ"; 


    
    cout<<"**********************************************\n";
    cout<<"Select, what you want\n1.Normal to Secret\n2.Secret to Normal\nQ.Quit the program\n";
    cout<<"**********************************************\n";
    
    
    while(true){
        
        cout<<"\n------------------------------------";
        cout<<"\nWhich one : ";
        cin>>selection;
        if(selection=="q" || selection=="Q"){
            
            cout<<"See you later...\n";
            break;
            
            }
            
        else if(selection=="1"){
            
            string sentence;
            cout<<"Enter your normal sentence : ";
            cin.ignore();
            getline(cin,sentence);
            cout<<"Your secret sentence : ";
            
            for(char i : sentence ){
                
                if(isalpha(i)){
                    
                    int a;
                    a=alphabet.find(i);
                    cout<<secret_alphabet[a];
                    
                    }
                else
                    cout<<" ";

                }
            }
        else if(selection=="2"){
            
            string sentence;
            cout<<"Enter your secret sentence : ";
            cin.ignore();
            getline(cin,sentence);
            cout<<"Your normal sentence : ";
            
            for(char i : sentence ){
                
                if(isalpha(i)){
                    
                    int a;
                    a=secret_alphabet.find(i);
                    cout<<alphabet[a];
                    
                    }
                else
                    cout<<" ";

                }
            }
            
            
        else
            cout<<"no match found, Please enter a correct value\n";
        
        
        }
    
	return 0;
}

