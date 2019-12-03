//NAME:AMEER AYMAN AHMED
//ID:135058

#include<iostream>
#include<string>
#include<ctime>
using namespace std;
void LCS(string S1, string S2,int counter){ //function that find the longest common subsequence    //step notcounted in the complixity
	int i, j; //intiate variables of type integer             //notcounted
	string answer = ""; //initiate variable of type string that restore the chr which is simillar in the 2 sequance       ////notcounted
	int n = S1.length(); //find the length of the first string which the user enter it and save it at the variable n      //counted
	int m = S2.length(); //find the length of the second string which the user enter it and save it at the variable m        //counted
	// create 2D dynamic array 
	int **V;                    //notcounted
	V = new int *[n + 1];
	for (i = 0; i < n + 1; i++){    //notcounted
		*V = new int[m + 1];     //notcounted
	}
	
	char P[1000][1000]; //declare 2D array of char that contain and represent the arrow that refer to char that are simillar    //notcounted
	//build the table of lcs
	for (i = 0; i <= n; i++){ 				//  //notcounted
		for (j = 0; j <= m; j++){			// Complexity nm           //notcounted
			if (i == 0 || j == 0){//intial values : put firt row and column of the table to 0 thats nothing happen        //notcounted    
				V[i][j] = 0;
				counter++;  
			}
			else if (S1[i] == S2[j]){  //check if the 2 char are the same then take the num of the corner of the array and add 1 on it       //notcounted
				V[i][j] = V[i - 1][j - 1] + 1;            //counted beacuse it's variable assignment
				P[i][j] = 92; //put at the table of the arrows diagonal arrow if the 2 char are the same
				counter++;
			}
			else if (V[i - 1][j] >= V[i][j - 1]){   // if the 2 char are not the same find the biggest num of the corner and put it       //notcounted
				V[i][j] = V[i - 1][j];                //counted beacuse it's variable assignment
				P[i][j] = '|'; // then move down if the num is in this location are grater than the num at the right and put down arrow
				counter++;
			}
			else         //notcounted
			{
				V[i][j] = V[i][j - 1];
				P[i][j] = '_';  //put right arrow at the table of arrows
				counter++;
			}
		}
	}

	//here we print the lcs
	for (i = 0; i <= n;){    //// Complexity nm                 //notcounted
		for (j = 0; j <= m;){                                      //notcounted 
			if (P[i][j] = 92){  //if the arrow is diagonal this mean that the 2 char are similar so we take it and put it at the string of the answer     //notcounted
				answer = S1[i + 1] + answer;          //counted beacuse it's variable assignment
				counter++;
				i++;   //increase values of i and j
				j++;
			}
			else if (P[i][j] = '_'){                   //notcounted
				counter++;
				j++;
			}
			else if (P[i][j] = '|'){                 //notcounted
				counter++;
				i++;
			}
		}
	}
	for (i = 0; i <= n; i++){    //print the table of lcs              //notcounted
		for (j = 0; j <= m; j++){   // Complexity nm                    //notcounted
			cout << " " << P[i][j];
			counter++;
		}
		cout << endl;
	}
	cout << answer;  //print the lcs
}

void main(){
	clock_t time;  //declare variable from the clock
	time = clock(); //save the time at this moment
	string s1, s2;
	int count = 0;
	int m, n;
	cout << "Enter the first string sequence: " << endl;  //take the first string
	cin >> s1;
	cout << "Enter the second string sequence: " << endl;  //take the second string
	cin >> s2;
	double clockClc;
	LCS(s1, s2,count);   //call function of lcs and pass the 2 strings to the function
	clockClc = clock() - time; // find the difference between the time and the time that this function take to done
	cout << count;  // print the final number of steps that happen
	cout << (clockClc / CLOCKS_PER_SEC); //print the time in seconds

}
// the Complexity is: nm+nm+nm=O(nm)
