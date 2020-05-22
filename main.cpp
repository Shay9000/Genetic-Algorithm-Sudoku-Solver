#include <iostream>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <genetic.h>
#include <time.h>
#include <omp.h>

using namespace std;

int main()
{
    {

    }
     FILE *fp;
     FILE *lp;
{
}
fp = fopen("Final_Test_Solving_4x4_with_reset_popSize(2000)maxGeneration(100).txt", "w+");
lp = fopen("Final Test.RRtxt", "a+");

  srand(time(0));
    time_t start, end;
        time(&start);
int myints[] = {1,0,4,0 ,3,4,0,2, 2,1,0, 4, 4, 0, 2, 0};
int popSize=2000;
 Population a = Population(popSize,myints,sizeof(myints));//Generation 0 initialization
cout <<sizeof(myints)<<endl;
    int generationNum=0;

        fprintf(fp,"%d",generationNum);
        fprintf(fp,"\n");
cout <<"Generation number = " <<generationNum<<"\tFittest fitness is = "<<a.getFittest().fitness<<endl;
int stuck =0;//this will be incremented when ever the fitness of the best chromosome is not changing
int maxGenerations=100;//if we reach max generations 50 generations and we are stuck then we must restart the GA5
while(a.getFittest().fitness!=0){
int temp =a.getFittest().fitness;//temp var that stores the current fittest chromosome


a.selectAndRecombine(50,2); //Start Genetic algorithm on this generation

cout <<"Generation number = " <<generationNum<<"\tFittest fitness is = "<<a.getFittest().fitness<<endl;
        fprintf(fp, "\nGENERATION NUMBER:");
        fprintf(fp,"%d",generationNum);
        fprintf(fp, "\tBEST FITNESS:");
        fprintf(fp,"%d",a.getFittest().fitness);
        fprintf(fp,"\n");
generationNum++;

if (a.getFittest().fitness==temp)//we are stuck in minima
    stuck++;
if (a.getFittest().fitness!=temp)//reset stuck
    stuck=0;
if(stuck == maxGenerations){
    generationNum=0;
    stuck=0;
    Population a=Population(popSize,myints,sizeof(myints));
    cout<<endl<<"========================================"<<endl
        <<"restarting"
        <<endl<<"========================================"<<endl;
fprintf(fp, "\n\nStuck at local minima ... restarting GA\n\n:");
}
}
a.printSolution(a.getFittest());//When you leave the while loop print the solution



 int n =sqrt(a.getFittest().representation.size());//square root of the full array which is n*n = n
 int offset=0,counter=0;//starting with offset 0 and counter 0
    for(int i = 0; i<n;i++){ //for each row in the Sudoku grid
        if(i>0){    //if we pass first row of the Sudoku
                if(i%(int)sqrt(n)==0){//if we are at the last row of a row of sub-grids
                        offset=n*i;//then the offset is n(number of elements in the row) * i(number of rows)
                        counter=offset;//save the offset in counter
                        for(int j=0;j<n;j++){//prints a line with the length of the row of the Sudoku
                           fprintf(fp,"___");
                            if((j+1)%(int)sqrt(n)==0 && j>0)
                                    fprintf(fp," ");
                            }                   //ends printing the line that is at the last row of a row of sub-grids

                        fprintf(fp,"\n");         //end line after the printed line (____\n)
                        }
                 else{                      //if we are not at the last row or a row of sub-grids
                            offset+=sqrt(n);//then we add sqrt(n) to the offset for the first sqrt n elements of the row
                                            //and later after printing each sqrt n elements the counter will increment by sqrt(n)
                            counter=offset; // save current value of the offset

                        }
                }
        for(int j = 0; j<sqrt(n); j++){//for each (sqrt(n)) sub-grids' row that is (sqrt(n))sized
            for(int k = 0; k<sqrt(n); k++){//for each element in that (sqrt(n))sized sub-grid's row
                fprintf(fp," ");
                fprintf(fp,"%d",a.getFittest().representation.at(j+k+counter));
                fprintf(fp," "); //print the it based on it's sub-grid offset number
                                                         //added to the element number
                                                         //and the current assumed to be printed elements of the grid
            }
                      fprintf(fp,"|");           //square vertical divider
                      counter+=((n-1));     //take into consideration the increment of the "printed square"
        }
        fprintf(fp,"\n");//end of sudoku row
    }
 time(&end);

    // Calculating total time taken by the program.
    double time_taken = (end - start);

    fprintf(lp,"\n");
    fprintf(lp,"generation #");
    fprintf(lp,"%d",generationNum);
    fprintf(lp,"\n");
    fprintf(lp,"%lf",time_taken);
   fclose(fp);
 return 0;
}
