//g++ -o allocator.exe allocator_OLin.cpp 
//./allocator.exe 1048576
#include <iostream>
using namespace std;

int main(int argc,char* argv[]){
    string command;         //String Command for user input
    int f=0;                //Int f for the while loop
    int S=atoi(argv[1]);    //Read the amount of memory needed
    int mem[S];     //Create the memory space
    for(int x=0;x<S;x++){ //Set all values in the array to -1
        mem[x]=-1;
    }
    while(f==0){        //Program only ends when QUIT is inputed
        int m, p;
        string c;
        cout << "allocator> ";  //Print out allocator to start
        getline(cin, command);  //Read the whole line of the input
        if(command=="QUIT"){    //If command is QUIT exit the progeam
            exit(0);
        }
        if(command=="STAT"){    //Command STAT to print out data
            int t=mem[0], start=0, end;
            for(int u=0;u<S;u++){   //Going through the array
                if(mem[u]!=t){  //Finding process
                    cout << "Addresses [" << start << " : " ;
                    end=u-1;    //Change the end time -1
                    cout << end << "] " ;
                    if(t==-1){  //Check if the process is not in that space
                        cout << "Free" << endl;
                    }else{
                        cout << "Process P" << t << endl;
                    }
                    t=mem[u];   //Next space process
                    start=u;    //Reset start time
                }
            }
            if(mem[S-1]==-1){   //Check if the last process is not at the end
                end=S-1;    //Set end time
                cout << "Addresses [" << start << " : " << end << "] " << "Free" << endl;
            }
        }
        if(command=="C"){   //Command C to compact the empty spaces
            int h=0;    //Set a tracker
            for(int z=0;z<S;z++){   //Going through the array
                if(mem[z]!=-1){  //Finding process
                    mem[h]=mem[z];
                    h++;
                }
            }
            for(int q=h;q<S;q++){   //Fill in space with -1
                mem[q]=-1;
            }
        }
        if(command.length()>=5){    //Check if the command was already done
            c = command.substr(0,2);    //Get the command
            if(command.length()==5){    //Check to see if the command is RQ or RL
                p = stoi(command.substr(4,1)); //Get the char from string and convert it to int
            }else{
                p = stoi(command.substr(4,1)); //Get the char from string and convert it to int
                m = stoi((command.substr(6,6)));    //Get the amount of memory for the process
            }
        }
        if(c=="RQ"){    //Command RQ to request memory space in the array mem[s]=p;
            int temp, at=mem[0], s=0;
            while(s<S){         //Loop to fo through the array
                if(mem[s]!=-1){ //Check if the slot is and process
                    s++;
                }
                if(mem[s]==-1){ //Check if it is empty. and dont really need this if statement
                    at=s;
                    temp=m;
                    for(int q=at;q<S;q++){  //Check if the mempry space is enough
                        if(temp!=0 && mem[q]!=-1){  //Not enough
                            s=q;
                            q=S;
                        }
                        temp--;
                        if(temp==0){    //Enough
                            q=S;
                            s=S;
                        }
                    }
                }
            }
            for(int l=at;l<S;l++){   //Going through the array to place th eprocess in
                if(mem[l]==-1 && m!=0){ //Checking for the right spot to put the process
                    mem[l]=p;
                    m--;
                }
            }
        }
        if(c=="RL"){    //Command RL to release the process from memory
            for(int r=0;r<S;r++){   //Going through the array to find the process
                if(mem[r]==p){  //Removing th eprocess from the arrray
                    mem[r]=-1;
                }
            }
        }
    }
}
