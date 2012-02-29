#include <stdio.h>
int main()
{
	char a[12];
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",a);
		printf("6%s\n",a+6);
	}
	return 0;
}

