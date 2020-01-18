// ax + my = 1, e gcd(a, m) = 1 para existir solucao
// outra forma de escrever: a*x = 1 (mod m)
int x, y;
int g = gcd(a, m, x, y);
if (g != 1)
    cout << "No solution!";
else
{
    x = (x%m + m) % m;
    cout << x << endl;
}