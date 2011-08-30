#include <stdio.h>
struct room {
	int need_troopers;
	int pos;
	int is_recursion;
	int from;
} room[100];
int room_ref[100];
int rooma[100];
int roomb[100];
int max_c;

struct tro_pos
{
	int need_troopers;
	int pos;
};

int n_of_room;
int troppers;

void fill_room(int index,int bugs,int pos)
{
	struct room *rtemp;
	rtemp=room+index;
	rtemp->need_troopers=(bugs+19)/20;
	rtemp->pos=pos;
	if(index!=0)
		rtemp->is_recursion=0;
}
void connect(int ra,int rb)	/* room a and b */
{
	room[rb].from=ra;
}
void print_way(int r)
{
	printf("%d",r+1);
	if(room[r].from!=-1){
		printf("->");
		print_way(room[r].from);
	} else {
		printf("\n");
	}
}

void print_room(int r)
{
	struct room * rt=room+r;
	printf("%d,%d,%d,%d\n",rt->need_troopers,rt->pos,rt->is_recursion,rt->from+1);
}

struct tro_pos rec_room(int r)
{
	struct tro_pos t;
	if(room[r].is_recursion==0){
		room[r].is_recursion=1;
		t=rec_room(room[r].from);
		t.need_troopers=room[r].need_troopers+=t.need_troopers;
		t.pos=room[r].pos+=t.pos;
	} else {
		t.need_troopers=room[r].need_troopers;
		t.pos=room[r].pos;
	}
	return t;
}
void search_set(int n)
{
	int i;
	for(i=0;i<n_of_room-1;++i){
		if(rooma[i]==n){
			connect(roomb[i],n);
			rooma[i]=roomb[i]=0;
		}
		else if(roomb[i]==n){
			connect(rooma[i],n);
			rooma[i]=roomb[i]=0;
		}
	}
}
void build_tree(void)
{
	int i,j;
	for(i=1;i<=max_c;++i)
		for(j=0;j<n_of_room;++j){
			if(room_ref[j]==i && j!=0){
				search_set(j);
			}
		}
}

int main(void)
{
	room[0].from=-1;
	room[0].is_recursion=1;
	int i;
	int bugs,pos;
	int ra,rb; 		/* room a and b */
	while(scanf("%d %d",&n_of_room,&troppers)){
		if(n_of_room == -1 && troppers == -1)
			return 0;
		
		for(i=0;i<n_of_room;++i){
			scanf("%d %d",&bugs,&pos);
			fill_room(i,bugs,pos);
		}
		max_c=0;
		rooma[0]=roomb[0]=1;
		
		for(i=0;i<n_of_room-1;++i){
			scanf("%d %d",&ra,&rb);
			--ra;
			--rb;
			rooma[i]=ra;
			roomb[i]=rb;
			if(++room_ref[ra]>max_c)
				max_c=room_ref[ra];
			if(++room_ref[rb]>max_c)
				max_c=room_ref[rb];
			
			/* connect(ra,rb); */
		}
		/* printf("a\n"); */
		/* for(i=0;i<n_of_room-1;++i){ */
		/* 	printf("%d,%d\n",rooma[i]+1,roomb[i]+1); */
		/* } */
		/* for(i=0;i<n_of_room;++i) */
		/* 	printf("%d\n",room_ref[i]); */
			
		build_tree();
		
		
		for(i=0;i<n_of_room;++i){
			rec_room(i);
		}
		pos=0;
		for(i=0;i<n_of_room;++i){
			if(room[i].need_troopers<=troppers && room[i].pos > pos)
				pos=room[i].pos;
		}
		printf("%d\n",pos);
		
		/* debug print ways */
		/* for(i=0;i<n_of_room;++i) */
		/* 	print_way(i); */

		/* debug print info */
		/* for(i=0;i<n_of_room;++i){ */
		/* 	print_room(i); */
		/* } */
		/* printf("\n"); */
	}
	return 0;
}

