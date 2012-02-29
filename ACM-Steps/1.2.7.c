#include <stdio.h>

int main(void)
{
	char day[3]={0},month[3]={0},year[5]={0};
	char s[20];
	char * r;
	int n,i;
	scanf("%d",&n);
	getchar();
	while(n--){
		fgets(s,20,stdin);
		day[0]=s[12];
		day[1]=s[13];
		month[0]=s[10];
		month[1]=s[11];
		for(i=0;i<4;++i){
			year[i]=s[6+i];
		}
		switch((s[0]-'0')*10+(s[1]-'0')){
		case 33:
			r="Zhejiang";
			break;
		case 11:
			r="Beijing";
			break;
		case 71:
			r="Taiwan";
			break;
		case 81:
			r="Hong Kong";
			break;
		case 82:
			r="Macao";
			break;
		case 54:
			r="Tibet";
			break;
		case 21:
			r="Liaoning";
			break;
		case 31:
			r="Shanghai";
			break;
		}
		printf("He/She is from %s,and his/her birthday is on %s,%s,%s based on the table.\n",r,month,day,year);
	}
	return 0;
}

