// Operadores Lógicos

    unsigned char a = 5, b = 9; // a = (00000101), b = (00001001)

    AND -          a&b   // The result is 00000001 (1)
    OR -           a|b   // The result is 00001101 (13)
    XOR -          a^b   // The result is 00001100 (12)
    NOT -          ~a    // The result is 11111010 (250)
    Left shift -   b<<1  // The result is 00010010 (18)
    Right shift -  b>>1  // The result is 00000100 (4)

    // Info

        Shifts são equivalentes a multiplicações(left) e divisões(right) por 2
            - Apenas para números positivos
            - Aproximações para baixo

        Bitmask - Variável inteira utilizada como um conjunto de dados booleanos



//Operações utilizando bitwise -

    //Trocar duas variáveis inteiras
	    a^=b;
	    b^=a;
	    a^=b;

    //Verificador de divisibilidade por 2
        (x & 1)? printf("Odd"): printf("Even");

    //Turn on o j-ésimo termo

        int S = 34; //(100010)
        int j = 3;

        S = S | (1<<j);

    //Turn off o j-ésimo termo

        int S = 42; //(101010)
        int j = 1;

        S &= ~(1<<j)

        S == 40 //(101000)

    //Checar o j-ésimo elemento

        int S = 42; //(101010)
        int j = 3;

        T = S & (1<<j);

        if(T==0)
            // O j-ésimo elemento é nulo
        else //T==(1<<j)
            // O j-ésimo elemento é não nulo

    //Trocar o j-ésimo elemento

        S ^= (1<<j)

    //Acessar a posição do primeiro bit ligado

        T = (S & (-S))
        T -> 4° bit ligado //(1000)

    //Dígito mais significativo de um número N

        double K = log10(N);
        K = K - floor(K);
        int X = pow(10, K);

    //Número de dígitos em um número N

        X =floor(log10(N)) + 1; 

    //Verificar se um número é uma potencia de 2

        bool isPowerOfTwo(int x)
        {
            return x && (!(x&(x-1)));
        }
