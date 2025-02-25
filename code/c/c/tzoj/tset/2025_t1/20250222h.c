

int main()
{
    int a, b, *pa=&a, *pb=&b;
    scanf("%d %d", pa, pb);
    Swap(&pa, &pb);
    printf("%d %d\n", a, b);
    return 0;
}

void Swap(int **pa, int **pb){
    int **temp; 
    **temp = **pa;
    **pa = **pb;
    **pb = **temp;
    return;
}