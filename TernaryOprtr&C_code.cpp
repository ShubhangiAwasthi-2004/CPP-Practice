//find the smallest non-negative integer value you can get by subtracting K from N any number of times (including zero times).
//ALSO NOTE THAT "printf and scanf" FUNCTIONS ARE ***VALID*** IN CPP AS WELL !!!!

#include <cstdio>
//NOTE THE LIBRARY NAME 'stdio.h' WON'T RUN FOR CPP.

int main(){
    
    int t; scanf("%d", &t);
    while(t--){
        long n, k; scanf("%d %ld", &n, &k);
        printf("%d\n", k ? n % k : n);
    }
    //note how '%d or %ld' does not matter in case of "int or long".
    return 0;
}

/*  ####### OUR LOGIC WAS THIS ######
     if ((n < k) || (k == 0))
            cout << n << endl;

        else if ((n == k) || (k == 1))
            cout << 0 << endl;

        else {
            while (n > k) {
                n = n - k;
            }
            cout << n << endl;
        }
*/
