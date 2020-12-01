#include <math.h>

int isPrime(int number){
	if (number > 2){
		int counter = 0;
		for(int i = 2; i <= floor(sqrt(number)+1); ++i){
			if (!(number % i))
				return 0;
   	}
   	return 1;
	} else {
		return (number == 2) ? 1 : 0;
	}
}
