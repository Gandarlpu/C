//compiler : Dev-C++
//3�� ������ �� �������� �´��ڵ��ΰŰ����� �� ������ ������ �𸣰ڽ��ϴ� �̤�.. 
#include<stdio.h>
#include<string.h>

void star(int n); //�ݺ��� 
void star2(int m); //��ȯ�� 
int arry(char *pt); //�ݺ����� 
int arry2(char *ptr , int i); //��ȯ���� 
//int maxfun(int *Mpt , int Marrlen); //�ִ밪 �Լ� 
int BSearch(int Barr[] , int first , int last , int target); //����Ž�� 

int main(int argc, char *argv[]) {

	int i=0 , n , m;
	int count=0;
	int count2=0; 
	char arr[50];
	char arr2[50];
	char *pt , *ptr;
	pt = &arr;
	ptr = &arr2;
	int Barr[5];
	int target;
	int idx , j; 	
	//int Marr[] = {3,6,2,7,9};
	//int Marrlen = 5;
	//int *Mpt;
	//Mpt = Marr;
	
	printf("�ݺ� ����ϰ���� ������ : ");
	scanf("%d" , &n);
	
	printf("��ȯ ����ϰ���� ������ : ");
	scanf("%d" , &m);
	
	printf("�ݺ� �� : ");
	star(n); //�ݺ� 
	printf("\n");
	printf("��ȯ �� : ");
	star(m); //��ȯ 
	printf("\n\n");
	
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	printf("�ݺ� �����Է� : ");
	scanf("%s" , &arr);
	
	count = arry(pt);
	printf("�ݺ����� ���� : %d\n\n" , count);
	
	printf("��ȯ �����Է� : ");
	scanf("%s" , &arr2);
	
	count2 = arry2(ptr , i);
	printf("��ȯ���� ���� : %d\n\n" , count2);
	
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	/*
	max = maxfun(Mpt , Marrlen);
	
	printf("�ִ� : %d\n" , max);
	*/ 
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	
	printf("5���� �� �Է� : ");
	for(i=0 ; i<5 ; i++){
		scanf("%d" , &Barr[i]);
	}
	//�� �Է�  
	
	for(i=5-1 ; i>0 ; i--){
		for(j=0 ; j<i ; j++){
			if(Barr[j] > Barr[j+1]){
			int temp = Barr[j];
			Barr[j] = Barr[j+1];
			Barr[j+1] = temp;
			}
		}
	}
	//���� 
	printf("%d , %d , %d , %d , %d\n" , Barr[0] , Barr[1] , Barr[2] , Barr[3] , Barr[4]);
	
	printf("ã������ �� �Է� : ");
	scanf("%d" , &target);
	
    idx = BSearch(Barr, 0, sizeof(Barr) / sizeof(int) - 1, target);
    //���ǹ迭 ,  �迭 ��ü�� ũ�� , ã������ �� 
	 
    
    if (idx == -1){
        printf("ã�� ���Ͽ����ϴ�.\n");
    }
    else{
        printf("%d���� %d��° �迭�� �ֽ��ϴ�.\n", target , idx+1);
    }
	
	return 0;
}

void star(int n){ //�ݺ� �� 
	
	int i , co;
	
	if(n>0){
		for(i=0 ; i<n ; i++){
			printf("*");
		}
	}else
		printf("������ x");
}

void star2(int m){ //��ȯ �� 
	
	int count=0;
	
	if(m < count){
		count++;
		printf("*");
		star2(m);
	}else if(m < 0)
		printf("������ x");
		
}

int arry(char *pt){

	int i,count=0;
	//printf("%d\n" , sizeof(arr));
	//534??
	//printf("%c" , pt[0]);
	for(i=0 ; i<50; i++){
		if(pt[i] != '\0')
			count++;
		else
			return (count);
		}
	
}

int arry2(char *ptr , int i){
	
	//printf("%d\n" , i);
	//int count=0;
	
	if(ptr[i] != '\0'){
		i++;
		return arry2(ptr , i);
	}else
		return i;
		
} 
/*
int maxfun(int *Mpt , int Marrlen){
	
	int max;
	
	if(Mpt[Marrlen] >= Mpt[Marrlen-1]){
		max = Mpt[Marrlen];
		return maxfun(Mpt , Marrlen-1);
	}else if(Mpt[Marrlen] <= Mpt[Marrlen-1]){
		max = Mpt[Marrlen];
		return maxfun(Mpt , Marrlen-1);
	}else
		return max;
		
}*/

int BSearch(int Barr[], int first, int last, int target){
    
	int mid = (first + last) / 2;
	//2�� Ž���� ���� ���� ������ ���� ������ 
    printf("mid : %d\n" , mid); 
    printf("first : %d\n" , first);
    printf("last : %d\n" , last);
    //Ž������  ��� 
    
	if (first > last)
        return (mid -1);	
        //ã�°� ����! 
	else{
		if (Barr[mid] == target){
	        return mid;
			//Ÿ�ٰ��� ã���� ��ȯ    	
		}else{
			if (Barr[mid] > target){
	                last = mid - 1;
	                BSearch(Barr, first, last, target);
	                //Ÿ�ٰ��� ������ �迭ũ�⸦ ��ĭ ���̰� ��ȯ 
	            }else{
	                first = mid + 1;
	                BSearch(Barr, first, last, target);
	                //Ÿ�ٰ��� ũ�� �迭ũ�⸦ ��ĭ �ø��� ��ȯ 
	            }//3�� else 
	        }//2�� else 
	}//1�� else
}

