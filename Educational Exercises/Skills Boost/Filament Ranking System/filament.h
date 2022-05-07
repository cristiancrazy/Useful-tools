/*****************************************
 * Author: Cristian Capraro
 * Under New BSD Licence (BSD 3-Clause)
 * Educational purposes
 * Filament Ranking System
 * ---------------------------------------
 * Interface file - This file contains
 * all external prototypes that will be
 * defined.
 *****************************************/

#pragma once

#include <iostream>
#include "add.cpp"
#include "print.cpp"
#include "rewrite.cpp"
#include "filter.cpp"

void addFilament(std::fstream&);

void printAllFilament(std::fstream&);

void printSortedByWeight(std::fstream&);

void rewriteSortedByWeight(std::string, std::fstream&);

void printFiltereByMaxPrice(std::fstream&, double);
void printFilteredByColor(std::fstream&, std::string);
void printFilteredByType(std::fstream&, std::string);