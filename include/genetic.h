#ifndef GENETIC_H
#define GENETIC_H
#include <vector>
#include <stdio.h>
using namespace std;
class Genetic
{
    public:
        Genetic();
        virtual ~Genetic();

    protected:

    private:
};


class Chromosome
{
    public:
        //The chromosome's array
        vector<int> representation;
        //The chromosome's fitness
        int fitness;
        Chromosome(int helpArray[],int size);
       // ~Chromosome();
        //operator overloading just so we can assign chromosomes in the population
        Chromosome& operator=(const Chromosome& c);
        bool operator > (const Chromosome b);
        bool operator < (const Chromosome b);
        //the evaluation function finds fitness of the chromosome
        void evaluate();

};

class Population
{
    private:
        //our starting sudoku puzzle (help array)
        vector<int> helpArray;
        //size of chromosome
        int size;
        //The number of chromosomes in a population
        int populationSize;

    public:
        //the actual chromosome population
        vector<Chromosome> genePool;
        //roulette wheel selection being the selection method
        vector<int> rouletteWheel;
        //constructor takes the specified size of the population and the helpArray (the puzzle)
        Population(int populationSize, int helpArray[], int size);
        //performs Selection of chromosomes, crossovers and mutations. Creating the next generation of chromosomes (solutions)
        void selectAndRecombine(int mutationRate, int elitisim);
        //Returns the fittest chromosome in our population
        Chromosome getFittest();
        //prints the solution to the sudoku puzzle that the
        void printSolution(Chromosome chromo);
        //clears the given population to avoid memory leaks are bad
        void clearPool(vector<Chromosome*>& pop);
        //swap mutations
        void mutation(int array[], vector<int> helpArray, int blockSize);
};


#endif // GENETIC_H
