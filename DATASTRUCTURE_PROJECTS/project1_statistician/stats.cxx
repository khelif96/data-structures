// FILE: stats.cxx
// CLASS IMPLEMENTED: statistician (See stats.h for documentation)
// #include <iostream>
#include <cassert>
#include "stats.h"
using namespace std;
namespace main_savitch_2C
{
	statistician::statistician(){
		total = 0;
		count = 0;
		largest = 0;
		tinyest = 0;
	}

	int statistician::length() const{
		return count;
	}
	
	void statistician::next(double r){

		if(length() == 0){
			tinyest = r;
			largest = r;
		}
		if(r < tinyest){
			tinyest = r;
		}
		if(r > largest){
			largest = r;
		}
		count ++;
		total += r;
	}

	double statistician::mean() const{
		assert(length() > 0);
		return  total/count;
	}

	void statistician::reset(){
		count = 0;
		total = 0;
		tinyest = 0;
		largest = 0;
	}

	double statistician::sum() const{
		return total;
	}

	double statistician::minimum() const{
		// cout << "L = " << length() << " min = " << minimum() << " max = " << maximum() << " mean = " << mean() <<  endl;
		// assert(length() > 0);
		return tinyest;
	}

	double statistician::maximum() const{
		// cout << "L = " << length() << " min = " << minimum() << " max = " << maximum() << " mean = " << mean() <<  endl;
		// assert(length() > 0);
		return largest;
	}

	statistician operator+(const statistician& s1, const statistician& s2){
		statistician result;
		// No need to add is s1.length() == 0 or s2.length() == 0 just assign values
		// Of other class
		if(s1.length() == 0){
			result.count = s2.length();
			result.tinyest = s2.minimum();
			result.largest = s2.maximum();
			result.total = s2.sum();
		}else if(s2.length() == 0){
			result.count = s1.length();
			result.tinyest = s1.minimum();
			result.largest = s1.maximum();
			result.total = s1.sum();
		}else{
			result.count = s1.length() + s2.length();
			result.total = s1.sum() + s2.sum();

			if (s1.minimum() <= s2.minimum()){
				result.tinyest = s1.minimum();

			}else{
				result.tinyest = s2.minimum();
			}
			if (s1.maximum() <= s2.maximum())
			result.largest = s2.maximum();
			else
			result.largest = s1.maximum();

		}
		return result;

	}

	bool operator==(const statistician& s1, const statistician& s2){
		if(s1.length() == 0 && s2.length() == 0){
			return true;
		}else{
			if (s1.length() == s2.length())
			{
				if ((s1.mean() == s2.mean()) && (s1.minimum() == s2.minimum())
				&& (s1.maximum() == s2.maximum()) && (s1.sum() == s2.sum())){
					return true;
				}else{
					return false;
				}
			}
		}
	}

	statistician operator*(double scale, const statistician& s2){
		statistician temp;
		temp.count = s2.length();
		if(scale > 0){
			temp.tinyest = s2.tinyest * scale;
			temp.largest = s2.largest * scale;
		} else {
			temp.tinyest = s2.largest * scale;
			temp.largest = s2.tinyest * scale;
		}

		// temp.largest = s2.maximum() * scale;
		temp.total = s2.total * scale;
		return temp;
	}

}
