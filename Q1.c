#include<stdio.h>


struct barrel{

    int numberofBottels;
    int price;
    int pricePerBotel;
};

/*Sorting array in decending order*/
void sortDec(struct barrel * barrels,int M)
{
	int i,j;
	struct barrel tmp;
	for(i = 0;i<M;i++)
		for(j=i;j<M;j++)
			if(barrels[i].pricePerBotel<barrels[j].pricePerBotel){
				tmp = barrels[i];
				barrels[i] = barrels[j];
				barrels[j] = tmp;
			}
}

/*Set the pricePerBotel value in barrels array*/
void valueSet(struct barrel * barrels,int M)
{
	int i;
	for(i=0;i<M;i++)barrels[i].pricePerBotel = barrels[i].price/barrels[i].numberofBottels;
}

int main(){
    int N=0,M=0,i,totPrice=0;

    scanf("%d %d",&N,&M);

    struct barrel barrels[M];
    
    /* Input M space-separated integers contain the volume of barrels and price */
    for(i=0;i<M;i++)scanf("%d",&barrels[i].numberofBottels);
    for(i=0;i<M;i++)scanf("%d",&barrels[i].price);
    
    /* Calculate pricePerBotel for whole barrel array */
    valueSet(barrels,M);
    /* Sort the barrel array in deacending order according to pricePerBotel */
	sortDec(barrels,M);

	/*Fill N bottels with highest pricePerBotel wine and calculate total price*/
    for(i = 0;i<M;i++)
		if(N>=barrels[i].numberofBottels){
			N -= barrels[i].numberofBottels;
			totPrice += barrels[i].price;
		}
		else totPrice += barrels[i].pricePerBotel*N;

    printf("%d",totPrice);
	return 0;
}
