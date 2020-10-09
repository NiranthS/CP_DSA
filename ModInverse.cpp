int modInverse(int A, int M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    
}
