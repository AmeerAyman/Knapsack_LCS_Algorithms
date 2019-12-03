#include<iostream>
#include<string>
#include<ctime>
using namespace std;
// the complixity for each primitive step is 1 and i will not write it here in this algorithm they will constant
int V[500][500];
int P[500][500];
int KnapSack(int capacity, int weight[], int value[], int n,int counter){   // this step counted
	for (int j = 0; j <= capacity; j++)  // complixity capacity  //not counted
	{
		V[0][j] = 0; //initial values of the table that denote to no item selected  //counted
		counter++;
	}
	for (int i = 0; i <= n; i++)  //complixity n  //not counted
	{
		V[i][0] = 0;     //initial values of the table that denote to no item selected  //counted
		counter++;
	} //build the table of the knapsack
	for (int i = 1; i <= n; i++)  //complixity n*capacity       //not counted
	{
		for (int j = 1; j <= capacity; j++){     //not counted
			if ((weight[i] <= j) && (value[i] + V[i - 1][j - weight[i]] > V[i - 1][j])){  //not counted
				V[i][j] = value[i] + V[i - 1][j - weight[i]];     //counted
				P[i][j] = j - weight[i];   //counted
				counter++;
			}
			else
				V[i][j] = value[i - 1][j];        //counted
			P[i][j] = j;      //counted
			counter++;
		}
	}
	int result[500][500];  // array that will hold the final result    //notcounted
	
	int j = capacity;     //notcounted
	for (int i = n; i > 0;i--){       //notcounted
		if (P[i][j] = j)
		{
			//this will not terminate ever and the compi will go to else 
		}
		else   //take the value and the weight of the current item and put it in the knapsack
		result[i][0] = value[i];       //counted
		result[0][i] = weight[i];      //counted
		counter++;
	}





}
void main(){
	int count = 0;
	clock_t time;  //declare variable from the clock
	time = clock(); //save the time at this moment
	int n, capacity;
	int *weight, *value;
	weight = new int[n];  //create array for the wieghts of items
	value = new int[n];  //create array for the values of items
	cout << "Enter the number of the items in the knapsack:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++){       //take all the values and weights from the user and put them in arrays
		cout << "Enter value of item " << i + 1 << endl;
		cin >> value[i];
		cout << "Enetr weight for item " << i + 1 << endl;
		cin >> weight[i];
	}
	cout << "Enter the capacity of the knapsack : " << endl;
	cin >> capacity;
	double clockClc;
	clockClc = clock() - time; // find the difference between the time and the time that this function take to done
	cout << KnapSack(capacity, weight, value, n,count);   //function call that pass the values,weights,number of items and the capacity of the knapsack to the item
	cout << (clockClc / CLOCKS_PER_SEC); //print the time in seconds
	cout << count;   //print number of steps that happen in all progrem
}

// the compixity is: n+capacity+n*capacity= O(n*capacity)