#include <iostream>
#include <random>
#include <fstream>

// defining simulation parameters
#define MIN_BINS_NUMBER 1000
#define MAX_BINS_NUMBER 100000
#define STEP            1000
#define REPEATS         50


// creating random numbers generator
std::random_device randomDevice(); 
std::mt19937 randomIntegerGenerator(randomDevice());

// declaring and opening files for saving simulation results
std::ofstream b_n_file("results/bn.csv");
std::ofstream u_n_file("results/un.csv");
std::ofstream l_n_file("results/ln.csv");
std::ofstream c_n_file("results/cn.csv"); 
std::ofstream d_n_file("results/dn.csv"); 
std::ofstream dn_minus_cn_file("results/dnminuscn.csv");


// function for one simulation for specific bins numbers
void simulate_for_n_bins(unsigned int bins_number) {
    // setting range of generating numbers
    std::uniform_int_distribution<> distribution(0, bins_number - 1);

    // initilizing empty bins
    unsigned int balls_in_bin[bins_number];
    for(unsigned int i = 0; i < bins_number; i++) {
        balls_in_bin[i] = 0;
    }

    // defining variables
    unsigned int emptyBins = bins_number;
    unsigned int oneBallBins = 0;
    unsigned int twoOrMoreBallBins = 0;
    unsigned int birthdayParadox = 0;
    unsigned int throwsToAllNoEmptyBins = 0;


    // simulating first n(bins_number) throws
    for(unsigned int i = 0; i < bins_number; i++) {
        unsigned int bin_numer = distribution(randomIntegerGenerator);
        
        if(balls_in_bin[bin_numer] == 0) {
            emptyBins--;
            oneBallBins++;
        }
        else if(balls_in_bin[bin_numer] == 1) {
            oneBallBins--;
            twoOrMoreBallBins++;

            if(birthdayParadox == 0) {
                birthdayParadox = i+1;
            }
        }

        balls_in_bin[bin_numer]++;
    }

    if(emptyBins == 0) {
        throwsToAllNoEmptyBins = bins_number;
    }
    u_n_file << emptyBins << ',';

    unsigned int maxBallNumber = 0;
    for(unsigned int i = 0; i < bins_number; i++) {
        if(balls_in_bin[i] > maxBallNumber) {
            maxBallNumber = balls_in_bin[i];
        }
    }
    l_n_file << maxBallNumber << ',';

    // iterating while in every bins are 2 or more balls
    unsigned int counter = bins_number;
    while(twoOrMoreBallBins != bins_number) {
        counter++;
        unsigned int bin_numer = distribution(randomIntegerGenerator);

        if(balls_in_bin[bin_numer] == 0) {
            emptyBins--;
            oneBallBins++;
            
            if(emptyBins == 0 && throwsToAllNoEmptyBins == 0) {
                throwsToAllNoEmptyBins = counter;
            }
        }
        else if(balls_in_bin[bin_numer] == 1) {
            oneBallBins--;
            twoOrMoreBallBins++;

            if(birthdayParadox == 0) {
                birthdayParadox = counter;
            }
        }

        balls_in_bin[bin_numer]++;
    }

    b_n_file << birthdayParadox << ','; 
    c_n_file << throwsToAllNoEmptyBins << ',';   
    d_n_file << counter << ','; 
    dn_minus_cn_file << counter - throwsToAllNoEmptyBins << ','; 
}


int main() {
    // main simulation loop
    for(unsigned int i = MIN_BINS_NUMBER; i <= MAX_BINS_NUMBER; i += STEP) {
        for(unsigned int j = 0; j < REPEATS; j++) {
            simulate_for_n_bins(i);
        }

        b_n_file << '\n';
        u_n_file << '\n';
        l_n_file << '\n';
        c_n_file << '\n';
        d_n_file << '\n';
        dn_minus_cn_file << '\n';
    }

    // closing files with simulation results
    b_n_file.close();
    u_n_file.close();
    l_n_file.close();
    c_n_file.close();
    d_n_file.close();
    dn_minus_cn_file.close();

    return 0;
}
