// Retorna o número de digitos de n! em O(1)

#define Pi 3.14159265358979311599796346854
#define Eul 2.71828182845904509079559829842

long long findDigits(int n)
{
	double x;

	if (n < 0) 
		return 0; 
	if (n == 1) 
		return 1; 

	x = ((n * log10(n / euler) + log10(2 * Pi * n)/2.0)); 	
  
	return floor(x) + 1;
}
