void mySort(int d[], unsigned int n)
{
int temp = 0, e = 0, i;
for ( i = 1; i<n; i++){
temp = d[i];
e = i - 1;
while ((e>=0)&&(temp<d[e])){
d[e+1] = d[e];
e--;
}
d[e+1]=temp;



}



}
