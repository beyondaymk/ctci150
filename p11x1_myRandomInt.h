#include "boost/random/uniform_int.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

boost::random::mt19937 gen;

int myRandomInt(int min, int max) {
    boost::random::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}