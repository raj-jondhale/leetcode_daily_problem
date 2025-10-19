int subtractProductAndSum(int n) {
    int product=1;
    int sum=0;

    while(n>0){
        int ld=n%10;
        product=product*ld;
        sum+=ld;
        n/=10;
    }
    return product-sum;
}