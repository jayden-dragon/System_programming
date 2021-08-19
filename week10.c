#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int nInput, i;
	int nCount = 0;
	
	char nName[100];

	struct info{
		char name[100];
		int age;
	};

	struct info *tmp = NULL;
	
	do{
		printf("Enter name : ");
		scanf("%s",nName);
		printf("Enter age(0 to end) : ");
		scanf("%d",&nInput);
		nCount++;

		tmp = realloc(tmp,nCount*sizeof(struct info));
		
		if(nName != NULL){
			strcpy(tmp[nCount-1].name,nName);
			tmp[nCount-1].age = nInput;
		}

		else{
			free(tmp);
			printf("realloc returns null.\n");
			exit(1);
		}

	}while(nInput != 0);
	
	printf("\n");

	for(i = 0;i<nCount;i++){
		printf("name : %s, age : %d\n",tmp[i].name,tmp[i].age);
	}

	printf("\n");

	free(tmp);

	return 0;
}