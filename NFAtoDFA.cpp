#include <iostream>
#include <string>
#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	int i,j,k,z,z1;
	string fineName; // ονομα του αρχειου
	string line; // διαβαζει τις γραμμες του αρχειου
	int linesOfFile=0; // μετραει τις γραμμες του αρχειου
	int s; // αριθμος καταστασεων
	int lenOfSymbols; // αριθμος συμβόλων
	string symbol[10]; // συμβολα, μαξ 10
	string arx;
	char tel;
	int sum1;
	string metav[100][3];  // 10 καταστασεις* 10 συμβολα, η μεταβαση περιγράφετε απο 3 στοιχεια, την τρεχουσα το συμβολο και την τελικη
	
    
    cout << "Enter file name: ";
	getline(cin, fineName);
	
	ifstream fin(fineName.data()); //input.txt
	if(fin.is_open() == false)
	{
		cout << "Error: File can't be loaded\n";
		exit(1);
	}
	
	while(!fin.eof())
	{
		getline(fin, line);
		if(fin == false)
			break;
		linesOfFile++;
		if(linesOfFile==1)
		{
			stringstream geek(line);  // μετατροπη string σε int 
			geek>>s;
		}
		else if(linesOfFile==2)
		{
			lenOfSymbols=0;
			for(i=0; i<line.length(); i++)
			{
				if(line[i]!=' ')
				{
					symbol[lenOfSymbols]=line[i];
					lenOfSymbols++;
				}
				
			}
		}
		else if(linesOfFile==3)
		{
			arx=line[0];
		}
		else if(linesOfFile==4)
		{
			tel=line[0]; // metatroph string se char
		}
		else
		{
			sum1=0;
			for(j=0; j<5; j+=2)
			{
				metav[linesOfFile-5][sum1]=line[j];
				sum1++;
			}
		}
	}
	fin.close();
	
	
	int S=pow(2,s); // δυναμικο καταστασεων, το μαξ του α
	int c=lenOfSymbols+1; // αριθμος συμβολων + 1
	int rows = linesOfFile-4; // υπολοιπομενες γραμμες στο αρχειο (4)
	string ptr[S][c]; // ΝΠΑ πινκας
	int a=2; // αριθμος διαφορετικων καταστασεων που εχουν προστεθει, a<=S, ξεκιναει με το γιατι εχει μπει το κενο και η αρχικη
	int flag; // αν υπαρχει ηδη η κατασταση 
	int flag1,flag2; // κραταει τον αριθμο γραμμης σε περιπτωση που υπαρχει ηδη η κατασταση
	string trex,arr[5];
	string arr1[5];
    string arr2[5];
    int sumt,pan,sum,len;
	
	for (i=0; i<c; i++) // αρχικοποιηση πρωτης σειρας σε κενο
	{
		ptr[0][i]="";
	}
	
	for (i=0; i<rows; i++) // αρχικοποιηση πρωτου στοιχειου με την αρχικη
	{
		if(metav[i][0]==arx)
		{
			ptr[1][0]=arx;
			break;
		}
	}
	
	// δημιουργια ptr με βαση τον matav
	for(i=0; i<rows; i++) // προσπελαση στον metabaseis
	{
		trex=metav[i][0];
		flag=0;
		for(j=1; j<=a; j++)
		{
			if(ptr[j][0]==trex)
			{
				flag1=j; // κραταμε τον αριθμο γραμμης που βρισκεται ηδη η κατασταση
				flag=1;
				break;
			}	
		}
		if(flag==1)
		{
			for(k=0; k<c; k++)
			{
				if(metav[i][1]==symbol[k])
				{
					flag2=k+1;
					break;
				}
			}
			ptr[flag1][flag2]+=metav[i][2]; 
		}
		else
		{
			a++;
			for(k=0; k<c; k++)
			{
				if(metav[i][1]==symbol[k])
				{
					flag2=k+1;
					break;
				}	
			}
			ptr[a-1][0]=metav[i][0];
			ptr[a-1][flag2]=metav[i][2];
		}
	}
	
	// ταξινομιση συμβολων καταστασεων και διαγραφη διπλων συμβολων
	for(i=0; i<a; i++)
	{
		for(j=1; j<c; j++)
		{
			len=ptr[i][j].length(); 
			if(len>1)
			{
				for(k=0; k<len; k++)
				{
					arr1[k]=ptr[i][j][k];
				}
				for(k=0; k<len; k++)
				{
					sumt=0;
					for(k=0; k<2; k++) //proapelasi symbol
					{
						pan=0;
						for(z=0; z<5; z++) // prosperasi arr1
						{
							if(symbol[k]==arr1[z] && pan!=1)
							{
								pan++;
								arr2[sumt]=arr1[z];
								sumt++;
							}
						}
					}
				}
				ptr[i][j]="";
				for(k=0; k<sumt; k++)
				{
					ptr[i][j]+=arr2[k];
				}
			}
		}
	}
	
	for(i=0; i<a; i++)
	{
		for(j=1; j<c; j++)
		{
			sum=0;
			for(k=0; k<a; k++) // προσπελαση πρωτης στηλης
			{
				if(ptr[i][j]==ptr[k][0])
				{
					sum=1;
				}
			}
			if(sum==0 && ptr[i][j]!="")
			{
				a++;
				ptr[a-1][0]=ptr[i][j];  // δημιουργια νεας γραμμης(-1 γιατι υπαρχει το κενο)
				len=ptr[a-1][0].length();  // διαχωρισμος καταστασεων σε πινακα για να γινει η προσπελαση
				
				if(len>1)
				{
					for(k=0; k<len; k++)  
					{
						arr[k]=ptr[a-1][0][k];  // δημιουργει τον πικανα απο καθε στοιχειο του ptr b
						
						for(z=0; z<a; z++)
						{
							if(ptr[z][0]==arr[k])
							{
								for(z1=1; z1<c; z1++)
								{
									ptr[a-1][z1]+=ptr[z][z1];
								}
							}
						}
					}
				}
			}
		}
	}
	
    ofstream fout("output.txt");
	if(fout.is_open() == false)
	{
		cout << "Error: File can't be created\n";
		exit(1);
	}
    for(i=0; i<a; i++) 
    {
    	for(k=0; k<2; k++)
				if(ptr[i][0][k]==tel) 
					fout<<">"; // σηματοδοτει τις τελικες καταστασεις
		for(j=0; j<c; j++)
		{
			if(ptr[i][j]=="")
				fout<< ptr[i][j]<<"@"; // σηματοδοτει τις κενες καταστασεις
			fout<< ptr[i][j]<<" ";
		}
    	fout<<endl;
	}
	fout.close();
	
	return 0; 
}
