#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<windows.h>

using namespace std;

void saveCounters(int &counter_p1,int &hit_p1, int &counter_p2, int &hit_p2)
{
    ofstream myfile("counters.txt");
    myfile<<counter_p1<< endl;
    myfile<<hit_p1<< endl;
    myfile<<counter_p2<< endl;
    myfile<<hit_p2<< endl;

    myfile.close();
}

void loadCounters(int &counter_p1,int& hit_p1,int &counter_p2,int& hit_p2)
{
    ifstream myfile("counters.txt");
    myfile>>counter_p1;
    myfile>>hit_p1;
    myfile>>counter_p2;
    myfile>>hit_p2;
    myfile.close();

}

void saveArray(string array[][7],string file_name)
{
    
    ofstream file(file_name);
    
    for(int i=0;i<7;i++)
    {
        for(int j =0;j<7;j++)
        {
            file << array[i][j]<<',';
        }
        
    }
    
    file.close();
    
}

void loadArray(string array[][7],string file_name)
{

    ifstream file(file_name);
    for(int i=0;i<7;i++)
    {
        for(int j =0;j<7;j++)
        {
            getline(file,array[i][j],',');
        }
    }
    file.close();
   
    
}

void cinfail(int& a)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout<<"Invalid input, enter again: ";
        cin>> a;
    }
}

void printArray(string array[][7],string player)
{
    cout<<endl;
    cout<<"Player "<<player<<endl;
    
    for(int i =0;i<7;i++)
    {
        
        for(int j =0;j<7;j++)
        {
            cout<<array[i][j];
        }
        cout<<endl;
    }
    
}

void inputShip(string array[][7],string player)
{
    system("CLS");
    
    
    string v_h;
    int counter=0;
          
    while(counter<3)
    {
   
        system("CLS");
        bool loop=1;
        printArray(array,player); 
        
        if(counter==0)
        {
            cout<<endl<<"Place your Battleship!!"<<endl;
        }
        if(counter==1)
        {
            cout<<endl<<"Place your Aircraft!!"<<endl;
        }
        if(counter ==2)
        {
            cout <<endl<< "Place your HeliiiKopterr!!!" << endl;
            cout << "Stop singing Soldier your are fighting a war here xD" << endl;
        }
        cout<<endl<<"V / H : "<<endl;
        cin>>v_h;
        
    
        
        if(v_h=="V")
        {
            while(loop)
            {
                
                int row,column;
                cout<<"Row: ";
                cin>>row;
                cinfail(row);
                cout<<"Column: ";
                cin>>column;
                cinfail(column);
                if(counter==0)
                {
                    if(row<5 && row>0 && column>0 && column<7 && array[row][column]=="[ ]" && array[row+1][column]=="[ ]" && array[row+2][column]=="[ ]")
                    {
                        
                            
                    for(int i=0;i<3;i++)
                    {
                        array[row+i][column]="[B]";
                    }
                    loop=0;
                    counter++;
                            
                    }
                    else
                    {
                        cout<<"Invalid! enter again"<<endl;
                    }
                }
                if(counter==1)
                {
                    if(row<5 && row>0 && column>0 && column<7 && array[row][column]=="[ ]" && array[row+1][column]=="[ ]" && array[row+2][column]=="[ ]")
                    {

                         
                    for(int i=0;i<3;i++)
                    {
                        array[row+i][column]="[A]";
                    }
                    loop=0;
                    counter++;
                       
                    }
                    else
                    {
                        cout<<"Invalid! enter again"<<endl;
                    }
                }
                if(counter==2)
                {
                    if(row<6 && row>0 && column>0 && column<7 && array[row][column]=="[ ]" && array[row+1][column]=="[ ]" )
                    {
                       
                    for(int i=0;i<2;i++)
                    {
                        array[row+i][column]="[H]";
                    }
                    loop=0;
                    counter++;
                          
                    }
                    else
                    {
                        cout<<"Invalid! enter again"<<endl;
                    }
                }
            }
        }
        else if(v_h=="H")    
        {
            
            while(loop)
            {
                
                int row,column;
                cout<<"Row: ";
                cin>>row;
                cinfail(row);
                cout<<"Column: ";
                cin>>column;
                cinfail(column);
            
               if(counter==0)
                {
                    if(row<7 && row>0 && column>0 && column<5 && array[row][column]=="[ ]" && array[row][column+1]=="[ ]" && array[row][column+2]=="[ ]")
                    {
                        
                    for(int i=0;i<3;i++)
                    {
                        array[row][column+i]="[B]";
                    }
                    loop=0;                      
                    counter++;
                        
                    }
                    else
                    {
                        cout<<"Invalid! enter again"<<endl;
                    }
                }
                if(counter==1)
                {
                    if(row<7 && row>0 && column>0 && column<5 && array[row][column]=="[ ]" && array[row][column+1]=="[ ]" && array[row][column+2]=="[ ]")
                    {
                        
                        for(int i=0;i<3;i++)
                        {
                        array[row][column+i]="[A]";
                        }
                        loop=0;
                        counter++;
                      
                    }
                    else
                    {
                        cout<<"Invalid! enter again"<<endl;
                    }
                }
                if(counter==2)
                {
                    if(row<7 && row>0 && column>0 && column<6 && array[row][column]=="[ ]" && array[row][column+1]=="[ ]" )
                    {
                       
                    for(int i=0;i<2;i++)
                    {
                    array[row][column+i]="[H]";
                    }
                    loop=0;
                    counter++;
                         
                    }
                    else
                    {
                        cout<<"Invalid! enter again"<<endl;
                    }
                }     
            }
        }   
    }


    system("CLS");
    printArray(array,player);
    string bruh;
    cout<<endl<<"Enter any key to continue....";
    cin>>bruh;



}

void hitOrMiss(string array[][7],string array_store[][7],string player, int& win, int &counter,bool &hit_or_miss)
{
    
    int column;
    int row;
    cout<<endl<<"Player "<<player<<endl;
    bool loop=true;
    
    if(hit_or_miss==true && counter>0)
    {
        cout << "----::::HITTTTT::::----" << endl;
    }
    else if (hit_or_miss==false && counter>0)
    {
        cout << "----::::MISS::::----" << endl;
    }

    while(loop)
    {
        
        cout<<"Enter Position"<<endl;
        cout<<"Row: ";
        cin>>row;
        cinfail(row);
        cout<<"Column: ";
        cin>>column;
        cinfail(column);

        if(array[row][column]=="[X]" || array[row][column]=="[W]")
        {
            cout<<"You have already attacked this Position"<<endl;
        }
        else if((array_store[row][column]=="[B]" || array_store[row][column]=="[A]" || array_store[row][column]=="[H]") && row>0 && row<7 && column>0 && column<7 )
        {
            array[row][column]="[X]";
            hit_or_miss=true;
            loop=false;
            win++;
            Beep(1000,500);
        }
        else if(row>0 && row<7 && column>0 && column<7)
        {
            array[row][column]="[W]";
            hit_or_miss=false;
            loop=false;
            
        }
        else
        {
            cout<<"\nINVALID INPUT\n"<<endl;
        }
        
    }

    
}

void computerHitOrMiss(string array[][7],string array_store[][7],string player, int& win,int &counter, bool& hit_or_miss)
{
    
    if(hit_or_miss==true && counter>0)
    {
        cout << "----::::HITTTTT::::----" << endl;
    }
    else if (hit_or_miss==false && counter>0)
    {
        cout << "----::::MISS::::----" << endl;
    }
    
    
    bool loop=true;
    while(loop)
    {
        int column=rand()%6+1;
        int row=rand()%6+1;

        if((array_store[row][column]=="[B]" || array_store[row][column]=="[A]" || array_store[row][column]=="[H]") && row>0 && row<7 && column>0 && column<7 )
        {
            array[row][column]="[X]";
            loop=false;
            win++;
            Beep(1000,500);
            
        }
        else if(row>0 && row<7 && column>0 && column<7)
        {
            array[row][column]="[W]";
            loop=false;
            
        }
        
    }
}

void computerInputShip(string array[][7])
{
    system("CLS");
    
    
    string v_h;
    
    int counter=0;
          
    while(counter<3)
    {
        bool loop=1;
        int random_no=rand()%2;
        if(random_no==1)
        {
            v_h="V";
        }
        else
        {
            v_h="H";
        }
        
        if(v_h=="V")
        {
            while(loop)
            {
                
                int column=rand()%6+1;
                int row=rand()%6+1;
                if(counter==0)
                {
                    if(row<5 && row>0 && column>0 && column<7 && array[row][column]=="[ ]" && array[row+1][column]=="[ ]" && array[row+2][column]=="[ ]")
                    {
                       
                        for(int i=0;i<3;i++)
                        {
                            array[row+i][column]="[B]";
                        }
                        loop=0;
                        counter++;
                          
                    }
                   
                }
                if(counter==1)
                {
                    if(row<5 && row>0 && column>0 && column<7 && array[row][column]=="[ ]" && array[row+1][column]=="[ ]" && array[row+2][column]=="[ ]")
                    {
                        
                        for(int i=0;i<3;i++)
                        {
                            array[row+i][column]="[A]";
                        }
                        loop=0;
                        counter++;
                     
                    }
                    
                }
                if(counter==2)
                {
                    if(row<6 && row>0 && column>0 && column<7 && array[row][column]=="[ ]" && array[row+1][column]=="[ ]" )
                    {
                      
                        for(int i=0;i<2;i++)
                        {
                            array[row+i][column]="[H]";
                        }
                        loop=0;
                        counter++;
                      
                    }
                   
                }
            }

        }
        else if(v_h=="H")    
        {
            
            while(loop)
            {
                int column=rand()%6+1;
                int row=rand()%6+1;
            
               if(counter==0)
                {
                    if(row<7 && row>0 && column>0 && column<5 && array[row][column]=="[ ]" && array[row][column+1]=="[ ]" && array[row][column+2]=="[ ]")
                    {
                        
                        for(int i=0;i<3;i++)
                        {
                            array[row][column+i]="[B]";
                        }
                        loop=0;                      
                        counter++;
                        
                    }
                    
                }
                if(counter==1)
                {
                    if(row<7 && row>0 && column>0 && column<5 && array[row][column]=="[ ]" && array[row][column+1]=="[ ]" && array[row][column+2]=="[ ]")
                    {
                        
                        for(int i=0;i<3;i++)
                        {
                            array[row][column+i]="[A]";
                        }
                        loop=0;
                        counter++;
                      
                    }
                 
                }
                if(counter==2)
                {
                    if(row<7 && row>0 && column>0 && column<6 && array[row][column]=="[ ]" && array[row][column+1]=="[ ]" )
                    {
                       
                        for(int i=0;i<2;i++)
                        {
                            array[row][column+i]="[H]";
                        }
                        loop=0;
                        counter++;
                        
                    }  
                }     
            }
        }   
    }    
}

int main()
{
    bool hit_or_miss=false;
    bool loop1=true;
    int input;
    string input2;
    while(loop1)
    {
        system("CLS");
        cout << "Press 1 TO PLAY GAME" << endl;
        cout << "Press 2 FOR RULES" << endl;
        bool valid1=true;
        while(valid1)
        {
            cin >> input;
            cinfail(input);
            if(input==1 || input==2)
            {
                valid1=false;
            }
            else
            {
                cout << "Invalid input, enter again: ";
            }
        }
    
        if(input==2)
        {
        
        
            system("CLS");
            cout << "::::::------RULES------::::::" << endl;
            cout << endl;
            cout << "1. You have to destroy your opponent's defences before he destroys yours" << endl;
            cout << "2. The battlefield is of 6x6 grid size in which you will place a BATTLESHIP , an AIRCRAFT and a HELIIIKKKOPTER (yes the meme xD)" << endl;
            cout << "3. You can place defences by entering their orientation, i.e horizontal or vertical. For horizontal orientation, type 'H' in the orientation option and type 'V' for vertical" << endl;
            cout << "4. Specify the row and column number respectively" << endl;
            cout << "4. You have a fleet of 3 Defences: BATTLESHIP(3 units long), AIRCRAFT (3 units long) and HELIIIKOPTER (2 units long)" << endl;
            cout << "5. After placing your ships, you can attack the enemy area. To attack an area, enter its row and Column accordingly" << endl;
            cout << "6. Attack hit to the enemy ship is denoted by a \'[X]\' and a MISS is denoted by \'[w]\'" << endl;
            cout << "7. After you are done attacking your turn ends" << endl;
            cout << "8. a Player has a maxmimum of 16 turns" << endl;
            cout << "9. The player which has sunk all of the opponents defences or has a higher number of hits is the Winner" << endl;
            cout << "10. Autosave is Active after both players have attacked." << endl;
            cout << endl;
            cout << "Enter Any Key to return to Main Menu" << endl;
            cin >> input2;
        }
        else if (input==1)
        {
            loop1=false;
        }
    }

    
    
    
    string array_p1[7][7]=
    {
        {" "," 1 "," 2 "," 3 "," 4 "," 5 "," 6 "},
        {"1","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"2","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"3","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"4","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"5","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"6","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}
    };
    
    string array_p2[7][7]=
    {
        {" "," 1 "," 2 "," 3 "," 4 "," 5 "," 6 "},
        {"1","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"2","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"3","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"4","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"5","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"6","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}
    };

    string array_store_p1[7][7]=
    {
        {" "," 1 "," 2 "," 3 "," 4 "," 5 "," 6 "},
        {"1","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"2","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"3","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"4","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"5","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"6","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}
    };

    string array_store_p2[7][7]=
    {
        {" "," 1 "," 2 "," 3 "," 4 "," 5 "," 6 "},
        {"1","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"2","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"3","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"4","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"5","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
        {"6","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}
    };


    int counter_p1=0;
    int counter_p2=0;
    int hit_p1=0;
    int hit_p2=0;
    string name_p1= "store_p1";
    string name_p2= "store_p2";


    int type_play;
    system("CLS");
    cout<<"1. Singleplayer\n2. Multiplayer"<<endl;
    bool valid2=true;
    while(valid2)
        {
            cin >> type_play;
            cinfail(type_play);
            if(type_play==1 || type_play==2)
            {
                valid2=false;
            }
            else
            {
                cout << "Invalid input, enter again: ";
            }
        }

    int game;
    system("CLS");
    cout<<"1. New game\n2. Load game"<<endl;
    bool valid3=true;
    while(valid3)
        {
            cin >> game;
            cinfail(game);
            if(game==1 || game==2)
            {
                valid3=false;
            }
            else
            {
                cout << "Invalid input, enter again: ";
            }
        }


    if(type_play==2)
    {
        if(game==1)
        {
            inputShip(array_store_p1,"1");
            saveArray(array_store_p1,name_p1);
            inputShip(array_store_p2,"2");
            saveArray(array_store_p2,name_p2);
        }
        else if(game == 2)
        {
            loadArray(array_store_p1,name_p1);
            loadArray(array_store_p2,name_p2);
            loadArray(array_p1,"p1");
            loadArray(array_p2,"p2");
            loadCounters(counter_p1,hit_p1,counter_p2,hit_p2);
        }

        system("CLS");
        while((counter_p1<16 && counter_p2<16) && (hit_p1<8 && hit_p2<8))
        {    
            printArray(array_p1,"1");
            printArray(array_p2,"2");
            hitOrMiss(array_p1,array_store_p2,"1",hit_p1,counter_p1,hit_or_miss);
            counter_p1++;
            system("CLS");
            printArray(array_p1,"1");
            printArray(array_p2,"2");
            hitOrMiss(array_p2,array_store_p1,"2",hit_p2,counter_p2,hit_or_miss);
            counter_p2++;
            saveCounters(counter_p1,hit_p1,counter_p2,hit_p2);
            saveArray(array_p1,"p1");
            saveArray(array_p2,"p2");
            system("CLS");
        
        }
        printArray(array_p1,"1");
        printArray(array_p2,"2");

        if(hit_p1 == hit_p2)
        {
            Beep(1000,500);
            cout<<endl<<"DRAW!!!!"<<endl;
        }
        else if(hit_p1>hit_p2)
        {
            Beep(1000,500);
            cout<<endl<<"PLAYER 1 WINS!!!!"<<endl;
        }
        else if(hit_p1<hit_p2)
        {
            Beep(1000,500);
            cout<<endl<<"PLAYER 2 WINS!!!!"<<endl;
        }
    }
    else if(type_play==1)
    {
    
        if(game==1)
        {
            inputShip(array_store_p1,"1");
            saveArray(array_store_p1,name_p1);
            computerInputShip(array_store_p2);
            saveArray(array_store_p2,name_p2);

        }
        else if(game == 2)
        {
            loadArray(array_store_p1,name_p1);
            loadArray(array_store_p2,name_p2);
            loadArray(array_p1,"p1");
            loadArray(array_p2,"p2");
            loadCounters(counter_p1,hit_p1,counter_p2,hit_p2);
        }
        
        system("CLS");
        while((counter_p1<16 && counter_p2<16) && (hit_p1<8 && hit_p2<8))
        {    
            printArray(array_p1,"1");
            printArray(array_p2,"Computer");
            hitOrMiss(array_p1,array_store_p2,"1",hit_p1,counter_p1,hit_or_miss);
            counter_p1++;
            system("CLS");
            printArray(array_p1,"1");
            printArray(array_p2,"Computer");
            computerHitOrMiss(array_p2,array_store_p1,"Computer",hit_p2,counter_p1,hit_or_miss);
            counter_p2++;
            saveCounters(counter_p1,hit_p1,counter_p2,hit_p2);
            saveArray(array_p1,"p1");
            saveArray(array_p2,"p2");
            system("CLS");
        }
        printArray(array_p1,"1");
        printArray(array_p2,"Computer");

        if(hit_p1 == hit_p2)
        {
            Beep(1000,500);
            cout<<endl<<"DRAW!!!!"<<endl;
        }
        else if(hit_p1>hit_p2)
        {
            Beep(1000,500);
            cout<<endl<<"PLAYER 1 WINS!!!!"<<endl;
        }
        else if(hit_p1<hit_p2)
        {
            Beep(1000,500);
            cout<<endl<<"COMPUTER WINS!!!!"<<endl;
        }
    }


    string end_game;
    cout<<endl<<"Enter any key to close game......";
    cin>>end_game;

    
    

    return 0;
}
