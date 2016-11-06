#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class String_Operation {
    
private:

   string prev,current, lastcommand;
   int last_executed, numberofcommands=0;
   int record[1000]={0};
   
   void print_result(string current){
       cout<<"Edited String: "<<current<<endl;
   }
      
public:
    
    String_Operation(){
        current = "";
        prev = current;
    }
    
    void add_string(){
        string addstr;
        cout<<"Enter the String to be added: ";
        getline(cin,addstr);
        
        current = current + addstr;
        prev = current;
        
        last_executed = 1;
        lastcommand = "add_string";
        record[numberofcommands++]=1;
        print_result(current); 
    }
        
    void find_pattern_in_string(){
        string pattern;
        cout<<"Enter the pattern to be searched: ";
        getline(cin, pattern);
        size_t position= current.find(pattern);
        if(position != -1)
     	    cout<<"Pattern found at position: "<<position<<endl;
        else
    	   cout<<"Pattern not found !"<<endl;
    	last_executed =2;  
    	lastcommand = "find_pattern_in_string";
    	
    	record[numberofcommands++]=2;

    }
        
    void reverse_string(){
        prev = current;
        int len = current.size();
        char temp;
        int i=0, j=len-1;
        while(i<j)
            {
            temp = current[i];
            current[i] = current[j];
            current[j] = temp;
            i++;
            j--;
        }
        last_executed =3;
        lastcommand = "reverse_string";
        
        print_result(current);
        record[numberofcommands++]=3;  
    } 
    
    void remove_blank(){
         prev = current;
         int len = current.size();
         int i = 0, j = 0,count=0;
         while (current[i])
         {
            if (current[i] != ' '){
            current[j++] = current[i];
            }
            else{
            count++;
            }
         i++; 
         }
        for(j=1; j<=count; j++){
        current[len-j]= ' ';
       }
       
       last_executed = 4;
       lastcommand = "remove_blank";
       
       print_result(current);
       record[numberofcommands++]=4;
    }
    
    void find_number_of_digits(){
        int count=0,i; 
        for(i=0;i<current.size();i++)
        if(isdigit(current[i])) count++;
        cout<<"Number of digits:"<<count<<endl;  
        lastcommand = "find_number_of_digits";
        last_executed = 5;
        record[numberofcommands++]=5;
    }
    
    void remove_vowels(){
        prev = current;
        int len,i,j;
        len=current.length();
	    for(i=0; i<len; i++){
	       	if(current[i]=='a' || current[i]=='e' || current[i]=='i' ||
	       	current[i]=='o' || current[i]=='u' || current[i]=='A' ||
	       	current[i]=='E' || current[i]=='I' || current[i]=='O' ||
	       	current[i]=='U')
		    {
		      	for(j=i; j<len; j++)
		      	{
			      	current[j]=current[j+1];
			    }
		        len--;
		    }
	   }
	  
        print_result(current);
        last_executed = 6;
        lastcommand = "remove_vowels";
        record[numberofcommands++]=6;
    }
    
    void undo(){
        current = prev;
        last_executed = 7;
        print_result(current);
        lastcommand = "undo";
        record[numberofcommands++]=7;
        
    }
   void redo(String_Operation* ss){

           if(last_executed == 1){
               ss->add_string();
				 }
			   else if(last_executed == 2){
				   ss->find_pattern_in_string();
				   }
				   else if(last_executed == 3){
					    ss->reverse_string();
						 }
					     else if(last_executed == 4){
							 ss->remove_blank();
							 }
						     else if(last_executed == 5){
						       ss->find_number_of_digits();
							      }
							      else if(last_executed == 6){
							          ss->remove_vowels();
								     }
								     else if(last_executed == 7){
								        ss->undo();
									     }
									     else if(last_executed == 9){
									         ss->number();
										     }
										     else if(last_executed == 10){
											      ss->last();
												  }
												  else if(last_executed == 11){
												        ss->nlast();
												     }
        last_executed = 8;
        record[numberofcommands++]=8;
        lastcommand = "redo";
    }
    void number(){
        last_executed = 9;
       
        lastcommand = "number";
        cout<<"Total no. of commands in our Editor = "<< 11<<endl;
        cout<<"Total no. of commands in executed till now = "<<numberofcommands<<endl;
        record[numberofcommands++]=9;
 }
    void last(){
        last_executed = 10;
        cout<<"Last command used was : "<< lastcommand<<endl;
        lastcommand = "last";
       
        record[numberofcommands++]=10;
        }
        
   void nlast(){
        string temp;
        int element,i;
        lastcommand = "nlast";
        last_executed = 11;
        
        cout<<"Enter to know what was the nth last command used: ";
        getline(cin, temp);         
        stringstream(temp) >> i;
        element = numberofcommands-i;
        
        if(record[element] == 1){
             cout<<"The command was : add_string "<<endl;
             }
              else if(record[element] == 2){
                 cout<<"The command was : find_pattern_in_string "<<endl;
                 }
                 else if(record[element] == 3){
                    cout<<"The command was : reverse_string "<<endl;
                    }
                    else if(record[element] == 4){
                         cout<<"The command was : remove_blank "<<endl;
                          }
                          else if(record[element] == 5){
                              cout<<"The command was : find_number_of_digits "<<endl;
                              }
                               else if(record[element] == 6){
                                    cout<<"The command was : remove_vowels "<<endl;
                                     }
                                  else if(record[element] == 7){
                                       cout<<"The command was : undo "<<endl;
                                       }
                                         else if(record[element] == 8){
                                              cout<<"The command was : redo "<<endl;
                                              } 
                                              else if(record[element] == 9){
                                                cout<<"The command was : number "<<endl;
                                                  }
                                                   else if(record[element] == 10){
                                                      cout<<"The command was : last "<<endl;
                                                      }
                                                     else if(record[element] == 11){
                                                         cout<<"The command was : nlast "<<endl;
                                                         }
        record[numberofcommands++]=11;
       }
};



int main () {

string mystr;
int command;

cout <<"1. add string"<< endl<< "2. find pattern in string"<< endl<<"3. reverse string"<< endl<< "4. remove blank from string"<< endl<<"5. find number of digits in string"<< endl<<"6. remove vowels from string"<< endl<<"7. undo - should undo the last command"<< endl<<"8. redo - should repeat the last command"<< endl<<"9. number - find number of commands"<< endl<<"10. last - what was last command used"<< endl<<"11. nlast - what was nth last command used"<<endl<< "Press 0 to exit"<<endl; 
    
    
String_Operation ss;

getline(cin,mystr);         
stringstream(mystr) >> command;
    
while(command!=0) {

switch (command)
{
    
case 1:
    ss.add_string();   
	break;
    
case 2:
    ss.find_pattern_in_string();
	break;
    
case 3:
     ss.reverse_string();
     break;
    
case 4:
    ss.remove_blank();
   	break;
    
case 5:
    ss.find_number_of_digits();
	break;
    
case 6:
    ss.remove_vowels();
	break;
    
case 7:
    ss.undo();
	break;
    
case 8:
    ss.redo(&ss);
	break;
    
case 9:
    ss.number();
	break;
    
case 10:
    ss.last();
	break;
    
case 11:
    ss.nlast();
	break; 
    
default:
	cout<<"Incorrect Choice !!!  "<<endl<<"Please enter a correct choice. "<<endl;
	break;
}
getline(cin,mystr);         
stringstream(mystr) >> command;
}
return 0;
}



