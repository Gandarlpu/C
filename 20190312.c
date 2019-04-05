//compiler : Dev-C++
//3번 문제는 제 생각에는 맞는코드인거같은데 왜 오류가 나는지 모르겠습니다 ㅜㅜ.. 
#include<stdio.h>
#include<string.h>

void star(int n); //반복별 
void star2(int m); //순환별 
int arry(char *pt); //반복문자 
int arry2(char *ptr , int i); //순환문자 
//int maxfun(int *Mpt , int Marrlen); //최대값 함수 
int BSearch(int Barr[] , int first , int last , int target); //이진탐색 

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
	
	printf("반복 출력하고싶은 별갯수 : ");
	scanf("%d" , &n);
	
	printf("순환 출력하고싶은 별갯수 : ");
	scanf("%d" , &m);
	
	printf("반복 별 : ");
	star(n); //반복 
	printf("\n");
	printf("순환 별 : ");
	star(m); //순환 
	printf("\n\n");
	
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	printf("반복 문자입력 : ");
	scanf("%s" , &arr);
	
	count = arry(pt);
	printf("반복문자 길이 : %d\n\n" , count);
	
	printf("순환 문자입력 : ");
	scanf("%s" , &arr2);
	
	count2 = arry2(ptr , i);
	printf("순환문자 길이 : %d\n\n" , count2);
	
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	/*
	max = maxfun(Mpt , Marrlen);
	
	printf("최댓값 : %d\n" , max);
	*/ 
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	
	printf("5가지 값 입력 : ");
	for(i=0 ; i<5 ; i++){
		scanf("%d" , &Barr[i]);
	}
	//값 입력  
	
	for(i=5-1 ; i>0 ; i--){
		for(j=0 ; j<i ; j++){
			if(Barr[j] > Barr[j+1]){
			int temp = Barr[j];
			Barr[j] = Barr[j+1];
			Barr[j+1] = temp;
			}
		}
	}
	//정렬 
	printf("%d , %d , %d , %d , %d\n" , Barr[0] , Barr[1] , Barr[2] , Barr[3] , Barr[4]);
	
	printf("찾으려는 값 입력 : ");
	scanf("%d" , &target);
	
    idx = BSearch(Barr, 0, sizeof(Barr) / sizeof(int) - 1, target);
    //임의배열 ,  배열 전체의 크기 , 찾으려는 값 
	 
    
    if (idx == -1){
        printf("찾지 못하였습니다.\n");
    }
    else{
        printf("%d값은 %d번째 배열에 있습니다.\n", target , idx+1);
    }
	
	return 0;
}

void star(int n){ //반복 별 
	
	int i , co;
	
	if(n>0){
		for(i=0 ; i<n ; i++){
			printf("*");
		}
	}else
		printf("음수값 x");
}

void star2(int m){ //순환 별 
	
	int count=0;
	
	if(m < count){
		count++;
		printf("*");
		star2(m);
	}else if(m < 0)
		printf("음수값 x");
		
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
	//2진 탐색의 논리에 의해 절반의 값씩 나누기 
    printf("mid : %d\n" , mid); 
    printf("first : %d\n" , first);
    printf("last : %d\n" , last);
    //탐색과정  출력 
    
	if (first > last)
        return (mid -1);	
        //찾는값 실패! 
	else{
		if (Barr[mid] == target){
	        return mid;
			//타겟값을 찾으면 반환    	
		}else{
			if (Barr[mid] > target){
	                last = mid - 1;
	                BSearch(Barr, first, last, target);
	                //타겟값이 작으면 배열크기를 한칸 줄이고 순환 
	            }else{
	                first = mid + 1;
	                BSearch(Barr, first, last, target);
	                //타겟값이 크면 배열크기를 한칸 늘리고 순환 
	            }//3번 else 
	        }//2번 else 
	}//1번 else
}

